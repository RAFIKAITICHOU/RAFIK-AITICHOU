#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct individus{
    int matricule;
    char noms[20];
    float taille;
    struct individus *psuivant;
}individus;
float moyenne(individus *tete){
    float somme,moy;
    int nbri=0;
    individus *temp;
    if(tete!=0){
    temp=tete;
    somme=0;
    while(temp!=NULL){
        somme=somme+temp->taille;
        nbri++;
        temp=temp->psuivant;
    }
   
    moy=somme/nbri;
    return moy;
    }
    else{
        return 0;
    }
}
int nombreindiv(individus *tete){
    int nb=0;
    individus *temp;
    temp=tete;
    while(temp!=NULL){
        nb++;
       temp=temp->psuivant;
    }
    return nb;
}
void existe(individus *tete,int mat){
    individus *temp=tete;
    if(tete==NULL){
        printf("la liste est vide");
    }
    else{
        while(temp!=NULL){
            if(temp->matricule==mat){
                printf("l´element %d existe\n",mat);
            }
            else{
              printf("%d n´existe pas\n",mat);
            }
            temp=temp->psuivant;
        }

    }
}
individus * ajouterIndividu(individus *tete,int mat,char nom[20],float tail){
    individus *B,*temp;
    B=(individus *) malloc(sizeof(individus));
    B->matricule=mat;
    for(int i=0;i<20;i++){//strcpy(noms,nom);
        B->noms[i]=nom[i];
    }
    B->taille=tail;
    B->psuivant=NULL;
    if(tete==NULL){
        tete=B;
    }
    else{
        temp=tete;
        while(temp->psuivant!=NULL){
            temp=temp->psuivant;
        }
        temp->psuivant=B;
    }
    return tete;
}
individus * ajouteraudebut(individus *tete,int nomb,int mat,char nom[20],float tail){
    individus *B;
    B=(individus *) malloc(nomb * sizeof(individus));
    B->matricule=mat;
    for(int i=0;i<20;i++){//strcpy(noms,nom);
        B->noms[i]=nom[i];
    }
    B->taille=tail;
    B->psuivant=tete;
    tete=B;
    return tete;
}
void affich(individus *tete){
    individus *temp;
    temp=tete;
    if(tete==NULL){
        printf("la liste est vide");
    }
    else{
        while(temp!=NULL){
            printf("[ %d %s %f ]\n",temp->matricule,temp->noms,temp->taille);
            temp=temp->psuivant;
        }
    }
}
void main(){
    individus *lis=NULL,*n;
    int i,nbr,nbrr,cher;
    char rep[6];;
    printf("veuillez entrer le nombre des individus:\n");
    scanf("%d",&nbr);
    for(i=0;i<nbr;i++){
        printf("entrer les info pour l´individu num %d:\n",i+1);
        //printf("matricule:\n");
        n->matricule=i+1;
        //scanf("%d",&(n->matricule));
        printf("nom:\n");
        scanf("%s",n->noms);
        printf("aille:\n");
        scanf("%f",&(n->taille));
        lis=ajouteraudebut(lis,nbr,n->matricule,n->noms,n->taille);
    }
    //system("clear");
    printf("####################################\n");
    affich(lis);
    printf("vous pouvez ajouter un autre individu (oui ou non):\n");
    scanf("%s",rep);
    if(strcmp(rep,"oui")==0){
        printf("veuillez entrer le nombre des individus:\n");
        scanf("%d",&nbrr);
        nbrr=nbrr+nbr;
        for(i=nbr;i<nbrr;i++){
            n=(individus*)malloc(sizeof(individus));
            printf("entrer les info pour l´individu num %d:\n",i+1);
            //printf("matricule:\n");
            n->matricule=i+1;
            //scanf("%d",&(n->matricule));
            printf("nom:\n");
            scanf("%s",n->noms);
            printf("aille:\n");
            scanf("%f",&(n->taille));
            lis=ajouteraudebut(lis,nbrr,n->matricule,n->noms,n->taille);
        }
        affich(lis);
    }
    // printf("le nombre des elements est: %d\n",nombreindiv(lis));
    printf("Veuillez entrer le matricule a recherche:\n");
    scanf("%d",&cher);
    affich(lis);
    existe(lis,cher);
    // if(existe(lis,cher)==1){
    //    printf("l´element %d existe\n",cher);
    // }
    // else{
        
    //    printf("%d n´existe pas\n",cher);
    // }
    printf("le nombre des individus est %d\n",nombreindiv(lis));
    printf("moyenne des tailles est: %f\n",moyenne(lis));

}
