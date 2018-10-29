#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <time.h>

#include "GameBoard.hpp"

using namespace std;
using namespace sf;

int main(int argc, char * argv[])
{
    srand(time(NULL));
    RenderWindow window(sf::VideoMode(600, 600), "SFML works!");
    window.setFramerateLimit(60);

    GameBoard myMap = GameBoard();

    Clock clock;
    Font police;
    Text text_fps;
    if(!police.loadFromFile("../assets/polices/arial.ttf")){
        cout << "erreur de chargement de la police" << endl;
    }

    text_fps.setFont(police);
    text_fps.setString("fps :");
    text_fps.setCharacterSize(11);
    text_fps.setPosition(Vector2f(550, 0));
    text_fps.setColor(Color::Red);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        int fps = (int)(1.f / clock.getElapsedTime().asSeconds());
        clock.restart();
        text_fps.setString("FPS :" + to_string(fps));
        myMap.update();
        
        window.clear();
        window.draw(text_fps);
        myMap.draw(&window);
        window.display();
    }

    return 0;
}
