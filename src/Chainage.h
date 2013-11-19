#ifndef CHAINAGE_H
#define CHAINAGE_H

/// Alexis Giraudet

struct Maillon
{
    //T elt;//todo: template
    Maillon *suiv;
};

class Chainage
{
    public:
        Chainage();
        ~Chainage();
        bool estVide();
        void reinitialiser();
        void insererTete();//todo: template
        void insererQueue();//todo: template
        void retirerTete();//todo: retourner first
        void retirerQueue();//todo: retourner last
        void insererOrdre();//todo: template
        void plusPetitElement();//todo: template, comparateur
        void retirerTous();//todo: template, predicat
        void afficher();
        
    
    private:
        unsigned int nb;
        Maillon *tete;
        Maillon *queue;
};
 
#endif
