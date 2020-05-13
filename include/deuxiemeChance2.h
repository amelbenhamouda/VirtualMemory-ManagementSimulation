#ifndef __DEUXIEMECHANCE2__
#define __DEUXIEMECHANCE2__

#include "structure.h"
#include "deuxiemeChance1.h"

/*
**Fonction qui permet de placer un pointeur sur la prochaine page à enlever.
**@parametre: Liste * liste -> liste contenant les pages
**@return rien
*/
void placer(Liste * liste);

/*
**Algorithme de seconde chance mixée au LRU
**@parametre: AllElement *all -> structure contenant les listes
**int page -> page entrée par l'utilisateur
**@return rien
*/
void algoSecondChance2(AllElement *all, int page);


#endif
