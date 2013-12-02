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
    while(chainage.nb != 0)
    {
        retirerTete(chainage);
        //retirerQueue(chainage);
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
    if(chainage.nb > 0)
    {
        Maillon *maillon = chainage.tete;
        chainage.tete = (*chainage.tete).suiv;
        if(chainage.nb == 1)
        {
            chainage.queue = 0;
        }
        delete maillon;
        chainage.nb--;
    }
}

void retirerQueue(Chainage &chainage)
{
    if(chainage.nb > 0)
    {
        if(chainage.nb == 1)
        {
            retirerTete(chainage);
        }
        else
        {
            Maillon *maillon = chainage.tete;
            while((*maillon).suiv != chainage.queue)
            {
                maillon = (*maillon).suiv;
            }
            delete (*maillon).suiv;
            (*maillon).suiv = 0;
            chainage.queue = maillon;
            chainage.nb--;
        }
    }
}

void insererOrdre(Chainage &chainage, const ReleveMeteo releveMeteo, CompReleveMeteo comparer)
{
    ;
}

ReleveMeteo plusPetitElement(const Chainage &chainage, CompReleveMeteo comparer)
{
    if(chainage.nb == 0)
    {
        throw std::exception();
    }
    Maillon *maillon = chainage.tete;
    ReleveMeteo releveMeteo = (*maillon).elt;
    while((*maillon).suiv != 0)
    {
        if(comparer((*maillon).elt,(*(*maillon).suiv).elt) > 0)
        {
            releveMeteo = (*(*maillon).suiv).elt;
        }
        maillon = (*maillon).suiv;
    }
    return releveMeteo;
}

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
