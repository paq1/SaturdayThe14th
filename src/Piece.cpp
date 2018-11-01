#include "Piece.hpp"

/************************************************/
/*                   CONSTANTES                 */
/************************************************/

/************************************************/
/*          CONSTRUCTEUR/DESTRUCTEUR            */
/************************************************/
Piece::Piece() : Item() {
    _valeure = 0;
}
Piece::Piece(
    const string& nom, 
    int nb, 
    const Vector2f& pos, 
    int value
) : Item(nom, nb, pos) {
    _valeure = value;
}
Piece::Piece(const Piece& o) : Item(
    o.getSpriteGame().getNom(),
    o.getSpriteGame().getNbImages(),
    o.getPosition()
), _valeure(o._valeure) {} 
Piece::~Piece() {}
/************************************************/
/*                   OPERATORS                  */
/************************************************/

const Piece& Piece::operator=(const Piece& opd) {
    if(this != &opd) {
        Item::operator=(opd);

        _valeure = opd._valeure;
    }
    return *this;
}

/************************************************/
/*                  GETTER/SETTER               */
/************************************************/

/************************************************/
/*                   METHODS                    */
/************************************************/
void Piece::agir(Player& player) {
    player.setArgent(
        player.getArgent() + _valeure
    );
    setASupprimer(true); // on peut supprimer l'item
}