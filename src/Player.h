#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player
{
public:
    Player(float radius, int x, int y);
    Player();
    void handleInput();
    void drawStaticCamera(sf::RenderWindow &window);
    void drawCenteredCamera(sf::RenderWindow &window);
    void update();
    void printKinematicInformation(sf::RenderWindow &window);
    void drawKinematicInformation(sf::RenderWindow &window);
    sf::Vector2f getPosition() const;
    float vx;
    float vy;
    float x;
    float y;
    const float MOV_SPEED = 0.05;

    float angle;
    const float TURN_SPEED = 0.05;

private:
    sf::CircleShape shape;
    const bool KIN_INFO = true;
};

#endif // PLAYER_H