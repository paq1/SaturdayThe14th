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
    Vector2f ancienne_position = _position;
    Vector2f ancienne_position_camera = 
    camera.getPosition();
    int speed = 4;
    if(Keyboard::isKeyPressed(Keyboard::Z)) {
        _position += Vector2f(0, -speed);
        if(_position.y > -25){
            camera.setPosition(
                camera.getPosition() + Vector2f(0, speed)
            );
        } else {
            _position = ancienne_position;
            camera.setPosition(
                ancienne_position_camera
            );
        }        
    }
    if(Keyboard::isKeyPressed(Keyboard::D)) {
        _position += Vector2f(speed, 0);
        if(_position.x < 98 * 25) {
            camera.setPosition(
                camera.getPosition() + Vector2f(-speed, 0)
            );
        } else {
            _position = ancienne_position;
            camera.setPosition(
                ancienne_position_camera
            );
        }
        
    }
    if(Keyboard::isKeyPressed(Keyboard::S)) {
        _position += Vector2f(0, speed);
        if(_position.y < 98 * 25){
            camera.setPosition(
                camera.getPosition() + Vector2f(0, -speed)
            );
        } else {
            _position = ancienne_position;
            camera.setPosition(
                ancienne_position_camera
            );
        }
    }
    if(Keyboard::isKeyPressed(Keyboard::Q)) {
        _position += Vector2f(-speed, 0);
        if(_position.x > -25) {
            camera.setPosition(
                camera.getPosition() + Vector2f(speed, 0)
            );
        } else {
            _position = ancienne_position;  
            camera.setPosition(
                ancienne_position_camera
            );          
        }
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