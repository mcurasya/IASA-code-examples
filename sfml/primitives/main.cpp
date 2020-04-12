#include <vector>
#include <SFML/Graphics.hpp>
#define SIZE 10;
int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(1200, 900), "primitives");
    sf::CircleShape circle(500.f);
    sf::RectangleShape rect(sf::Vector2f(500, 600));
    std::vector<sf::ConvexShape> shape = {circle, rect};
    int counter = 0;
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(event.type == sf::Event::KeyPressed){
                switch (event.key.code)
                {
                case sf::Keyboard::Left:
                    if (counter == 0)
                        counter = SIZE;
                    counter--;
                    break;
                case sf::Keyboard::Right:
                    counter = (counter + 1) % SIZE;
                    break;
                default:
                    break;
                }
            }
        }

        window.clear();
        window.display();
    }
    return 0;
}