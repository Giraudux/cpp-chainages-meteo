#ifndef DATE_H
#define DATE_H

#include <iostream>

/// Alexis Giraudet

class Date
{
    public:
        Date();
        ~Date();
        int comparer(Date date);
        std::string afficher();
    
    private:
        // tout mettre en heure ?
        unsigned short int annee;
        unsigned short int jour;
        unsigned short int heure;
};
 
#endif
