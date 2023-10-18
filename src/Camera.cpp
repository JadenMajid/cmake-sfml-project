#include "Camera.h"

Camera::Camera(sf::RenderWindow& screen) : window(screen) {}

/**
 * @brief Converts a world position to screen position.
 * 
 * @param worldPos The world position to convert.
 * @return sf::Vector2f The screen position.
 */
sf::Vector2f Camera::worldToScreen(sf::Vector2f worldPos) const
{
    sf::Vector2u windowSize = window.getSize();
    sf::View view = window.getView();
    sf::Vector2f viewCenter = view.getCenter();
    sf::Vector2f viewSize = view.getSize();
    sf::Vector2f viewTopLeft = viewCenter - viewSize / 2.f;
    sf::Vector2f viewRelativePos = worldPos - viewTopLeft;
    sf::Vector2f screenPos = viewRelativePos * (float)windowSize.x / viewSize.x;
    screenPos.y = windowSize.y - screenPos.y;
    return screenPos;
}
