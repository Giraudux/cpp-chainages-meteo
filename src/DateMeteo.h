#ifndef DATEMETEO_H
#define DATEMETEO_H

#include <iostream>

/// Alexis Giraudet

struct DateMeteo
{
    unsigned short int annee;
    unsigned short int jour;
    unsigned short int heure;
};

DateMeteo creerDateMeteo();
void initialiserDateMeteo(DateMeteo &dateMeteo);
int comparerDateMeteo(const DateMeteo &dateMeteo1, const DateMeteo &dateMeteo2);
void afficherDateMeteo(const DateMeteo &dateMeteo, std::ostream &sortie);

#endif
