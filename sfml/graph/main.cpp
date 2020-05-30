#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

#include "grid.hpp"

float func(float x) //function that is needed to be drawn
{
    return 3 - 1 / x;
}
//creates points that will be plotted on our graph
sf::VertexArray getPoints(float from, float to, float coeffitient_x, float coeffitient_y)
{
    sf::VertexArray arr(sf::LineStrip); //array of points
    for (float x = from; x < to - 2 * from; x += 0.01)
    {
        sf::Vertex point = sf::Vertex(sf::Vector2f(coeffitient_x * x, -func(x) * coeffitient_y));
        point.color = sf::Color::White;
        //check if an asymtote
        if (arr.getVertexCount() and (point.position.y / coeffitient_y) / (arr[arr.getVertexCount() - 1].position.y / coeffitient_y) < 0 and point.position.y > 10)
        {
            //make them transparent
            point.color = sf::Color::Transparent;
            arr[arr.getVertexCount() - 1].color = sf::Color::Transparent;
        }
        //add point to an array
        arr.append(point);
    }
    return arr;
}

int main(int argc, const char **argv)
{
    //create window and add antialiasing
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8.0;
    sf::RenderWindow window(sf::VideoMode(1500, 1500, sf::Style::Fullscreen), "function graph");
    window.setVerticalSyncEnabled(true);
    sf::Font font;
    font.loadFromFile("font.ttf");
    //some of needed constants
    float moving_speed = 40;
    float zoom_coefficient = 1;
    int bounds = 100;
    int coefficient = 100;
    sf::grid gr(1, 1, coefficient, coefficient, bounds, bounds, 1);
    sf::VertexArray values = getPoints(-bounds, bounds, coefficient, coefficient);

    sf::View view(sf::Vector2f(0, 0), sf::Vector2f(1500, 1500)); //view that will be moved
    window.setView(view);
    while (window.isOpen()) //main cycle
    {
        sf::Event event; // check for events
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) //key pressed events
            {
                //==========  move  =======================
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
                //=========================================
                //============  zoom  =====================
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
                //=========================================
            }
        }
        //============== redraw ===================
        window.clear();
        window.setView(view);
        window.draw(gr);
        window.draw(values);
        window.display();
         //=========================================
    }

    return 0;
}