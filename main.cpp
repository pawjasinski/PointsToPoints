#include "point.h"
#include "pointstand.h"

int main()
{
    std::fstream punkty;
    std::fstream osnowa;
    std::vector<Point*> Punkty;
    std::vector<PointStand*> Osnowa;
    Punkty = loadPoints(punkty, "Punkty.txt");
    Osnowa = loadPointsStand(osnowa, "Osnowa.txt");
    writeOut(Osnowa);
    freeMemory(Punkty);
    freeMemory(Osnowa);
    exit(0);
}
