#include "./../include/lru.h"

void putPointerLru(Liste *liste, int page) {
    Element * tmp = liste->tete;
    while (tmp != NULL) {
        if (tmp->page == page) {
            break;
        }
        tmp = tmp->suivant;
    }
    liste->vieux = tmp;
}

void algoLRU(AllElement *all, int page) {
    if (pageValid(page, all->l1) == -1) {
        fprintf(stderr, "La page entre est incorrecte\n");
    }
    else {
    	int enlever;
      	switch (isnotliste(all->taberr, page)) {
      		case 0:
      			if (all->l1->size < all->nbespace) {
				    addtail(all->l1, page);
				    changeTabPos(all->taberr, page, 1);
				    addtail(all->ldern, page);
				    if (all->l1->vieux == NULL) {
		                all->l1->vieux = all->l1->tete;
			        }
	  			} 
	  			else {
				    enlever = all->ldern->tete->page;
				    changeTabPos(all->taberr, page, 1);
	     			putPointerLru(all->l1, enlever);
                    pop(all->ldern);
	   				all->l1->vieux->page = page;
            		all->l1->vieux = all->l1->vieux->suivant;
            		if (all->l1->vieux == NULL) {
                		all->l1->vieux = all->l1->tete;
            		}
				    addtail(all->ltrie, enlever);
				    addtail(all->ldern, page);
				    changeTabPos(all->taberr, enlever, 2);
	  			}
	  			break;
			case 1:
				addtail(all->ldern, page);
				retirertrier(all, page);
				break;
			case 2:
				enlever = all->ldern->tete->page;
	    		changeTabPos(all->taberr, page, 1);
	     		putPointerLru(all->l1, enlever);
                pop(all->ldern);
	   			all->l1->vieux->page = page;
            	all->l1->vieux = all->l1->vieux->suivant;
            	if (all->l1->vieux == NULL) {
                	all->l1->vieux = all->l1->tete;
            	}
			    addtail(all->ltrie, enlever);
			    addtail(all->ldern, page);
			    changeTabPos(all->taberr, enlever, 2);
			    retirertrie(all, page);
			    break;	    	  
		}
    }
}              
