#include "point.h"


Point::~Point()
{
}
double Point::distance(Point a)
{
    return std::sqrt( std::pow((a.x - x), 2) + std::pow((a.y - y),2) );
}
void Point::show()
{
    //std::cout.width(20);
    std::cout << "Name " << name << "\n";
    //std::cout.width(20);
    std::cout << "X " << x << "\n";
    //std::cout.width(20);
    std::cout << "Y " << y << "\n";
    //std::cout.width(20);
    std::cout << "Z " << z << "\n";
}
