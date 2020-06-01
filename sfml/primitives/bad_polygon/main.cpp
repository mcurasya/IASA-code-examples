#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, char const *argv[])
{
    RenderWindow window(sf::VideoMode(1200, 900), "window");
    ConvexShape poly(12);
    poly.setPoint(0, Vector2f(200, 100));
    poly.setPoint(1, Vector2f(600, 100));
    poly.setPoint(2, Vector2f(600, 300));
    poly.setPoint(3, Vector2f(500, 300));
    poly.setPoint(4, Vector2f(500, 600));
    poly.setPoint(5, Vector2f(600, 600));
    poly.setPoint(6, Vector2f(600, 800));
    poly.setPoint(7, Vector2f(200, 800));
    poly.setPoint(8, Vector2f(200, 600));
    poly.setPoint(9, Vector2f(300, 600));
    poly.setPoint(10, Vector2f(300, 300));
    poly.setPoint(11, Vector2f(200, 300));
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
