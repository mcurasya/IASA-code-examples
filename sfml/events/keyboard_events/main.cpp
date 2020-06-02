#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

int main(int argc, char const *argv[])
{
    RenderWindow window(VideoMode(1200, 900), "keyboard events example"); //create window
    Text text;
    Font font;
    font.loadFromFile("font.ttf");
    text.setFont(font);
    text.setCharacterSize(32);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::TextEntered) //if any text key is pressed
            {
                String str(event.text.unicode); //get character from unicode
                text.setString(str + " key is pressed"); //concatenate and set string
            }
            else
            {
                text.setString("nothing is pressed");
            }
        }
        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}