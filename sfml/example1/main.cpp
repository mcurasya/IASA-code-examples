#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    //initialise
    float rotationspeed = 0.f;
    sf::RenderWindow window(sf::VideoMode(1200, 900), "example 1");
    //create square
    sf::RectangleShape square(sf::Vector2f(250, 250));
    square.setFillColor(sf::Color::Cyan);
    square.setOutlineColor(sf::Color::Green);
    square.setOutlineThickness(5);
    square.setOrigin(square.getLocalBounds().width / 2, square.getLocalBounds().height / 2);
    square.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    //main loop
    while (window.isOpen())
    {
        sf::Event event;
        //event loop
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) //keyboard events
            {
                if (event.key.code == sf::Keyboard::Up && rotationspeed < 1.f)
                {
                    rotationspeed += 0.01;
                }
                if (event.key.code == sf::Keyboard::Down && rotationspeed > -1.f)
                {
                    rotationspeed -= 0.01;
                }
            }
        }
        //update
        square.rotate(rotationspeed);
        //redraw
        window.clear();
        window.draw(square);
        window.display();
    }

    return 0;
}
