#include "Player.hpp"

/************************************************/
/*                   CONSTANTES                 */
/************************************************/

/************************************************/
/*          CONSTRUCTEUR/DESTRUCTEUR            */
/************************************************/
Player::Player() {
    loadTexturesSprites();
    _currentImage = 0;
    _position = Vector2f(50,50);
}
Player::~Player() {}
/************************************************/
/*                   OPERATORS                  */
/************************************************/

/************************************************/
/*                  GETTER/SETTER               */
/************************************************/

/************************************************/
/*                   METHODS                    */
/************************************************/
void Player::loadTexturesSprites() {
    if(!_textures[0].loadFromFile(
        "../assets/assets_pixel_50x50/isometric_pixel_0001.png"
    )) {
        cout << "erreur de chargement" << endl;
    }
    if(!_textures[1].loadFromFile(
        "../assets/assets_pixel_50x50/isometric_pixel_0002.png"
    )) {
        cout << "erreur de chargement" << endl;
    }
    if(!_textures[2].loadFromFile(
        "../assets/assets_pixel_50x50/isometric_pixel_0003.png"
    )) {
        cout << "erreur de chargement" << endl;
    }
    if(!_textures[3].loadFromFile(
        "../assets/assets_pixel_50x50/isometric_pixel_0004.png"
    )) {
        cout << "erreur de chargement" << endl;
    }
    for (int i = 0; i < 4; i++){
        _sprites[i].setTexture(_textures[i]);
    }
}
void Player::deplacement(Camera& camera) {
    int speed = 2;
    if(Keyboard::isKeyPressed(Keyboard::Z)) {
        _position += Vector2f(0, -speed);
        camera.setPosition(
            camera.getPosition() + Vector2f(0, speed)
        );
    }
    if(Keyboard::isKeyPressed(Keyboard::D)) {
        _position += Vector2f(speed, 0);
        camera.setPosition(
            camera.getPosition() + Vector2f(-speed, 0)
        );
    }
    if(Keyboard::isKeyPressed(Keyboard::S)) {
        _position += Vector2f(0, speed);
        camera.setPosition(
            camera.getPosition() + Vector2f(0, -speed)
        );
    }
    if(Keyboard::isKeyPressed(Keyboard::Q)) {
        _position += Vector2f(-speed, 0);
        camera.setPosition(
            camera.getPosition() + Vector2f(speed, 0)
        );
    }
}
void Player::update(Camera& camera) {
    deplacement(camera);

    _sprites[_currentImage].setPosition(
        to3Diso(_position + camera.getPosition())
    );
}

void Player::draw(RenderWindow* p_window) {
    p_window->draw(_sprites[_currentImage]);
}