#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, char const *argv[])
{
    RenderWindow window(VideoMode(1200, 900), "views example");
    View v(Vector2f(0, 0), Vector2f(1200, 1200));
    window.setView(v);
    RectangleShape r[] = {RectangleShape(Vector2f(200, 200)),
                          RectangleShape(Vector2f(200, 200)),
                          RectangleShape(Vector2f(200, 200)),
                          RectangleShape(Vector2f(200, 200))};
    for (size_t i = 0; i < 4; i++)
    {
        r[i].setOrigin(100, 100);
    }
    r[0].setPosition(-200, 200);
    r[1].setPosition(200, 200);
    r[2].setPosition(200, -200);
    r[3].setPosition(-200, -200);
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
        v.rotate(0.1);
        window.setView(v);
        //redraw
        
        window.clear();
        for (size_t i = 0; i < 4; i++)
        {
            window.draw(r[i]);
        }
        window.display();
    }

    return 0;
}
