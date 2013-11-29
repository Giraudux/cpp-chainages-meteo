#ifndef RELEVEMETEO_H
#define RELEVEMETEO_H

#include <iostream>

#include "DateMeteo.h"

/// Alexis Giraudet

struct ReleveMeteo
{
    unsigned int station;
    DateMeteo date;
    int temperature;
};

typedef int (*CompReleveMeteo)(const ReleveMeteo &rm1, const ReleveMeteo &rm2);
typedef bool (*PredicatReleveMeteo)(const ReleveMeteo &rm);

ReleveMeteo creerReleveMeteo();
void initialiserReleveMeteo(ReleveMeteo &releveMeteo);
int comparerReleveMeteo(ReleveMeteo releveMeteo1, ReleveMeteo releveMeteo2);
void afficherReleveMeteo(const ReleveMeteo &releveMeteo, std::ostream &sortie);

#endif
