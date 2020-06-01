#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, char const *argv[])
{
    RenderWindow window(VideoMode(1200, 900), "I");
    VertexArray arr(LinesStrip);
    arr.append(Vertex(Vector2f(200, 100), Color::Red));
    arr.append(Vertex(Vector2f(600, 100), Color::Magenta));
    arr.append(Vertex(Vector2f(600, 300), Color::Green));
    arr.append(Vertex(Vector2f(500, 300), Color::Yellow));
    arr.append(Vertex(Vector2f(500, 600), Color::Magenta));
    arr.append(Vertex(Vector2f(600, 600), Color::Red));
    arr.append(Vertex(Vector2f(600, 800), Color::Yellow));
    arr.append(Vertex(Vector2f(200, 800), Color::Green));
    arr.append(Vertex(Vector2f(200, 600), Color::Magenta));
    arr.append(Vertex(Vector2f(300, 600), Color::Green));
    arr.append(Vertex(Vector2f(300, 300), Color::Yellow));
    arr.append(Vertex(Vector2f(200, 300), Color::Red));
    arr.append(Vertex(Vector2f(200, 100), Color::Magenta));
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
        window.draw(arr);
        window.display();
    }
    return 0;
}