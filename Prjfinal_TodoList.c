#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


// Structure pour la date
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Structure pour les tâches
typedef struct {
    int id;
    char titre[100];
    char description[100];
    Date deadline;
    char statut[100];
} Tache;

Tache taches[100]; // Tableau de tâches
int nbTaches = 0; // Compteur de tâches


void ajouterTaches() {
    int nbTachesAAjouter;
    printf("Entrez le nombre de tâches à ajouter : ");
    scanf("%d", &nbTachesAAjouter);
    
    for (int i = 0; i < nbTachesAAjouter; i++) {
        if (nbTaches < 100) {
            Tache nouvelleTache;
            
            printf("Entrez l'identifiant de la tache %d : ", i + 1);
            scanf("%d", &nouvelleTache.id);
            
            printf("Entrez le titre de la tache %d : ", i + 1);
            scanf("%s", nouvelleTache.titre); 
            
            printf("Entrez la description de la tache %d : ", i + 1);
            scanf("%s", nouvelleTache.description); 
            
            int jour, mois, annee;
            do {
                printf("Entrez le jour du deadline (jj) de la tache %d : ", i + 1);
                scanf("%d", &jour);
                if (jour < 1 || jour > 31) {
                    printf("Erreur : jour invalide. Veuillez entrer un jour entre 1 et 31.\n");
                }
            } while (jour < 1 || jour > 31);
            
            do {
                printf("Entrez le mois du deadline (mm) de la tâche %d : ", i + 1);
                scanf("%d", &mois);
                if (mois < 1 || mois > 12) {
                    printf("Erreur : mois invalide. Veuillez entrer un mois entre 1 et 12.\n");
                }
            } while (mois < 1 || mois > 12);
            
            do {
                printf("Entrez l'année du deadline (aaaa) de la tâche %d : ", i + 1);
                scanf("%d", &annee);
                if (annee < 2024) {
                    printf("Erreur : année invalide. Veuillez entrer une année supérieure ou égale à 2024.\n");
                }
            } while (annee < 2024);
            
            nouvelleTache.deadline.jour = jour;
            nouvelleTache.deadline.mois = mois;
            nouvelleTache.deadline.annee = annee;
            
            printf("Entrez le statut de la tache %d (a realiser, en cours de réalisation, finalisee) : ", i + 1);
            scanf("%s", nouvelleTache.statut); 
            
            taches[nbTaches] = nouvelleTache;
            nbTaches++;
            
            printf("Tache %d ajoutée avec succes !\n", i + 1);
        } else {
            printf("Erreur : tableau de taches plein.\n");
            break;
        }
    }
}


void afficherTaches() {
    printf("Liste des taches :\n");
    for (int i = 0; i < nbTaches; i++) {
        printf("Identifiant : %d\n", taches[i].id);
        printf("Titre : %s\n", taches[i].titre);
        printf("Description : %s\n", taches[i].description);
        printf("Deadline : %d/%d/%d\n", taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee);
        printf("Statut : %s\n\n", taches[i].statut);
    }
}

void trierTachesAlphabetique() {
    for (int i = 0; i < nbTaches - 1; i++) {
        for (int j = i + 1; j < nbTaches; j++) {
            if (strcmp(taches[i].titre, taches[j].titre) > 0) {
                Tache temp = taches[i];
                taches[i] = taches[j];
                taches[j] = temp;
            }
        }
    }
    afficherTaches();
}

void trierTachesDeadline() {
    for (int i = 0; i < nbTaches - 1; i++) {
        for (int j = i + 1; j < nbTaches; j++) {
            if (taches[i].deadline.annee > taches[j].deadline.annee ||
                (taches[i].deadline.annee == taches[j].deadline.annee &&
                 taches[i].deadline.mois > taches[j].deadline.mois) ||
                (taches[i].deadline.annee == taches[j].deadline.annee &&
                 taches[i].deadline.mois == taches[j].deadline.mois &&
                 taches[i].deadline.jour > taches[j].deadline.jour)) {
                Tache temp = taches[i];
                taches[i] = taches[j];
                taches[j] = temp;
            }
        }
    }
    afficherTaches();
}

void afficherTachesUrgentes() {
    int jourActuel = 1; 
    int moisActuel = 1; 
    int anneeActuelle = 2024; 
    
    printf("Taches urgentes (deadline dans 3 jours ou moins) :\n");
    for (int i = 0; i < nbTaches; i++) {
        int joursRestants = (taches[i].deadline.annee - anneeActuelle) * 365 +
                            (taches[i].deadline.mois - moisActuel) * 30 +
                            (taches[i].deadline.jour - jourActuel);
        if (joursRestants <= 3) {
            printf("Identifiant : %d\n", taches[i].id);
            printf("Titre : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].description);
            printf("Deadline : %d/%d/%d\n", taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee);
            printf("Statut : %s\n\n", taches[i].statut);
        }
    }
}

// void afficherTachesUrgentes() {
//     time_t t = time(NULL);
//     struct tm *tm_info = localtime(&t);
    
//     Date currentDate;
//     currentDate.jour = tm_info->tm_mday;
//     currentDate.mois = tm_info->tm_mon + 1;
//     currentDate.annee = tm_info->tm_year + 1900;
    
//     printf("Tâches urgentes (deadline dans 3 jours ou moins) :\n");
//     for (int i = 0; i < nbTaches; i++) {
//         int joursRestants = calculerJoursRestants(taches[i].deadline, currentDate);
//         if (joursRestants <= 3) {
//             printf("Identifiant : %d\n", taches[i].id);
//             printf("Titre : %s\n", taches[i].titre);
//             printf("Description : %s\n", taches[i].description);
//             printf("Deadline : %d/%d/%d\n", taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee);
//             printf("Statut : %s\n\n", taches[i].statut);
//         }
//     }
// }


void modifierDescriptionTache() {
    int idTache;
    printf("Entrez l'identifiant de la tâche à modifier : ");
    scanf("%d", &idTache);
    
    for (int i = 0; i < nbTaches; i++) {
        if (taches[i].id == idTache) {
            printf("Entrez la nouvelle description de la tâche %d : ", idTache);
            scanf("%s", taches[i].description); 
            printf("Description de la tâche %d modifiée avec succès !\n", idTache);
            return;
        }
    }
    printf("Erreur : tache non trouvée.\n");
}

void modifierStatutTache() {
    int idTache;
    printf("Entrez l'identifiant de la tâche à modifier : ");
    scanf("%d", &idTache);
    
    for (int i = 0; i < nbTaches; i++) {
        if (taches[i].id == idTache) {
            printf("Entrez le nouveau statut de la tâche %d (à réaliser, en cours de réalisation, finalisée) : ", idTache);
            scanf("%s", taches[i].statut); 
            printf("Statut de la tâche %d modifié avec succès !\n", idTache);
            return;
        }
    }
    printf("Erreur : tâche non trouvée.\n");
}

void modifierDeadlineTache() {
    int idTache;
    printf("Entrez l'identifiant de la tâche à modifier : ");
    scanf("%d", &idTache);
    
    for (int i = 0; i < nbTaches; i++) {
        if (taches[i].id == idTache) {
            printf("Entrez le nouveau jour du deadline (jj) de la tâche %d : ", idTache);
            scanf("%d", &taches[i].deadline.jour);
            
            printf("Entrez le nouveau mois du deadline (mm) de la tâche %d : ", idTache);
            scanf("%d", &taches[i].deadline.mois);
            
            printf("Entrez la nouvelle année du deadline (aaaa) de la tâche %d : ", idTache);
            scanf("%d", &taches[i].deadline.annee);
            
            printf("Deadline de la tâche %d modifié avec succès !\n", idTache);
            return;
        }
    }
    printf("Erreur : tâche non trouvée.\n");
}

void supprimerTache() {
    int idTache;
    printf("Entrez l'identifiant de la tâche à supprimer : ");
    scanf("%d", &idTache);
    
    for (int i = 0; i < nbTaches; i++) {
        if (taches[i].id == idTache) {
            
            for (int j = i; j < nbTaches - 1; j++) {
                taches[j] = taches[j + 1];
            }
            nbTaches--;
            printf("Tâche %d supprimée avec succès !\n", idTache);
            return;
        }
    }
    printf("Erreur : tâche non trouvée.\n");
}

void rechercherTacheParId() {
    int idTache;
    printf("Entrez l'identifiant de la tâche à rechercher : ");
    scanf("%d", &idTache);
    
    for (int i = 0; i < nbTaches; i++) {
        if (taches[i].id == idTache) {
            printf("Tâche %d trouvée :\n", idTache);
            printf("Titre : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].description);
            printf("Statut : %s\n", taches[i].statut);
            printf("Deadline : %d/%d/%d\n", taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee);
            return;
        }
    }
    printf("Erreur : tâche non trouvée.\n");
}

void rechercherTacheParTitre() {
    char titre[100];
    printf("Entrez le titre de la tâche à rechercher : ");
    scanf("%99s", titre); 
    
    for (int i = 0; i < nbTaches; i++) {
        if (strcmp(taches[i].titre, titre) == 0) {
            printf("Tâche trouvée :\n");
            printf("Identifiant : %d\n", taches[i].id);
            printf("Description : %s\n", taches[i].description);
            printf("Statut : %s\n", taches[i].statut);
            printf("Deadline : %d/%d/%d\n", taches[i].deadline.jour, taches[i].deadline.mois, taches[i].deadline.annee);
            return;
        }
    }
    printf("Erreur : tâche non trouvée.\n");
}

void afficherNbTaches() {
    printf("Nombre total de tâches : %d\n", nbTaches);
}

void afficherNbTachesEtat() {
    int nbTachesCompletees = 0;
    int nbTachesIncompletes = 0;
    
    for (int i = 0; i < nbTaches; i++) {
        if (strcmp(taches[i].statut, "Finalise") == 0) {
            nbTachesCompletees++;
        } else {
            nbTachesIncompletes++;
        }
    }
    
    printf("Nombre de tâches complètes : %d\n", nbTachesCompletees);
    printf("Nombre de tâches incomplètes : %d\n", nbTachesIncompletes);
}

void afficherNbJoursRestants() {
    for (int i = 0; i < nbTaches; i++) {
        int joursRestants = calculerJoursRestants(taches[i].deadline);
        printf("Tâche %d : %d jours restants\n", taches[i].id, joursRestants);
    }
}

Date getCurrentDate() {
    time_t now = time(NULL);
    struct tm *currentDateTime = localtime(&now);
    
    Date currentDate;
    currentDate.jour = currentDateTime->tm_mday;
    currentDate.mois = currentDateTime->tm_mon + 1; 
    currentDate.annee = currentDateTime->tm_year + 1900; 
    
    return currentDate;
}

int calculerJoursRestants(Date deadline) {
  
    Date currentDate = getCurrentDate();
    
    int joursRestants = (deadline.annee - currentDate.annee) * 365 +
                        (deadline.mois - currentDate.mois) * 30 +
                        (deadline.jour - currentDate.jour);
    
    return joursRestants;
}

int main() {
    int choix;
    
    do {
        printf("Menu :\n");
        printf("1. Ajouter des tâches\n");
        printf("2. Afficher les tâches\n");
        printf("3. Trier les tâches par titre\n");
        printf("4. Trier les tâches par deadline\n");
        printf("5. Afficher les tâches urgentes\n");
        printf("6. Modifier la description d'une tâche\n");
        printf("7. Modifier le statut d'une tâche\n");
        printf("8. Modifier la deadline d'une tâche\n");
        printf("9. Supprimer une tâche\n");
        printf("10. Rechercher une tâche par ID\n");
        printf("11. Rechercher une tâche par titre\n");
        printf("12. Afficher le nombre total de tâches\n");
        printf("13. Afficher le nombre de tâches complètes et incomplètes\n");
        printf("14. Afficher le nombre de jours restants pour chaque tâche\n");
        printf("15. Quitter\n");
        
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                ajouterTaches();
                break;
            case 2:
                afficherTaches();
                break;
            case 3:
                trierTachesAlphabetique();
                break;
            case 4:
                trierTachesDeadline();
                break;
            case 5:
                afficherTachesUrgentes();
                break;
            case 6:
                modifierDescriptionTache();
                break;
            case 7:
                modifierStatutTache();
                break;
            case 8:
                modifierDeadlineTache();
                break;
            case 9:
                supprimerTache();
                break;
            case 10:
                rechercherTacheParId();
                break;
            case 11:
                rechercherTacheParTitre();
                break;
            case 12:
                afficherNbTaches();
                break;
            case 13:
                afficherNbTachesEtat();
                break;
            case 14:
                afficherNbJoursRestants();
                break;
            case 15:
                printf("Au revoir !\n");
                break;
            default:
                printf("Erreur : choix invalide.\n");
        }
    } while (choix != 15);
    
    return 0;
}