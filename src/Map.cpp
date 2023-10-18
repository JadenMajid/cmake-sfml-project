#include "Map.h"

Map::Map()
{
    sf::VertexArray originalLines(sf::LineStrip, 5);
    originalLines.append(sf::Vector2f(0, 0));
    originalLines.append(sf::Vector2f(200, 0));
    originalLines.append(sf::Vector2f(200, 200));
    originalLines.append(sf::Vector2f(0, 200));
    originalLines.append(sf::Vector2f(0, 0));

    this->originalLines = originalLines;
    sf::VertexArray drawingLines(sf::LineStrip, 5);

    drawingLines.append(sf::Vector2f(0, 0));
    drawingLines.append(sf::Vector2f(200, 0));
    drawingLines.append(sf::Vector2f(200, 200));
    drawingLines.append(sf::Vector2f(0, 200));
    drawingLines.append(sf::Vector2f(0, 0));

    this->drawingLines = drawingLines;

    sf::Transform staticMap;
    staticMap.translate(sf::Vector2f(400 - originalLines.getBounds().height / 2, 300-originalLines.getBounds().width/2));
    this->staticMap = staticMap;

    sf::Transform centeredPlayer;
    centeredPlayer.combine(staticMap);
}

void Map::draw(sf::RenderWindow &window) const
{
    window.draw(drawingLines);
}

void Map::moveCenteredMaptoCenter(int width, int height)
{
    int originalheight = originalLines.getBounds().height;
    int originalwidth = originalLines.getBounds().width;
    for (int i = 0; i < originalLines.getVertexCount(); i++)
    {
        drawingLines[i] = staticMap.transformPoint(originalLines[i].position.x, originalLines[i].position.y);
    }
}

void Map::drawCenteredMap(sf::RenderWindow &window)
{
    moveCenteredMaptoCenter(window.getSize().x, window.getSize().y);
    draw(window);
}

void Map::moveCenteredMaptoCenter(sf::Vector2u vec)
{
    moveCenteredMaptoCenter(vec.x, vec.y);
}

void Map::moveCenteredMapToCenterPlayer(int width, int height, Player &player)
{
    int originalheight = originalLines.getBounds().height;
    int originalwidth = originalLines.getBounds().width;
    sf::Transform centeredPlayer;

    //centeredPlayer.translate(player.getPosition());
    centeredPlayer.rotate(player.angle*180*7/22.f, player.getPosition());
    
    centeredPlayer.combine(staticMap);

    for (int i = 0; i < originalLines.getVertexCount(); i++)
    {   
        sf::Vector2f rotatedPosition = centeredPlayer.transformPoint(originalLines[i].position.x, originalLines[i].position.y);
        drawingLines[i] = rotatedPosition;
    }
}

void Map::drawCenteredMapToCenterPlayer(sf::RenderWindow &window, Player &player)
{
    moveCenteredMapToCenterPlayer(window.getSize().x, window.getSize().y, player);
    draw(window);
}
