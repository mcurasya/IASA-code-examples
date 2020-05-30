#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
    //initialise
    sf::RenderWindow window(sf::VideoMode(1200, 900), "window");
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
        }
        //update
        //redraw
        window.clear();
        window.display();
    }

    return 0;
}
