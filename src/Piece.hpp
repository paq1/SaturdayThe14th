#ifndef _PIECE_
#define _PIECE_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string> 

#include "Item.hpp"

using namespace std;
using namespace sf;

class Piece : public Item {
private:
    int _valeure;
public:
    /************************************************/
    /*                   CONSTANTES                 */
    /************************************************/

    /************************************************/
    /*          CONSTRUCTEUR/DESTRUCTEUR            */
    /************************************************/
    Piece();
    Piece(const string&, int, const Vector2f&, int);
    Piece(const Piece&);
    virtual ~Piece();
    /************************************************/
    /*                   OPERATORS                  */
    /************************************************/
    const Piece& operator=(const Piece&);
    /************************************************/
    /*                  GETTER/SETTER               */
    /************************************************/
    
    /************************************************/
    /*                   METHODS                    */
    /************************************************/
    virtual void agir(Player&);
};

#endif