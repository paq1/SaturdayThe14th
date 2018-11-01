#ifndef _PLAYER_
#define _PLAYER_

#include <iostream>
#include <SFML/Graphics.hpp>

#include "OutilsMaths.hpp"
#include "Camera.hpp"
#include "SpriteGame.hpp"
#include "GameGrid.hpp"

using namespace OutilsMaths;
using namespace std;
using namespace sf;

#define DIRECTION 4

class Player {
private:
    Vector2f _position;
    SpriteGame _sprites[DIRECTION];
    int _currentImage, _argent;
    
    // animation
    Time _oldTime; // pas besoin a initialiser
    bool _isInit;
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
    int getArgent() const;
    void setArgent(int);
    /************************************************/
    /*                   METHODS                    */
    /************************************************/
    void loadTexturesSprites();
    void deplacement(Camera&);
    void animation(const Time&);
    void update(Camera&, const GameGrid&,const Time&);
    void draw(RenderWindow*);
};

#endif