#include "DateMeteo.h"

/// Alexis Giraudet

DateMeteo creerDateMeteo()
{
    DateMeteo dateMeteo;
    initialiserDateMeteo(dateMeteo);
    return dateMeteo;
}

void initialiserDateMeteo(DateMeteo &dateMeteo)
{
    dateMeteo.annee = 0;
    dateMeteo.jour = 0;
    dateMeteo.heure = 0;
}

int comparerDateMeteo(const DateMeteo &dateMeteo1, const DateMeteo &dateMeteo2)
{
    //TODO
    return 0;
}

void afficherDateMeteo(const DateMeteo &dateMeteo, std::ostream &sortie)
{
    sortie << dateMeteo.annee << " " << dateMeteo.jour << " " << dateMeteo.heure;
}
