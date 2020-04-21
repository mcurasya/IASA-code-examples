#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(1200, 900), "rotation test");
    sf::RectangleShape shape(sf::Vector2f(500, 200));
    shape.move(200, 200);
    shape.setRotation(20.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    
    return 0;
}
