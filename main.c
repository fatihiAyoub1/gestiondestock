#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char nom[20];
    int prix;
    int quantite;
} Product;

// tableau global bach nkhznou produits
Product produits[MAX_PRODUCTS];
int totalProduits = 0;

// Fonction Ajouter produit
void Ajouter() {
    if (totalProduits >= MAX_PRODUCTS) {
        printf("Tableau rempli.\n");
        return;
    }

    printf("Entrez le nom du produit:\n");
    scanf("%s", produits[totalProduits].nom);

    printf("Entrez la quantité:\n");
    scanf("%d", &produits[totalProduits].quantite);

    printf("Entrez le prix:\n");
    scanf("%d", &produits[totalProduits].prix);

    totalProduits++;
}

// Fonction afficher produits
void afficher() {
    if (totalProduits == 0) {
        printf("Aucun produit enregistré.\n");
        return;
    }

    printf("===== Liste des produits =====\n");
    for (int i = 0; i < totalProduits; i++) {
        printf("Produit %d:\n", i + 1);
        printf("Nom: %s\n", produits[i].nom);
        printf("Quantité: %d\n", produits[i].quantite);
        printf("Prix: %d\n", produits[i].prix);
        printf("----------------------------\n");
    }
}

int main() {
    int choix;

    do {
        printf("\n====== MENU ======\n");
        printf("1. Ajouter un produit\n");
        printf("2. Afficher les produits\n");
        printf("3. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                Ajouter();
                break;
            case 2:
                afficher();
                break;
            case 3:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 3);

    return 0;
}
