#include <SFML/Graphics.hpp>

class grid : public sf::Drawable
{
private:
    int cell_width;
    int rows; //number of rows
    int columns; //number of columns
    int** cells; //array of cells
public:
    grid(const sf::RenderWindow& window, int cell_width);
    ~grid(); //destructor
    void update(); //update function
    void handleclick(int x, int y); //cell state change function
    void clear(); //clear grid function
    void generateRandomGrid(); //random grid function
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; //redraw function
};
