#include "./../include/argument.h"

int isnumber (char *arg) {
    int i;
    int size = strlen(arg);
    for (i = 0; i < size; i++) {
        if (!isdigit(arg[i])) {
            return -1;
        }
    }
    return 0;
}

void optionStart(int argc, char *argv[], int *size, int *maxpage, int *algo) {
    int opt;
    while ((opt = getopt(argc, argv, "s:v:fldc")) != -1) {
        switch (opt) {
            case 's':
                *size = atoi(optarg);  /*taille reelle*/
                break;
            case 'v':
                *maxpage = atoi(optarg);  /*taille virtuelle*/
                break;
            case 'f': /* FIFO */
                *algo = 0;
                break;
            case 'l': /* LRU */
                *algo = 1;
                break;
            case 'd': /* 2ème chance version 1*/
                *algo = 2;
                break;
            case 'c': /* 2ème chance version 2*/
                *algo = 3;
                break;
            default:
                fprintf(stderr, "Ligne de commande incorrecte.\n");
                exit(EXIT_FAILURE);
        }
    }

    if ((*size > *maxpage) || (*size == -1) || (*maxpage == -1) || (*algo == -1)) {
        fprintf(stdout,"Problème dans les arguments.\n");
        exit(EXIT_FAILURE);
    }
}

void command(char *arg, AllElement *all, int algo) {
    if (strcmp(arg, "p") == 0) {
        memoryAndReservePage(all);
    }
    else if (strcmp(arg, "x") == 0) {
        printf("fin du programe\n");
        exit(EXIT_FAILURE);
    }
    else if (isnumber(arg) == 0) {
        if (algo == 0) {
            algoFIFO(all,atoi(arg));
        }
        else if (algo == 1) {
            algoLRU(all,atoi(arg));
        }
        else if (algo == 2) {
            algoSecondChance1(all, atoi(arg));
        }
        else {
            algoSecondChance2(all, atoi(arg));
        }
        pathList(all, all->l1);
    }
    else {
        printf("Erreur de saisie.\n");
    }
}
