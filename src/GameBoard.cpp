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
    _gameGrid = GameGrid();
}
GameBoard::~GameBoard() {}
/************************************************/
/*                   OPERATORS                  */
/************************************************/

/************************************************/
/*                  GETTER/SETTER               */
/************************************************/

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
    for(int i = 0; i < NB_TILE; i++)
        _sprites[i].setTexture(_textures[i]);
}
void GameBoard::update(Camera& camera) {
    int speed = 2;
    if(Keyboard::isKeyPressed(Keyboard::Up)){
        camera.setPosition(  
            camera.getPosition() + Vector2f(0, -speed)
        );
    }
    if(Keyboard::isKeyPressed(Keyboard::Right)){
        camera.setPosition(  
            camera.getPosition() + Vector2f(speed, 0)
        );
    }
    if(Keyboard::isKeyPressed(Keyboard::Down)){
        camera.setPosition(  
            camera.getPosition() + Vector2f(0, speed)
        );
    }
    if(Keyboard::isKeyPressed(Keyboard::Left)){
        camera.setPosition(  
            camera.getPosition() + Vector2f(-speed, 0)
        );
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