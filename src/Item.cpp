#include "Item.hpp"

#include "OutilsMaths.hpp"

/************************************************/
/*                   CONSTANTES                 */
/************************************************/

/************************************************/
/*          CONSTRUCTEUR/DESTRUCTEUR            */
/************************************************/
Item::Item() {
    _aSupprimer = false;
} 
Item::Item(const string& nom, int nb, const Vector2f& pos) {
    _sprite = SpriteGame(
        nom,
        nb
    );
    _position = pos;
    _aSupprimer = false;
}
Item::Item(const Item& o) {
    _sprite = o._sprite;
    _position = o._position;
    _aSupprimer = o._aSupprimer;
}
Item::~Item() {}
/************************************************/
/*                   OPERATORS                  */
/************************************************/
const Item& Item::operator=(const Item& opd) {
    if(this != &opd) {
        // aucun champs a supprimer
        _sprite = opd._sprite;
        _position = opd._position;
        _aSupprimer = opd._aSupprimer;
    }
    return *this;
}
/************************************************/
/*                  GETTER/SETTER               */
/************************************************/
const SpriteGame& Item::getSpriteGame() const {
    return _sprite;
}
bool Item::getASupprimer() const { return _aSupprimer; }
void Item::setASupprimer(bool val) { _aSupprimer = val; }
const Vector2f& Item::getPosition() const { return _position; }
void Item::setPosition(const Vector2f& pos) {
    _position = pos;
}
/************************************************/
/*                   METHODS                    */
/************************************************/
void Item::update(const Camera& camera) {
    _sprite.setPosition(
        to3Diso(
            _position + camera.getPosition()
        )
    );
}
void Item::draw(RenderWindow* p_window) {
    _sprite.draw(p_window);
}