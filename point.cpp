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
std::vector<Point*> loadPoints(std::fstream& file, const std::string fileName)
{
    file.open(fileName, std::ios::in);
    if(! file.good())
    {
        std::cout<<"Can't open the file\n";
        std::cin.get();
        exit(1);
    }
    std::vector<Point*> PointsArray;
    std:: string tempLine;
    for(uint i = 0; ! file.eof(); ++i)
    {
        std::getline(file, tempLine);
        if(tempLine.empty()) break; // break loop if find an empty line
        std:: stringstream ss{tempLine};
        PointsArray.push_back(new Point);
        if ( ! (ss >> *PointsArray[i] ))
        {
            std::cout << "Error in line " << i + 1<< "\n";
            std::cin.get();
            exit(1);
        }
    }
    file.close();
    return PointsArray;
}
void freeMemory(std::vector<Point*> free)
{
    for(uint i = 0; i < free.size(); ++i)
    {
        delete free[i];
    }
}
