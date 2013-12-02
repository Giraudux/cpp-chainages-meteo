#include "main.h"

/// Alexis Giraudet

bool lireFichier(char *filename, Chainage &chainage)
{
    std::ifstream ifs(filename, std::ifstream::in);
    if(ifs)
    {
        char line[32];
        while(ifs.getline(line,32))
        {
            std::istringstream iss(line);
            ReleveMeteo releveMeteo = creerReleveMeteo();
            iss >> releveMeteo.station;
            iss >> releveMeteo.date.annee;
            iss >> releveMeteo.date.jour;
            iss >> releveMeteo.date.heure;
            iss >> releveMeteo.temperature;
            insererQueue(chainage, releveMeteo);
        }
        return true;
    }
    return false;
}

double calculerTemperatureMoyenne(const Chainage &chainage)
{
    if(chainage.nb < 1)
    {
        throw std::exception();
    }
    else
    {
        double acc = 0;
        Maillon *maillon = chainage.tete;
        while(maillon != 0)
        {
            acc += (*maillon).elt.temperature;
            maillon = (*maillon).suiv;
        }
        return acc/chainage.nb;
    }
}

void retirerDefauts(Chainage &chainage, const double ecartMax)
{
    if(chainage.nb < 1)
    {
        throw std::exception();
    }
    else
    {
        double acc = 0;
        Maillon *maillon = chainage.tete, *maillonPre = 0;
        while(maillon != 0)
        {
            if((maillon != chainage.tete) && (maillon != chainage.queue) &&  (fabs((*maillon).elt.temperature - (*maillonPre).elt.temperature) > ecartMax) && (fabs((*(*maillon).suiv).elt.temperature - (*maillon).elt.temperature) > ecartMax))
            {
                (*maillonPre).suiv = (*maillon).suiv;
                maillonPre = (*maillon).suiv;
                delete maillon;
                maillon = (*maillonPre).suiv;
                chainage.nb--;
                
            }
            else
            {
                maillonPre = maillon;
                maillon = (*maillon).suiv;
            }
        }
    }
}

double calculerEcartMoyenTemperature(const Chainage &chainage)
{
    if(chainage.nb < 2)
    {
        throw std::exception();
    }
    else
    {
        double acc = 0;
        Maillon *maillon = chainage.tete;
        while((*maillon).suiv != 0)
        {
            acc += fabs(((*((*maillon).suiv)).elt.temperature) - ((*maillon).elt.temperature));
            maillon = (*maillon).suiv;
        }
        return acc/(chainage.nb-1);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cout << "tp3 <nom du fichier à lire>" << std::endl;
        return 1;
    }
    else
    {
        Chainage c = creerChainage();
        if(!lireFichier(argv[1],c))
        {
            std::cout << "fichier incorrect" << std::endl;
            return 1;
        }
        else
        {
            try
            {
                ReleveMeteo rm = creerReleveMeteo();
                std::cout << "nombre de relevés = " << c.nb << std::endl;
                rm = plusPetitElement(c,compReleveMeteo2);
                std::cout << "relevé de la température minimale = ";
                afficherReleveMeteo(rm,std::cout);
                std::cout << std::endl;
                rm = plusPetitElement(c,compReleveMeteo3);
                std::cout << "relevé de la température maximale = ";
                afficherReleveMeteo(rm,std::cout);
                std::cout << std::endl;
                std::cout << "température moyenne = " << calculerTemperatureMoyenne(c) << std::endl;
                std::cout << "écart moyen des températures = " << calculerEcartMoyenTemperature(c) << std::endl;
                
                std::cout << std::endl;
                
                std::cout << "suppression des \"défauts\" (écart maximum = 2 * écart moyen)..." << std::endl;
                retirerDefauts(c,calculerEcartMoyenTemperature(c)*2);
                std::cout << "suppression du premier relevé (tête)..." << std::endl;
                retirerTete(c);
                std::cout << "suppression du dernier relevé (queue)..." << std::endl;
                retirerQueue(c);
                
                std::cout << std::endl;
                
                std::cout << "nombre de relevés = " << c.nb << std::endl;
                rm = plusPetitElement(c,compReleveMeteo2);
                std::cout << "relevé de la température minimale = ";
                afficherReleveMeteo(rm,std::cout);
                std::cout << std::endl;
                rm = plusPetitElement(c,compReleveMeteo3);
                std::cout << "relevé de la température maximale = ";
                afficherReleveMeteo(rm,std::cout);
                std::cout << std::endl;
                std::cout << "température moyenne = " << calculerTemperatureMoyenne(c) << std::endl;
                std::cout << "écart moyen des températures = " << calculerEcartMoyenTemperature(c) << std::endl;
            }
            catch(std::exception &e)
            {
                std::cout << std::endl << "nombre de relevés insuffisant pour effectuer les opérations" << std::endl;
            }
            reinitialiser(c);//pas de fuite mémoire
            return 0;
        }
    }
}
