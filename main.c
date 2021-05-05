#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>
#include "LISTEprim.h"
#include <conio.h>
#include<ctype.h>
#include<dos.h>
#define TAILLE_MAX 1000
COORD coord = {0,0};

void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int verifdate (DAT date);
int main()
{
    char mot[15]="MENU PRINCIPAL";
    int choix,i,j;
    LISTE g[24];
    //*g=(LISTE)malloc(24*sizeof(LISTECOVID));
    char gov[24][50]= {"ARIANA","BEJA","BEN AROUS","BIZERTE","GABES","GAFSA","JENDOUBA","KAIROUAN","KASSERINE","KEBILI","LA MANOUBA","LE KEF","MAHDIA","MEDNIN","MONASTIR","NABEUL","SFAX","SIDI BOUZID","SILIANA","SOUSSE","TATAOUINE","TOZEUR","TUNIS","ZAGHOUAN"};
    char govtri[24][50]= {"ARIANA","BEJA","BEN AROUS","BIZERTE","GABES","GAFSA","JENDOUBA","KAIROUAN","KASSERINE","KEBILI","LA MANOUBA","LE KEF","MAHDIA","MEDNIN","MONASTIR","NABEUL","SFAX","SIDI BOUZID","SILIANA","SOUSSE","TATAOUINE","TOZEUR","TUNIS","ZAGHOUAN"};

    for( i=0; i<24; i++)
        g[i]=listeCreer();




start:
    system("cls");
    Color(14,0);
    gotoxy(10,4);
    for(j=0; j<20; j++)
    {
        Sleep(50);
        printf("*");
    }
    for(j=0; j<strlen(mot); j++)
    {
        Sleep(50);
        printf("%c",mot[j]);
    }
    for(j=0; j<20; j++)
    {
        Sleep(50);
        printf("*");
    }
    gotoxy(20,5);

    printf("\xDB\xDB\xDB\xDB\xB2 1. Ajouter une date   ");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Modifier une information");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Afficher les statistiques dun governorat");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Supprimer une date");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. affichage trie dune date");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. importer les donn%ces dun fichier txt",130);
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Fermer l'Application");
    gotoxy(20,19);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,20);

    printf("Entrer votre choix:");
    Color(15,0);
    fflush(stdin);
    switch(getch())
    {
    case '1' : //ajout date
    {
        int i=0;
        system("cls");
        DAT d=(DAT)malloc(sizeof(date));
        do
        {
            fflush(stdin);
            printf("\n\n\t\t\tdonnez la date sous format jj/mm/aaaa\n");
            scanf("%2i/%2i/%i\n",&(d->jj),&(d->mm),&(d->aa));

            if(cherchedate(g[0],d))
                printf("\t\t\t Cette date existe d%cja\n",130);
        }
        while((!verifdate(d))||(cherchedate(g[0],d)));
        for(i=0; i<24; i++)
        {
            int k=1;
            system("cls");
            box();
            lbox();
            gotoxy(30,8);
            printf("\t\t%s\n",gov[i]);
            ELEMENT e=elementCreer();
            fflush(stdin);
            elementLire(&e);
            e->d->jj=d->jj;
            e->d->mm=d->mm;
            e->d->aa=d->aa;
            NOEUD p;
            p=g[i]->tete;
            while((p!=NULL)&&((p->elt->d->aa)<(e->d->aa)||(((p->elt->d->aa)==(e->d->aa))&&((p->elt->d->mm)<(e->d->mm)))||((p->elt->d->aa)==(e->d->aa))&&((p->elt->d->mm)==(e->d->mm)&&(p->elt->d->jj)<(e->d->jj))))
            {
                k++;
                p=p->suivant;

            }
            inserer(g[i],e,k);
            fflush(stdin);


        }
        free(d);
        printf("\n\n\n tapez sur n'importe quel bouton pour revenir au menu\n");
        system("pause>null");
        goto start;
    }
    break;
    case '2' :
    {
        int chio;
        system("cls");
        nomgover();
        Color(15,0);
        do
        {
            printf("Tapez le num%cro du gouvernorat dont vous voulez modifier des informations\n",130);
            scanf("%i",&chio);
        }
        while((chio<1)||(chio>24));

        DAT da=(DAT)malloc(sizeof(date));
        do{
        printf("donnez la date dont vous voulez modifier les informations\n");
        scanf("%2i/%2i/%i",&(da->jj),&(da->mm),&(da->aa));
        }
        while(!verifdate(da));
        NOEUD p;
        int h=1;
        p=g[chio-1]->tete;
        while((p!=NULL)&&!(((da->jj)==(p->elt->d->jj))&&((da->mm)==(p->elt->d->mm))&&((da->aa)==(p->elt->d->aa))))
        {
            h++;
            p=p->suivant;
        }
        if(p==NULL)
        {

           Color(4,0);
            printf("on na pas de stats pour cette date\n");
            Color(15,0);
        }
        else
        {
modify:
            system("cls");
            Color(14,0);
            elementAfficher(p->elt);
            gotoxy(20,5);

            printf("\xDB\xDB\xDB\xDB\xB2 1. modifier le nombre de cas positifs   ");
            gotoxy(20,7);
            printf("\xDB\xDB\xDB\xDB\xB2 2. Modifier le nombre de deces  ");
            gotoxy(20,9);
            printf("\xDB\xDB\xDB\xDB\xB2 3. modifier le nombre de guerisons ");
            gotoxy(20,11);
            printf("\xDB\xDB\xDB\xDB\xB2 4. modifier le nombre de vaccin%cs",130);
            gotoxy(20,13);
            printf("\xDB\xDB\xDB\xDB\xB2 5. Retour au menu principal");
            gotoxy(20,15);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,18);

            printf("Entrer votre choix:");
            Color(15,0);
            fflush(stdin);
            switch(getch())
            {
            case '1' :
            {
                do
                {
                    printf("\ndonnez le nouveau nombre de cas positifs\n");
                    scanf("%i",&(p->elt->cas_p));
                }
                while(p->elt->cas_p<0);
                goto modify;
            }
            break;
            case '2':
            {
                do
                {
                    printf("\ndonnez le nouveau nombre de deces\n");
                    scanf("%i",&(p->elt->deces));
                }
                while(p->elt->deces<0);
                goto modify;
            }
            break;
            case '3' :
            {
                do
                {
                    printf("\ndonnez le nouveau nombre de gu%crisons\n",130);
                    scanf("%i",&(p->elt->guerison));
                }
                while(p->elt->guerison<0);
                goto modify;
            }
            break;
            case '4' :
            {
                do
                {
                    printf("\ndonnez le nouveau nombre de vaccin%cs\n",130);
                    scanf("%i",&(p->elt->nbv));
                }
                while(p->elt->nbv<0);
                goto modify;

            }
            break;

            case '5' :
            {
                goto start;
            }
            break;
            default :
            {
                printf("choix incorrect\n");
                sleep(3000);
                goto modify;
            }

            }
        }



        free(da);
        free(p);

        printf("\n\n\n tapez sur n'importe quel bouton pour revenir au menu\n");
        system("pause>null");
        goto start;
    }
    break;
    case '3' :
    {

        int choice;
        system("cls");
        nomgover();
        Color(15,0);
        do
        {
            printf("choisissez le governorat a afficher\n");
            scanf("%i",&choice);
        }
        while((choice<1)||(choice>24));
        system("cls");
        //start
        box();
        lbox();
        gotoxy(30,8);
        printf("\t\t%s\n",gov[choice-1]);

        //end
        //printf("\n\n\t\t\t%s\n",gov[choice-1]);
        listeAfficher(g[choice-1]);
        if(!estVide(g[choice-1]))
        {


            printf("\n\n\t\t\tSi vous voulez connaitre levolution statistique\n\ttapez 1 sinon nimporte quel bouton\n");
            char x=getch();
            if(x=='1')
            {
                system("cls");
                statsgover(g[choice-1],gov[choice-1]);
            }
        }



        printf("\n\n\n\t\t tapez sur n'importe quel bouton pour revenir au menu\n");
        system("pause>null");
        goto start;
    }
    break;
    case '4' :
    {
        DAT d=(DAT)malloc(sizeof(date));
            system("cls");
        do
        {
            fflush(stdin);

            printf("\n\n\t\t\tdonnez la date dont vous voulez supprimer jj/mm/aaaa\n");
            scanf("%2d/%2d/%d",&d->jj,&d->mm,&d->aa);

        }
        while(!verifdate(d));
        NOEUD p;
        int h=1,i;
        p=g[0]->tete;
        while((p!=NULL)&&!(((d->jj)==(p->elt->d->jj))&&((d->mm)==(p->elt->d->mm))&&((d->aa)==(p->elt->d->aa))))
        {
            h++;
            p=p->suivant;
        }
        if(p==NULL)
        {
            Color(4,0);
            printf("on na pas de stats pour cette date\n");
            Color(15,0);
            sleep(3);
        }
        else
        {
            for(i=0; i<24; i++)
                supprimer(g[i],h);
        }
        //free(d);

        goto start;


    }
    break;
    case '5' :
    {
        system("cls");
        int i,h;
        NOEUD p,q,n;
        char govtri[24][50]= {"ARIANA","BEJA","BEN AROUS","BIZERTE","GABES","GAFSA","JENDOUBA","KAIROUAN","KASSERINE","KEBILI","LA MANOUBA","LE KEF","MAHDIA","MEDNIN","MONASTIR","NABEUL","SFAX","SIDI BOUZID","SILIANA","SOUSSE","TATAOUINE","TOZEUR","TUNIS","ZAGHOUAN"};
        int tri;
        int ord;
        LISTE LR=listeCreer();
        ELEMENT e=elementCreer();
        ELEMENT aux=elementCreer();
        DAT da=(DAT)malloc(sizeof(date));
        system("cls");
        Color(15,3);
        printf("\n\n\n\t\t\t 1-Cas positifs\n\t\t\t\t 2- gu%crisons\n\t\t\t\t\t 3- deces\n\t\t\t\t\t\t 4-vaccin%cs\n",130,130);
        Color(15,0);
        printf("\n\n\t\t\t saisissez les cl%cs de tries dans lordre qui vous convient :",130);
        fflush(stdin);
        scanf("%i",&tri);
        do
        {
            system("cls");
              printf("______________________________________________________________________________\n\n");
              printf("     ------- VEUILLEZ CHOISIR L'ORDRE DE TRI QUI VOUS CONVIENT--------\n\n\n");
              printf("                 1-ORDRE CROISSANT \n");
              printf("                 2-ORDRE DECROISSANT  \n\n");
              printf("______________________________________________________________________________\n\n");

            scanf("%i",&ord);
        }
        while((ord<1)||(ord>2));
        do
        {
            fflush(stdin);
            printf("donnez la date sous format jj/mm/aaaa\n");
            scanf("%2i/%2i/%i\n",&(da->jj),&(da->mm),&(da->aa));
        }
        while(!verifdate(da));

        h=1;
        p=g[0]->tete;
        while((p!=NULL)&&!(((da->jj)==(p->elt->d->jj))&&((da->mm)==(p->elt->d->mm))&&((da->aa)==(p->elt->d->aa))))
        {
            h++;
            p=p->suivant;
        }
        if(p==NULL)
        {
            system("cls");
            Color(4,0);
            printf("\n\t\t\ton na pas de statistiques pour cette date\n");
            sleep(4);
            Color(14,0);
            goto start;
        }
        else
        {
            fflush(stdin);
            for(i=0; i<24; i++)
            {
                fflush(stdin);
                e=recuperer(g[i],h);
                inserer(LR,e,i+1);
            }
            switch(tri)
            {
            case 1234 :
            {
                if(ord==2)
                {

                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->cas_p)>(p->elt->cas_p))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)>(p->elt->guerison)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)>(p->elt->deces)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)>(p->elt->nbv))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->cas_p)<(p->elt->cas_p))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)<(p->elt->guerison)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)<(p->elt->deces)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)<(p->elt->nbv))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }

                }
            } //end case
            break;
            case 1243 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->cas_p)>(p->elt->cas_p))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)>(p->elt->guerison)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)>(p->elt->nbv)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)>(p->elt->deces))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->cas_p)<(p->elt->cas_p))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)<(p->elt->guerison)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)<(p->elt->nbv)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)<(p->elt->deces))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 1324 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->cas_p)>(p->elt->cas_p))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)>(p->elt->deces)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)>(p->elt->guerison)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)>(p->elt->nbv))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->cas_p)<(p->elt->cas_p))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)<(p->elt->deces)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)<(p->elt->guerison)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)<(p->elt->nbv))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 1342 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->cas_p)>(p->elt->cas_p))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)>(p->elt->deces)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)>(p->elt->nbv)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)>(p->elt->guerison))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->cas_p)<(p->elt->cas_p))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)<(p->elt->deces)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)<(p->elt->nbv)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)<(p->elt->guerison))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 1423 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->cas_p)>(p->elt->cas_p))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)>(p->elt->nbv)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)>(p->elt->guerison)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)>(p->elt->deces))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->cas_p)<(p->elt->cas_p))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)<(p->elt->nbv)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)<(p->elt->guerison)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)<(p->elt->deces))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;

            case 1432 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->cas_p)>(p->elt->cas_p))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)>(p->elt->nbv)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)>(p->elt->deces)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)>(p->elt->guerison))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->cas_p)<(p->elt->cas_p))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)<(p->elt->nbv)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)<(p->elt->deces)))||(((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)<(p->elt->guerison))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;

            case 2134 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->guerison)>(p->elt->guerison))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)>(p->elt->cas_p)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)>(p->elt->deces)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)>(p->elt->nbv))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->guerison)<(p->elt->guerison))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)<(p->elt->cas_p)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)<(p->elt->deces)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)<(p->elt->nbv))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 2143 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->guerison)>(p->elt->guerison))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)>(p->elt->cas_p)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)>(p->elt->nbv)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)>(p->elt->deces))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->guerison)<(p->elt->guerison))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)<(p->elt->cas_p)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)<(p->elt->nbv)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)<(p->elt->deces))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 2314 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->guerison)>(p->elt->guerison))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)>(p->elt->deces)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)>(p->elt->cas_p)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)>(p->elt->nbv))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->guerison)<(p->elt->guerison))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)<(p->elt->deces)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)<(p->elt->cas_p)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)<(p->elt->nbv))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;

            case 2341 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->guerison)>(p->elt->guerison))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)>(p->elt->deces)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)>(p->elt->nbv)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)>(p->elt->cas_p))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->guerison)<(p->elt->guerison))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)<(p->elt->deces)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)<(p->elt->nbv)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)<(p->elt->cas_p))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 2413 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->guerison)>(p->elt->guerison))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)>(p->elt->nbv)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)>(p->elt->cas_p)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)>(p->elt->deces))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->guerison)<(p->elt->guerison))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)<(p->elt->nbv)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)<(p->elt->cas_p)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)<(p->elt->deces))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;

            case 2431 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->guerison)>(p->elt->guerison))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)>(p->elt->nbv)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)>(p->elt->deces)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)>(p->elt->cas_p))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->guerison)<(p->elt->guerison))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)<(p->elt->nbv)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)<(p->elt->deces)))||(((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)<(p->elt->cas_p))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 3124 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->deces)>(p->elt->deces))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)>(p->elt->cas_p)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)>(p->elt->guerison)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)>(p->elt->nbv))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->deces)<(p->elt->deces))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)<(p->elt->cas_p)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)<(p->elt->guerison)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)<(p->elt->nbv))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 3142 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->deces)>(p->elt->deces))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)>(p->elt->cas_p)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)>(p->elt->nbv)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)>(p->elt->guerison))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->deces)<(p->elt->deces))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)<(p->elt->cas_p)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)<(p->elt->nbv)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)<(p->elt->guerison))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 3214 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->deces)>(p->elt->deces))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)>(p->elt->guerison)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)>(p->elt->cas_p)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)>(p->elt->nbv))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->deces)<(p->elt->deces))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)<(p->elt->guerison)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)<(p->elt->cas_p)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->nbv)<(p->elt->nbv))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 3241 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->deces)>(p->elt->deces))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)>(p->elt->guerison)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)>(p->elt->nbv)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)>(p->elt->cas_p))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->deces)<(p->elt->deces))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)<(p->elt->guerison)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)<(p->elt->nbv)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)<(p->elt->cas_p))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 3412 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->deces)>(p->elt->deces))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)>(p->elt->nbv)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)>(p->elt->cas_p)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)>(p->elt->guerison))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->deces)<(p->elt->deces))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)<(p->elt->nbv)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)<(p->elt->cas_p)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)<(p->elt->guerison))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 3421 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->deces)>(p->elt->deces))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)>(p->elt->nbv)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)>(p->elt->guerison)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)>(p->elt->cas_p))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->deces)<(p->elt->deces))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)<(p->elt->nbv)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)<(p->elt->guerison)))||(((q->elt->deces)==(p->elt->deces))&&((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)<(p->elt->cas_p))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 4123 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->nbv)>(p->elt->nbv))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)>(p->elt->cas_p)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)>(p->elt->guerison)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)>(p->elt->deces))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->nbv)<(p->elt->nbv))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)<(p->elt->cas_p)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)<(p->elt->guerison)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)<(p->elt->deces))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 4132 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->nbv)>(p->elt->nbv))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)>(p->elt->cas_p)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)>(p->elt->deces)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)>(p->elt->guerison))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->nbv)<(p->elt->nbv))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)<(p->elt->cas_p)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)<(p->elt->deces)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)<(p->elt->guerison))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 4213 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->nbv)>(p->elt->nbv))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)>(p->elt->guerison)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)>(p->elt->cas_p)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)>(p->elt->deces))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->nbv)<(p->elt->nbv))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)<(p->elt->guerison)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)<(p->elt->cas_p)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->deces)<(p->elt->deces))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 4231 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->nbv)>(p->elt->nbv))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)>(p->elt->guerison)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)>(p->elt->deces)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)>(p->elt->cas_p))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->nbv)<(p->elt->nbv))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)<(p->elt->guerison)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)<(p->elt->deces)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)<(p->elt->cas_p))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 4312 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->nbv)>(p->elt->nbv))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)>(p->elt->deces)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)>(p->elt->cas_p)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)>(p->elt->guerison))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->nbv)<(p->elt->nbv))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)<(p->elt->deces)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)<(p->elt->cas_p)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->cas_p)==(p->elt->cas_p))&&((q->elt->guerison)<(p->elt->guerison))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            case 4321 :
            {
                if (ord==2)
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->nbv)>(p->elt->nbv))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)>(p->elt->deces)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)>(p->elt->guerison)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)>(p->elt->cas_p))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }
                else
                {
                    i=0;
                    h=0;
                    char gv[30];
                    for(p=LR->tete; p->suivant!=NULL; p=p->suivant)
                    {
                        h=i+1;
                        for(q=p->suivant; q!=NULL; q=q->suivant)
                        {
                            if(((q->elt->nbv)<(p->elt->nbv))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)<(p->elt->deces)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)<(p->elt->guerison)))||(((q->elt->nbv)==(p->elt->nbv))&&((q->elt->deces)==(p->elt->deces))&&((q->elt->guerison)==(p->elt->guerison))&&((q->elt->cas_p)<(p->elt->cas_p))))
                            {

                                //fflush(stdin);
                                elementCopier(&aux,q->elt);
                                elementCopier(&q->elt,p->elt);
                                elementCopier(&p->elt,aux);
                                fflush(stdin);
                                strcpy(gv,govtri[i]);
                                strcpy(govtri[i],govtri[h]);
                                strcpy(govtri[h],gv);

                            }
                            h++;
                        }
                        i++;
                    }
                }

            }
            break;
            default :
            {
                system("cls");
                Color(4,0);
                printf("\n\n\t\t\tchoix incorrect des cl%cs de tri\n",130);
                sleep(4);
                Color(15,0);
                goto start;

            }

            }// end switch

            system("cls");

            /*listeAfficher(LR);
            for(i=0; i<24; i++)
            {
                printf("%s\n",govtri[i]);
            }*/
            //start
            system("cls");
            gotoxy(1,1);
            Color(11,0);
            printf("*******************************STATS tri%ces*****************************",130);
            gotoxy(2,2);
            printf(" GOUVERNORAT    Cas positifs     Guerisons      Deces    Nombre de vaccines");
            Color(15,0);
            j=4;
            p=LR->tete;
            i=0;
            while(p!=NULL)
            {
                gotoxy(3,j);
                printf("%s",govtri[i]);
                gotoxy(22,j);
                if(p->elt->cas_p>=100)
                    Color(4,0);
                else if(p->elt->cas_p>=50)
                    Color(14,0);
                else
                    Color(10,0);
                printf("%d",p->elt->cas_p);
                Color(15,0);
                gotoxy(35,j);
                Color(10,0);
                printf("%d",p->elt->guerison);
                Color(15,0);
                gotoxy(49,j);
                if(p->elt->deces>=100)
                    Color(4,0);
                else
                    Color(14,0);
                printf("%d",p->elt->deces);
                gotoxy(65,j);
                Color(10,0);
                printf("%d",p->elt->nbv);
                Color(15,0);
                printf("\n\n");
                p=p->suivant;
                i++;
                j++;
            }
            //end
            //listeDetruire(LR);
             //elementDetruire(e);
            // elementDetruire(aux);
            //free(da);
            printf("\n\n\n tapez sur n'importe quel bouton pour revenir au menu\n");
            system("pause>null");
            goto start;

        }
    }
    break;
    case '6' :
    {

        FILE*fichier = NULL;
        char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
        char ch[100];
        NOEUD p;
        //ELEMENT ok=elementCreer();
        int i=0,l=1;
        int j,m,a,cas,gue,dec,vac;

        //debut
        printf ("\n\n\tdonnez le nom du fichier et n'oubliez pas d'ajouter lextension .txt a la fin\n");
        fflush(stdin);
        gets(ch);
        fichier=fopen(ch,"r");
        if(fopen(ch,"r"))
        {
            while(!feof(fichier))

            {
                ELEMENT ok=elementCreer();
                fflush(stdin);
                if (i==24)
                {
                    i=0;
                    //l++;
                }


                fgets(chaine,TAILLE_MAX,fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"
                sscanf(chaine,"%d %d %d %d %d %d %d\n",&j,&m,&a,&cas,&gue,&dec,&vac);
                // printf("%s", chaine); // On affiche la chaîne
                fflush(stdin);
                ok->d->jj=j;
                ok->d->mm=m;
                ok->d->aa=a;
                ok->cas_p=cas;
                ok->guerison=gue;
                ok->deces=dec;
                ok->nbv=vac;
                l=1;
                p=g[i]->tete;
                while((p!=NULL)&&((p->elt->d->aa)<(ok->d->aa)||(((p->elt->d->aa)==(ok->d->aa))&&((p->elt->d->mm)<(ok->d->mm)))||((p->elt->d->aa)==(ok->d->aa))&&((p->elt->d->mm)==(ok->d->mm)&&(p->elt->d->jj)<(ok->d->jj))))
                 {

                 l++;
                 p=p->suivant;
                 }
                if(!cherchedate(g[i],ok->d)) //si une date existe deja on linsere pas
                {


                inserer(g[i],ok,l);
                //elementDetruire(ok);
                i++;
                }
            }
            fflush(stdin);
            fclose(fichier);
            system("cls");
            Color(10,0);

            printf ( "\n\n\n\t\t**********la lecture du ficher est effectee avec succes *********** \n"   ) ;
            Color(15,0);
        }
        else
        {
            system("cls");
            Color(4,0);
            printf("\n\t\t\terreur douverture du fichier\n");
            Color(15,0);

        }

        printf("\n\n\n\t\t Tapez n importe ou pour revenir au menu principal\n");
        system("pause>NULL");
        system("cls") ;
        // sleep(4);
        goto start;


    }
    break;
    case '7' :
    {
        fflush(stdin);
        system("cls");
        int j;
        //for( j=0; j<24; j++)
           // listeDetruire(g[j]);
        Color(14,0);
        box();
        gotoxy(16,6);
        printf("\tSTATISTIQUE COVID");
        gotoxy(16,7);
        printf("\tPROJET ASD 2 EN C");
        gotoxy(16,8);
        printf("\tREALISE PAR :");
        gotoxy(16,9);
        printf("\tNIDHAL TIJANI ");
        gotoxy(16,10);
        printf("******************************************");
        gotoxy(16,12);
        printf("*******************************************");
        gotoxy(16,13);
        printf("*******************************************");
        gotoxy(16,15);
        printf("********************************************");
        gotoxy(10,19);
        printf("DANS 3s VOUS ALLEZ QUITTER LAPPLICATION...........>");
        Color(15,0);
//flushall();
        Sleep(3000);
        exit(0);
    }
    break;
    default:
    {
        system("cls");
        printf("choix incorrect\n");
        printf("\n\n\n tapez sur n'importe quel bouton pour revenir au menu\n");
        system("pause>null");
        goto start;
    }
    }





    return 0;



}

void Color(int couleurDuTexte,int couleurDeFond) //procédure pour les couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}//10 vert 4 rouge 11 bleu 14 jaune shwaya (15,0) couleur normale
int datecomparer(DAT d, DAT d1)
{
    if(d->aa>d1->aa)
        return 1;
    else if((d->aa==d1->aa)&&(d->mm>d1->mm))
        return 1;
    else if ((d->aa==d1->aa)&&(d->mm==d1->mm)&&(d->jj>d1->jj))
        return 1;
    else if ((d->aa==d1->aa)&&(d->mm==d1->aa)&&(d->jj==d1->jj))
        return 0;
    else
        return -1;
}

int verifdate (DAT date)
{
    time_t now;
    int jour,mois,an;
    time(&now);

    struct tm *local = localtime(&now);
    jour = local->tm_mday;
    mois = local->tm_mon + 1;
    an = local->tm_year + 1900;
    if((date->aa<2020)||((date->aa==2020)&&(date->mm<3)||((date->aa==2020)&&(date->mm==3)&&(date->jj<2))))
    {
        printf("\t\t\tCher utilisateur le premier cas de covid detecte en Tunisie etait le 2/3/2020\n");
        return 0;

    }
    else
    {


        if((date->aa>an)||((date->aa==an)&&(date->mm>mois))||((date->aa==an)&&(date->mm==mois)&&(date->jj>jour)))
        {
            Color(4,0);
            printf("\n\t\t\tCher utilisateur vous ne pouvez pas saisir une date superieure a la date actuelle\n ");
            Color(15,0);
            return 0;
        }
        else
        {
            //check year
            if((date->aa>=1900)&&(date->aa<=9999))
            {
                //check month
                if((date->mm>=1)&&(date->mm<=12))
                {
                    //check days
                    if(((date->jj>=1)&&(date->jj<=31))&& ((date->mm==1)||(date->mm==3)||(date->mm==5)||(date->mm==7)||(date->mm==8)||(date->mm==10)||(date->mm==12)))
                        return 1;
                    else if(((date->jj>=1)&&(date->jj<=30)) && ((date->mm==4)||(date->mm==6)||(date->mm==9)||(date->mm==11)))
                        return 1;
                    else if((date->jj==29)&& (date->mm==2) && ((date->aa%400==0)||((date->aa%4==0)&&(date->aa%100!=0))))
                        return 1;
                    else if(((date->jj>=1)&&(date->jj<=28)) && (date->mm==2))
                        return 1;
                    else
                    {
                        Color(4,0);
                        printf("\n\t\t\tDate invalide!\n");
                        Color(15,0);
                        return 0;
                    }
                }
                else
                {
                    Color(4,0);
                    printf("\n\t\t\tDate invalide!\n");
                    Color(15,0);
                    return 0;
                }
            }
            else
            {
                Color(4,0);
                printf("\n\t\t\tDate invalide!\n");
                Color(15,0);
                return 0;
            }
        }
    }



}
int cherchedate(LISTE L,DAT da)
{
    int i=1;
    NOEUD p;
    p=L->tete ;

    while((p!=NULL)&&!(((da->jj)==(p->elt->d->jj))&&((da->mm)==(p->elt->d->mm))&&((da->aa)==(p->elt->d->aa))))
    {
        i++;
        p = p->suivant;
    }
    if(p==NULL)
        return 0;
    else
        return i;
}





void statsgover(LISTE L, char x[])
{
    NOEUD p;
    int s=0,moycas,moyguer,moydec,moyvac;
    p=L->tete;





    s=0;

    while(p!=NULL)
    {
        s=s+(p->elt->cas_p);
        p=p->suivant;
    }
    moycas=s/listeTaille(L);



    p=L->tete;
    s=0;

    while(p!=NULL)
    {
        s=s+(p->elt->guerison);
        p=p->suivant;
    }
    moyguer=s/listeTaille(L);




    p=L->tete;
    s=0;

    while(p!=NULL)
    {
        s=s+(p->elt->deces);
        p=p->suivant;
    }
    moydec=s/listeTaille(L);

    p=L->tete;
    s=0;
    while(p!=NULL)
    {
        s=s+(p->elt->nbv);
        p=p->suivant;
    }
    moyvac=s/listeTaille(L);
//10 vert 4 rouge 11 bleu 14 jaune shwaya (15,0) couleur normale
    box();
    lbox();
    gotoxy(30,8);
    printf("\t\t%s\n",x);
    gotoxy(39,13);
    printf("moyenne de nouveau cas positifs :");
    if(moycas>=100)
        Color(4,0);
    else if(moycas>=50)
        Color(14,0);
    else
        Color(10,0);
    printf("%i",moycas);
    Color(15,0);
    gotoxy(8,18);
    printf("moyenne de guerisons : ");

    Color(10,0);

    printf("\t%i",moyguer);
    Color(15,0);
    gotoxy(39,18);
    printf("moyenne de deces : ");
    if(moydec>=100)
        Color(4,0);
    else
        Color(14,0);

    printf("%i",moydec);
    Color(15,0);
    gotoxy(8,23);
    printf("moyenne de vaccination : ");

    Color(10,0);
    printf("%i",moyvac);
    Color(15,0);







}

int datecopier(DAT*d1,DAT d2)
{
    (*d1)->jj=d2->jj;
    (*d1)->mm=d2->mm;
    (*d1)->aa=d2->aa;
}






void nomgover()
{
    Color(15,3);

    printf("1-Ariana\t\t\t2-B%cja\t\t\t3-Ben Arous\t\t\t4-Bizerte\n\n\n5-Gabes\t\t\t\t6-Gafsa\t\t\t7-Jendouba\t\t\t8-Kairouan\n\n\n9-Kasserine\t\t\t10-Kebili\t\t11-La Manouba\t\t\t12-Le Kef\n\n\n13-Mahdia\t\t\t14-Mednin\t\t15-Monastir\t\t\t16-Nabeul\n\n\n17-Sfax\t\t\t\t18-Sidi Bouzid\t\t19-Siliana\t\t\t20-Sousse\n\n\n21-Tataouine\t\t\t22-Tozeur\t\t23-Tunis\t\t\t24-Zaghouan\n\n\n",130);

}

void lbox()
{
    gotoxy(25,6);
    printf("%c",201);
    for(int i=26; i<55; i++)
    {
        gotoxy(i,6);
        printf("%c",205);
    }
    gotoxy(55,6);
    printf("%c",187);
    gotoxy(25,6);
    for(int i=6; i<8; i++)
    {
        gotoxy(25,i+1);
        printf("%c",186);
    }
    gotoxy(25,9);
    printf("%c",200);
    for(int i=26; i<55; i++)
    {
        gotoxy(i,9);
        printf("%c",205);
    }
    gotoxy(55,9);
    printf("%c",188);
    gotoxy(55,6);
    for(int i=6; i<8; i++)
    {
        gotoxy(55,i+1);
        printf("%c",186);
    }

}

void box()
{
    for(int i=3; i<=79; i++) 	//This 'FOR' loop will print a combination of
    {
        gotoxy(i,3);    //the 79th column is reached.
        printf("%c",219);
        gotoxy(78,45);
        printf("%c",219);
        gotoxy(i,45);
        printf("%c",219);
    }

    for(int i=3; i<=45; i++)    //This 'FOR' loop will print asterisks 'I'
    {
        //vertically till the 3th row is reached.
        gotoxy(3,i);
        printf("%c",219);
        gotoxy(79,i);
        printf("%c",219);
    }
}
