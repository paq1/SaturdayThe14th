#include "GameBoard.hpp"

#include <string>
#include "OutilsMaths.hpp"

using namespace OutilsMaths;

/************************************************/
/*                   CONSTANTES                 */
/************************************************/

/************************************************/
/*          CONSTRUCTEUR/DESTRUCTEUR            */
/************************************************/
GameBoard::GameBoard() {
    loadTexturesSprites();
    loadElementMap();
    _gameGrid = GameGrid();
}
GameBoard::~GameBoard() {
    deleteAllElementMap();
}
/************************************************/
/*                   OPERATORS                  */
/************************************************/

/************************************************/
/*                  GETTER/SETTER               */
/************************************************/
const GameGrid& GameBoard::getGameGrid() const {
    return _gameGrid;
}
/************************************************/
/*                   METHODS                    */
/************************************************/
bool GameBoard::isInScreen(const Vector2f& pos) const {
    return (pos.x > -100 && pos.x < 600 && 
    pos.y > -100 && pos.y < 600);
}
void GameBoard::loadTexturesSprites() {
    string dest = string(
        "../assets/assets_pixel_50x50/isometric_pixel_0000.png"
    );
    if(!_textures[0].loadFromFile(dest)){
        cout << "erreur de chargement de " << dest << endl;
    }
    dest = string(
        "../assets/assets_pixel_50x50/isometric_pixel_0051.png"
    );
    if(!_textures[1].loadFromFile(dest)){
        cout << "erreur de chargement de " << dest << endl;
    }
    for(int i = 0; i < NB_TILE; i++)
        _sprites[i].setTexture(_textures[i]);
}
void GameBoard::loadElementMap() {
    _listeElementMap = list<ElementMap*>();

    for (int i = 0; i < NB_ARBRE; i++) {
        int x = alea_entre_bornes(50, (5000 - 150)/2),
            y = alea_entre_bornes(50, (5000 - 150)/2);
        
        _listeElementMap.push_back(
            new ElementMap(
                Vector2f(x, y),
                "../assets/element_map/arbre_entier0.png"
            )
        );
    }
}
void GameBoard::deleteAllElementMap() {
    _listeElementMap.remove_if([](ElementMap * e){
        delete e;
        return true;
    });
}
void GameBoard::update(Camera& camera) {
    for(ElementMap * e : _listeElementMap){
        e->update(camera);
    }
}
void GameBoard::draw(RenderWindow * p_window, const Camera& camera) {
    for(int l = 0; l < _gameGrid.getNbLine(); l++){
        for(int c = 0; c < _gameGrid.getNbColumn(); c++){
            Vector2f pos = Vector2f(c * (50/2), l * (50/2));
            Vector2f pos_affiche = to3Diso(
                pos + camera.getPosition()
            );

            if(isInScreen(pos_affiche)){
                _sprites[_gameGrid.getId(l,c)].setPosition(pos_affiche);
                p_window->draw(_sprites[_gameGrid.getId(l,c)]);
            }
        }
    }
    
}
void GameBoard::drawElementMap(RenderWindow* p_window, const Camera& camera) const {
    for(ElementMap * e : _listeElementMap){
        if(
            isInScreen(
                to3Diso(
                    e->getPosition() + camera.getPosition()
                )
            )
        ){
            e->draw(p_window);
        }
            
    }
}