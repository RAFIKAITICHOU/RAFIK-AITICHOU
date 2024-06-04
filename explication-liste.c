#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Module{
  char intitule[30];
  int coefficient;
  struct Module *moduleSuivant;
};
//----------------------------------------
struct Module * initialiser(struct Module *t){
  t = (struct Module*)malloc(sizeof(struct Module));
  struct Module *ptr = t;

  char reponse;
  do{
    printf("\nIntitule du module : ");
    scanf("%s", ptr->intitule);
    printf("Coefficient : ");
    scanf("%d", &ptr->coefficient);

    printf("Do you want to add a new course (y,n)?");
    scanf("%c",&reponse);
    if(reponse == 'y' || reponse =='Y'){
        ptr->moduleSuivant = (struct Module*)malloc(sizeof(struct Module));
        ptr = ptr->moduleSuivant;
    }else{
      ptr->moduleSuivant = NULL;
    }
  }while(reponse == 'y' || reponse == 'Y');

  return t;
}
//-------------------------
struct Module* ajouterDebut(struct Module *t){
 struct Module *nouveauModule = (struct Module*)malloc(sizeof(struct Module));

 printf("---- Sisair les informations du nouveau module [Au debut] ---\n\n");
 printf("  -Intitule du module    : "); 
 scanf("%s", nouveauModule->intitule);
 printf("  -Coefficient du module : "); 
 scanf("%d", &nouveauModule->coefficient);
 nouveauModule->moduleSuivant = t;

 t = nouveauModule;

 return t; // return nouveauModule;
}
//-------------------------
struct Module* ajouterFin(struct Module *t){
    struct Module *nouveauModule = malloc(sizeof(struct Module));

    printf("---- Sisair les informations du nouveau module [A la fin] ---\n\n");
    printf("  -Intitule du module    : "); scanf("%s", &nouveauModule->intitule);
    printf("  -Coefficient du module : "); scanf("%d", &nouveauModule->coefficient);
    nouveauModule->moduleSuivant = NULL;

    if(t == NULL) t = nouveauModule;
    else{
         struct Module *ptr = t;

         while(ptr->moduleSuivant != NULL){
            ptr = ptr->moduleSuivant;
         }
         ptr->moduleSuivant = nouveauModule;
    }
    return t;
}
//-------------------------
void ajouterMilieu(struct Module *t, char nomModule[30]){
   if(t == NULL)printf("--> La liste est vide ---\n");
   else{
     struct Module *ptr = t;
     bool found = false;
     while(ptr != NULL){
        if(strcmp(nomModule, ptr->intitule) == 0){
            found = true;
            struct Module* nouveauModule = malloc(sizeof(struct Module));
            printf("  -Intitule du module    : ");
            scanf("%s", &nouveauModule->intitule);
            printf("  -Coefficient du module : ");
            scanf("%d", &nouveauModule->coefficient);
            nouveauModule->moduleSuivant = ptr->moduleSuivant;
            ptr->moduleSuivant = nouveauModule;
            ptr = NULL; // Quitter la boucle
        }else ptr = ptr->moduleSuivant;
     }
     if(found == false) printf("\nLe module <%s> nexiste pas dans la liste", nomModule);
   }
}
//--------------------
bool rechercher(struct Module *t, char nomModule[30]){
 struct Module *ptr = t;
 while(ptr != NULL){
    if(strcmp(ptr->intitule, nomModule)==0) return true;
    else ptr = ptr->moduleSuivant;
 }
 return false;
}
//--------------------
void afficher(struct Module *t){
 printf("\n\n ---- Liste des modules ----\n");
 while(t != NULL){
    printf("  -Intitule    : %s\n", t->intitule);
    printf("  -Coefficient : %d\n -------\n", t->coefficient);
    t = t->moduleSuivant;
 }
}
//-------------------------
void afficher_R(struct Module *t){
 if(t != NULL){
    printf("\n  -Intitule    : %s\n", t->intitule);
    printf("  -Coefficient : %d\n -------", t->coefficient);
    afficher_R(t->moduleSuivant);
 }
}
//-------------------------
int tailleListe(struct Module *t){
  int nombreNoeuds = 0;

  struct Module *ptr = t;
  while(ptr != NULL){
    nombreNoeuds++;
    ptr = ptr->moduleSuivant;
  }

  return nombreNoeuds;
}
//--------------------
struct Module *niemeElement(struct Module *t, int n);
int nombreOccurrence(struct Module *t, int n){
  struct Module *niemeModule = niemeElement(t, n);
  int nbOccurences = 0;
  if(niemeModule != NULL){

    struct Module *ptr = t;
    while(ptr != NULL){
      if(strcmp(ptr->intitule, niemeModule->intitule)==0) nbOccurences++;
      ptr = ptr->moduleSuivant;
    }
  }
  return nbOccurences;
}
//-------------------------
void nombreOccurrences(struct Module *t){
 struct Module *ptr = t;
 int i = 1;
 while(ptr != NULL){
   printf("  -Module <%s> --> %d fois\n", ptr->intitule,
                                          nombreOccurrence(t, i));
   i++;
   ptr = ptr->moduleSuivant;
 }
//  getche();
};
//-------------------------
struct Module *niemeElement(struct Module *t, int n){
 int i = 1;

 struct Module *ptr = t;
 while(ptr != NULL){
    if(i==n) return ptr;
    else {
          i++;
          ptr = ptr->moduleSuivant;
    }
 }

 return NULL;
};
//-------------------------
struct Module* inverserListe(struct Module *t){
     if(t != NULL) // La liste n'est pas vide
        if(t->moduleSuivant != NULL){ // La liste contient plus d'un élément
           struct Module *precedent = t,
                         *actuel    = t->moduleSuivant;
           while(actuel != NULL){
             struct Module *suivant = actuel->moduleSuivant;

             actuel->moduleSuivant = precedent;

             precedent = actuel;
             actuel = suivant;
           }
           t->moduleSuivant = NULL;
           t = precedent;

        }else printf("La liste est composée d'un seul module, elle reste la meme");
     else printf("La liste est vide !!!");
     return t;
};
//-------------------------
int main(){

  struct Module *tete = NULL;
for(int i=0;i<2;i++){
    tete=ajouterDebut(tete);
}
  afficher(tete);
//   tete = initialiser(tete);
//   printf("\n=> La liste initiale :\n");
//   afficher(tete);
//   tete = inverserListe(tete);
//   printf("\n=> La liste apres l'inversion :\n");
  return 0;
}
