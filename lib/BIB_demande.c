#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "BIB_standard.h"
#include "BIB_recruteur.h"
#include "BIB_offre.h"
#include "BIB_demande.h"
#include "conio2.h"


/* Implémentation de la machine abstraite des listes des demandes */

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Allouer un espace mémoire pour un maillon de la liste des demandes
 *
 * @param dem L'adresse du l'espace alloué pour le maillon (passage par variable)
 */
void allouerLLC_dem(ElementListeDemandes **dem)
{
    *dem = (ElementListeDemandes *)malloc(sizeof(ElementListeDemandes));
    if((*dem) == NULL)
    {
        printf("Probleme Allocation Dynamique !\n");
        exit(EXIT_FAILURE);
    }
    (*dem)->adr = NULL;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Retourne la valeur d'un maillon dans la liste des demandes
 *
 * @param dem pointeur vers le maillon qu'on veut retourner sa valeur
 * @return la valeur d'élément pointé par dem
 */
Demande valeurLLC_dem(PMaillonDemandes dem)
{
    if(dem == NULL)
    {
        printf("ATTENTION! le pointeur vers le maillon est NULL, il n'a pas de valeur!! [ERREUR-le programme sera arrete]\n");
        exit(EXIT_FAILURE);
    }
    return dem->val;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Retourne l'adresse du maillon suivant dans la liste des demandes
 *
 * @param dem pointeur vers le maillon qu'on veut savoire l'élément qui le suit
 * @return adresse d'élément suivant dans la liste
 */
PMaillonDemandes suivantLLC_dem(PMaillonDemandes dem)
{
    if(dem == NULL)
    {
        printf("ATTENTION! le pointeur vers le maillon est NULL, il n'existe pas le maillon suivant!! [ERREUR-le programme sera arrete]\n");
        exit(EXIT_FAILURE);
    }
    return dem->adr;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief affecter une valeur à le champ val du maillon pointé par dem
 *
 * @param dem pointeur vers un maillon de la liste des demandes
 * @param valeur la valeur à affecter
 */
void aff_valLLC_dem(PMaillonDemandes dem, Demande valeur)
{
    if(dem == NULL)
    {
        printf("ATTENTION! le pointeur vers le maillon est NULL, il n'existe pas le champ valeur pour le modifier!! [ERREUR-le programme sera arrete]\n");
        exit(EXIT_FAILURE);
    }
    dem->val = valeur;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief affecter une adresse à le champ adr du maillon pointé par dem
 *
 * @param dem pointeur vers un maillon de la liste des demandes
 * @param adresse l'adresse(pointeur) à affecter
 */
void aff_adrLLC_dem(PMaillonDemandes dem, PMaillonDemandes adresse)
{
    if(dem == NULL)
    {
        printf("ATTENTION! le pointeur vers le maillon est NULL, il n'existe pas le champ adresse pour le modifier!! [ERREUR-le programme sera arrete]\n");
        exit(EXIT_FAILURE);
    }
    dem->adr = adresse;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief libérer un maillon de la liste des demandes
 *
 * @param dem pointeur vers le maillon qu'on va libérer
 */
void libererLLC_dem(PMaillonDemandes dem)
{
    free(dem);
    dem = NULL;
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------


/* Les fonctions sur les listes des demandes */

//--------------------------------------------------------------------------------------------------------

/**
 * @brief construire la liste des demandes à partir de fichier
 *
 * @param tete la tête de la liste des demandes à construire (passage par variable)
 */
void creat_LLC_dem(PMaillonDemandes *tete)
{
    // Déclaration des variables et initialisations
    PMaillonDemandes p = NULL, q = NULL;
    Demande valeur;
    *tete = NULL;
    char tempCompetences[TAILLE_CHAINE_MAX], tempLangues[TAILLE_CHAINE_MAX], tempDiplome[TAILLE_CHAINE_MAX], *tempChaine = NULL;

    FILE *fichier = fopen("data/annonces(demandes).txt", "r");
        if(fichier == NULL)
        {
            printf("Probleme d'ouverture de fichier!\n");
            exit(EXIT_FAILURE);
        }

        while(!feof(fichier))
        {
            // allouer un nouveau maillon et le initialiser apartir d'une ligne de fichier
            allouerLLC_dem(&p);

            // Récupération des données depuis le fichier
            fscanf(fichier, "%s %d/%d/%d %s %d %s %s\n", \
            valeur.nomDuDemandeur, &valeur.datePublication.jour, &valeur.datePublication.mois, \
            &valeur.datePublication.annee, tempDiplome, &valeur.nbrAnneesEXP, tempCompetences, tempLangues);

            // Traitement des espaces dans le nom du demandeur
            for(char *c = valeur.nomDuDemandeur; *c != '\0'; c++)
            {
                if(*c == '_')
                    *c = ' ';
            }

            // initialisation des tableaux des diplôme
            for(int i = 0; i < MAX_DIPLOME; i++)
                strcpy(valeur.diplome[i], "");

            // Remplir le tableau des diplômes
            int indice = 0;
            tempChaine = strtok(tempDiplome, "(,)"); // diviser la chaine des diplome selon le délémiteur ','
            while(tempChaine != NULL)
            {
                strcpy(valeur.diplome[indice], tempChaine);

                // Traitement des espaces dans les diplômes de demandeur
                for(char *c = valeur.diplome[indice]; *c != '\0'; c++)
                {
                    if(*c == '_')
                    *c = ' ';
                }

                tempChaine = strtok(NULL, "(,)");
                indice++;
            }

            // initialisation des tableaux des compitences
            for(int i = 0; i < MAX_COMPETENCES; i++)
                valeur.competences[i] = False;

            // Remplir le tableau des compitences
            tempChaine = strtok(tempCompetences, "(,)"); // diviser la chaine des competences selon le délémiteur ','
            while(tempChaine != NULL)
            {
                valeur.competences[StrToInt(tempChaine)] = True;
                tempChaine = strtok(NULL, "(,)");
            }

            // initialisation des tableaux des langues
            for(int i = 0; i < MAX_LANGUES; i++)
                valeur.languesMaitrisees[i] = False;

            // remplir le tableau des langues
            tempChaine = strtok(tempLangues, "(,)"); // diviser la chaine des langues selon le délémiteur ','
            while(tempChaine != NULL)
            {
                valeur.languesMaitrisees[StrToInt(tempChaine)] = True;
                tempChaine = strtok(NULL, "(,)");
            }

            aff_valLLC_dem(p, valeur);

            // insertion dans la tete
            if(*tete == NULL)
                *tete = p;
            else
                aff_adrLLC_dem(q, p);
            q = p;
        }
    fclose(fichier);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief afficher une seule demande (tous les informations)
 *
 * @param dem la demande à afficher
 */
void printDemande(Demande dem)
{
    char temp[TAILLE_CHAINE_MAX] = {};

    printf("\t+------------------------------+\n");
    printf("\t| Nom du demandeur             : %s\n", dem.nomDuDemandeur);
    printf("\t| Date de publication          : %d/%d/%d\n", dem.datePublication.jour, dem.datePublication.mois, dem.datePublication.annee);

    printf("\t| Diplomes                     : \n");
    for(int i = 0; i < MAX_DIPLOME; i++)
    {
        if(strcmp(dem.diplome[i], "") == 0)
            break;

        printf("\t| ");
        gotoxy(40, wherey());
        printf(":> %s\n", dem.diplome[i]);
    }

    (dem.nbrAnneesEXP == 1) ? printf("\t| Nombre d'annees d'experiences: %d an\n", dem.nbrAnneesEXP) : printf("\t| Nombre d'annees d'experiences: %d ans\n", dem.nbrAnneesEXP);

    printf("\t| Liste des competences        : \n");
    for(int i = 0; i < MAX_COMPETENCES; i++)
    {
        if(dem.competences[i])
        {
            decoderCompetence(i, temp);
            printf("\t| ");
            gotoxy(40, wherey());
            printf(":> %s\n", temp);
        }
    }

    printf("\t| Langues maitrisees           : \n");
    for(int i = 0; i < MAX_LANGUES; i++)
    {
        if(dem.languesMaitrisees[i])
        {
            decoderLangue(i, temp);
            printf("\t| ");
            gotoxy(40, wherey());
            printf(":> %s\n", temp);
        }
    }

    printf("\t+------------------------------+\n\n");
}

//----------------------------random names----------------------------------------------------------------------------

/**
 * @brief afficher la liste des demandes
 *
 * @param tete la tête de la liste des demandes à afficher
 */
void afficher_LLC_dem(PMaillonDemandes tete)
{
    if(tete == NULL)
    {
        printf("\tLa liste des demandes est vide, rien a afficher!\n");
        return;
    }

    PMaillonDemandes p = tete;
    gotoxy(16, wherey());
    printf("La 1-ere demande: \n");
    printDemande(valeurLLC_dem(p));

    int i = 2;
    for(p = suivantLLC_dem(tete); p != NULL; p = suivantLLC_dem(p))
    {
        gotoxy(16, wherey());
        printf("La %d-eme demande: \n", i);
        printDemande(valeurLLC_dem(p));
        i++;
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief libérer (supprimer) toute la liste des demandes sans l'archiver
 *
 * @param tete la tête de la liste des demandes à libérer (supprimer)
 */
void libererTous_LLC_dem(PMaillonDemandes *tete)
{
    while(*tete != NULL)
    {
        PMaillonDemandes p = *tete;
        *tete = suivantLLC_dem(*tete);
        libererLLC_dem(p);
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief calculer la taille de la liste des demandes
 *
 * @param tete la tête de la liste qu'on veut calculer sa taille
 * @return int la taille de la liste (le nombre des éléments)
 */
int taille_LLC_dem(PMaillonDemandes tete)
{
    int cpt = 0;
    for(PMaillonDemandes p = tete; p != NULL; p = suivantLLC_dem(p))
        cpt++;
    return cpt;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Tester si deux demandes sont identique
 *
 * @param dem1 la première demande
 * @param dem2 la deuxième demande
 * @return Bool le résultat de la comparaison entre les deux demandes
 */
Bool eq_dem(Demande dem1, Demande dem2)
{
    // comparer le nom du demandeur
    if(! comparerStr(dem1.nomDuDemandeur, dem2.nomDuDemandeur))
        return False;

    // comparer la date de publication
    if(datecmp(dem1.datePublication, dem2.datePublication) != 0)
        return False;

    // comparer le nombre d'années d'expériences
    if(dem1.nbrAnneesEXP != dem2.nbrAnneesEXP)
        return False;

    // comparer les compétences
    for(int i = 0; i < MAX_COMPETENCES; i++)
    {
        if((dem1.competences[i] != dem2.competences[i]))
            return False;
    }

    // comparer les lanues maitrisées
    for(int i = 0; i < MAX_LANGUES; i++)
    {
        if((dem1.languesMaitrisees[i] != dem2.languesMaitrisees[i]))
            return False;
    }

    // comparer les diplôme
    Bool trouv;
    int j;
    for(int i = 0; ((i < MAX_DIPLOME) && (strcmp(dem1.diplome[i], "") != 0)); i++) // parcourir les diplômes du premier demandeur
    {
        // rechercher dem1.diplome[i] dans la liste des diplomes du deuxième demandeur et si il n'existe pas : return False
        trouv = False;

        j = 0;
        while((j < MAX_DIPLOME) && (strcmp(dem2.diplome[j],"") != 0) && (! trouv))
        {
            trouv = comparerStr(dem1.diplome[i], dem2.diplome[j]);
            j++;
        }

        if(! trouv)
            return False;
    }


    return True;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief permet à l'utilisateur de créer une nouvelle demande
 *
 * @return Demande la demande crée
 */
Demande creatDemande(void)
{
    Demande dem;

    system("cls");
    printf("\n\n\t\t\t    Creation d'une nouvelle demande :  \n\n\n");

    printf("Entrer le nom du demandeur: ");
    fflush(stdin);
    fgets(dem.nomDuDemandeur, TAILLE_CHAINE_MAX, stdin);
    dem.nomDuDemandeur[strlen(dem.nomDuDemandeur) - 1] = 0;
    fflush(stdin);

    system("cls");
    printf("\n\n\t\t\t    Creation d'une nouvelle demande :  \n\n\n");

    printf("Entrer la date de publication : \n");
    scanDate(&dem.datePublication);

    system("cls");
    printf("\n\n\t\t\t    Creation d'une nouvelle demande :  \n\n\n");

    scanDiplomes(dem.diplome);

    system("cls");
    printf("\n\n\t\t\t    Creation d'une nouvelle demande :  \n\n\n");

    printf("Entrer le nombre d'annees d'experiences: ");
scan:
    fflush(stdin);
    system("color 07");
    int inputs = scanf("%d", &dem.nbrAnneesEXP);
    if((inputs != 1) || (dem.nbrAnneesEXP < 0))
    {
        system("color 47");
        printf("\033[A\33[2K\rEntrer le nombre d'annees d'experiences: ");
        goto scan;
    }
    fflush(stdin);

    system("cls");
    printf("\n\n\t\t\t    Creation d'une nouvelle demande :  \n\n\n");

    scanCompetences(dem.competences);

    system("cls");
    printf("\n\n\t\t\t    Creation d'une nouvelle demande :  \n\n\n");

    scanLangues(dem.languesMaitrisees);

    fflush(stdin);
    return dem;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief permet à l'utilisateur de modifier une demande
 * 
 * @param demande la demande a modifier (passage par variable)
 */
void modifDemande(Demande *demande)
{
    Demande backup = *demande;
    int inputs = 0, choix = 0;

debut:
    system("cls");
    system("color 07");
    printf("\n\n\t\t\t    Modification des informations du demande :  \n\n\n");

    printf("\tVoici les informations du demande:\n");
    printDemande(*demande);

    printf("\n\t\t    Quelle est l'information du demande que vous voulez modifier :  \n\n\n");

    printf("\t1\tLe nom du demandeur\n");
    printf("\t2\tLa date de publication\n");
    printf("\t3\tLes diplomes\n");
    printf("\t4\tLe nombre d'annees d'experiences\n");
    printf("\t5\tLes competences\n");
    printf("\t6\tLes langues maitrisees\n");
    textcolor(LIGHTGREEN);
    printf("\t7\tFin du modification\n");
    textcolor(LIGHTGRAY);

    printf("\n\n\t\tEntrer votre choix: ");
    fflush(stdin);
    inputs = scanf("%d", &choix);
    fflush(stdin);

    if ((inputs != 1) || (choix < 1) || (choix > 7))
    {
        system("color 47");
        goto debut;
    }

    switch (choix)
    {
        case 1:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations du demande :  \n\n\n");
            printf("Entrer le nouveau nom du demandeur: ");
            fflush(stdin);
            fgets(demande->nomDuDemandeur, TAILLE_CHAINE_MAX, stdin);
            demande->nomDuDemandeur[strlen(demande->nomDuDemandeur) - 1] = 0;
            fflush(stdin);
            goto debut;
            break;
        }

        case 2:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations du demande :  \n\n\n");
            printf("\n\nEntrer la nouvelle date de publication \n");
            scanDate(&demande->datePublication);
            goto debut;
            break;
        }

        case 3:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations du demande :  \n\n\n");
            scanDiplomes(demande->diplome);
            goto debut;
            break;
        }

        case 4:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations du demande :  \n\n\n");
            printf("Entrer le nouveau nombre d'annees d'experiences: ");
scan:
            system("color 07");
            fflush(stdin);
            int inputs = scanf("%d", &demande->nbrAnneesEXP);
            if((inputs != 1) || (demande->nbrAnneesEXP < 0))
            {
                system("color 47");
                printf("\033[A\33[2K\rEntrer le nouveau nombre d'annees d'experiences: ");
                goto scan;
            }
            fflush(stdin);
            goto debut;
            break;
        }

        case 5:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations du demande :  \n\n\n");
            scanCompetences(demande->competences);
            goto debut;
            break;
        }

        case 6:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations du demande :  \n\n\n");
            scanLangues(demande->languesMaitrisees);
            goto debut;
            break;
        }

        case 7:
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
                    *demande = backup;
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
 * @brief insertion d'une demande au début (dans la tête) de la liste des demandes
 *
 * @param tete la tête de la liste dans laquelle on veut insérer (passage par variable)
 * @param demande la demade à insérer
 */
void insererDemande_LLC_dem(PMaillonDemandes *tete, Demande demande)
{
    PMaillonDemandes p;
    allouerLLC_dem(&p);
    aff_valLLC_dem(p, demande);
    aff_adrLLC_dem(p, *tete);
    *tete = p;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief accès par position au éléments de la liste des demandes
 *
 * @param tete la tête de la liste des demandes
 * @param position la position de la demande dans la liste (commence par 1)
 * @return PMaillonDemandes l'adresse du maillon de la demande (NULL s'il n'existe pas)
 */
PMaillonDemandes accesPos_LLC_dem(PMaillonDemandes tete, int position)
{
    PMaillonDemandes p = tete;
    int i = 1;

    while((p != NULL) && (i < position))
    {
        p = suivantLLC_dem(p);
        i++;
    }

    return p;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief suppression par position des éléments de la liste des demandes
 *
 * @param tete la tête de la liste des demandes (passage par variable)
 * @param position la position de la demande à supprimer
 */
void suppressionPos_LLC_dem(PMaillonDemandes *tete, int position)
{
    PMaillonDemandes p, q;

    if(position == 1)
    {
        p = *tete;
        *tete = suivantLLC_dem(*tete);
        libererLLC_dem(p);
    }
    else if(position > 1)
    {
        p = accesPos_LLC_dem(*tete, position - 1);
        if(p != NULL)
        {
            q = suivantLLC_dem(p);
            if(q != NULL)
            {
                aff_adrLLC_dem(p, suivantLLC_dem(q));
                libererLLC_dem(q);
            }
        }
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief calculer le nombre des compétences maitrisées par un demandeur
 *
 * @param demande une demande
 * @return int le nombre des compétences maitrisées par l'annonceur de la demande
 */
int nbrCompetences_dem(Demande demande)
{
    int cpt = 0;

    for(int i = 0; i < MAX_COMPETENCES; i++)
    {
        if(demande.competences[i] == True)
            cpt++;
    }

    return cpt;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief vérifier si la demande satisfait la critère suivante: maitrisant au moins une langue requise
 *
 * @param demande une demande
 * @param offre une offre
 * @return Bool le résultat de la vérification
 */
Bool verifierLangues(Demande demande, Offre offre)
{
    for(int i = 0; i < MAX_LANGUES; i++)
    {
        if(offre.languesExige[i] && demande.languesMaitrisees[i])
            return True;
    }
    return False;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief vérifier si la demande satisfait la critère suivante: ayant au moins 2 compétences requises
 *
 * @param demande une demande
 * @param offre une offre
 * @return Bool le résultat de la vérification
 */
Bool verifierCompetences(Demande demande, Offre offre)
{
    int cpt = 0;

    for(int i = 0; i < MAX_LANGUES; i++)
    {
        if(offre.competencesRequises[i] && demande.competences[i])
        {
            cpt++;

            if(cpt == 2) // si le nombre des compéteces requises atteint 2
                return True;
        }
    }

    return False;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief vérifier si la demande satisfait la critère suivante: même diplôme ou plus
 *
 * @param demande une demande
 * @param offre une offre
 * @return Bool le résultat de la vérification
 */
Bool verifierDiplomes(Demande demande, Offre offre)
{
    // lower case tous les caractères du dîplome exigé
    size_t lenDiplome_off = strlen(offre.diplomeExige);
    char *lowerDiplome_off = calloc(lenDiplome_off+1, sizeof(char));
    for(size_t i = 0; i < lenDiplome_off; i++)
    {
        lowerDiplome_off[i] = tolower((unsigned char)offre.diplomeExige[i]);
    }

    for(int i = 0; ((i < MAX_DIPLOME) && (strcmp(demande.diplome[i], "") != 0)); i++)
    {
        // lower case tous les caractères des dîplomes de demandeur
        size_t lenDiplome_dem = strlen(demande.diplome[i]);
        char *lowerDiplome_dem = calloc(lenDiplome_dem+1, sizeof(char));
        for(size_t j = 0; j < lenDiplome_dem; j++)
        {
            lowerDiplome_dem[j] = tolower((unsigned char)demande.diplome[i][j]);
        }

        if(strcmp(lowerDiplome_dem, lowerDiplome_off) == 0) // comparer les deux nouveaux dîplomes (lower case)
            return True;

        free(lowerDiplome_dem);
    }

    free(lowerDiplome_off);

    return False;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief valider une demande selon les critères :
 *      même diplôme ou plus,
 *      ayant au moins 2 compétences requises,
 *      maitrisant au moins une langue requise.
 *
 * @param demande une demande
 * @param offre une offre
 * @return Bool
 */
Bool validerDemande(Demande demande, Offre offre)
{
    if(verifierLangues(demande, offre) && verifierCompetences(demande, offre) && verifierDiplomes(demande, offre))
        return True;
    return False;
}


//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
