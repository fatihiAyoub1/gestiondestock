#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char nom[20];
    int prix;
    int quantite;
} Product;

Product produits[MAX_PRODUCTS];
int totalProduits = 0;

// Fonction Ajouter
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

// Fonction Afficher
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

// Fonction Modifier
void modifier() {
    char nomRecherche[20];
    printf("Entrez le nom du produit à modifier: ");
    scanf("%s", nomRecherche);

    int trouve = 0;
    for (int i = 0; i < totalProduits; i++) {
        if (strcmp(produits[i].nom, nomRecherche) == 0) {
            printf("Produit trouvé. Entrez les nouvelles informations :\n");

            printf("Nouveau nom: ");
            scanf("%s", produits[i].nom);

            printf("Nouvelle quantité: ");
            scanf("%d", &produits[i].quantite);

            printf("Nouveau prix: ");
            scanf("%d", &produits[i].prix);

            printf("Produit modifié avec succès.\n");
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Produit non trouvé.\n");
    }
}

// Fonction Supprimer
void supprimer() {
    char nomRecherche[20];
    printf("Entrez le nom du produit à supprimer: ");
    scanf("%s", nomRecherche);

    int trouve = 0;
    for (int i = 0; i < totalProduits; i++) {
        if (strcmp(produits[i].nom, nomRecherche) == 0) {
            // Décaler tous les produits suivants
            for (int j = i; j < totalProduits - 1; j++) {
                produits[j] = produits[j + 1];
            }
            totalProduits--;
            printf("Produit supprimé avec succès.\n");
            trouve = 1;
            break;
        }
    }

    if (!trouve) {
        printf("Produit non trouvé.\n");
    }
}

// Programme principal
int main() {
    int choix;

    do {
        printf("\n====== MENU ======\n");
        printf("1. Ajouter un produit\n");
        printf("2. Afficher les produits\n");
        printf("3. Modifier un produit\n");
        printf("4. Supprimer un produit\n");
        printf("5. Quitter\n");
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
                modifier();
                break;
            case 4:
                supprimer();
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 5);

    return 0;
}
