#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    char nom[20];
    float prix;
    int nombre;
}Mobaile;
typedef struct{
    Mobaile Data;
    struct typeCellule *nexte;
}typeCellule;
int nombremobil(typeCellule *tete){
    typeCellule *temps;
    int nb=0;
    temps=tete;
    while(temps!=NULL){
       nb=nb+temps->Data.nombre;
       temps=temps->nexte;
    }
    return nb;
}
// typeCellule * suppMobail(typeCellule *tete){
//     typeCellule *temp,*p;
//     if(tete!=NULL){
//         if(tete->Data.nombre==0){
//             p=tete;
//             tete=tete->nexte;
//             free(p);
//         }
//         else{
//             temp=tete;
//             while(temp->nexte!=NULL&&temp->Data.nombre){

//             }
//         }
//     }
// }
typeCellule * ajouteEnTete(typeCellule *tete,char nom[20],float prix,int nombre){
    typeCellule *B;
    B=(typeCellule *)malloc(sizeof(typeCellule));
    strcpy(B->Data.nom,nom);
    B->Data.prix=prix;
    B->Data.nombre=nombre;
    B->nexte=tete;
    tete=B;
   return tete;
}
void affich(typeCellule *tete){
    typeCellule * temp;
    temp=tete;
    if(tete==NULL){
        printf("la liste est vide");
    }
    else{
        while(temp!=NULL){
            printf("|%s %.2f %d|\n",temp->Data.nom,temp->Data.prix,temp->Data.nombre);
            temp=temp->nexte;
        }
    }

}

void main(){
    typeCellule *lis,*n;
    lis=NULL;
    int i, nb,nbrr;
    char rep[6];
    int supp;
    printf("veuillez entrer le nombre des mobiles:\n");
    scanf("%d",&nb);
    for(i=0;i<nb;i++){
        printf("entrer les info pour mobile num %d:\n",i+1);
        printf("nom:\n");
        scanf("%s",n->Data.nom);
        printf("prix:\n");
        scanf("%f",&(n->Data.prix));
        printf("nombre:\n");
        scanf("%d",&(n->Data.nombre));
        lis=ajouteEnTete(lis,n->Data.nom,n->Data.prix,n->Data.nombre);
    }
    affich(lis);
    printf("vous pouvez ajouter un autre mobaile (oui ou non):\n");
    scanf("%s",rep);
    if(strcmp(rep,"oui")==0){
        printf("veuillez entrer le nombre des mobail:\n");
        scanf("%d",&nbrr);
        nbrr=nbrr+nb;
        for(i=nb;i<nbrr;i++){
            n=(typeCellule*)malloc(sizeof(typeCellule));
            printf("entrer les info pour mobile num %d:\n",i+1);
            printf("nom:\n");
            scanf("%s",n->Data.nom);
            printf("prix:\n");
            scanf("%f",&(n->Data.prix));
            printf("nombre:\n");
            scanf("%d",&(n->Data.nombre));
            lis=ajouteEnTete(lis,n->Data.nom,n->Data.prix,n->Data.nombre);
        }
        affich(lis);
    }


    printf("nombre des mobile est :%d\n",nombremobil(lis));
    // printf("le nombre des mobiles vendus est %d",nombremobil(lis));

}