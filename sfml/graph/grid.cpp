#include "grid.hpp"
#include <string>
sf::grid::grid(float step_x, float step_y, float x_coefficient, float y_coefficient, float bounds_x, float bounds_y, int numbers_after_comma)
{
    this->numbers_after_comma = numbers_after_comma + 1;
    offset_x = offset_y = 2;
    this->step_x = step_x;
    this->step_y = step_y;
    coeffitient_x = x_coefficient;
    coeffitient_y = y_coefficient;
    this->bounds_x = bounds_x;
    this->bounds_y = bounds_y;
    this->lines = this->init(); //create lines
    this->font = Font();        //add font for grid point markers
    font.loadFromFile("font.ttf");
}
void sf::grid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(&lines[0], lines.size(), Lines); //draw lines
    sf::Text pozn;                               //variable for text markers
    pozn.setFont(font);
    pozn.setCharacterSize(25);
    pozn.setPosition(offset_x, offset_y);
    pozn.setString(std::to_string(0));
    target.draw(pozn); // draw zero point
    //=============== draw point markers on x axis =============
    for (float i = step_x; i <= bounds_x; i += step_x)
    {
        //positive markers
        pozn.setPosition(i * coeffitient_x + offset_x, offset_y);
        std::string num = std::to_string(i);
        pozn.setString(num.substr(0, num.find('.') + numbers_after_comma));
        target.draw(pozn);
        //negative markers
        pozn.setPosition(-i * coeffitient_x + offset_x, offset_y);
        num = std::to_string(-i);
        pozn.setString(num.substr(0, num.find('.') + numbers_after_comma));
        target.draw(pozn);
    }
    //====================================================
    //============== draw point markers on x axis ===============
    for (float i = step_y; i <= bounds_y; i += step_y)
    {
        //negative markers
        pozn.setPosition(offset_x, coeffitient_y * i + offset_y);
        std::string num = std::to_string(-i);
        pozn.setString(num.substr(0, num.find('.') + numbers_after_comma));
        target.draw(pozn);
        //positive markers
        pozn.setPosition(offset_x, -coeffitient_y * i + offset_y);
        num = std::to_string(i);
        pozn.setString(num.substr(0, num.find('.') + numbers_after_comma));
        target.draw(pozn);
    }
}

std::vector<sf::Vertex> sf::grid::init()
{
    std::vector<sf::Vertex> line; //vector of points
    for (float i = 0; i < bounds_x; i += this->step_x) //veritcal lines
    {
        //top point of right half
        Vertex top = Vector2f(i * coeffitient_x, -bounds_y * coeffitient_y);
        top.color = Color::Green;
        if (i == 0)
        {
            top.color = Color::White;
        }
        line.push_back(top);
        //bottom point of right half
        Vertex bottom = Vector2f(i * coeffitient_x, bounds_y * coeffitient_y);
        bottom.color = Color::Red;
        if (i == 0)
        {
            bottom.color = Color::White;
        }
        line.push_back(bottom);
        //top point of left half
        top = Vector2f(-i * coeffitient_x, -bounds_y * coeffitient_y);
        top.color = Color::Green;
        if (i == 0)
        {
            top.color = Color::White;
        }
        line.push_back(top);
        //bottom point of left half
        bottom = Vector2f(-i * coeffitient_x, bounds_y * coeffitient_y);
        bottom.color = Color::Red;
        if (i == 0)
        {
            bottom.color = Color::White;
        }
        line.push_back(bottom);
    }
    for (float i = 0; i < bounds_y; i += this->step_y) //horisontal lines
    {
        //same stuff going on
        Vertex left = Vector2f(-bounds_x * coeffitient_x, i * coeffitient_y);
        left.color = Color::Red;
        if (i == 0)
        {
            left.color = Color::White;
        }
        line.push_back(left);
        Vertex right = Vector2f(bounds_x * coeffitient_x, i * coeffitient_y);
        right.color = Color::Blue;
        if (i == 0)
        {
            right.color = Color::White;
        }
        line.push_back(right);
        left = Vector2f(-bounds_x * coeffitient_x, -i * coeffitient_y);
        left.color = Color::Red;
        if (i == 0)
        {
            left.color = Color::White;
        }
        line.push_back(left);
        right = Vector2f(bounds_x * coeffitient_x, -i * coeffitient_y);
        right.color = Color::Blue;
        if (i == 0)
        {
            right.color = Color::White;
        }
        line.push_back(right);
    }

    return line; //return array
}

sf::grid::~grid()
{
}