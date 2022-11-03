#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "BIB_standard.h"
#include "BIB_recruteur.h"
#include "BIB_offre.h"
#include "BIB_demande.h"
#include "conio2.h"


/* Implémentation de la machine abstraite des listes des recruteurs */

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Allouer un espace mémoire pour un maillon de la liste des recruteurs
 *
 * @param rec L'adresse du l'espace alloué pour le maillon (passage par variable)
 */
void allouerLLC_rec(ElementListeRecruteurs **rec)
{
    *rec = (ElementListeRecruteurs *)malloc(sizeof(ElementListeRecruteurs));
    if((*rec) == NULL)
    {
        printf("Probleme Allocation Dynamique !\n");
        exit(EXIT_FAILURE);
    }
    (*rec)->adr = NULL;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Retourne la valeur d'un maillon dans la liste des recruteurs
 *
 * @param rec pointeur vers le maillon qu'on veut retourner sa valeur
 * @return la valeur d'élément pointé par rec
 */
Recruteur valeurLLC_rec(PMaillonRecruteurs rec)
{
    if(rec == NULL)
    {
        printf("ATTENTION! le pointeur vers le maillon est NULL, il n'a pas de valeur!! [ERREUR-le programme sera arrete]\n");
        exit(EXIT_FAILURE);
    }
    return rec->val;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Retourne l'adresse du maillon suivant dans la liste des recruteurs
 *
 * @param rec pointeur vers le maillon qu'on veut savoire l'élément qui le suit
 * @return adresse d'élément suivant dans la liste
 */
PMaillonRecruteurs suivantLLC_rec(PMaillonRecruteurs rec)
{
    if(rec == NULL)
    {
        printf("ATTENTION! le pointeur vers le maillon est NULL, il n'existe pas le maillon suivant!! [ERREUR-le programme sera arrete]\n");
        exit(EXIT_FAILURE);
    }
    return rec->adr;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief affecter une valeur à le champ val du maillon pointé par rec
 *
 * @param rec pointeur vers un maillon de la liste des recruteurs
 * @param valeur la valeur à affecter
 */
void aff_valLLC_rec(PMaillonRecruteurs rec, Recruteur valeur)
{
    if(rec == NULL)
    {
        printf("ATTENTION! le pointeur vers le maillon est NULL, il n'existe pas le champ valeur pour le modifier!! [ERREUR-le programme sera arrete]\n");
        exit(EXIT_FAILURE);
    }
    rec->val = valeur;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief affecter une adresse à le champ adr du maillon pointé par rec
 *
 * @param rec pointeur vers un maillon de la liste des recruteurs
 * @param adresse l'adresse(pointeur) à affecter
 */
void aff_adrLLC_rec(PMaillonRecruteurs rec, PMaillonRecruteurs adresse)
{
    if(rec == NULL)
    {
        printf("ATTENTION! le pointeur vers le maillon est NULL, il n'existe pas le champ adresse pour le modifier!! [ERREUR-le programme sera arrete]\n");
        exit(EXIT_FAILURE);
    }
    rec->adr = adresse;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief libérer un maillon de la liste des recruteurs
 *
 * @param rec pointeur vers le maillon qu'on va libérer
 */
void libererLLC_rec(PMaillonRecruteurs rec)
{
    free(rec);
    rec = NULL;
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------


/* Les fonctions sur les listes des recruteurs */

//--------------------------------------------------------------------------------------------------------

/**
 * @brief construire la liste des recruteurs à partir de fichier
 *
 * @param tete la tête de la liste des recruteurs (passage par variable)
 */
void creat_LLC_rec(PMaillonRecruteurs *tete)
{
    PMaillonRecruteurs p = NULL, q = NULL;
    Recruteur valeur;
    *tete = NULL;

    FILE *fichier = fopen("data/annonceurs(recruteurs).txt", "r");
        if(fichier == NULL)
        {
            printf("Probleme d'ouverture de fichier!\n");
            exit(EXIT_FAILURE);
        }

        while(!feof(fichier)) // lire les données des recruteurs depuis le fichier
        {
            allouerLLC_rec(&p);
            fscanf(fichier, "%s %s %s %s\n", valeur.nom, valeur.adresse, valeur.mail, valeur.numeroTelephone);

            valeur.__nbrAnnonce = 0; // initialiser le nombre des annonces (offres) de chaque recruteur à 0

            for(char *c = valeur.nom; *c != '\0'; c++) // Traitement des espaces dans le nom du recruteur
            {
                if(*c == '_')
                    *c = ' ';
            }

            for(char *c = valeur.adresse; *c != '\0'; c++) // Traitement des espaces dans l'adresse du recruteur
            {
                if(*c == '_')
                    *c = ' ';
            }

            aff_valLLC_rec(p, valeur);

            // insertion dans la tete
            if(*tete == NULL)
                *tete = p;
            else
                aff_adrLLC_rec(q, p);
            q = p;
        }
    fclose(fichier);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief afficher un seul recruteur (tous les informations)
 *
 * @param rec le recruteur à afficher
 */
void printRecruteur(Recruteur rec)
{
    printf("\t+----------------------+\n");
    printf("\t| Nom du recruteur     : %s\n", rec.nom);
    printf("\t| Adresse du recruteur : %s\n", rec.adresse);
    printf("\t| Mail professionnel   : %s\n", rec.mail);
    printf("\t| Numero de telephone  : %s\n", rec.numeroTelephone);
    printf("\t| Nombre des annonces  : %d\n", rec.__nbrAnnonce);
    printf("\t+----------------------+\n\n");
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief afficher la liste des recruteurs
 *
 * @param tete la tête de la liste des recruteurs à afficher
 */
void afficher_LLC_rec(PMaillonRecruteurs tete)
{
    if(tete == NULL)
    {
        printf("\tLa liste des recruteurs est vide, rien a afficher!\n");
        return;
    }

    PMaillonRecruteurs p = tete;
    gotoxy(11, wherey());
    printf("Le 1-er recruteur: \n");
    printRecruteur(valeurLLC_rec(p));

    int i = 2;
    for(p = suivantLLC_rec(tete); p != NULL; p = suivantLLC_rec(p))
    {
        gotoxy(11, wherey());
        printf("Le %d-eme recruteur: \n", i);
        printRecruteur(valeurLLC_rec(p));
        i++;
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief libérer (supprimer) toute la liste des recruteurs sans l'archiver
 *
 * @param tete la tête de la liste des recruteurs à libérer (supprimer)
 */
void libererTous_LLC_rec(PMaillonRecruteurs *tete)
{
    PMaillonRecruteurs p = NULL;
    while(*tete != NULL)
    {
        p = *tete;
        *tete = suivantLLC_rec(*tete);
        libererLLC_rec(p);
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief calculer la taille de la liste des recruteurs
 *
 * @param tete la tête de la liste qu'on veut calculer sa taille
 * @return int la taille de la liste (le nombre des éléments)
 */
int taille_LLC_rec(PMaillonRecruteurs tete)
{
    int cpt = 0;

    for(PMaillonRecruteurs p = tete; p != NULL; p = suivantLLC_rec(p))
        cpt++;

    return cpt;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief permet à l'utilisateur de créer un nouveau recruteur
 *
 * @return Recruteur le recruteur crée
 */
Recruteur creatRecruteur(void)
{
    Recruteur rec;
    rec.__nbrAnnonce = 0; // initialiser le nombre des annonces (offres) du nouveau recruteur à 0

    system("cls");
    printf("\n\n\t\t\t    Creation d'un nouveau recruteur :  \n\n\n");

    printf("Entrer le nom du recruteur: ");
    fflush(stdin);
    fgets(rec.nom, TAILLE_CHAINE_MAX, stdin);
    rec.nom[strlen(rec.nom) - 1] = 0;

    system("cls");
    printf("\n\n\t\t\t    Creation d'un nouveau recruteur :  \n\n\n");

    printf("Entrer l'adresse du recruteur: ");
    fflush(stdin);
    fgets(rec.adresse, TAILLE_CHAINE_MAX, stdin);
    rec.adresse[strlen(rec.adresse) - 1] = 0;

    system("cls");
    printf("\n\n\t\t\t    Creation d'un nouveau recruteur :  \n\n\n");

    printf("Entrer le mail du recruteur: ");
    fflush(stdin);
    fgets(rec.mail, TAILLE_CHAINE_MAX, stdin);
    rec.mail[strlen(rec.mail) - 1] = 0;

    system("cls");
    printf("\n\n\t\t\t    Creation d'un nouveau recruteur :  \n\n\n");

    printf("Entrer le numero de telephone du recruteur: ");
    fflush(stdin);
    fgets(rec.numeroTelephone, TAILLE_CHAINE_MAX, stdin);
    rec.numeroTelephone[strlen(rec.numeroTelephone) - 1] = 0;

    fflush(stdin);
    return rec;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief permet à l'utilisateur de modifier un recruteur
 * 
 * @param recruteur le recruteur a modifier (passage par variable)
 */
void modifRecruteur(Recruteur *recruteur)
{
    Recruteur backup = *recruteur;
    int inputs = 0, choix = 0;

debut:
    system("cls");
    system("color 07");
    printf("\n\n\t\t\t    Modification des informations du recruteur :  \n\n\n");

    printf("\tVoici les informations du recruteur:\n");
    printRecruteur(*recruteur);

    printf("\n\t\t    Quelle est l'information du recruteur que vous voulez modifier :  \n\n\n");

    printf("\t1\tLe nom du recruteur\n");
    printf("\t2\tL'adresse du recruteur\n");
    printf("\t3\tLe mail du recruteur\n");
    printf("\t4\tLe numero de telephone du recruteur\n");
    textcolor(LIGHTGREEN);
    printf("\t5\tFin du modification\n");
    textcolor(LIGHTGRAY);

    printf("\n\n\t\tEntrer votre choix: ");
    fflush(stdin);
    inputs = scanf("%d", &choix);
    fflush(stdin);

    if ((inputs != 1) || (choix < 1) || (choix > 5))
    {
        system("color 47");
        goto debut;
    }


    switch (choix)
    {
        case 1:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations du recruteur :  \n\n\n");
            printf("Entrer le nouveau nom du recruteur: ");
            fflush(stdin);
            fgets(recruteur->nom, TAILLE_CHAINE_MAX, stdin);
            recruteur->nom[strlen(recruteur->nom) - 1] = 0;
            goto debut;
            break;
        }

        case 2:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations du recruteur :  \n\n\n");
            printf("Entrer la nouvelle adresse du recruteur: ");
            fflush(stdin);
            fgets(recruteur->adresse, TAILLE_CHAINE_MAX, stdin);
            recruteur->adresse[strlen(recruteur->adresse) - 1] = 0;
            goto debut;
            break;
        }

        case 3:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations du recruteur :  \n\n\n");
            printf("Entrer le nouveau mail du recruteur: ");
            fflush(stdin);
            fgets(recruteur->mail, TAILLE_CHAINE_MAX, stdin);
            recruteur->mail[strlen(recruteur->mail) - 1] = 0;
            goto debut;
            break;
        }

        case 4:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations du recruteur :  \n\n\n");
            printf("Entrer le nouveau numero de telephone du recruteur: ");
            fflush(stdin);
            fgets(recruteur->numeroTelephone, TAILLE_CHAINE_MAX, stdin);
            recruteur->numeroTelephone[strlen(recruteur->numeroTelephone) - 1] = 0;
            goto debut;
            break;
        }

        case 5:
        {
            textcolor(LIGHTGREEN);
            deleteConsoleLines(-2);
            while(True)
            {
                printf("\tAppuyez sur \"ENTRER\" pour confirmer les modifications et sur \"ECHAP\" pour annuler les modifications ... ");
                int key = getch();
                if(key == 13) // ENTRER
                {
                    fflush(stdin);
                    textcolor(LIGHTGRAY);
                    return;
                }
                else if(key == 27) // ECHAP
                {
                    *recruteur = backup;
                    fflush(stdin);
                    textcolor(LIGHTGRAY);
                    return;
                }
                deleteConsoleLines(1);
            }
            break;
        }

        default:
            break;
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief insertion d'un recruteur au début (dans la tête) de la liste des recruteurs
 *
 * @param tete la tête de la liste dans laquelle on veut insérer (passage par variable)
 * @param recruteur le recruteur à insérer
 */
void insererRecruteur_LLC_rec(PMaillonRecruteurs *tete, Recruteur recruteur)
{
    PMaillonRecruteurs p;
    allouerLLC_rec(&p);
    aff_valLLC_rec(p, recruteur);
    aff_adrLLC_rec(p, *tete);
    *tete = p;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief rechercher un recruteur dans la liste des recruteurs par son nom
 *
 * @param tete la tête de la liste dans laquelle on veut rechercher
 * @param nomRecruteur le nom du recruteur qu'on veut rechercher
 * @return PMaillonRecruteurs l'adresse du maillon de recruteur (NULL s'il n'existe pas)
 */
PMaillonRecruteurs rechRecruteurNom(PMaillonRecruteurs tete, char nomRecruteur[]) // rech par nom
{
    PMaillonRecruteurs p = tete;
    Bool trouv = False;

    // lower case tous les caractères du nom du recruteur à rechercher
    size_t nomRecruteurLen = strlen(nomRecruteur);
    char *lowerNomRecruteur = calloc(nomRecruteurLen+1, sizeof(char));
    for(size_t i = 0; i < nomRecruteurLen; i++)
    {
        lowerNomRecruteur[i] = tolower((unsigned char)nomRecruteur[i]);
    }

    while((!trouv) && (p != NULL))
    {
        // lower case tous les caractères du nom de recreteur de la liste dans laquelle on recherche
        size_t lenNomP = strlen(valeurLLC_rec(p).nom);
        char *lowerNomP = calloc(lenNomP+1, sizeof(char));
        for(size_t i = 0; i < lenNomP; i++)
        {
            lowerNomP[i] = tolower((unsigned char)valeurLLC_rec(p).nom[i]);
        }

        if(strcmp(lowerNomP, lowerNomRecruteur) == 0) // comparer les deux nouveaux noms (lower case)
            trouv = True;
        else
            p = suivantLLC_rec(p);

        free(lowerNomP);
    }

    free(lowerNomRecruteur);

    return p;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief accès par position au éléments de la liste des recruteurs
 *
 * @param tete la tête de la liste des recruteurs
 * @param position la position de recruteur dans la liste (commence par 1)
 * @return PMaillonRecruteurs l'adresse du maillon de recruteur (NULL s'il n'existe pas)
 */
PMaillonRecruteurs accesPos_LLC_rec(PMaillonRecruteurs tete, int position)
{
    PMaillonRecruteurs p = tete;
    int i = 1;

    while ((p != NULL) && (i < position))
    {
        p = suivantLLC_rec(p);
        i++;
    }

    return p;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief suppression par position des éléments de la liste des recruteurs
 *
 * @param tete la tête de la liste des recruteurs (passage par variable)
 * @param position la position à supprimer
 */
void suppressionPos_LLC_rec(PMaillonRecruteurs *tete, int position)
{
    PMaillonRecruteurs p, q;

    if(position == 1) // suppression de la tete
    {
        p = *tete;
        *tete = suivantLLC_rec(*tete);
        libererLLC_rec(p);
    }
    else if(position > 1) // le cas générale
    {
        p = accesPos_LLC_rec(*tete, position - 1);
        if(p != NULL)
        {
            q = suivantLLC_rec(p);
            if(q != NULL)
            {
                aff_adrLLC_rec(p, suivantLLC_rec(q));
                libererLLC_rec(q);
            }
        }
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief calculer la position d'un recruteur dans la liste des recruteurs
 *
 * @param tete la tête de la liste des recruteurs
 * @param recruteur le recruteur à calculer sa position dans la liste
 * @return int la position de recruteur dans la liste des recruteurs (-1 s'il n'existe pas)
 */
int position_LLC_rec(PMaillonRecruteurs tete, Recruteur recruteur)
{
    PMaillonRecruteurs p = tete;
    int position = 0;
    Bool trouv = False;

    while((p != NULL) && (!trouv))
    {
        trouv = strcmp(valeurLLC_rec(p).nom, recruteur.nom) == 0;
        position ++;
        p = suivantLLC_rec(p);
    }

    if(!trouv)
        return -1;
    return position;
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
