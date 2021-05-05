#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED
#include "COVIDPRIM.h"
typedef struct structNoeud {
ELEMENT elt;
struct structNoeud * precedent;
struct structNoeud * suivant;
} structNoeud, *NOEUD;

typedef struct {
NOEUD tete;
NOEUD queu;
int lg;
} LISTECOVID,*LISTE;
typedef struct // a verifier
{
    LISTE govers[24];
    int tete;
    int queu;
}lst;

#endif // LISTE_H_INCLUDED
