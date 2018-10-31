#ifndef _GAME_BOARD_
#define _GAME_BOARD_

#include <iostream>
#include <list>
#include <SFML/Graphics.hpp>

#include "GameGrid.hpp"
#include "Camera.hpp"
#include "ElementMap.hpp"

#define NB_TILE 2
#define NB_ARBRE 500

using namespace std;
using namespace sf;

class GameBoard {
private:
    Texture _textures[NB_TILE];
    Sprite _sprites[NB_TILE];
    GameGrid _gameGrid;
    list<ElementMap*> _listeElementMap;
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
    const GameGrid& getGameGrid() const;
    /************************************************/
    /*                   METHODS                    */
    /************************************************/
    bool isInScreen(const Vector2f&) const;
    void loadTexturesSprites();
    void loadElementMap();
    void deleteAllElementMap();
    void update(Camera&);
    void draw(RenderWindow*, const Camera&);
    void drawElementMap(RenderWindow*, const Camera&) const;
};

#endif