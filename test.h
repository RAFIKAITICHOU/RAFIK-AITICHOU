#ifndef H_test
#define H_test
#include<stdio.h>
#include<stdlib.h>
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
    f->dernier=NULL;
    f->premier=NULL;
}
int estvide(file *f){
    if(f->premier==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
void enfiler(file *f){
    etudiant e;
    Noeud *newetd=(Noeud*)malloc(sizeof(Noeud));
    printf("Entrez l´apogee:");
    scanf("%d",&(e.apogee));
    printf("enterz le nom: \n");
    scanf("%s",e.nom);
    newetd->data=e;
    if(f->premier==NULL){
        f->dernier=newetd;
        f->premier=newetd;
    }
    else{
        f->dernier=newetd;
    }
}
void defiler (file *f,etudiant e){
    Noeud *aide=f->premier;
    aide->data=e;
    f->premier=f->premier->next;
    free(aide);
}
void affich(file *f){
    if(f==NULL || f->premier==NULL){
        printf("La file est vide!!");
    }
    Noeud *tmp=f->premier;
    while(tmp!=NULL){
        printf("%d %s\n",tmp->data.apogee,tmp->data.nom);
        tmp=tmp->next;
    }
    
}

#endif 