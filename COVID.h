#ifndef COVID_H_INCLUDED
#define COVID_H_INCLUDED
typedef struct
{
    int jj;
    int mm;
    int aa;
}date,*DAT;
typedef struct
{
    DAT d;
    int cas_p;
    int guerison;
    int deces;
    int nbv;
}covid,*ELEMENT;


#endif // COVID_H_INCLUDED
