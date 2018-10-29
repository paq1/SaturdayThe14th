#include "GameGrid.hpp"

/************************************************/
/*                   CONSTANTES                 */
/************************************************/
const int GameGrid::TERRE = 0;
/************************************************/
/*          CONSTRUCTEUR/DESTRUCTEUR            */
/************************************************/
GameGrid::GameGrid() {
    _nbLine = NB_LINE;
    _nbColumn = NB_COLUMN;
    loadGrid();
}
GameGrid::~GameGrid() {}
/************************************************/
/*                   OPERATORS                  */
/************************************************/
const GameGrid& GameGrid::operator=(const GameGrid& opd) {
    if(this != &opd){
        _nbLine = opd._nbLine;
        _nbColumn = opd._nbColumn;
        loadGrid();
    }
    return *this;
}
/************************************************/
/*                  GETTER/SETTER               */
/************************************************/
int GameGrid::getId(int line, int column) const {
    return _grid[line][column];
}
void GameGrid::setId(int value, int line, int column) {
    _grid[line][column] = value;
}
int GameGrid::getNbLine() const { return _nbLine; }
int GameGrid::getNbColumn() const { return _nbColumn; }
/************************************************/
/*                   METHODS                    */
/************************************************/
void GameGrid::loadGrid() {
    for(int l = 0; l < NB_LINE; l++) {
        for(int c = 0; c < NB_COLUMN; c++) {
            setId(TERRE, l, c);
        }
    }
}