#include "./../include/deuxiemeChance2.h"

void placer(Liste * liste) {
	Element * tmp = liste->vieux;
    while (tmp != NULL) {
        if (tmp->masque == 0) {
        	liste->vieux = tmp;
        	break;
        }
        if (tmp->masque == 1) {
        	changeBit(liste, tmp->page, 0);
        	tmp = tmp->suivant;
        }
        if (tmp == NULL) {
        	tmp = liste->tete;
        }
    }
}

void algoSecondChance2(AllElement *all, int page) {
    if (pageValid(page, all->l1) == -1) {
        fprintf(stderr, "La page est incorrecte\n");
    }
    else {
    	int enlever;
    	switch (isnotliste(all->taberr, page)) {
    		case 0:
    			if (all->l1->size < all->nbespace) {
	    			addtail(all->l1, page);
	    			changeTabPos(all->taberr, page, 1);
		    		if (all->l1->vieux == NULL) {
	                	all->l1->vieux = all->l1->tete;
		      		}
	  			} 
	  			else {
				    placer(all->l1);
				    enlever=all->l1->vieux->page;
				    changeTabPos(all->taberr, page, 1);
	   				all->l1->vieux->page = page;
            		all->l1->vieux = all->l1->vieux->suivant;
            		if (all->l1->vieux == NULL) {
                		all->l1->vieux = all->l1->tete;
            		}
	    			addtail(all->ltrie, enlever);
	    			changeTabPos(all->taberr, enlever, 2);
	  			}
	  			break;
			case 1:
				changeBit(all->l1, page, 1);
				break;
			case 2:
	  			placer(all->l1);
	  			enlever=all->l1->vieux->page;
	   			all->l1->vieux->page = page;
            	all->l1->vieux = all->l1->vieux->suivant;
            	if (all->l1->vieux == NULL) {
                	all->l1->vieux = all->l1->tete;
            	}
	    		addtail(all->ltrie, enlever);
	    		changeTabPos(all->taberr, enlever, 2);
	    		retirertrie(all, page);
	    		changeTabPos(all->taberr, page, 1);
	    		break;	    	  
		}
	}
} 
