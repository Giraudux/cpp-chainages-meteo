#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "math.h"

#include "Chainage.h"
#include "DateMeteo.h"
#include "ReleveMeteo.h"

/// Alexis Giraudet

bool lireFichier(char *filename, Chainage &chainage);
double calculerTemperatureMoyenne(const Chainage &chainage);
double calculerEcartMoyenTemperature(const Chainage &chainage);
void retirerDefauts(Chainage &chainage, const double ecartMax);
int main(int argc, char *argv[]);
