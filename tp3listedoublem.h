#ifndef H_tp3listedoublem
#define H_tp3listedoublem
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char nom[20];
    float moyenne;
    struct Etudiant * suivante;
    struct Etudiant * prev;
}Etudiant;
typedef struct{
    Etudiant *premier;
    Etudiant * dernier;
}Liste;
void creerListe(Liste *newEtudiant){
    newEtudiant->dernier=newEtudiant->premier=NULL; 
}
void insererDébut(Liste *p, char *n, float m){
    Etudiant *b=(Etudiant*)malloc(sizeof(Etudiant));
    b->suivante=b->prev=NULL;
    b->moyenne=m;
    strcpy(b->nom,n);
    if(p->premier==NULL){  //insree vide
        p->premier=b;
        p->dernier=b;
    }
    else{
        b->suivante=p->premier;
        p->premier->prev=b;
        p->premier=b;
    }
}
void insererFin(Liste *p, char *n, float m){
    Etudiant *b=(Etudiant*)malloc(sizeof(Etudiant));
    b->suivante=b->prev=NULL;
    b->moyenne=m;
    strcpy(b->nom,n);   
    if(p->premier==NULL){  //insree vide
        p->premier=b;
        p->dernier=b;
    }else{
        b->prev=p->dernier;
        
        p->dernier=b;
    }
}

#endif