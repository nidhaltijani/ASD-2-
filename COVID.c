#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "COVIDPRIM.h"



ELEMENT elementCreer (void) {
ELEMENT L;
L = (ELEMENT) malloc(sizeof(covid));
L->d=(DAT)malloc(sizeof(date));
L->cas_p=0;
L->d->aa=0;
L->d->jj=0;
L->d->mm=0;
L->deces=0;
L->guerison=0;
L->nbv=0;
return L;
}
void elementDetruire (ELEMENT elt) {
    free(elt->d);
free(elt);
}
void elementLire(ELEMENT*elt) {

gotoxy(39,13);
		printf("cas positifs :");
		gotoxy(8,18);
		printf("guerisons   : ");
		gotoxy(39,18);
		printf("d%cces       : ",130);
		gotoxy(8,23);
		printf("VACCINES  : ");


		do{
		gotoxy(55,13);

    scanf("%i",&((*elt)->cas_p));
    }
    while ((*elt)->cas_p<0);

		do{
		gotoxy(22,18);
    scanf("%i",&((*elt)->guerison));
}
    while ((*elt)->guerison<0);

		do{
		gotoxy(55,18);
    scanf("%i",&((*elt)->deces));
    }
        while ((*elt)->deces<0);

		do{
		gotoxy(22,23);
    scanf("%i",&((*elt)->nbv));
}
    while ((*elt)->nbv<0);

}
void elementAfficher(ELEMENT elt)
{
    printf("\n \t%i / %i / %i on a %i cas positifs %i deces %i guerisons et %i vaccines\n",elt->d->jj,elt->d->mm,elt->d->aa,elt->cas_p,elt->deces,elt->guerison,elt->nbv);
}
void elementAffecter(ELEMENT* inf , ELEMENT inf1 ){
    *inf=inf1;
}
void elementCopier(ELEMENT *e1,ELEMENT e2)
{
    memcpy(*e1,e2,sizeof(covid));
}

