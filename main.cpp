#include "point.h"
#include <vector>
#include <sstream>

std::vector<Point*> loadPoints(std::fstream& plik);

int main()
{
    std::fstream punkty;
    std::fstream osnowa;
    punkty.open("Punkty.txt", std::ios::in);
    osnowa.open("Osnowa.txt", std::ios::in);
    if(! punkty.is_open())
    {
        std::cout<<"Can't open File with Points\n";
        exit(1);
    }
    else if(! osnowa.is_open())
    {
        std::cout<<"Can't open File with Ossowa\n";
        exit(1);
    }
    std::vector<Point*> Punkty;
    std::vector<Point*> Osnowa;
    Punkty = loadPoints(punkty);
    Osnowa = loadPoints(osnowa);
}

std::vector<Point*> loadPoints(std::fstream& plik)
{
    std::vector<Point*> tab;
    for(uint i = 0; ! plik.eof(); ++i)
    {
        std:: string temp;
        std::getline(plik, temp);
        if(temp.empty()) break; // break loop if find an empty line
        std:: stringstream ss{temp};
        tab.push_back(new Point);
        if ( ! (ss >> *tab[i] ))
        {
            std::cout << "Error in line " << i + 1<< "\n";
            std::cin.get();
            exit(1);
        }
        tab[i]->show();
    }
    return tab;
}
