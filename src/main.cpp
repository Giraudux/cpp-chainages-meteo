#include "main.h"

/// Alexis Giraudet

bool lire(char *filename, Chainage &chainage)
{
    std::ifstream ifs(filename, std::ifstream::in);
    if(ifs)
    {
        char line[32];
        while(ifs.getline(line,32))
        {
            std::istringstream iss(line);
            ReleveMeteo releveMeteo = creerReleveMeteo();
            iss >> releveMeteo.station;
            iss >> releveMeteo.date.annee;
            iss >> releveMeteo.date.jour;
            iss >> releveMeteo.date.heure;
            iss >> releveMeteo.temperature;
            insererQueue(chainage, releveMeteo);
        }
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        return 1;
    }
    Chainage c = creerChainage();
    lire(argv[1],c);
    afficherChainage(c,std::cout);
    return 0;
}
