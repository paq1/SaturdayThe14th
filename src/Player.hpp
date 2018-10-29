#ifndef _PLAYER_
#define _PLAYER_

#include <iostream>
#include <SFML/Graphics.hpp>

#include "OutilsMaths.hpp"
#include "Camera.hpp"

using namespace OutilsMaths;
using namespace std;
using namespace sf;

class Player {
private:
    Vector2f _position;
    Texture _textures[4];
    Sprite _sprites[4];
    int _currentImage;
public:
    /************************************************/
    /*                   CONSTANTES                 */
    /************************************************/

    /************************************************/
    /*          CONSTRUCTEUR/DESTRUCTEUR            */
    /************************************************/
    Player();
    virtual ~Player();
    /************************************************/
    /*                   OPERATORS                  */
    /************************************************/

    /************************************************/
    /*                  GETTER/SETTER               */
    /************************************************/
    
    /************************************************/
    /*                   METHODS                    */
    /************************************************/
    void loadTexturesSprites();
    void update(Camera&);
    void draw(RenderWindow*);
};

#endif