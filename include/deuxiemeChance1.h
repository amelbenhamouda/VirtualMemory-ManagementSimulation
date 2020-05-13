#ifndef __DEUXIEMECHANCE1__
#define __DEUXIEMECHANCE1__

#include "structure.h"

/*
**Fonction qui permet de changer le bit du nombre en 1 si il etait à 0 et inversement
**@parametre: char * masque -> masque à changer
** int pos -> entier pour connaitre à quelle valeur mettre le masque
**@return rien
*/
void switchBit(char *masque, int pos);

/*
**Fonction qui permet de changer le masque d'une page
**@parametre: Liste *liste -> liste contenant les nombres
** int page -> page dont on modifie le masque
** int pos -> valeur à mettre au masque
**@return rien
*/
void changeBit(Liste * liste, int page, int pos);

/*
**Algorithme de seconde chance mixée au LRU
**@parametre: AllElement *all -> structure contenant les listes
**int page -> page entrée par l'utilisateur
**@return rien
*/
void algoSecondChance1(AllElement *all, int page);

/*
**Fonction qui place le pointeur sur la page à enlever
**@parametre: AllElement * all -> structure contenant les listes
**int page -> page demandée
**@return rien
*/
void putPointerDeuxiemeChance(AllElement *all, int page);

#endif
