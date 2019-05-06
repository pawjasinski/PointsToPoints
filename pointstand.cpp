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
    for(uint i = 0; i < positions.size(); ++i)
    {
        uint index = 0;
        double min = distance( *positions[i], *points[0] );
        for(uint j = 0; j < points.size(); ++j)
        {
            if( min > distance( *positions[i], *points[j] ) ) index = j;
        }
        positions[i]->addPoint(points[index]);
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
        for(uint j = 0; j < pS[i]->sizeOfPoints(); ++j)
        {
            pS[i]->getPoint(j);
        }
    }
    file.close();
}
