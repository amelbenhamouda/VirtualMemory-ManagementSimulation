#include "./../include/deuxiemeChance1.h"

void changeBit(Liste * liste, int page, int pos) {
  	Element * tmp = liste->tete;
  	while (tmp != NULL) {
    	if (tmp->page == page) {
      		switchBit(&(tmp->masque), pos);
      		break;
    	}
    	tmp = tmp->suivant;
  	}
}

void switchBit(char *masque, int pos) {
  	switch (pos) {
  		case 1:
  			(*masque) = (*masque)|(1<<0);
  			break;
  		case 0: 
  			(*masque) = (*masque)&~(1<<0);
  			break;
  	}
}

void putPointerDeuxiemeChance(AllElement *all, int page) {
    Element * tmp = all->l1->tete;
    while (tmp != NULL) {
        if (tmp->page == page) {

            break;
        }
		if (tmp->masque == 1) {
	  		switchBit(&(tmp->masque), 0);
	   		addtail(all->ldern, tmp->page);
	   		retirertrier(all, tmp->page);
		}
        tmp = tmp->suivant;
    }
    all->l1->vieux = tmp;
}

void algoSecondChance1(AllElement *all, int page) {
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
	     			putPointerDeuxiemeChance(all, enlever);
                    pop(all->ldern);
		     		if (all->l1->vieux->masque == 1) {
					    changeBit(all->l1, enlever, 0);
					    all->l1->vieux = all->l1->vieux->suivant;
	       				if (all->l1->vieux == NULL) {
                			all->l1->vieux = all->l1->tete;
            			}
	    			}
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
	  			changeBit(all->l1, page, 1);
	  			addtail(all->ldern, page);   
	  			retirertrier(all, page);
	  			break;
			case 2:
 				enlever = all->ldern->tete->page;
	    		changeTabPos(all->taberr, page, 1);
	     		putPointerDeuxiemeChance(all, enlever);
                pop(all->ldern);
		    	if (all->l1->vieux->masque == 1) {
	      			changeBit(all->l1, enlever, 0);
	      			all->l1->vieux = all->l1->vieux->suivant;
	       			if (all->l1->vieux == NULL) {
                		all->l1->vieux = all->l1->tete;
            		}
	    		}
	   			all->l1->vieux->page = page;
            	all->l1->vieux = all->l1->vieux->suivant;
            	if (all->l1->vieux == NULL) {
	                all->l1->vieux = all->l1->tete;
	            }
			    addtail(all->ltrie, enlever);
			    addtail(all->ldern, page);
			    changeTabPos(all->taberr, enlever, 2);
			    retirertrie(all, page);
	     		changeTabPos(all->taberr, page, 1);
	     		break;
		}
    }
}
