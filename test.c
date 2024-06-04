#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *p_next;
    struct node *p_prev;
}typeCellule;
typedef struct {
    int taille;
    typeCellule *p_deb;
    typeCellule *p_fin;
}Dlist;
void initialiser( Dlist *p){
    p->taille=0;
    p->p_deb=p->p_fin=NULL;
}
void inséreVide(Dlist *p,int val){
    
    typeCellule *b=(typeCellule *)malloc(sizeof(typeCellule));
    b->p_prev=b->p_next=NULL;
    b->data=val;
    p->p_deb=b;
    p->p_fin=b;
    p->taille=1;
}
void inséreDebut(Dlist *p,int val){
    typeCellule *b=(typeCellule *)malloc(sizeof(typeCellule));
    b->p_prev=b->p_next=NULL;
    b->data=val;
    if(p->p_deb==NULL){
        p->p_deb=b;
        p->p_fin=b;
        p->taille++;
    }
    else{
        b->p_next=p->p_deb;
        p->p_deb->p_prev=b;
        p->p_deb=b;
        p->taille++;
    }

}
void inséreAlaFin(Dlist *p,int val){
    typeCellule *b=(typeCellule *)malloc(sizeof(typeCellule));
    b->p_prev=b->p_next=NULL;
    b->data=val;
    if(p->p_deb==NULL){
        p->p_deb=b;
        p->p_fin=b;
        p->taille++;
    }
    else{
        b->p_prev=p->p_fin;
        p->p_fin->p_next=b;
        p->p_fin=b;
        p->taille++;
    }

}
void affichage(Dlist *p){
    typeCellule *tmp;
    tmp=p->p_deb;
    printf("Debut---");
    while(tmp!=NULL){
        printf("| %d |",tmp->data);
        tmp=tmp->p_next;
    }
    printf("---Fin");
    printf("\n");
    printf("la taille est %d\n",p->taille);
}
void rechercher(Dlist *p,int v){
    if(p->p_deb!=NULL){
        typeCellule *tmp=p->p_deb;
        while(tmp!=NULL && tmp->data!=v){
            tmp=tmp->p_next;
        }
        if(tmp!=NULL){
            printf("%d existe\n",v);
        }
        else{
            printf("%d Non existe!!\n",v);
        }

    }
}
int maxListe(Dlist *p){
    typeCellule *tmp;
    int max;
    tmp=p->p_deb;
    max=p->p_deb->data;
    while(tmp!=NULL){
        if(max<tmp->data){
            max=tmp->data;
        }
        tmp=tmp->p_next;
    }
    return max;
}
void supprimerElem(Dlist *p){
    printf("Quelle position voulez-vous supprimer?\n");
    int choix;
    printf("\t1)Au debut\n");
    printf("\t2)À la fin\n");
    printf("\t3)Au mileau\n");
    scanf("%d",&choix);
    switch(choix){
        case 1: 
            printf("Votre choix est : supprimer Au debut\n");
            typeCellule *tmp=p->p_deb;
            if(p->p_deb->p_next==NULL){
                free(p->p_deb);
                p->taille=0;
                p->p_deb=NULL;
            }
            else{
                p->p_deb->p_next->p_prev=NULL;
                p->p_deb=p->p_deb->p_next;
                p->taille--;
                free(tmp);
            }
            break;
        case 2:
           printf("Votre choix est : supprimer À la fin\n");
           tmp=p->p_fin;
           tmp->p_prev->p_next=NULL;
           p->p_fin=tmp->p_prev;
           p->taille--;
           free(tmp);
           break;
        case 3: //on suppose supp Apres.
          printf("Votre choix est : supprimer au mileau\n");
          printf("Entrer element a supprimer:\n");
          int v;
          scanf("%d",&v);
          tmp=p->p_deb;
          while(tmp!=NULL && tmp->data!=v){
            tmp=tmp->p_next;
          }
          if(tmp!=NULL){
            if(tmp->p_next!=NULL){
               tmp->p_next->p_prev=tmp->p_prev;
            }
            tmp->p_prev->p_next=tmp->p_next;
            p->taille--;
            free(tmp);
          }
          break;
        default:printf("choix invalide!!\n");
                break;
    }
}
void librer(Dlist *p) {
    typeCellule *tmp = p->p_deb;
    while (tmp != NULL) {
        typeCellule *next = tmp->p_next;
        free(tmp);#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *p_next;
    struct node *p_prev;
}typeCellule;
typedef struct {
    int taille;
    typeCellule *p_deb;
    typeCellule *p_fin;
}Dlist;
void initialiser( Dlist *p){
    p->taille=0;
    p->p_deb=p->p_fin=NULL;
}
void inséreVide(Dlist *p,int val){

    typeCellule *b=(typeCellule *)malloc(sizeof(typeCellule));
    b->p_prev=b->p_next=NULL;
    b->data=val;
    
    p->p_deb=b;
    p->p_fin=b;
    p->taille=1;
}
void inséreDebut(Dlist *p,int val){
    typeCellule *b=(typeCellule *)malloc(sizeof(typeCellule));
    b->p_prev=b->p_next=NULL;
    b->data=val;
    if(p->p_deb==NULL){
        p->p_deb=b;
        p->p_fin=b;
        p->taille++;
    }
    else{
        b->p_next=p->p_deb;
        p->p_deb->p_prev=b;
        p->p_deb=b;
        p->taille++;
    }

}
void inséreAlaFin(Dlist *p,int val){
    typeCellule *b=(typeCellule *)malloc(sizeof(typeCellule));
    b->p_prev=b->p_next=NULL;
    b->data=val;
    if(p->p_deb==NULL){
        p->p_deb=b;
        p->p_fin=b;
        p->taille++;
    }
    else{
        b->p_prev=p->p_fin;
        p->p_fin->p_next=b;
        p->p_fin=b;
        p->taille++;
    }

}
void affichage(Dlist *p){
    typeCellule *tmp;
    tmp=p->p_deb;
    printf("Debut---");
    while(tmp!=NULL){
        printf("| %d |",tmp->data);
        tmp=tmp->p_next;
    }
    printf("---Fin");
    printf("\n");
    printf("la taille est %d\n",p->taille);
}
void rechercher(Dlist *p,int v){
    if(p->p_deb!=NULL){
        typeCellule *tmp=p->p_deb;
        while(tmp!=NULL && tmp->data!=v){
            tmp=tmp->p_next;
        }
        if(tmp!=NULL){
            printf("%d existe\n",v);
        }
        else{
            printf("%d Non existe!!\n",v);
        }

    }
}
int maxListe(Dlist *p){
    typeCellule *tmp;
    int max;
    tmp=p->p_deb;
    max=p->p_deb->data;
    while(tmp!=NULL){
        if(max<tmp->data){
            max=tmp->data;
        }
        tmp=tmp->p_next;
    }
    return max;
}
void supprimerElem(Dlist *p){
    printf("Quelle position voulez-vous supprimer?\n");
    int choix;
    printf("\t1)Au debut\n");
    printf("\t2)À la fin\n");
    printf("\t3)Au mileau\n");
    scanf("%d",&choix);
    switch(choix){
        case 1: 
            printf("Votre choix est : supprimer Au debut\n");
            typeCellule *tmp=p->p_deb;
            if(p->p_deb->p_next==NULL){
                free(p->p_deb);
                p->taille=0;
                p->p_deb=NULL;
            }
            else{
                p->p_deb->p_next->p_prev=NULL;
                p->p_deb=p->p_deb->p_next;
                p->taille--;
                free(tmp);
            }
            break;
        case 2:
           printf("Votre choix est : supprimer À la fin\n");
           tmp=p->p_fin;
           tmp->p_prev->p_next=NULL;
           p->p_fin=tmp->p_prev;
           p->taille--;
           free(tmp);
           break;
        case 3: //on suppose supp Apres.
          printf("Votre choix est : supprimer au mileau\n");
          printf("Entrer element a supprimer:\n");
          int v;
          scanf("%d",&v);
          tmp=p->p_deb;
          while(tmp!=NULL && tmp->data!=v){
            tmp=tmp->p_next;
          }
          if(tmp!=NULL){
            if(tmp->p_next!=NULL){
               tmp->p_next->p_prev=tmp->p_prev;
            }
            tmp->p_prev->p_next=tmp->p_next;
            p->taille--;
            free(tmp);
          }
          break;
        default:printf("choix invalide!!\n");
                break;
    }
}
void librer(Dlist *p) {
    typeCellule *tmp = p->p_deb;
    while (tmp != NULL) {
        typeCellule *next = tmp->p_next;
        free(tmp);
        tmp = next;
    }
    p->p_deb = p->p_fin = NULL;
    p->taille = 0;
}
int main(){
    Dlist *liste=(Dlist *)malloc(sizeof(Dlist));
    initialiser(liste);
    // inséreVide(liste,8);
    inséreDebut(liste,9);
    inséreDebut(liste,10);
    inséreDebut(liste,24);
    inséreDebut(liste,6);
    inséreDebut(liste,99);
    inséreDebut(liste,0);
    affichage(liste);
    printf("Le max est: %d\n",maxListe(liste));
    rechercher(liste,10);
    rechercher(liste,3);

    supprimerElem(liste);
    affichage(liste);
    supprimerElem(liste);
    affichage(liste);
    supprimerElem(liste);
    affichage(liste);
    librer(liste);
    affichage(liste);
    return 0;
}

        tmp = next;
    }
    p->p_deb = p->p_fin = NULL;
    p->taille = 0;
}
int main(){
    Dlist *liste;
    initialiser(liste);
    // inséreVide(liste,8);
    inséreDebut(liste,9);
    inséreDebut(liste,10);
    inséreDebut(liste,24);
    inséreDebut(liste,6);
    inséreDebut(liste,99);
    inséreDebut(liste,0);
    affichage(liste);
    printf("Le max est: %d\n",maxListe(liste));
    rechercher(liste,10);
    rechercher(liste,3);

    supprimerElem(liste);
    affichage(liste);
    supprimerElem(liste);
    affichage(liste);
    supprimerElem(liste);
    affichage(liste);
    librer(liste);
    affichage(liste);
    return 0;
}
