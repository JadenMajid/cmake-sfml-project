#include <SFML/Graphics.hpp>

class Line{
    public:
        Line(float x, float y, sf::Vector2f vec){
            this->x = x;
            this->y = y;
            this->vec = vec;
        }

        Line(float x1, float y1, float x2, float y2){
            this->x = x1;
            this->y = y1;
            this->vec = sf::Vector2f(x2-x1, y2-y1);
        }

        void draw(sf::RenderWindow& window){
            
        }

        
    private:
        float x;
        float y;
        sf::Vector2f vec;
};