#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, char const *argv[])
{
    RenderWindow window(sf::VideoMode(1200, 900), "window");
    ConvexShape poly(5);
    poly.setPoint(0, Vector2f(200, 100));
    poly.setPoint(1, Vector2f(600, 100));
    poly.setPoint(2, Vector2f(600, 300));
    poly.setPoint(3, Vector2f(500, 600));
    poly.setPoint(4, Vector2f(300, 500));
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
        window.draw(poly);
        window.display();
    }
    return 0;
}
