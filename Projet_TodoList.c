#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char id[30];
    char titre[100];
    char description[100];
    char deadline[100];
    char statut[100];
} Tache;

Tache taches[100];
int nbTaches = 0;

// int DepasserDeadline(char deadline[]) {
//     int jour, mois, annee;
//     sscanf(deadline, "%d-%d-%d", &jour, &mois, &annee);

//     // Date actuelle (10 Septembre 2024)
//     int jourActuel = 10, moisActuel = 9, anneeActuelle = 2024;

//     if (annee < anneeActuelle) 
//         return 1;
//     else if (annee == anneeActuelle && mois < moisActuel) 
//         return 1;
//     else if (annee == anneeActuelle && mois == moisActuel && jour < jourActuel) 
//         return 1;

//     return 0;
// }

int main(){
  char description[200], statut[30], deadline[30];
  // Tache temp;
  int choix;
  

  do {
    printf("\nMenu Principal:\n");
    printf("1. Ajouter une nouvelle tâche\n");
    printf("2. Afficher la liste des tâches\n");
    printf("3. Modifier une tâche\n");
    printf("4. Supprimer une tâche\n");
    printf("5. Rechercher une tâche\n");
    printf("6. Statistiques\n");
    printf("7. Quitter\n");
    printf("Entrez votre choix : ");
    int choix;
    scanf("%d", &choix);
    getchar();
    switch (choix) {
    case 1:
    int n;
    char id[30];

    printf("Combien de taches voulez-vous ajouter? ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) { 
        printf("L'identifiant de la tache %d: %d\n", i+1, nbTaches+1);
        int j;
        for (int j = 0; j < nbTaches; j++) {
            if (strcmp(id, taches[j].id) == 0) {
                printf("ID deja utilisé. Veuillez saisir nouveau id: ");
                scanf("%s", id);
                i--;
                break;
            }
        }
        if (strcmp(id, taches[j].id) != 0) {
            strcpy(taches[nbTaches].id, id);
        }


        printf("Entrer le titre de la tache %d: ", i+1);
        scanf("%s", taches[nbTaches].titre);


        printf("Entrer la description de la tache %d: ", i+1);
        scanf("%s", taches[nbTaches].description);
        getchar();

        printf("Entrer le deadline de la tache %d (jour mois annee): ", i+1);
        scanf("%s", taches[nbTaches].deadline);
        getchar();

        printf("Entrer le statut de la tache %d (a realiser / en cours de realisation / finalisee): ", i+1);
        scanf("%s", taches[nbTaches].statut);
        getchar();

        printf("Tache ajoutée avec succès.\n");
        printf("\t%s | %s | %s | %s | %s\n", taches[i].id, taches[i].id, taches[i].description, taches[i].deadline, taches[i].statut);

        nbTaches++;
    }

    break;
    case 2:
    int choix1;

    printf("Choisissez l'option convenable\n");
    printf("1. Afficher la liste de toutes les taches.\n");
    printf("2. Afficher la liste de toutes les taches par deadline.\n");
    printf("3. Afficher la liste de toutes les taches par ordre alphabétique.\n");

    printf("Entrer votre choix: ");
    scanf("%d", &choix1);
    getchar();


    switch (choix1) {
        case 1:
            printf("Liste des tâches:\n");
            for (int i = 0; i < nbTaches; i++) 
                printf("Tache %d\n\tID: %s | Titre: %s | Description: %s | Deadline: %s | Statut: %s\n", i+1, taches[i].id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
            break;
        
        case 2:
            for (int i = 0; i < nbTaches - 1; i++) {
                for (int j = 0; j < nbTaches - i - 1; j++) {
                    if (strcmp(taches[j].deadline, taches[j + 1].deadline) > 0) {
                        Tache tmp = taches[j];
                        taches[j] = taches[j + 1];
                        taches[j + 1] = tmp;
                    }
                }
            }
            printf("Liste des tâches:\n");
            for (int i = 0; i < nbTaches; i++) {
                printf("Tache %d\n\tID: %s | Titre: %s | Description: %s | Deadline: %s | Statut: %s\n", i+1, taches[i].id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
            }
            break;

        case 3:
            for (int i = 0; i < nbTaches-1; i++) {
                for (int j = 0; j < nbTaches-i-1; j++) {
                    if (strcmp(taches[j].titre, taches[j+1].titre) > 0) {
                        Tache tmp = taches[j];
                        taches[j] = taches[j+1];
                        taches[j+1] = tmp;
                    }
                }
            }
            printf("Liste des tâches:\n");
            for (int i = 0; i < nbTaches; i++) {
                printf("Tâche %d\n\tID: %s | Titre: %s | Description: %s | Deadline: %s | Statut: %s\n",
                   i + 1, taches[i].id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
            }
            break;

        default:
            printf("Choix invalide.\n");
            break;
    }
    break;

    case 3:
   int choix2;
    printf("Entrer l'id de la tache que vous voulez modifier: ");
    scanf("%s", id);
    getchar();

    int i;
    for (i = 0; i < nbTaches; i++) {
        if (strcmp(taches[i].id, id) == 0) {
            printf("Choisissez l'option convenable\n");
            printf("1. Modifier la description d'une tâche.\n");
            printf("2. Modifier le statut d'une tâche.\n");
            printf("3. Modifier le deadline d'une tâche.\n");

            printf("Entrer votre choix: ");
            scanf("%d", &choix2);
            getchar();

            switch (choix2) {
                case 1:
                    printf("Entrer la nouvelle description: ");
                    scanf("%s", description);
                    strcpy(taches[i].description, description);
                    break;
                case 2:
                    printf("Entrer le nouveau statut: ");
                    scanf("%s", statut);
                    strcpy(taches[i].statut, statut);
                    break;
                case 3:
                    printf("Entrer le nouveau deadline: ");
                    scanf("%s", deadline);
                    strcpy(taches[i].deadline, deadline);
                    break;
                default:
                    printf("Choix invalide");
                    break;
            }
        }
        printf("Tâche modifié:\n\tID: %s | Description: %s | Statut: %s | Deadline: %s\n", taches[i].id, taches[i].description, taches[i].statut, taches[i].deadline);
        return;
    }
    break;

    case 4:

    printf("Entrez l'identifiant de le tache que vous voulez suprimer : ");
    scanf("%s", id);
    getchar();

    for (int i = 0; i < nbTaches; i++) {
        if (strcmp(taches[i].id, id) == 0) {
            for (int j = i; j < nbTaches - 1; j++) {
                taches[j] = taches[j + 1];
            }
            nbTaches--;
            printf("Tache supprimé avec succès.\n");
            return;
        }
    } 
    printf("Tache non trouvé.\n");
    break;

    case 5:
    char titre[30];
    int choix3;
    printf("Choisissez l'option convenable\n");
    printf("1. Rechercher une tâche par son identifiant.\n");
    printf("2. Rechercher une tâche par son titre.\n");
    printf("Entrer votre choix: ");
    scanf("%d", &choix3);
    getchar();

    if (choix3 < 1 || choix3 > 2) {
        printf("Choix invalide. Veuillez choisir entre 1 et 2.\n");
        return;
    }
    else if (choix3 == 1) {
        printf("Entrer l'identifiant de la tache recherchée: ");
        scanf("%s", id);
        getchar();

        for (int i = 0; i < nbTaches; i++) {
            if (strcmp(taches[i].id, id) == 0) {
                printf("Tâche correspondante:\n");
                printf("\tID : %s | Titre : %s | Description : %s | Deadline : %s | Statut : %s\n", taches[i].id, taches[i].titre, taches[i].description, taches[i].deadline, taches[i].statut);
                return;
            }
        }
        printf("Aucune tâche correspondante.\n");  
    }
    else {
        printf("Entrer le titre de la tâche recherchée: ");
        scanf("%s", titre);

        for (int i = 0; i < nbTaches; i++) {
            if (strcmp(taches[i].titre, titre) == 0) {
                printf("Tâche correspondante:\n");
                printf("\tID : %s | Titre : %s | Description : %s | Deadline : %s | Statut : %s\n", taches[i].id, taches[i].titre, taches[i].description, taches[i].description, taches[i].statut);
                break;
            }
        }                
        printf("Aucune tâche correspondante.\n");
    }
    break; 

// case 6:
//     {
//         int enCours = 0, finalise = 0, aRealiser = 0, depasse = 0;
//         Tache proche = taches[0];

//         for (int i = 0; i < nbTaches; i++) {
//             if (strcmp(taches[i].statut, "en cours de réalisation") == 0) 
//                 enCours++;
//             else if (strcmp(taches[i].statut, "finalisée") == 0) 
//                 finalise++;
//             else if (strcmp(taches[i].statut, "à réaliser") == 0) 
//                 aRealiser++;

//             if (DepasserDeadline(taches[i].deadline)) 
//                 depasse++;

//             if (strcmp(taches[i].deadline, proche.deadline) < 0) 
//                 proche = taches[i];
//         }

//         printf("=== Statistiques ===\n");
//         printf("Nombre total de tâches: %d\n", nbTaches);
//         printf("Tâches en cours: %d\n", enCours);
//         printf("Tâches finalisées: %d\n", finalise);
//         printf("Tâches à réaliser: %d\n", aRealiser);
//         printf("Tâches dont le deadline est dépassé: %d\n", depasse);
//         printf("Tâche la plus proche du deadline: \n\tID: %s | Titre: %s | Deadline: %s\n", 
//             proche.id, proche.titre, proche.deadline);

//     }
//     break;

     case 7:
     printf("Au revoir !\n");
     break;
     default:
     printf("Choix invalide\n");
     }
  }while (choix!=7);
}

