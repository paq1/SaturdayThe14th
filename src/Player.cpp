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

    // animation
    _isInit = false;
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
    _sprites[0] = SpriteGame(
        "../assets/assets_pixel_50x50/isometric_pixel_001",
        8
    );
    _sprites[1] = SpriteGame(
        "../assets/assets_pixel_50x50/isometric_pixel_002",
        8
    );
    _sprites[2] = SpriteGame(
        "../assets/assets_pixel_50x50/isometric_pixel_003",
        8
    );
    _sprites[3] = SpriteGame(
        "../assets/assets_pixel_50x50/isometric_pixel_004",
        8
    );
}
void Player::deplacement(Camera& camera) {
    Vector2f ancienne_position = _position;
    Vector2f ancienne_position_camera = 
    camera.getPosition();
    int speed = 4;
    if(Keyboard::isKeyPressed(Keyboard::Z)) {
        _currentImage = 0;
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
        _currentImage = 1;
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
        _currentImage = 2;
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
        _currentImage = 3;
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
void Player::animation(const Time& timer) {
    if(!_isInit) {
        _oldTime = timer + seconds(1.f);
        _isInit = true;
    }

    if(timer > _oldTime) {
        _isInit = false;
        int currentImg = _sprites[_currentImage].getCurrentImage();
        int nbImg = _sprites[_currentImage].getNbImages();
        int newCurrentImage = 0;
        if(currentImg < nbImg - 2) {
            newCurrentImage = currentImg + 1;
        }
        _sprites[_currentImage].setCurrentImage(newCurrentImage);
    }
}
void Player::update(Camera& camera, const Time& timer) {
    deplacement(camera);
    animation(timer);
    _sprites[_currentImage].setPosition(
        to3Diso(_position + camera.getPosition())
    );
}
void Player::draw(RenderWindow* p_window) {
    _sprites[_currentImage].draw(p_window);
}