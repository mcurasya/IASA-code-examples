#ifndef __GRID__
#define __GRID__
#include <SFML/Graphics.hpp>
#include <vector>
namespace sf
{
    class grid : public sf::Drawable
    {
    private:
        sf::Font font;
        float step_x;            //x step of grid
        float step_y;            //y step of grid
        float coeffitient_x;     //makes graph bigger in x axis
        float coeffitient_y;     //makes graph bigger in y axis
        float offset_x;          //arbitrary constant for graph point markers
        float offset_y;          //arbitrary constant for graph point markers
        float bounds_x;          //bounds of graph in x axis
        float bounds_y;          //bounds of graph in x axis
        int numbers_after_comma; //numbers afer comma for point markers
        sf::VertexArray lines;   //array of vertices that create grid lines

    public:
        grid(float step_x = 1, float step_y = 1, float x_coefficient = 100, float y_coefficient = 100, float bounds_x = 50, float bounds_y = 50, int numbers_after_comma = 2);
        ~grid();

    private:
        sf::VertexArray init();                                                     // function for creating these points
        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const; //draw func
    };
} // namespace sf

#endif