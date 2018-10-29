#ifndef _OUTILS_MATHS_
#define _OUTILS_MATHS_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <math.h>

using namespace std;
using namespace sf;

namespace OutilsMaths {
    Vector2f to3Diso(const Vector2f&);
    int alea_entre_bornes(int, int);
    double distance_entre_2_points(const Vector2f&, const Vector2f&);
    double angle_entre_points(const Vector2f&, const Vector2f&);
}

#endif