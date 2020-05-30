#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, char const *argv[])
{
    RenderWindow window(sf::VideoMode(1200, 900), "window");
    RectangleShape rect(Vector2f(250, 200));
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
        window.draw(rect);
        window.display();
    }
    return 0;
}
