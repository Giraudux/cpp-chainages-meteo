#include "main.h"

/// Alexis Giraudet

bool lectureReleve(char *filename, Chainage &chainage)
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
    lectureReleve(argv[1],c);
    //afficherChainage(c,std::cout);
    try
    {
        ReleveMeteo rm = creerReleveMeteo();
        rm = plusPetitElement(c,compReleveMeteo1);
        afficherReleveMeteo(rm,std::cout);
        std::cout << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "chainage vide" << std::endl;
    }
    reinitialiser(c);
    return 0;
}
