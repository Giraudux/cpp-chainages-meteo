#include "Chainage.h"

/// Alexis Giraudet

template <class T>
Chainage<T>::Chainage() : nb(0), tete(0), queue(0)
{
    ;
}

template <class T>
Chainage<T>::~Chainage()
{
    reinitialiser();
}

template <class T>
bool Chainage<T>::estVide()
{
    return nb<=0;
}

template <class T>
void Chainage<T>::reinitialiser()
{
    nb = 0;
}

template <class T>
void Chainage<T>::insererTete(T &data)
{
    nb++;
    Maillon *maillon = new Maillon;
    *maillon.elt = data;
    *maillon.suiv = (*tete).suiv;
    tete = maillon;
    
}

template <class T>
void Chainage<T>::insererQueue(T data)
{
    nb++;
}

template <class T>
T Chainage<T>::retirerTete()
{
    if(tete != 0)
    {
        nb--;
        Maillon *maillon = tete;
        tete = (*tete).suiv;
        delete maillon;
    }
    return;
}

template <class T>
T Chainage<T>::retirerQueue()
{
    nb--;
    return;
}

template <class T>
void Chainage<T>::insererOrdre()
{
    ;
}

template <class T>
void Chainage<T>::plusPetitElement()
{
    ;
}

template <class T>
void Chainage<T>::retirerTous()
{
    ;
}

template <class T>
void Chainage<T>::afficher()
{
    ;
}

