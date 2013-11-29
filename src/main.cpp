#include <iostream>

#include "Chainage.h"
#include "DateMeteo.h"
#include "ReleveMeteo.h"

/// Alexis Giraudet

int main(int argc, char *argv[])
{
    DateMeteo dm = creerDateMeteo();
    afficherDateMeteo(dm,std::cout);
    std::cout << std::endl;
    ReleveMeteo rm = creerReleveMeteo();
    afficherReleveMeteo(rm,std::cout);
    std::cout << std::endl;
    return 0;
}
