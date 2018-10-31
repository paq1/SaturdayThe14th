#include "Item.hpp"

/************************************************/
/*                   CONSTANTES                 */
/************************************************/

/************************************************/
/*          CONSTRUCTEUR/DESTRUCTEUR            */
/************************************************/
Item::Item() {} // non utile
Item::Item(const string& nom, int nb, const Vector2f& pos) {
    _sprite = SpriteGame(
        nom,
        nb
    );
    _position = pos;
}
Item::Item(const Item& o) {
    _sprite = o._sprite;
    _position = o._position;
}
Item::~Item() {}
/************************************************/
/*                   OPERATORS                  */
/************************************************/

/************************************************/
/*                  GETTER/SETTER               */
/************************************************/

/************************************************/
/*                   METHODS                    */
/************************************************/
//void Item::update(const Camera& camera) {

//}
void Item::update(const Camera& camera) {
    
}
void Item::draw(RenderWindow* p_window) {

}