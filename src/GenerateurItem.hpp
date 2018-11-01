#ifndef _GENERATEUR_ITEM_
#define _GENERATEUR_ITEM_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>

#include "Piece.hpp"
#include "Player.hpp"
#include "Camera.hpp"

using namespace std;
using namespace sf;

class GenerateurItem {
private:
    list<Piece*> _listePieces;
public:
    /************************************************/
    /*                   CONSTANTES                 */
    /************************************************/
    GenerateurItem();
    virtual ~GenerateurItem();
    /************************************************/
    /*          CONSTRUCTEUR/DESTRUCTEUR            */
    /************************************************/
    
    /************************************************/
    /*                   OPERATORS                  */
    /************************************************/
    
    /************************************************/
    /*                  GETTER/SETTER               */
    /************************************************/
    
    /************************************************/
    /*                   METHODS                    */
    /************************************************/
    void loadItems();
    void deleteAllItems();
    void update(const Camera&, Player&);
    void draw(RenderWindow*);
};

#endif