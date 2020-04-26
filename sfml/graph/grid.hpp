#include <SFML/Graphics.hpp>
#include <vector>
namespace sf
{
class grid
{
private:
    sf::Font font;
    float step_x;
    float step_y;
    float coeffitient_x;
    float coeffitient_y;
    float offset_x;
    float offset_y;
    float bounds_x;
    float bounds_y;
    int numbers_after_comma;
    std::vector<sf::Vertex> lines;
    std::vector<sf::Vertex> init();

public:
    grid(float step_x=1, float step_y=1, float x_coefficient=100, float y_coefficient=100, float bounds_x=50, float bounds_y=50, int numbers_after_comma=2);
    ~grid();
    void draw(sf::RenderWindow &window);
};
} // namespace sf