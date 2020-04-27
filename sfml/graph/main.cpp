#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

#include "grid.hpp"




float func(float x)
{
    return 3-1/x;
}

std::vector<sf::Vertex> getPoints(float from, float to, float coeffitient_x, float coeffitient_y)
{
    std::vector<sf::Vertex> arr;
    for (float x = from; x < to - 2 * from; x += 0.01)
    {
        sf::Vertex point = sf::Vertex(sf::Vector2f(coeffitient_x * x, -func(x) * coeffitient_y));
        point.color = sf::Color::White;
        if (arr.size() and (point.position.y / coeffitient_y) / (arr[arr.size() - 1].position.y / coeffitient_y) < 0 and point.position.y > 10)
        {
            point.color = sf::Color::Transparent;
            arr[arr.size() - 1].color = sf::Color::Transparent;
        }
        arr.push_back(point);
    }
    return arr;
}

int main(int argc, const char **argv)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8.0;
    sf::RenderWindow window(sf::VideoMode(1500, 1500, sf::Style::Fullscreen), "function graph");
    window.setVerticalSyncEnabled(true);
    sf::Font font;
    font.loadFromFile("font.ttf");

    float moving_speed = 40;
    float zoom_coefficient = 1;
    int bounds = 100;
    int coefficient = 100;
    sf::grid gr(1, 1, coefficient, coefficient, bounds, bounds, 1);
    std::vector<sf::Vertex> values = getPoints(-bounds, bounds, coefficient, coefficient);

    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(1500, 1500));
    window.setView(view);
    while (window.isOpen())
    {
        int redraw_needed = 0;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                redraw_needed = 1;
                if (event.key.code == sf::Keyboard::H)
                {
                    view.move(-zoom_coefficient * moving_speed, 0);
                }
                if (event.key.code == sf::Keyboard::J)
                {
                    view.move(0, zoom_coefficient * moving_speed);
                }
                if (event.key.code == sf::Keyboard::K)
                {
                    view.move(0, -zoom_coefficient * moving_speed);
                }
                if (event.key.code == sf::Keyboard::L)
                {
                    view.move(zoom_coefficient * moving_speed, 0);
                }
                if (event.key.code == sf::Keyboard::X)
                {
                    view.zoom(1.1f);
                    zoom_coefficient *= 1.1;
                }
                if (event.key.code == sf::Keyboard::Z)
                {
                    view.zoom(0.9f);
                    zoom_coefficient *= 0.9;
                }
            }
        }
            window.clear();
            window.setView(view);
            window.draw(gr);
            window.draw(&values[0], values.size() / 2, sf::LineStrip);
            window.display();
    }

    return 0;
}