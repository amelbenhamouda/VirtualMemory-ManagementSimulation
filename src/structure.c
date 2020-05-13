#include "./../include/structure.h"

/**************************************
* Commun a fifo lru et deuxiemeChance
**************************************/

void initList(Liste * liste, int maxpage, int size) {
    liste->tete = NULL;
    liste->vieux = NULL;
    liste->maxpage = maxpage;
    liste->fin = NULL;
    liste->size = size;
}

void initall(AllElement *all, int maxpage, int size) {
    initList(all->l1, maxpage, 0);
    initList(all->ldern, maxpage, 0);
    initList(all->ltrie, maxpage, 0);
}

void pathList(AllElement *all, Liste * liste) {
    if (liste == NULL) {
        exit(EXIT_FAILURE);
    }

    int counter = 0;
    Element *memory = liste->tete;
    while (counter < all->nbespace) {
        if (memory != NULL) { 
            printf("%d", memory->page);
            memory = memory->suivant;
        }
        else {
            printf("x");
        }
        counter++;
    }
    printf("\n");
}

void memoryAndReservePage(AllElement *all) {
    if (all == NULL) {
        exit(EXIT_FAILURE);
    }

    int counter = 0;
    Element *memory = all->l1->tete;
    while (counter < all->nbespace) {
        if (memory != NULL) {
            printf("%d", memory->page);
            memory = memory->suivant;
        }
        else {
            printf("x");
        }
        counter++;
    }
    printf("        ");
    counter = 0;
    Element *reserve = all->ltrie->tete;
    while (counter < all->sizetab) {
        if (reserve != NULL) {
            printf("%d", reserve->page);
            reserve = reserve->suivant;
        }
        else {
            printf("x");
        }
        counter++;
    }
    printf("\n");
}

void freeList(Liste *liste) {
    Element*tmp;
    while (liste != NULL) {
        tmp = liste->tete->suivant;
        free(liste);
        liste->tete = tmp;
    }
}

void buildAll(AllElement *all, int size, int maxpage, int algo) {
    initall(all, maxpage, size);
    all->algo = algo;
    all->sizetab = maxpage;
    all->nbespace = size;
    all->max = maxpage * 2;
    all->taberr = calloc(maxpage, sizeof(int));
    if (all->taberr == NULL) {
        fprintf(stderr, "Erreur d'allocation\n");
        exit(EXIT_FAILURE);
    }
}

int pageValid(int nb, Liste *liste) {
    if (nb >= 0 && nb < liste->maxpage) {
        return 0;
    }
    return -1;
}

void printTabPos(int *tab, int maxpage) {
    int i;
    for (i = 0; i < maxpage; i++) {
        printf("%d\n", tab[i]);
    }
}

int isnotliste(int *tab, int page) {
    return tab[page];
}

void changeTabPos(int *tab,int page, int new) {
    tab[page] = new;
}

void addtail(Liste *liste, int page) {
    Element *new = malloc(sizeof(Element));
    if (new == NULL) {
        fprintf(stderr, "Erreur d'allocation\n");
        exit(EXIT_FAILURE);
    }
    new->page = page;
    new->masque = 0;
    new->suivant = NULL;
  
    Element *tmp = liste->tete;
    if (tmp == NULL) {
        tmp = new;
        liste->tete = tmp;
        liste->vieux = tmp;
    }
    else {
        while (tmp->suivant != NULL) {
            tmp = tmp->suivant;
        }
        tmp->suivant = new;
    }
    liste->vieux = new->suivant;
    liste->size = liste->size + 1;
}
            
void retirertrie(AllElement *all, int page) {
    Element *cur = all->ltrie->tete;
    Element *tmp = all->ltrie->tete;;
    if (tmp->page == page) {
        all->ltrie->tete = tmp->suivant;
        free(tmp);
        return ;
    }
    cur = tmp->suivant;
    while (cur != NULL ) {
        if (cur->page == page) {
            tmp->suivant = cur->suivant;
            free(cur);
            return ;
        }
        tmp = cur;
        cur = cur->suivant;
    }
}

/**************************************
* Commun a lru et deuxiemeChance
**************************************/

void retirertrier(AllElement *all, int page) {
    Element *cur = all->ldern->tete;
    Element *tmp = all->ldern->tete;;
    if (tmp->page == page) {
        all->ldern->tete = tmp->suivant;
        free(tmp);
        return ;
    }
    cur = tmp->suivant;
    while (cur != NULL ) {
        if (cur->page == page) {
            tmp->suivant = cur->suivant;
            free(cur);
            return ;
        }
        tmp = cur;
        cur = cur->suivant;
    }
}

void pop(Liste *liste) {
    if (liste == NULL) {
        return ;
    }
    Element *tmp = liste->tete;
    liste->tete = liste->tete->suivant;
    free(tmp);
}
