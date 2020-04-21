#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(1200, 900), "scaling example");
    sf::CircleShape shape(300.f);
    shape.move(200, 200);
    shape.setScale(1.5, 0.5);
    shape.setFillColor(sf::Color::Cyan);
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
