#include "pointstand.h"

PointStand::~PointStand()
{
}

std::vector<PointStand*> loadPointsStand(std::fstream& file, const std::string fileName)
{
    file.open(fileName, std::ios::in);
    if(! file.good())
    {
        std::cout<<"Can't open the file\n";
        std::cin.get();
        exit(1);
    }
    std::vector<PointStand*> PointsArray;
    std:: string tempLine;
    for(uint i = 0; ! file.eof(); ++i)
    {
        std::getline(file, tempLine);
        if(tempLine.empty()) break; // break loop if find an empty line
        std:: stringstream ss{tempLine};
        PointsArray.push_back(new PointStand);
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

void assignPointsToPositions(const std::vector<Point*> points, const std::vector<PointStand*> positions)
{
    for(uint i = 0; i < points.size(); ++i)
    {
        uint index = 0;
        double min = distance( *points[i], *dynamic_cast<Point*>( positions[0]) );
        for(uint j = 0; j < positions.size(); ++j)
        {
            if (min > distance( *points[i], *dynamic_cast<Point*>( positions[j] )))
            {
                min = distance( *points[i], *dynamic_cast<Point*>( positions[j]) );
                index = j;
            }
        }
        positions[index]->addPoint(points[i]);
    }
}

void freeMemory(std::vector<PointStand*> free)
{
    for(uint i = 0; i < free.size(); ++i)
    {
        delete free[i];
    }
}
void writeOut(std::vector<PointStand*> pS)
{
    std::fstream file;
    file.open("export.txt", std::ios::out);
    file << "Name\tx\ty\tz\r\n";
    for(uint i = 0; i < pS.size(); ++i)
    {
        file << pS[i];
        file << "Punkty:\n";
        for(uint j = 0; j < pS[i]->sizeOfPoints(); ++j)
        {
            file << pS[i]->getPoint(j);
        }
    }
    file.close();
}
