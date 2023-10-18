#include <SFML/Graphics.hpp>
#include "Player.h"
#include <cmath>

Player::Player(float radius, int x, int y)
{
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(x, y);
    this->x = x;
    this->y = y;
    this->angle = 0;
}

Player::Player()
{
    shape.setRadius(20);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(0, 0);
}

/**
 * @brief Handles input for the player object.
 *
 * This function checks for keyboard input and updates the player's velocity and angle accordingly.
 *
 */
void Player::handleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        vy += MOV_SPEED * sin(angle);
        vx += MOV_SPEED * cos(angle);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        angle -= TURN_SPEED;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        vy -= MOV_SPEED * sin(angle);
        vx -= MOV_SPEED * cos(angle);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        angle += TURN_SPEED;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        vy = 0;
        vx = 0;
    }
}

void Player::drawStaticCamera(sf::RenderWindow &window)
{
    update();
    if (KIN_INFO)
    {
        printKinematicInformation(window);
        drawKinematicInformation(window);
    }


    // Bound x and y within the window's dimensions
    x = std::max(0.f, std::min(x, static_cast<float>(window.getSize().x - 2 * shape.getRadius())));
    y = std::max(0.f, std::min(y, static_cast<float>(window.getSize().y - 2 * shape.getRadius())));

    // Bound vx and vy to be reasonable
    vx = std::max(-3.f, std::min(vx, 3.f));
    vy = std::max(-3.f, std::min(vy, 3.f));

    shape.setPosition(x, y);
    window.draw(shape);
}

void Player::drawCenteredCamera(sf::RenderWindow &window){
    if (KIN_INFO)
    {
        printKinematicInformation(window);
        drawKinematicInformation(window);
    }
    update();
    shape.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    window.draw(shape);
}

void Player::update()
{
    handleInput();
    x += vx;
    y += vy;
    shape.move(vx, vy);
}

sf::Vector2f Player::getPosition() const
{
    return sf::Vector2f(x, y);
}

/**
 * Prints the kinematic information of the player on the given window.
 * @param window The window to draw the kinematic information on.
 */
void Player::printKinematicInformation(sf::RenderWindow &window)
{
    sf::Font font;
    font.loadFromFile("/System/Library/Fonts/SFCompact.ttf");

    // Load it from a file
    sf::Text text;
    text.setFont(font);
    std::string kin_string = "vx:";
    kin_string.append(std::to_string(this->vx));
    kin_string.append("\nvy:");
    kin_string.append(std::to_string(this->vy));
    kin_string.append("\nx:");
    kin_string.append(std::to_string(this->x));
    kin_string.append("\ny:");
    kin_string.append(std::to_string(this->y));
    kin_string.append("\nangle:");
    kin_string.append(std::to_string(this->angle));
    text.setString(kin_string);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    // text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    window.draw(text);
}

/**
 * Draws the kinematic information of the player on the given window.
 * This includes a red line indicating the direction of the player and a cyan line indicating the velocity of the player.
 * @param window The window to draw the kinematic information on.
 */
void Player::drawKinematicInformation(sf::RenderWindow &window)
{
    float len = 20;
    sf::RectangleShape direction(sf::Vector2f(len, 3.f));
    direction.setFillColor(sf::Color::Red);
    direction.setRotation(angle * 180.f * 7 / 22.f);
    direction.setPosition(shape.getPosition().x + shape.getRadius(), shape.getPosition().y + shape.getRadius());

    window.draw(direction);

    sf::RectangleShape velocity(sf::Vector2f(len, 3.f));
    velocity.setFillColor(sf::Color::Cyan);
    velocity.setRotation(atan2(vy, vx) * 180 * 7 / 22.f);
    velocity.setPosition(shape.getPosition().x + shape.getRadius(), shape.getPosition().y + shape.getRadius());

    if (vx != 0.f && vy != 0.f)
        window.draw(velocity);
}
