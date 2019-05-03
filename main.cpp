#include "point.h"
#include <vector>

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
    /*else if(! osnowa.is_open())
    {
        std::cout<<"Can't open File with Ossowa\n";
        exit(1);
    }*/
    std::vector<Point*> test;
    test = loadPoints(punkty);
    for(uint i = 0; i < test.size(); ++i) std::cout<<test[i];
    int ddd = std::cin.get();
    std::cout<<ddd;
}

std::vector<Point*> loadPoints(std::fstream& plik)
{
    std::vector<Point*> tab;
    for(uint i = 0; ! plik.eof(); ++i)
    {
        tab.push_back(new Point);
        plik>>*tab[i];
    }
    return tab;
}
