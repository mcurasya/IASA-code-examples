#include <SFML/Graphics.hpp>
#include <iostream>



int main(int argc, char const *argv[])
{
    std::cout << "please enter number of points you want->";
    int point_count;
    std::cin >> point_count;
    //initialise
    sf::RenderWindow window(sf::VideoMode(1200, 900), "window");
    sf::CircleShape circle(250, point_count);
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
        window.draw(circle);
        window.display();
    }
    return 0;
}
