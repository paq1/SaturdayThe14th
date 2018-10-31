#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <time.h>

#include "GameBoard.hpp"
#include "Camera.hpp"
#include "Player.hpp"

using namespace std;
using namespace sf;

int main(int argc, char * argv[])
{
    srand(time(NULL));
    string title = "Saturday the 14th";
    RenderWindow window(sf::VideoMode(600, 600), title);
    window.setFramerateLimit(30);

    Camera camera = Camera(Vector2f(380, 100));
    GameBoard myMap = GameBoard();
    Player player = Player();

    Clock clock;
    Clock clockTimer;
    Time timer;

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
        
        timer = clockTimer.getElapsedTime();

        int fps = (int)(1.f / clock.getElapsedTime().asSeconds());
        clock.restart();
        text_fps.setString("FPS :" + to_string(fps));
        player.update(camera, myMap.getGameGrid(),timer);
        myMap.update(camera);
        
        
        window.clear();
        myMap.draw(&window, camera);
        player.draw(&window);
        myMap.drawElementMap(&window, camera);
        window.draw(text_fps);
        window.display();
    }

    return EXIT_SUCCESS;
}
