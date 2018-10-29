#include "Camera.hpp"

/************************************************/
/*                   CONSTANTES                 */
/************************************************/

/************************************************/
/*          CONSTRUCTEUR/DESTRUCTEUR            */
/************************************************/
Camera::Camera() {
    _position = Vector2f(0,0);
}
Camera::Camera(const Vector2f& position) {
    _position = position;
}
Camera::~Camera() {}
/************************************************/
/*                   OPERATORS                  */
/************************************************/

/************************************************/
/*                  GETTER/SETTER               */
/************************************************/
const Vector2f& Camera::getPosition() const { 
    return _position; 
}
Camera& Camera::setPosition(const Vector2f& position) {
    _position = position;
    return *this;
}
/************************************************/
/*                   METHODS                    */
/************************************************/