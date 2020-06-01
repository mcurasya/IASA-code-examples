#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(1200, 900), "texts");
    sf::Font font;
    font.loadFromFile("font.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("Hello world!");
    text.setCharacterSize(150);
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