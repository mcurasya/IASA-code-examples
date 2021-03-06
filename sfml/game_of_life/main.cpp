#include <SFML/Graphics.hpp>
#include <string>
#include <ctime>
#include "grid.hpp"
#define WINDOW_WIDTH 2400
#define WINDOW_HEIGHT 1800
int main(int argc, const char **argv)
{
    srand(std::time(NULL));
    //create window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "game of life");
    grid gr(window, 25);     //create grid
    int framerateLimit = 10; //technically the speed of update
    window.setFramerateLimit(framerateLimit);
    sf::Font font;
    sf::Text status; //status marker
    font.loadFromFile("FG.ttf");
    status.setFont(font);
    status.setString("pause");
    status.setCharacterSize(50);
    status.setFillColor(sf::Color::Green);
    status.move(20, 10);
    sf::Text fps; //update speed marker
    fps.setFont(font);
    fps.setString("fps: " + std::to_string(framerateLimit));
    fps.setCharacterSize(50);
    fps.setFillColor(sf::Color::Magenta);
    fps.setOrigin(fps.getLocalBounds().width, 0);
    fps.setPosition(window.getSize().x - 50, 10);
    int simulate = 0; //simulation status
    while (window.isOpen())
    {
        sf::Event event; //check for events
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Enter or event.key.code == sf::Keyboard::Space)
                {
                    simulate = !simulate; //change simulation status
                }
                if (event.key.code == sf::Keyboard::Tab)
                {
                    gr.clear(); //clear screen
                }
                if (event.key.code == sf::Keyboard::R)
                {
                    gr.generateRandomGrid(); //random grid generator
                }
                if (event.key.code == sf::Keyboard::Up) //change update speed
                {
                    if (framerateLimit < 120)
                        framerateLimit += 2;
                    fps.setString("fps: " + std::to_string(framerateLimit));
                    window.setFramerateLimit(framerateLimit);
                }
                if (event.key.code == sf::Keyboard::Down)
                {
                    if (framerateLimit > 2)
                        framerateLimit -= 2;
                    fps.setString("fps: " + std::to_string(framerateLimit));
                    window.setFramerateLimit(framerateLimit);
                }
            }
            if (event.type == sf::Event::MouseButtonPressed) //change pressed cell state
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    gr.handleclick(event.mouseButton.x, event.mouseButton.y);
                }
            }
            if (event.type == sf::Event::Resized)
            {
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                fps.setPosition(window.getSize().x - 50, 10);
            }
        }

        if (simulate)
            gr.update(); //update if sumulation
        //redraw
        window.clear(sf::Color::Black);
        window.draw(gr);
        window.draw(fps);
        if (!simulate)
            window.draw(status);
        window.display();
    }

    return 0;
}