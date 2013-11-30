#include "Chainage.h"

/// Alexis Giraudet

Chainage creerChainage()
{
    Chainage chainage;
    initialiserChainage(chainage);
    return chainage;
}

void initialiserChainage(Chainage &chainage)
{
    chainage.nb = 0;
    chainage.tete = 0;
    chainage.queue = 0;
}

void reinitialiser(Chainage &chainage)
{
    while(chainage.tete != 0)
    {
        retirerTete(chainage);
    }
}

void insererTete(Chainage &chainage, const ReleveMeteo releveMeteo)
{
    Maillon *maillon = new Maillon;
    (*maillon).elt = releveMeteo;
    (*maillon).suiv = chainage.tete;
    chainage.tete = maillon;
    if(chainage.queue == 0)
    {
        chainage.queue = maillon;
    }
    chainage.nb++;
}
void insererQueue(Chainage &chainage, const ReleveMeteo releveMeteo)
{
    if(chainage.nb == 0)
    {
        insererTete(chainage,releveMeteo);
    }
    else
    {
        Maillon *maillon = new Maillon;
        (*maillon).elt = releveMeteo;
        (*maillon).suiv = 0;
        (*(chainage.queue)).suiv = maillon;
        chainage.queue = maillon;
        chainage.nb++;
    }
}

void retirerTete(Chainage &chainage)
{
    ;
}

void retirerQueue(Chainage &chainage)
{
    ;
}

void insererOrdre(Chainage &chainage, const ReleveMeteo releveMeteo, CompReleveMeteo comparer)
{
    ;
}

//ReleveMeteo plusPetitElement(const Chainage &chainage, CompReleveMeteo comparer);

void retirerTous(Chainage &chainage, PredicatReleveMeteo verifier)
{
    ;
}

void afficherChainage(const Chainage &chainage, std::ostream &sortie)
{
    Maillon *maillon = chainage.tete;
    while(maillon != 0)
    {
        afficherReleveMeteo((*maillon).elt,sortie);
        sortie << std::endl;
        maillon = (*maillon).suiv;
    }
}
