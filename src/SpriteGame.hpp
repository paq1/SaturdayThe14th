#ifndef _SPRITE_GAME_
#define _SPRITE_GAME_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

class SpriteGame {
private:
    Texture *_textures;
    Sprite *_sprites;
    int _nbImages, _currentImage;
    string _nom;
public:
    /************************************************/
    /*                   CONSTANTES                 */
    /************************************************/

    /************************************************/
    /*          CONSTRUCTEUR/DESTRUCTEUR            */
    /************************************************/
    SpriteGame();
    SpriteGame(const string&, int);
    SpriteGame(const SpriteGame&);
    virtual ~SpriteGame();
    /************************************************/
    /*                   OPERATORS                  */
    /************************************************/
    const SpriteGame& operator=(const SpriteGame&);
    /************************************************/
    /*                  GETTER/SETTER               */
    /************************************************/
    int getCurrentImage() const;
    void setCurrentImage(int);
    void setPosition( const Vector2f& );
    /************************************************/
    /*                   METHODS                    */
    /************************************************/
    void loadAll(const string&, int);
    void deleteAll();
    void draw(RenderWindow*);
};

#endif