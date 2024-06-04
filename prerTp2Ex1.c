#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    int matricule;
    char nom[20];
    float taille;
}Data;
typedef struct {
    Data element;
    struct individu *psuivante;
}individu;

individu * ajouterEnTete(individu *tete,Data ind){
    individu *B,*temp;
    B=(individu*)malloc(sizeof(individu));
    B->element.matricule=ind.matricule;
    strcpy(B->element.nom,ind.nom);
    B->element.taille=ind.taille;
    B->psuivante=tete;
    tete=B;
    return tete;
}
int existe(individu *tete,int mat){
    individu *temp;
    temp=tete;
    while(temp!=0){
        if(temp->element.matricule==mat){
            return 1;
        }
        else{
            return 0;
        }
        temp=temp->psuivante;
    }

}
float moyenneTaille(individu *tete){
    individu *temp;
    float s=0;
    int nbr=0;
    if(tete==NULL){
        printf("\nla liste est vide!!\n");
        return 0;
    }
    else{
        temp=tete;
        while(temp!=NULL){
            s=s+temp->element.taille;
            nbr++;
            temp=temp->psuivante;
        }

        return s/nbr;
    }
}

void affich(individu *tete){
    individu *temp;
    if(tete==NULL){
        printf("la liste est vide");
    }
    else{
    temp=tete;
    while (temp!=NULL){
        printf("||--> %d %s %.2f ||\n",temp->element.matricule,temp->element.nom,temp->element.taille);
        temp=temp->psuivante;
    }
    }
}
int nombindivu(individu *tete){
    int nb=0;
    individu *temp;
    temp=tete;
    while(temp!=NULL){
        nb++;
        temp=temp->psuivante;
    }
    return nb;
}
void main(){
    individu *liste;
    Data n;
    liste=NULL;
    int i,nb,nbrr,cher;
    char rep[5];
    printf("Veuillez entrer nombre des individus\n");
    scanf("%d",&nb);
    for(i=0;i<nb;i++){
        printf("entrer les info pour individu num %d\n",i+1);
        n.matricule=i+1;
        printf("Nom:\n");
        scanf("%s",n.nom);
        printf("La taille:\n");
        scanf("%f",&(n.taille));
        liste=ajouterEnTete(liste,n);
    }
    affich(liste);
    printf("vous pouvez ajouter un autre individu (oui ou non):\n");
    scanf("%s",rep);
    if(strcmp(rep,"oui")==0){
        printf("veuillez entrer le nombre des individus:\n");
        scanf("%d",&nbrr);
        nbrr=nbrr+nb;
        for(i=nb;i<nbrr;i++){
            // n=(sizeof(Data));
            printf("entrer les info pour l´individu num %d:\n",i+1);
            n.matricule=i+1;
            printf("nom:\n");
            scanf("%s",n.nom);
            printf("aille:\n");
            scanf("%f",&(n.taille));
            liste=ajouterEnTete(liste,n);
        }
        affich(liste);
    }
    printf("Veuillez entrer le matricule a recherche:\n");
    scanf("%d",&cher);
    if (existe(liste,cher)==1){
        printf("%d existe\n",cher);
    }
    else{
        printf("%d n´existe pas\n",cher);
    }
    printf("nombre des indvidu est: %d\n",nombindivu(liste));
    printf("la moyenne des taille est %.2f\n",moyenneTaille(liste));

}
