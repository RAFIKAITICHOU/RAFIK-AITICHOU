                                        /*      AIT ICHOU RAFIK INFORMATIQUE S4 2023/2024     */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char data;
    struct node *p_next;
    struct node *p_prev;
} typeCellule;

typedef struct {
    int taille;
    typeCellule *p_deb;
    typeCellule *p_fin;
} Dlist;
/************************************************************/
void initialiser(Dlist *p) {
    p->taille = 0;
    p->p_deb = p->p_fin = NULL;
}
/************************************************************/
void inséreVide(Dlist *p, char v) {
    typeCellule *b = (typeCellule *)malloc(sizeof(typeCellule));
    b->p_prev = b->p_next = NULL;
    (b->data=v);
    p->p_deb = b;
    p->p_fin = b;
    p->taille = 1;
}
/************************************************************/
void inséreDebut(Dlist *p, char v) {
    typeCellule *b = (typeCellule *)malloc(sizeof(typeCellule));
    b->p_prev = b->p_next = NULL;
    (b->data=v);
    if (p->p_deb == NULL) {
        p->p_deb = b;
        p->p_fin = b;
        p->taille=1;
    } else {
        b->p_next = p->p_deb;
        p->p_deb->p_prev = b;
        p->p_deb = b;
        p->taille++;
    }
}
/************************************************************/
void inséreAlaFin(Dlist *p, char v) {
    typeCellule *b = (typeCellule *)malloc(sizeof(typeCellule));
    b->p_prev = b->p_next = NULL;
    (b->data=v);
    if (p->p_deb == NULL) {
        p->p_deb = b;
        p->p_fin = b;
        p->taille=1;
    } else {
        b->p_prev = p->p_fin;
        p->p_fin->p_next = b;
        p->p_fin = b;
        p->taille++;
    }
}
/************************************************************/
void affichage(Dlist *p) {
    typeCellule *tmp;
    tmp = p->p_deb;
    printf("Debut---");
    while (tmp != NULL) {
        printf("| %c |", tmp->data);
        tmp = tmp->p_next;
    }
    printf("---Fin");
    printf("\n");
    printf("la taille est %d\n", p->taille);
}

/************************************************************/
void concat(Dlist *p1,Dlist *p2){
    if(p1->p_deb == NULL){
        p1->p_deb = p2->p_deb;
        p1->p_fin = p2->p_fin;
        p1->taille = p2->taille;
    }
    else{
        p1->p_fin->p_next = p2->p_deb;
        p2->p_deb->p_prev = p1->p_fin;
        p2->p_deb = p1->p_deb;
        p1->p_fin=p2->p_fin;
        p1->taille += p2->taille;
    }
    free(p2);
}

int main() {
    
    Dlist *liste1 = (Dlist *)malloc(sizeof(Dlist));
    Dlist *liste2 = (Dlist *)malloc(sizeof(Dlist));
    /************************************************************/
    initialiser(liste1);
    inséreVide(liste1,  'E');
    inséreAlaFin(liste1, 'X');
    inséreAlaFin(liste1, 'A');
    inséreAlaFin(liste1, 'M');
    inséreAlaFin(liste1, 'E');
    inséreAlaFin(liste1, 'N');
    affichage(liste1);
    /************************************************************/
    initialiser(liste2);
    inséreVide(liste2, 'A');
    inséreAlaFin(liste2, 'L');
    inséreAlaFin(liste2, 'G');
    inséreAlaFin(liste2, 'O');
    affichage(liste2);
    /************************************************************/
    printf("////////////////////////////////////////\n");
    concat(liste1,liste2);
    affichage(liste1);
    affichage(liste2);
    /************************************************************/
    return 0;
}
