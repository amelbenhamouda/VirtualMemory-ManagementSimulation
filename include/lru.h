#ifndef __LRU__
#define __LRU_

#include "structure.h"

/*
**Fonction qui place un pointeur su la page à enlever
**@parametre: liste * liste -> liste contenant les pages
** int page -> page demandée
**@return rien
*/
void putPointerLru(Liste *liste, int page);

/*
**Algorithme LRU
**@parametre: AllElement * all -> structure contenant les listes
** int page -> page demandée
**@return rien
*/
void algoLRU(AllElement *all, int page);

#endif