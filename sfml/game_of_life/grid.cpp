#include "grid.hpp"

grid::~grid(){

}

void grid::clear(){
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            cells[i][j] = 0;
        }
        
    }
    
}

grid::grid(const sf::RenderWindow& window, int cell_width){
    this->cell_width = cell_width;
    sf::Vector2u sizes = window.getSize();
    columns = sizes.x / this->cell_width;
    rows = sizes.y / this->cell_width;
    cells = new int*[rows];
    for (size_t i = 0; i < rows; i++)
    {
        cells[i] = new int[columns];
    }
    clear();
   
}
void grid::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if(cells[i][j]){
                //sf::RectangleShape cell(sf::Vector2f(cell_width, cell_width));
                sf::CircleShape cell(cell_width/2);
                cell.setFillColor(sf::Color::White);
                cell.setOutlineThickness(-2);
                cell.setOutlineColor(sf::Color::Black);
                cell.setPosition(cell_width * j, cell_width * i);
                target.draw(cell);
            }
        }
        
    }
    
}

void grid::update(){
    int count[rows][columns];
    for (size_t i = 1; i < rows-1; i++)
    {
        for (size_t j = 1; j < columns-1; j++)
        {
            count[i][j] = 0;
            count[i][j]+= cells[i-1][j-1];
            count[i][j]+= cells[i][j-1];
            count[i][j]+= cells[i+1][j-1];
            count[i][j]+= cells[i-1][j];
            count[i][j]+= cells[i+1][j];
            count[i][j]+= cells[i-1][j+1];
            count[i][j]+= cells[i][j+1];
            count[i][j]+= cells[i+1][j+1];
        }
    }
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if(count[i][j] <= 1){
                cells[i][j] = 0;
            }
            if(count[i][j] == 3){
                cells[i][j] = 1;
            }
            if(count[i][j] >= 4){
                cells[i][j] = 0;
            }
        }
    }
}

void grid::handleclick(int x, int y){
    x = x - x%cell_width;
    y = y - y%cell_width;
    x/=cell_width;
    y/=cell_width;
    cells[y][x] = !cells[y][x];
}

void grid::generateRandomGrid(){
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            cells[i][j] = rand() % 2;
        }
        
    }
    
}