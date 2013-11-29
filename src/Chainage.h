#ifndef CHAINAGE_H
#define CHAINAGE_H

#include "ReleveMeteo.h"

/// Alexis Giraudet

struct Maillon
{
    ReleveMeteo elt;
    Maillon *suiv;
};

struct Chainage
{
    unsigned int nb;
    Maillon *tete;
    Maillon *queue;
};

#endif
