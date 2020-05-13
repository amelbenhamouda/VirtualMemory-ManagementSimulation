#ifndef __STRUCTURE__
#define __STRUCTURE__

#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int page;
    char masque;
    struct element *suivant;
} Element;

typedef struct liste {
    int maxpage;
    Element *tete;
    Element *vieux;
    Element *fin;
    int size;
} Liste;

typedef struct allElement {
    Liste *l1;
    Liste *ldern;
    Liste *ltrie;
    int *taberr;
    int sizetab;
    int max;
    int nbespace;
    int algo;
} AllElement;

/*
**Fonction qui permet d'initialiser une liste (met tous ses pointeurs à NULL)
**@parametre: Liste * liste -> liste à initialiser 
** int maxpage -> taille virtuelle
** int size -> taille reelle
**@return rien
*/
void initList(Liste *liste, int maxpage, int size);

/*
**Fonction qui permet d'afficher une liste
**@parametre:  AllElement *all -> structure contenant toutes les listes et champs nécéssaire
** Liste * liste -> liste à afficher
**@return rien
*/
void pathList(AllElement *all, Liste * liste);

/*
**Fonction qui permet d'afficher la liste en mémoire et la liste en réserve
**@parametre:  AllElement *all -> structure contenant toutes les listes et des champs
**@return rien
*/
void memoryAndReservePage(AllElement *all);

/*
**Fonction qui permet de libérer une liste
**@parametre: Liste * liste -> liste à libérer 
**@return rien
*/
void freeList(Liste *liste);

/*
**Fonction qui returne l'emplacement de la page 
**@parametre: int *tab -> tableau contenant la valeur localisant la page
** int page -> page que l'on cherche
**@return 0 si la page n'a jamais été demandé, 1 si elle se trouve dans la liste 
** et 2 si elle est dans les pages en réserves
*/
int isnotliste(int *tab, int page);

/*
**Fonction qui permet d'initialiser la structure contenant toute les listes
**@parametre: AllElement *all -> structure contenant toutes les listes et des champs
** int maxpage -> taille virtuelle
** int size -> taille reelle
**@return rien
*/
void initall(AllElement *all, int maxpage, int size);

/*
**Fonction qui permet de construire toutes la structure (initialise toute les listes, remplit les champs)
**@parametre: AllElement *all -> structure contenant toutes les listes et des champs
** int maxpage -> taille virtuelle
** int size -> taille reelle
**int algo -> entier représentant l'algorithme choisit
**@return rien
*/
void buildAll(AllElement *all, int size, int maxpage,int algo);

/*
**Fonction qui verifie si la page demandée est valide
**@parametre: int nb -> page demandée a verifier
** Liste * liste -> liste contenant les pages
**@return 0 si c'est valide et -1 sinon
*/
int pageValid(int nb, Liste *liste);

/*
**Fonction qui affiche la table contenant la position des pages
**@parametre: int * tab -> tableau contenant les positions
** int maxpage -> maximum des pages disponibles
**@return rien
*/
void printTabPos(int *tab, int maxpage);

/*
**Fonction qui permet de changer la position d'une page 
**@parametre: int * tab -> tableau contenant les positions
** int page -> page dont on change la position
** int new -> nouvelle valeur pour la position
**@return rien
*/
void changeTabPos(int *tab,int page, int new);

/*
**Fonction qui permet d'ajouter une page a la fin d'une liste
**@parametre: liste * liste -> liste ou ajouter la page
** int page -> page à ajouter
**@return rien
*/
void addtail(Liste *liste, int page);


/*
**Fonction qui permet de retirer de la liste ldern  la page demandé
**@parametre: AllElement *all -> structure contenant toutes les listes et des champs
** int page -> page à retirer
**@return rien
*/
void retirertrie(AllElement *all, int page);

/*
**Fonction qui permet de retirer de la liste ltrie la page demandé
**@parametre: AllElement *all -> structure contenant toutes les listes et des champs
** int page -> page à retirer
**@return rien
*/
void retirertrier(AllElement *all, int page);

/*
**Fonction qui permet de retirer le premier element d'une liste 
**@parametre: liste * liste -> liste ou retirer le premier element
**@return rien
*/
void pop(Liste *liste);

#endif
