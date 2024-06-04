#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stock {
    char nom[20];
    int nombre;
    float prix;
    struct stock *psuivent;
} stock;

stock *acheter(stock *tete, char nom[20], int nombre, float prix) {
    stock *nouveau;
    nouveau = (stock*)malloc(sizeof(stock));
    strcpy(nouveau->nom, nom);
    nouveau->nombre = nombre;
    nouveau->prix = prix;
    nouveau->psuivent = tete;
    tete = nouveau;
    return tete;
}

void afficherStock(stock *tete) {
    stock *temp;
    if (tete == NULL) {
        printf("Le stock est vide!!\n");
        return;
    } else {
        temp = tete;
        while (temp != NULL) {
            printf("|%s  %d  %.2f DH|---", temp->nom, temp->nombre, temp->prix);
            temp = temp->psuivent;
        }
    }
}

stock *vendre(stock *tete, int nombre) {
    stock *temp;
    temp = tete;
    while (temp != NULL) {
        temp->nombre -= nombre;
        temp = temp->psuivent;
    }
    return tete;
}

stock *supprimeLeStock(stock *tete) {
    stock *temp, *p;
    if (tete == NULL) {
        return NULL;
    } else {
        temp = tete;
        while (temp != NULL && temp->nombre != 0) {
            temp = temp->psuivent;
        }
        if (temp != NULL) {
            p = tete;
            while (p != NULL && p->psuivent != temp) {
                p = p->psuivent;
            }
            if (p != NULL) {
                p->psuivent = temp->psuivent;
                free(temp);
            }
        }
    }
    return tete;
}

float prixStock(stock *tete) {
    stock *temp;
    float prixtt = 0;
    temp = tete;
    while (temp != NULL) {
        prixtt += temp->prix * temp->nombre;
        temp = temp->psuivent;
    }
    return prixtt;
}

int main() {
    stock *Stock = NULL;
    stock *pr = NULL;
    int i, nbr, nbvendu;
    pr = (stock*)malloc(sizeof(stock));
    printf("Veuillez entrer le nombre de médicaments :\n");
    scanf("%d", &nbr);
    for (i = 0; i < nbr; i++) {
        printf("Entrer les informations pour le produit numéro %d:\n", i + 1);
        printf("Nom: ");
        scanf("%s", pr->nom);
        printf("Nombre de boîtes: ");
        scanf("%d", &(pr->nombre));
        printf("Prix: ");
        scanf("%f", &(pr->prix));
        Stock = acheter(Stock, pr->nom, pr->nombre, pr->prix);
    }
    afficherStock(Stock);
    printf("\nDonner le nombre de boîtes vendues pour chaque médicament suivant:\n");
    for (i = 0; i < nbr; i++) {
        printf("\nPour le médicament numéro %d\n", i + 1);
        scanf("%d", &nbvendu);
        Stock = vendre(Stock, nbvendu);
    }
    Stock = supprimeLeStock(Stock);
    afficherStock(Stock);
    printf("\nLe prix total des médicaments dans le stock est: %.2f DH\n", prixStock(Stock));

    return 0;
}
