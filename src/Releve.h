#ifndef RELEVE_H
#define RELEVE_H

#include "Date.h"

/// Alexis Giraudet

class Releve
{
    public:
        Releve();
        ~Releve();
        int comparer(Releve releve);
        void afficher();
        
    
    private:
        unsigned int station;
        Date date;
        int temperature;
};
 
#endif
