#ifndef _CAMERA_
#define _CAMERA_

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Camera {
private:
    Vector2f _position;
public:
    /************************************************/
    /*                   CONSTANTES                 */
    /************************************************/

    /************************************************/
    /*          CONSTRUCTEUR/DESTRUCTEUR            */
    /************************************************/
    Camera();
    Camera(const Vector2f&);
    virtual ~Camera();
    /************************************************/
    /*                   OPERATORS                  */
    /************************************************/

    /************************************************/
    /*                  GETTER/SETTER               */
    /************************************************/
    const Vector2f& getPosition() const;
    Camera& setPosition(const Vector2f&);
    /************************************************/
    /*                   METHODS                    */
    /************************************************/
};

#endif