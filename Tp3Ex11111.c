
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char nom[20];
    int nombre;
    float prix;
    struct stock *psuivent;
}stock;
stock * acheter(stock *tete,char nom[20],int nombre,float prix){
    stock *nouveau;
    nouveau=(stock*)malloc(sizeof(stock));
    strcpy(nouveau->nom,nom);
    nouveau->nombre=nombre;
    nouveau->prix=prix;
    nouveau->psuivent=tete;
    tete=nouveau;
    return tete;
}
void afficherStock(stock *tete){
    stock *temp;
    if(tete==NULL){
        printf("le stock est vide!!\n");
        exit(1);//return;
    }
    else{
        temp=tete;
        while(temp!=NULL){
            printf("|%s  %d  %.2f DH|---",temp->nom,temp->nombre,temp->prix);
            temp=temp->psuivent;
        }
    }
}
stock * vendre(stock *tete,int nombre){
    stock * temp;
    temp=tete;
    while(temp!=0){
        temp->nombre =temp->nombre - nombre;
        temp=temp->psuivent;
    }

    return tete;
}
stock * supprimeLeStock(stock *tete){
    stock *temp,*p;
    if(tete->nombre==NULL&&tete->psuivent==NULL){
        free(tete);
        tete=NULL;
    }
    else{
        temp=tete;
        while(temp!=NULL && temp->nombre!=0){
            temp=temp->psuivent;
        }
        if(temp!=NULL){
            p=tete;
            while(p!=NULL && p->psuivent!=temp){
                p=p->psuivent;
            }
            if(p!=NULL){
                p->psuivent=temp->psuivent;
                free(temp);
            }
        }
    }
    return tete;
}
float prixStock(stock *tete){
    stock *temp;
    float prixtt=0;
    while(temp!=NULL){
        prixtt=prixtt+temp->prix*temp->nombre;
        temp=temp->psuivent;
    }
    return prixtt;
}
int main(){
    stock *Stock=NULL;
    stock *pr=NULL;
    int i,nbr,nbvendu;
    pr=(stock*)malloc(sizeof(stock));
    printf("veuillez entrer le nombre du médicament:\n");
    scanf("%d", &nbr);
    for(i=0;i<nbr;i++){
        printf("entrer les info pour le produit num %d:\n", i + 1);
        printf("Nom: ");
        scanf("%s",pr->nom);
        printf("\nnombre Boîte: ");
        scanf("%d",&(pr->nombre));
        printf("\nPrix: ");
        scanf("%f",&(pr->prix));
        Stock=acheter(Stock,pr->nom,pr->nombre,pr->prix);   
    }
    afficherStock(Stock);
    printf("\nDonner le nombre des boites vendue par chaque médicament suivante:");
    afficherStock(Stock);
    for(i=0;i<nbr;i++){
        printf("\nPour médicament num %d\n",i+1);
        scanf("%d",&nbvendu);
        Stock=vendre(Stock,nbvendu);
    }
    supprimeLeStock(Stock);
    afficherStock(Stock);
    printf("le prix total des médicaments dans le stock est: %.2f\n",prixStock(Stock));
    return 0;
}