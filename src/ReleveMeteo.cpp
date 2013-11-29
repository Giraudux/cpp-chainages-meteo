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

void afficherReleveMeteo(const ReleveMeteo &releveMeteo, std::ostream &sortie)
{
    sortie << releveMeteo.station << " ";
    afficherDateMeteo(releveMeteo.date,sortie);
    sortie << " " << releveMeteo.temperature;
}
