#ifndef POINTSTAND_H
#define POINTSTAND_H
#include "point.h"

class PointStand : public Point
{
private:
    std::vector<Point*> points;
public:
    PointStand(std::string name = "_", double x = 0, double y = 0, double z = 0): Point(name, x, y, z) {} // inicjalizacja konstruktorem klasy bazowej
    ~PointStand();
    void addPoint(Point* p) { points.push_back(p); }
};

std::vector<PointStand*> loadPointsStand(std::fstream& file, const std::string fileName);
void assignPointsToPositions(const std::vector<Point*> points, const std::vector<PointStand*> positions);
#endif // POINTSTAND_H
