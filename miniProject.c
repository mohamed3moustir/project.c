#include <stdio.h>
#include <string.h>
char Titre[10][100];
char auteur[10][100];
float prix[10];
short stock[10];
int nom = 0;

// F1
void ajouter_livre() {
    if (nom >= 10) {
        printf("Impossible d'ajouter .\n");
        return;
    }
    
    printf("Titre du livre: ");
    scanf(" %[^\n]", Titre[nom]);
    printf("Auteur du livre: ");
    scanf(" %[^\n]", auteur[nom]);
    printf("Prix du livre: ");
    scanf("%f", &prix[nom]);
    printf("Quantité en stock: ");
    scanf("%hd", &stock[nom]);  
    
    nom++;
    printf("Livre ajouté avec succès!\n");
}

// F2
void afficher_livres() {
    if (nom == 0) {
        printf(" livre en stock.\n");
        return;
    }
    
    printf("Liste des livres disponibles:\n");
    for (int i = 0; i < nom; i++) {
        printf("Titre: %s | Auteur: %s | Prix: %.2f | Stock: %d\n",
               Titre[i], auteur[i], prix[i], stock[i]);
    }
}
//F3
void rechercher_livre() {
    char titre1[10];
    printf("Entrez le titre du livre à rechercher: ");
    scanf(" %[^\n]", titre1);
    
    for (int i = 0; i < nom; i++) {
       
        if (strcmp(Titre[i], titre1) == 0) {
            printf(" Titre: %s | Auteur: %s | Prix: %.2f |stock:  %d\n",
                   Titre[i],auteur[i], prix[i], stock[i]);
            return;
        }
    }
    
    printf("Livre non trouvé.\n");
}

//f4
void mettre_a_jour_quantite() {
    char titre2[100];
    int nouvelle;
    
    printf("Entrez le titre du livre à mettre à jour: ");
    scanf(" %[^\n]", titre2);
    
    for (int i = 0; i < nom; i++) {
        
        if (strcmp(Titre[i], titre2) == 0) {
            printf("Entrez la nouvelle stock ");
            scanf("%d", &nouvelle);
             stock[i]= nouvelle;
            printf("stock mise à jour avec succès!\n");
            return;
        }
    }
    
    printf("Livre non trouvé.\n");
}

//F5
void supprimer_livre() {
    char titre3[100];
    
    printf("Entrez le titre du livre à supprimer: ");
    scanf(" %[^\n]", titre3);
    
    for (int i = 0; i < nom; i++) {
        if (strcmp(Titre[i], titre3) == 0) {
            
            for (int j = i; j < nom - 1; j++) {
                stock[j] = stock[j + 1];
            }
            nom--;
            printf("Livre supprimé avec succès!\n");
            return;
        }
    }
    
    printf("Livre non trouvé.\n");
}
//F6
void afficher_nombre_total() {
    int total = 0;
    
    for (int i = 0; i < nom; i++) {
        total += stock[i];
    }
    
    printf("Nombre total de livres en stock: %d\n", total);
}
int main() {
    int choix;

    do {
        printf("\n---  Stock de Librairie ---\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres\n");
        printf("3. Rechercher un livre par son titre\n");
        printf("4. Mettre à jour la stock  d'un livre\n");
        printf("5. Supprimer un livre\n");
        printf("6. Afficher le nombre total de livres en stock\n");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_livre();
                break;
            case 2:
                afficher_livres();
                break;
            case 3:
                rechercher_livre();
                break;
            case 4:
                mettre_a_jour_quantite();
                break;
            case 5:
                supprimer_livre();
                break;
            case 6:
                afficher_nombre_total();
                break;
            
            default:
                printf("Choix invalide!\n");
        }
    } while (choix != 6);

    return 0;
}

