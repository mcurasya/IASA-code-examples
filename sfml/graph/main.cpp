#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

#include "grid.hpp"

using namespace sf;
using namespace std;

float func(float x)
{
    return 3-1/x;
}

vector<Vertex> getPoints(float from, float to, float coeffitient_x, float coeffitient_y)
{
    vector<Vertex> arr;
    for (float x = from; x < to - 2 * from; x += 0.01)
    {
        Vertex point = Vertex(Vector2f(coeffitient_x * x, -func(x) * coeffitient_y));
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
    ContextSettings settings;
    settings.antialiasingLevel = 8.0;
    RenderWindow window(VideoMode(1500, 1500, Style::Fullscreen), "function graph");
    window.setVerticalSyncEnabled(true);
    Font font;
    font.loadFromFile("font.ttf");

    float moving_speed = 40;
    float zoom_coefficient = 1;
    int bounds = 100;
    int coefficient = 100;
    sf::grid gr(1, 1, coefficient, coefficient, bounds, bounds, 1);
    vector<Vertex> values = getPoints(-bounds, bounds, coefficient, coefficient);

    View view(Vector2f(0, 0), Vector2f(1500, 1500));
    window.setView(view);
    window.clear();
    gr.draw(window);
    window.draw(&values[0], values.size() / 2, LineStrip);
    window.setView(view);
    window.display();
    while (window.isOpen())
    {
        int redraw_needed = 0;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::KeyPressed)
            {
                redraw_needed = 1;
                if (event.key.code == Keyboard::H)
                {
                    view.move(-zoom_coefficient * moving_speed, 0);
                }
                if (event.key.code == Keyboard::J)
                {
                    view.move(0, zoom_coefficient * moving_speed);
                }
                if (event.key.code == Keyboard::K)
                {
                    view.move(0, -zoom_coefficient * moving_speed);
                }
                if (event.key.code == Keyboard::L)
                {
                    view.move(zoom_coefficient * moving_speed, 0);
                }
                if (event.key.code == Keyboard::X)
                {
                    view.zoom(1.1f);
                    zoom_coefficient *= 1.1;
                }
                if (event.key.code == Keyboard::Z)
                {
                    view.zoom(0.9f);
                    zoom_coefficient *= 0.9;
                }
            }
        }
            window.clear();
            window.setView(view);
            gr.draw(window);
            window.draw(&values[0], values.size() / 2, LineStrip);
            window.display();
    }

    return 0;
}