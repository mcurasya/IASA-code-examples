#include "grid.hpp"

grid::~grid()
{ //free some memory
    for (size_t i = 0; i < rows; i++)
    {
        delete[] cells[i];
    }
    delete[] cells;
}

void grid::clear()
{ //set all cells to "dead" state
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            cells[i][j] = 0;
        }
    }
}

grid::grid(const sf::RenderWindow &window, int cell_width)
{
    this->cell_width = cell_width;
    sf::Vector2u sizes = window.getSize();
    columns = sizes.x / this->cell_width; //compute column number of materix
    rows = sizes.y / this->cell_width;    //compute row number of matrix
    cells = new int *[rows];              //create array of array pointers
    for (size_t i = 0; i < rows; i++)
    {
        cells[i] = new int[columns]; //create arrays in there
    }
    clear(); //clear out all trash that was before in memory
}
void grid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (cells[i][j])
            {
                //sf::RectangleShape cell(sf::Vector2f(cell_width, cell_width));
                sf::CircleShape cell(cell_width / 2); //create cell
                cell.setFillColor(sf::Color::White);
                cell.setOutlineThickness(-2);
                cell.setOutlineColor(sf::Color::Black);
                cell.setPosition(cell_width * j, cell_width * i); //change positions of i and j for correct show
                target.draw(cell);
            }
        }
    }
}

void grid::update()
{
    int count[rows][columns]; //array for counting all alive neighbours for every cell
    for (size_t i = 1; i < rows - 1; i++) //count number of alive neighbours for cells
    {
        for (size_t j = 1; j < columns - 1; j++) 
        {
            count[i][j] = 0;
            count[i][j] += cells[i - 1][j - 1];
            count[i][j] += cells[i][j - 1];
            count[i][j] += cells[i + 1][j - 1];
            count[i][j] += cells[i - 1][j];
            count[i][j] += cells[i + 1][j];
            count[i][j] += cells[i - 1][j + 1];
            count[i][j] += cells[i][j + 1];
            count[i][j] += cells[i + 1][j + 1];
        }
    }
    for (size_t i = 0; i < rows; i++) //update states of cells
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (count[i][j] <= 1)
            {
                cells[i][j] = 0;
            }
            if (count[i][j] == 3)
            {
                cells[i][j] = 1;
            }
            if (count[i][j] >= 4)
            {
                cells[i][j] = 0;
            }
        }
    }
}

void grid::handleclick(int x, int y)
{
    x = x - x % cell_width;
    y = y - y % cell_width;
    x /= cell_width;
    y /= cell_width; //find a cell that was clicked
    cells[y][x] = !cells[y][x]; //change it`s state
}

void grid::generateRandomGrid()
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            cells[i][j] = rand() % 2;//set one of 2 states for every cell
        }
    }
}