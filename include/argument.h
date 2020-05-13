#ifndef __ARGUMENT__
#define __ARGUMENT__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <getopt.h>
#include "structure.h"
#include "fifo.h"
#include "lru.h"
#include "deuxiemeChance1.h"
#include "deuxiemeChance2.h"

/*
**Fonction qui permet de verifier si une chaine est un nombre
**@parametre: char * arg -> chaine à verifier
**@return 0 si la chaine est bien un nombre et -1 sinon
*/
int isnumber(char *arg);

/*
**Fonction qui verifie si la ligne de commande est correcte
**@parametre: int argc ->  nombre d'argument
** char *argv[] -> argument de la ligne de commande
** int * size -> taille reelle
** int *maxpage -> taille virtuelle
** int * algo -> algorithme utilise
**@return rien
*/
void optionStart(int argc, char *argv[], int *size, int *maxpage, int *algo);

/*
**Fonction qui affiche les differentes liste selon la commande demande
**@parametre: char * arg -> commande taper par l'utilisateur
** AllElement * all -> structure contenant les differentes listes et informations
** int algo -> algorithme demande
**@return rien
*/
void command(char *arg, AllElement *all, int algo);

#endif