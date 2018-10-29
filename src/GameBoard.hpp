#ifndef _GAME_BOARD_
#define _GAME_BOARD_

#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameGrid.hpp"
#include "Camera.hpp"

#define NB_TILE 1
#define NB_ARBRE 500

using namespace std;
using namespace sf;

class GameBoard {
private:
    Texture _textures[NB_TILE];
    Sprite _sprites[NB_TILE];
    GameGrid _gameGrid;
    Camera _camera;
public:
    /************************************************/
    /*                   CONSTANTES                 */
    /************************************************/

    /************************************************/
    /*          CONSTRUCTEUR/DESTRUCTEUR            */
    /************************************************/
    GameBoard();
    virtual ~GameBoard();
    /************************************************/
    /*                   OPERATORS                  */
    /************************************************/

    /************************************************/
    /*                  GETTER/SETTER               */
    /************************************************/

    /************************************************/
    /*                   METHODS                    */
    /************************************************/
    bool isInScreen(const Vector2f&) const;
    void loadTexturesSprites();
    void update();
    void draw(RenderWindow*);
};

#endif