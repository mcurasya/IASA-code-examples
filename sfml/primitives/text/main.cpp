#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(1200, 900), "texts");
    sf::Font font;
    font.loadFromFile("font.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("Hello world!");
    text.setCharacterSize(150);
    text.setOrigin(text.getLocalBounds().width/2, text.getLocalBounds().height/2);
    text.setPosition(window.getSize().x/2, window.getSize().y/2);
    text.setStyle(sf::Text::Bold | sf::Text::StrikeThrough | sf::Text::Italic);
    text.setFillColor(sf::Color::Green);
    text.setOutlineColor(sf::Color::Magenta);
    text.setOutlineThickness(3);
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        window.draw(text);
        window.display();
    }
    

}