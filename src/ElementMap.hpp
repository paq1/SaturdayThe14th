#ifndef _ELEMENT_MAP_
#define _ELEMENT_MAP_

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Camera.hpp"

using namespace std;
using namespace sf;

class ElementMap {
private:
    Texture _texture;
    Sprite _sprite;
    Vector2f _position;
public:
/************************************************/
/*                   CONSTANTES                 */
/************************************************/

/************************************************/
/*          CONSTRUCTEUR/DESTRUCTEUR            */
/************************************************/
    ElementMap();
    ElementMap(const Vector2f&, const string&);
    virtual ~ElementMap();
/************************************************/
/*                   OPERATORS                  */
/************************************************/

/************************************************/
/*                  GETTER/SETTER               */
/************************************************/
    const Vector2f& getPosition() const;
    void setPosition(const Vector2f&);
    void setPositionSprite(const Vector2f&);
/************************************************/
/*                   METHODS                    */
/************************************************/
    void loadTextureSprite(const string&);
    void update(const Camera&);
    void draw(RenderWindow*);
};

#endif