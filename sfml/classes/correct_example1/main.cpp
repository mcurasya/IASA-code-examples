#include <iostream>
#include "Vector.hpp"

int main(int argc, char const *argv[])
{
    float x, y;
    std::cout << "enter first vector\n";
    std::cout << "x->";
    std::cin >> x;
    std::cout << "y->";
    std::cin >> y;
    Vector v1(x, y);
    std::cout << "enter second vector\n";
    std::cout << "x->";
    std::cin >> x;
    std::cout << "y->";
    std::cin >> y;
    //different vectors are different instances, not connected to each other
    Vector v2(x, y); // different vectors have different components, but we used the same values x, y
    v1.add(v2);      //add a second vector to first one
    std::cout << "new vector x=" << v1.x << " y=" << v1.y << std::endl;
    std::cout << "enter scalar->";
    float scalar;
    std::cin >> scalar;
    v1.scale(scalar); //scale first vector
    std::cout << "new vector x=" << v1.x << " y=" << v1.y << std::endl;
    return 0;
}
