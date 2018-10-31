#include "SpriteGame.hpp"

/************************************************/
/*                   CONSTANTES                 */
/************************************************/

/************************************************/
/*          CONSTRUCTEUR/DESTRUCTEUR            */
/************************************************/
SpriteGame::SpriteGame() {
    _nbImages = 0;
    _currentImage = 0;
    _nom = "";

    _textures = NULL;
    _sprites = NULL;
}
SpriteGame::SpriteGame(const string& nom, int nb) {
    loadAll(nom, nb);
}
SpriteGame::SpriteGame(const SpriteGame& o) {
    loadAll(o._nom, o._nbImages);    
}
SpriteGame::~SpriteGame() { deleteAll(); }
/************************************************/
/*                   OPERATORS                  */
/************************************************/
const SpriteGame& SpriteGame::operator=(const SpriteGame& opd) {
    if(this != &opd) {
        deleteAll();
        loadAll(opd._nom, opd._nbImages);
    }
    return *this;
}
/************************************************/
/*                  GETTER/SETTER               */
/************************************************/
int SpriteGame::getNbImages() const { return _nbImages; }
int SpriteGame::getCurrentImage() const { return _currentImage; }
void SpriteGame::setCurrentImage(int i) { 
    _currentImage = i;
    //cout << "changement image" << endl; 
}
void SpriteGame::setPosition( const Vector2f& position ) {
    _sprites[_currentImage].setPosition(position);
}
/************************************************/
/*                   METHODS                    */
/************************************************/
SpriteGame * SpriteGame::clone() const {
    return new SpriteGame(*this);
}
void SpriteGame::loadAll(const string& nom, int nb) {
    _nbImages = nb;
    _currentImage = 0;
    _nom = nom;
    _textures = new Texture[_nbImages];
    _sprites = new Sprite[_nbImages];

    for(int i = 0; i < _nbImages; i++) {
        string dest = nom + to_string(i) + ".png";
        if(!_textures[i].loadFromFile(dest)) {
            cout << "erreur de chargement" << endl;
        }
        _sprites[i].setTexture(_textures[i]);
    }
}
void SpriteGame::deleteAll() {
    delete[] _textures;
    delete[] _sprites;
}
void SpriteGame::draw(RenderWindow * p_window) {
    p_window->draw(_sprites[_currentImage]);
}