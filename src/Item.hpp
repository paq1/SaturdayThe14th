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
    bool _aSupprimer;
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
    const Item& operator=(const Item&);
    /************************************************/
    /*                  GETTER/SETTER               */
    /************************************************/
    const SpriteGame& getSpriteGame() const;
    bool getASupprimer() const;
    void setASupprimer(bool);
    const Vector2f& getPosition() const;
    void setPosition(const Vector2f&);
    /************************************************/
    /*                   METHODS                    */
    /************************************************/
    void update(const Camera&);
    void draw(RenderWindow*);
    virtual void agir(Player&) = 0;
};

#endif