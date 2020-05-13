#include <stdio.h>
#include <stdlib.h>
#include "./../include/structure.h"
#include "./../include/argument.h"
#include "./../include/fifo.h"
#include "./../include/lru.h"
#include "./../include/deuxiemeChance1.h"
#include "./../include/deuxiemeChance2.h"

int main(int argc, char*argv[]) {
    if (argc != 6) {
        fprintf(stderr,"Argument manquant.\n");
        fprintf(stderr, "usage %s -s tailleReelle -v tailleVirtuelle -algoChoisie\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    AllElement *all = malloc(sizeof(AllElement));
    all->l1 = malloc(sizeof(Liste));
    if (all->l1 == NULL) {
        fprintf(stdout, "Erreur d'allocation");
        exit(EXIT_FAILURE);
    }
    all->ldern = malloc(sizeof(Liste));
    if (all->ldern == NULL) {
        fprintf(stdout, "Erreur d'allocation");
        exit(EXIT_FAILURE);
    }
    all->ltrie = malloc(sizeof(Liste));
    if (all->ltrie == NULL) {
        fprintf(stdout, "Erreur d'allocation");
        exit(EXIT_FAILURE);
    }
    
    int size = -1; 
    int maxpage = -1;
    int algo = -1;
    char arg[2];

    optionStart(argc, argv, &size, &maxpage, &algo);

    buildAll(all, size, maxpage, algo);

    scanf("%s", arg);
    while (strcmp(arg, "x") != 0) {
        command(arg, all, algo);
        scanf("%s", arg);
    }

    return 0;
}
