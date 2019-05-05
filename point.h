#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include <sstream>

class Point
{
private:
    std:: string name;
    double x, y, z;
public:
    //Point():name("_"), x(0), y(0), z(0) {}
    Point(std::string name = "_", double x = 0, double y = 0, double z = 0): name(name), x(x), y(y), z(z) {}
    virtual ~Point();
    friend double distance(Point a, Point b) { return std::sqrt( std::pow((a.x - b.x), 2) + std::pow((a.y - b.y),2) ); }
    double distance(Point a);
    void show();
    friend std::ostream& operator<<(std::ostream& os, const Point* p)
    {
        os.width(20);
        os << "Name " << p->name << "\n";
        os.width(20);
        os << "X " << p->x << "\n";
        os.width(20);
        os << "Y " << p->y << "\n";
        os.width(20);
        os << "Z " << p->z << "\n";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Point& p)
    {
        is >> p.name;
        is >> p.x;
        is >> p.y;
        is >> p.z;
        return is;
    }
};

std::vector<Point*> loadPoints(std::fstream& file, const std::string fileName);
#endif // POINT_H
