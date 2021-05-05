#ifndef LISTEPRIM_H_INCLUDED
#define LISTEPRIM_H_INCLUDED
#include "LISTESDD.h"
#include "COVIDPRIM.h"
NOEUD noeudCreer(ELEMENT e);
void noeudDetruire(NOEUD n);
LISTE listeCreer(void);
int estVide(LISTE L);
int estSaturee(LISTE L);
int listeTaille(LISTE L);
ELEMENT recuperer(LISTE L, int pos);
void listeDetruire(LISTE L);
void listeAfficher(LISTE L);
int inserer (LISTE L,ELEMENT e, int pos);
int supprimer (LISTE L, int pos );

#endif // LISTEPRIM_H_INCLUDED
