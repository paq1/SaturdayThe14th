#ifndef _GAME_GRID_
#define _GAME_GRID_

#include <iostream>
#include <SFML/Graphics.hpp>

#define NB_LINE   100
#define NB_COLUMN 100
#define SIZE_TILE 50

using namespace std;
using namespace sf;

class GameGrid {
private:
    int _grid[NB_LINE][NB_COLUMN];
    int _nbLine, _nbColumn;
public:
    /************************************************/
    /*                   CONSTANTES                 */
    /************************************************/
    static const int TERRE;
    static const int PIERRE;
    /************************************************/
    /*          CONSTRUCTEUR/DESTRUCTEUR            */
    /************************************************/
    GameGrid();
    virtual ~GameGrid();
    /************************************************/
    /*                   OPERATORS                  */
    /************************************************/
    const GameGrid& operator=(const GameGrid&);
    /************************************************/
    /*                  GETTER/SETTER               */
    /************************************************/
    int getId(int, int) const;
    void setId(int, int, int);
    int getNbLine() const;
    int getNbColumn() const;
    /************************************************/
    /*                   METHODS                    */
    /************************************************/
    void loadGrid();
    int getTileAt(const Vector2f&) const;
};

#endif