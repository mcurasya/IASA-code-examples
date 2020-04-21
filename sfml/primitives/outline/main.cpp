#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(1200, 900), "rotation test");
    //same radius
    sf::CircleShape negativeOutlineCircle(250);
    sf::CircleShape positiveOutlineCircle(250);
    //different outline
    negativeOutlineCircle.setOrigin(negativeOutlineCircle.getLocalBounds().width/2, negativeOutlineCircle.getLocalBounds().height/2);
    positiveOutlineCircle.setOrigin(positiveOutlineCircle.getLocalBounds().width/2, positiveOutlineCircle.getLocalBounds().height/2);
    negativeOutlineCircle.setOutlineColor(sf::Color::Green);
    positiveOutlineCircle.setOutlineColor(sf::Color::Magenta);
    negativeOutlineCircle.setOutlineThickness(-50);
    positiveOutlineCircle.setOutlineThickness(50);
    negativeOutlineCircle.setPosition(300, 450);
    positiveOutlineCircle.setPosition(900, 450);
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
        window.draw(negativeOutlineCircle);
        window.draw(positiveOutlineCircle);
        window.display();
    }
    
    return 0;
}