#ifndef RELEVEMETEO_H
#define RELEVEMETEO_H

#include "DateMeteo.h"

/// Alexis Giraudet

struct ReleveMeteo
{
    unsigned int station;
    DateMeteo date;
    int temperature;
};

#endif
