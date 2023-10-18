#include <cmath>
#include <iostream>
#include "Player.h"
#include "Map.h"

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    const int FRAME_RATE = 144;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My window");
    window.setFramerateLimit(FRAME_RATE);
    float t = 0;
    const float dt = 0.02f;

    Player player(10, WIDTH / 2, HEIGHT / 2);
    Map map;
    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        // player.draw(window);
        map.drawCenteredMapToCenterPlayer(window, player);

        player.drawCenteredCamera(window);

        t += dt;
        // std::cout << t << '\n' << std::endl;
        window.display();
    }
}