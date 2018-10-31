#ifndef _ITEM_
#define _ITEM_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#include "SpriteGame.hpp"
#include "Player.hpp"
#include "Camera.hpp"

using namespace std;
using namespace sf;

class Item {
private:
    SpriteGame _sprite;
    Vector2f _position;
public:
    /************************************************/
    /*                   CONSTANTES                 */
    /************************************************/

    /************************************************/
    /*          CONSTRUCTEUR/DESTRUCTEUR            */
    /************************************************/
    Item();
    Item(const string&, int, const Vector2f&);
    Item(const Item&);
    virtual ~Item();
    /************************************************/
    /*                   OPERATORS                  */
    /************************************************/

    /************************************************/
    /*                  GETTER/SETTER               */
    /************************************************/
    
    /************************************************/
    /*                   METHODS                    */
    /************************************************/
    void update(const Camera&);
    void draw(RenderWindow*);
    virtual void agit(Player&) = 0;
};

#endif