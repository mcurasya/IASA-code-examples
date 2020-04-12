#include <SFML/Graphics.hpp>
#include "grid.hpp"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 900
int main(int argc, const char** argv) {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "game of life");
    grid gr(window, 25);
    window.setFramerateLimit(10);
    sf::Font font;
    sf::Text status;
    font.loadFromFile("FG.ttf");
    status.setFont(font);
    status.setString("pause");
    status.setCharacterSize(50);
    status.setFillColor(sf::Color::Green);
    status.move(20, 0);
    int simulate = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Enter or event.key.code == sf::Keyboard::Space){
                    simulate = !simulate;
                }
            }
            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    gr.handleclick(event.mouseButton.x, event.mouseButton.y);
                }
            }
        }

        if(simulate)
            gr.update();
        window.clear();
        window.draw(gr);
        if(!simulate)
            window.draw(status);
        window.display();
    }
    
    return 0;
}