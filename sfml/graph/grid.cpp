#include "grid.hpp"
#include <string>
sf::grid::grid(float step_x, float step_y, float x_coefficient, float y_coefficient, float bounds_x, float bounds_y, int numbers_after_comma)
{
    this->numbers_after_comma = numbers_after_comma+1;
    offset_x = offset_y = 2;
    this->step_x = step_x;
    this->step_y = step_y;
    coeffitient_x = x_coefficient;
    coeffitient_y = y_coefficient;
    this->bounds_x = bounds_x;
    this->bounds_y = bounds_y;
    this->lines = this->init();
    this->font = Font();
    font.loadFromFile("font.ttf");
}
void sf::grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(&lines[0], lines.size(), Lines);
    sf::Text pozn;
    pozn.setFont(font);
    pozn.setCharacterSize(25);
    pozn.setPosition(offset_x, offset_y);;
    pozn.setString(std::to_string(0));
    target.draw(pozn);
    for (float i = step_x; i <= bounds_x; i += step_x)
    {
        pozn.setPosition(i * coeffitient_x + offset_x, offset_y);
        std::string num = std::to_string(i);
        pozn.setString(num.substr(0, num.find('.') + numbers_after_comma));
        target.draw(pozn);
        pozn.setPosition(-i * coeffitient_x + offset_x, offset_y);
        num = std::to_string(-i);
        pozn.setString(num.substr(0, num.find('.') + numbers_after_comma));
        target.draw(pozn);
    }
    for (float i = step_y; i <= bounds_y; i += step_y)
    {
        pozn.setPosition(offset_x, coeffitient_y * i + offset_y);
        std::string num = std::to_string(-i);
        pozn.setString(num.substr(0, num.find('.') + numbers_after_comma));
        target.draw(pozn);
        pozn.setPosition(offset_x, -coeffitient_y * i + offset_y);
        num = std::to_string(i);
        pozn.setString(num.substr(0, num.find('.') + numbers_after_comma));
        target.draw(pozn);
    }
}

std::vector<sf::Vertex> sf::grid::init()
{
    std::vector<sf::Vertex> line;
    for (float i = 0; i < bounds_x; i += this->step_x)
    {
        Vertex top = Vector2f(i * coeffitient_x, -bounds_y * coeffitient_y);

        top.color = Color::Green;
        if (i == 0)
        {
            top.color = Color::White;
        }
        line.push_back(top);
        Vertex bottom = Vector2f(i * coeffitient_x, bounds_y * coeffitient_y);
        bottom.color = Color::Red;
        if (i == 0)
        {
            bottom.color = Color::White;
        }
        line.push_back(bottom);
        top = Vector2f(-i * coeffitient_x, -bounds_y * coeffitient_y);

        top.color = Color::Green;
        if (i == 0)
        {
            top.color = Color::White;
        }
        line.push_back(top);
        bottom = Vector2f(-i * coeffitient_x, bounds_y * coeffitient_y);
        bottom.color = Color::Red;
        if (i == 0)
        {
            bottom.color = Color::White;
        }
        line.push_back(bottom);
    }
    for (float i = 0; i < bounds_y; i += this->step_y)
    {
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

    return line;
}

sf::grid::~grid()
{
}