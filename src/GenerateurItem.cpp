#include "GenerateurItem.hpp"

#include "OutilsMaths.hpp"

using namespace OutilsMaths;

/************************************************/
/*                   CONSTANTES                 */
/************************************************/

/************************************************/
/*          CONSTRUCTEUR/DESTRUCTEUR            */
/************************************************/
GenerateurItem::GenerateurItem() {
    loadItems();
}
GenerateurItem::~GenerateurItem() {
    deleteAllItems();
}
/************************************************/
/*                   OPERATORS                  */
/************************************************/

/************************************************/
/*                  GETTER/SETTER               */
/************************************************/

/************************************************/
/*                   METHODS                    */
/************************************************/
void GenerateurItem::loadItems() {
    _listePieces.push_back(
        new Piece(
            "../assets/element_map/feu", 
            3, 
            Vector2f(200, 200), 
            10
        )
    );
}
void GenerateurItem::deleteAllItems() {
    _listePieces.remove_if([](Item * i) {
        delete i;
        return true;
    });
}
void GenerateurItem::update(const Camera& camera, Player& player) {
    for(Piece * p : _listePieces){
        p->update(camera);
    }

    for(Piece * p : _listePieces) {
        double distance = distance_entre_2_points(
            p->getPosition(),
            player.getPosition()
        );
        if(distance < 50) {
            p->agir(player);
        }
    }

    _listePieces.remove_if([](Piece * p){
        if(p->getASupprimer()) {
            delete p;
            return true;
        }
    });

    cout << player.getArgent() << endl;
}
void GenerateurItem::draw(RenderWindow* p_window) {
    for(Piece * p : _listePieces){
        p->draw(p_window);
    }
}