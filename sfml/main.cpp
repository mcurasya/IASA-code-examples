#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;

int main(int argc, const char** argv) {
    RenderWindow window(VideoMode(800, 600), "function graph");
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.display();
        
    }
    
    return 0;
}