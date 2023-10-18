#ifndef MAP_H
#define MAP_H
#include "Player.h"

class Map
{
public:
    Map();

    void draw(sf::RenderWindow &window) const;

    void moveCenteredMaptoCenter(int width, int height);

    void moveCenteredMaptoCenter(sf::Vector2u vec);

    void moveCenteredMapToCenterPlayer(int width, int height, Player &player);

    void drawCenteredMapToCenterPlayer(sf::RenderWindow &window, Player &player);

    void drawCenteredMap(sf::RenderWindow &window);

private:
    sf::VertexArray originalLines;
    sf::VertexArray drawingLines;
    sf::RenderStates renderstates;
    sf::Transform staticMap;
    sf::Transform centeredPlayer;
};
#endif