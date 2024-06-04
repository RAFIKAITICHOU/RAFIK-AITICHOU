#ifndef H_test
#define H_test
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct etudiant{
    int apogee;
    char nom[20];
}etudiant;
typedef struct Noeud{
    etudiant data;
    struct  Noeud *next;
}Noeud;
typedef struct file{
    Noeud *premier;
    Noeud *dernier;
}file;
void intia(file *f){
    f=(file*)malloc(sizeof(file));
    f->dernier=NULL;
    f->premier=NULL;
}
void estvide(file *f){
    if(f->premier==NULL){
        printf("La file est vide!!!");
    }
    else{
        printf("La file non vide");
    }
}
void enfiler(file *f){
    etudiant e;
    Noeud *newetd=(Noeud*)malloc(sizeof(Noeud));
    printf("Entrez l´apogee:");
    scanf("%d",&(e.apogee));
    printf("enterz le nom: \n");
    scanf("%s",e.nom);
    newetd->data.apogee=e.apogee;
    strcpy(newetd->data.nom,e.nom);
    if(f->premier==NULL){
        f->dernier=newetd;
        f->premier=newetd;
    }
    else{
        
    }
}


#endif 