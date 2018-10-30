#include "ElementMap.hpp"

#include "OutilsMaths.hpp"

using namespace OutilsMaths;

/************************************************/
/*                   CONSTANTES                 */
/************************************************/

/************************************************/
/*          CONSTRUCTEUR/DESTRUCTEUR            */
/************************************************/
ElementMap::ElementMap() {
    loadTextureSprite("../assets/element_map/arbre_entier0.png");
    _position = Vector2f(0,0);
}
ElementMap::ElementMap(const Vector2f& pos, const string& dest) {
    loadTextureSprite(dest);
    _position = pos;
}
ElementMap::~ElementMap() {}

/************************************************/
/*                   OPERATORS                  */
/************************************************/

/************************************************/
/*                  GETTER/SETTER               */
/************************************************/
const Vector2f& ElementMap::getPosition() const {
    return _position;
}
void ElementMap::setPosition(const Vector2f& pos) {
    _position = pos;
}
void ElementMap::setPositionSprite(const Vector2f& pos) {
    _sprite.setPosition(pos);    
}
/************************************************/
/*                   METHODS                    */
/************************************************/
void ElementMap::loadTextureSprite(const string& dest) {
    if(!_texture.loadFromFile(dest)) {
        cout << "erreur de chargement text element map" << endl;
    }

    _sprite.setTexture(_texture);
}
void ElementMap::update(const Camera& camera) {
    _sprite.setPosition(
        to3Diso(
            _position + camera.getPosition()
        )
    );
}
void ElementMap::draw(RenderWindow * p_window) {
    p_window->draw(_sprite);
}