#ifndef _GAME_BOARD_
#define _GAME_BOARD_

#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameGrid.hpp"

#define NB_TILE 2
#define NB_ARBRE 500

using namespace std;
using namespace sf;

class GameBoard {
private:
    GameGrid _gameGrid;
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
};

#endif