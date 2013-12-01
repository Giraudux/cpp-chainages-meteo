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
    return (dateMeteo1.heure + dateMeteo1.jour*100 + dateMeteo1.annee*100000) - (dateMeteo2.heure + dateMeteo2.jour*100 + dateMeteo2.annee*100000);
}

void afficherDateMeteo(const DateMeteo &dateMeteo, std::ostream &sortie)
{
    sortie << dateMeteo.annee << " " << dateMeteo.jour << " " << dateMeteo.heure;
}
