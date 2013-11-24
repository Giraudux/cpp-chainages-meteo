#ifndef CHAINAGE_H
#define CHAINAGE_H

/// Alexis Giraudet

template <class T>
class Chainage
{
    struct Maillon
    {
        T elt;//todo: template
        Maillon *suiv;
    };

    public:
        Chainage();
        ~Chainage();
        bool estVide();
        void reinitialiser();
        void insererTete(T &data);//todo: template
        void insererQueue(T data);//todo: template
        T retirerTete();//todo: retourner first
        T retirerQueue();//todo: retourner last
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
