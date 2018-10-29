#include "OutilsMaths.hpp"

sf::Vector2f OutilsMaths::to3Diso(const sf::Vector2f& pos_2d){
    float x = pos_2d.x - pos_2d.y;
    float y = (pos_2d.x + pos_2d.y) / 2;
    return sf::Vector2f(x,y);
}

int OutilsMaths::alea_entre_bornes(int min, int max) {
    return rand()%(max - min + 1) + min;
}

double OutilsMaths::distance_entre_2_points(const Vector2f& p1, const Vector2f& p2){
    return pow(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2), 0.5);
}

double OutilsMaths::angle_entre_points(const Vector2f& p1, const Vector2f& p2){
    return atan2((p2.y - p1.y), (p2.x - p1.x));
}