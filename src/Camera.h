#ifndef CAMERA_H
#define CAMERA_H
#include <SFML/Graphics.hpp>

class Camera {
    public:
        Camera(sf::RenderWindow& window);
        sf::Vector2f Camera::worldToScreen(sf::Vector2f worldPos) const;

    private:
        sf::RenderWindow& window;
};

#endif