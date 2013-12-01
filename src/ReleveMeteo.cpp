#include "ReleveMeteo.h"

/// Alexis Giraudet

ReleveMeteo creerReleveMeteo()
{
    ReleveMeteo releveMeteo;
    initialiserReleveMeteo(releveMeteo);
    return releveMeteo;
}

void initialiserReleveMeteo(ReleveMeteo &releveMeteo)
{
    releveMeteo.station = 0;
    releveMeteo.date = creerDateMeteo();
    releveMeteo.temperature = 0;
}

int compReleveMeteo1(const ReleveMeteo &rm1, const ReleveMeteo &rm2)
{
    if((rm1.station == rm2.station) && (comparerDateMeteo(rm1.date,rm2.date) == 0) && (rm1.temperature == rm2.temperature))
    {
        return 0;
    }
    else if((rm1.temperature < rm2.temperature) || ((rm1.temperature == rm2.temperature) && ((comparerDateMeteo(rm1.date,rm2.date) > 0) || ((comparerDateMeteo(rm1.date,rm2.date) == 0) && (rm1.station < rm2.station)))))
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void afficherReleveMeteo(const ReleveMeteo &releveMeteo, std::ostream &sortie)
{
    sortie << releveMeteo.station << " ";
    afficherDateMeteo(releveMeteo.date,sortie);
    sortie << " " << releveMeteo.temperature;
}
