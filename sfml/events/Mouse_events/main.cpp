#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, char const *argv[])
{
    RenderWindow window(VideoMode(1200, 900), "keyboard events example"); //create window
    CircleShape circle(250);
    circle.setFillColor(Color::Red);
    circle.setOutlineColor(Color::Cyan);
    circle.setOutlineThickness(-25);
    FloatRect rect = circle.getLocalBounds();
    circle.setOrigin(rect.width / 2, rect.height / 2);
    bool show = false; //do not display first, display after first click
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) 
            {
                show = true;
                circle.setPosition(event.mouseButton.x, event.mouseButton.y);
            }
            
        }
        window.clear();
        if (show)
            window.draw(circle);
        window.display();
    }
    return 0;
}
