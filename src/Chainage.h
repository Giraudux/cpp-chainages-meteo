#ifndef CHAINAGE_H
#define CHAINAGE_H

#include <iostream>
#include <exception>

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

Chainage creerChainage();
void initialiserChainage(Chainage &chainage);
void reinitialiser(Chainage &chainage);
void insererTete(Chainage &chainage, const ReleveMeteo releveMeteo);
void insererQueue(Chainage &chainage, const ReleveMeteo releveMeteo);
void retirerTete(Chainage &chainage);
void retirerQueue(Chainage &chainage);
void insererOrdre(Chainage &chainage, const ReleveMeteo releveMeteo, CompReleveMeteo comparer);
ReleveMeteo plusPetitElement(const Chainage &chainage, CompReleveMeteo comparer);
void retirerTous(Chainage &chainage, PredicatReleveMeteo verifier);
void afficherChainage(const Chainage &chainage, std::ostream &sortie);

#endif
