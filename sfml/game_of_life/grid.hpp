#include <SFML/Graphics.hpp>

class grid : public sf::Drawable
{
private:
    int cell_width;
    int rows;
    int columns;
    int** cells;
public:
    grid(const sf::RenderWindow& window, int cell_width);
    ~grid();
    void update();
    void handleclick(int x, int y);
    void clear();
    void generateRandomGrid();
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; 
};
