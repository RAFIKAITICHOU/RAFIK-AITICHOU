#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    char nom[20];
    float prix;
    int nombre;
}Mobile;
typedef struct{
    Mobile data;
    struct typeCellule *nexte;
}typeCellule;
typeCellule * insererEnTete(typeCellule *tete,Mobile elem){
    typeCellule *B;
    B=(typeCellule*)malloc(sizeof(typeCellule));
    strcpy(B->data.nom,elem.nom);
    B->data.nombre=elem.nombre;
    B->data.prix=elem.prix;
    B->nexte=tete;
    tete=B;
    return tete;
}
void affich(typeCellule *tete){
    typeCellule *temp;
    if (tete==NULL){
        printf("La liste est Vide!\n");
    }
    else{
        temp=tete;
        while (temp!=NULL){
            printf("|%s  %.2f  %d|\t \n",temp->data.nom,temp->data.prix,temp->data.nombre);
            temp=temp->nexte;
        }
    }
}  
int nombreMobileV(typeCellule *tete){
    int s=0;
    typeCellule *temp;
    temp=tete;
    while(temp!=NULL){
        s=s+temp->data.nombre;
        temp=temp->nexte;
    }
    return s;
}
void main(){
    typeCellule *liste;
    liste=NULL;
    Mobile n;
    int nbmo,i;
    printf("Veuliiez entrer nombre des mobles\n");
    scanf("%d",&nbmo);
    for(i=0;i<nbmo;i++){
        printf("Veuillez entrer les info de mobiles num %d\n",i+1);
        printf("Nom:\n");
        scanf("%s",n.nom);
        printf("Prix:\n");
        scanf("%f",&(n.prix));
        printf("Nombre:\n");
        scanf("%d",&(n.nombre));
        liste=insererEnTete(liste,n);
    }
    affich(liste);
    printf("Le nombre des mobiles Vendus est : %d\n",nombreMobileV(liste));

}