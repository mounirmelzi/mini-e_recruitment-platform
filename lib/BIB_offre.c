#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "BIB_standard.h"
#include "BIB_recruteur.h"
#include "BIB_offre.h"
#include "BIB_demande.h"
#include "conio2.h"


/* Implémentation de la machine abstraite des listes des offres */

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Allouer un espace mémoire pour un maillon de la liste des offres
 *
 * @param off L'adresse du l'espace alloué pour le maillon (passage par variable)
 */
void allouerLLC_off(ElementListeOffres **off)
{
    *off = (ElementListeOffres *)malloc(sizeof(ElementListeOffres));
    if((*off) == NULL)
    {
        printf("Probleme Allocation Dynamique !\n");
        exit(EXIT_FAILURE);
    }
    (*off)->adr = NULL;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Retourne la valeur d'un maillon dans la liste des offres
 *
 * @param off pointeur vers le maillon qu'on veut retourner sa valeur
 * @return la valeur d'élément pointé par off
 */
Offre valeurLLC_off(PMaillonOffres off)
{
    if(off == NULL)
    {
        printf("ATTENTION! le pointeur vers le maillon est NULL, il n'a pas de valeur!! [ERREUR-le programme sera arrete]\n");
        exit(EXIT_FAILURE);
    }
    return off->val;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Retourne l'adresse du maillon suivant dans la liste des offres
 *
 * @param off pointeur vers le maillon qu'on veut savoire l'élément qui le suit
 * @return adresse d'élément suivant dans la liste
 */
PMaillonOffres suivantLLC_off(PMaillonOffres off)
{
    if(off == NULL)
    {
        printf("ATTENTION! le pointeur vers le maillon est NULL, il n'existe pas le maillon suivant!! [ERREUR-le programme sera arrete]\n");
        exit(EXIT_FAILURE);
    }
    return off->adr;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief affecter une valeur à le champ val du maillon pointé par off
 *
 * @param off pointeur vers un maillon de la liste des offres
 * @param valeur la valeur à affecter
 */
void aff_valLLC_off(PMaillonOffres off, Offre valeur)
{
    if(off == NULL)
    {
        printf("ATTENTION! le pointeur vers le maillon est NULL, il n'existe pas le champ valeur pour le modifier!! [ERREUR-le programme sera arrete]\n");
        exit(EXIT_FAILURE);
    }
    off->val = valeur;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief affecter une adresse à le champ adr du maillon pointé par off
 *
 * @param off pointeur vers un maillon de la liste des offres
 * @param adresse l'adresse(pointeur) à affecter
 */
void aff_adrLLC_off(PMaillonOffres off, PMaillonOffres adresse)
{
    if(off == NULL)
    {
        printf("ATTENTION! le pointeur vers le maillon est NULL, il n'existe pas le champ adresse pour le modifier!! [ERREUR-le programme sera arrete]\n");
        exit(EXIT_FAILURE);
    }
    off->adr = adresse;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief libérer un maillon de la liste des offres
 *
 * @param off pointeur vers le maillon qu'on va libérer
 */
void libererLLC_off(PMaillonOffres off)
{
    free(off);
    off = NULL;
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------


/* Les fonctions sur les listes des offres */

//--------------------------------------------------------------------------------------------------------

/**
 * @brief construire la liste des offres à partir de fichier
 *
 * @param tete la tête de la liste des offres à construire (passage par variable)
 * @param listeRecruteurs la tête de la liste des recruteurs (pour modifier le nombre des annonce du recruteur)
 */
void creat_LLC_off(PMaillonOffres *tete, PMaillonRecruteurs listeRecruteurs)
{
    // Déclaration des variables et initialisations
    PMaillonOffres p = NULL, q = NULL;
    Offre valeur;
    *tete = NULL;
    char tempCompetences[TAILLE_CHAINE_MAX], tempLangues[TAILLE_CHAINE_MAX], *tempChaine = NULL;

    FILE *fichier = fopen("data/annonces(offres).txt", "r");
        if(fichier == NULL)
        {
            printf("Probleme d'ouverture de fichier!\n");
            exit(EXIT_FAILURE);
        }

        while(!feof(fichier))
        {
            // allouer un nouveau maillon et le initialiser apartir d'une ligne de fichier
            allouerLLC_off(&p);
            // Récupération des données depuis le fichier
            fscanf(fichier, "%s %s %s %d %s %s %d/%d/%d %d/%d/%d\n", \
            valeur.nomDuRecruteur, valeur.intituleDuPoste, valeur.diplomeExige, &(valeur.nbrAnneesEXP), \
            tempCompetences, tempLangues, &(valeur.datePublication.jour), &(valeur.datePublication.mois), \
            &(valeur.datePublication.annee), &(valeur.delaiEnvoi.jour), &(valeur.delaiEnvoi.mois), \
            &(valeur.delaiEnvoi.annee));

            // Traitement des espaces dans nom du recruteur
            for(char *c = valeur.nomDuRecruteur; *c != '\0'; c++)
            {
                if(*c == '_')
                    *c = ' ';
            }

            // Traitement des espaces dans intitulé du poste
            for(char *c = valeur.intituleDuPoste; *c != '\0'; c++)
            {
                if(*c == '_')
                    *c = ' ';
            }

            // Traitement des espaces dans diplôme exigé
            for(char *c = valeur.diplomeExige; *c != '\0'; c++)
            {
                if(*c == '_')
                    *c = ' ';
            }

            // initialisation des tableaux des compitences
            for(int i = 0; i < MAX_COMPETENCES; i++)
                valeur.competencesRequises[i] = False;

            // remplir le tableau des competences
            tempChaine = strtok(tempCompetences, "(,)"); // diviser la chaine des competences selon le délémiteur ','
            while(tempChaine != NULL)
            {
                valeur.competencesRequises[StrToInt(tempChaine)] = True;
                tempChaine = strtok(NULL, "(,)");
            }

            // initialisation des tableaux des langues
            for(int i = 0; i < MAX_LANGUES; i++)
                valeur.languesExige[i] = False;

            // remplir le tableau des langues
            tempChaine = strtok(tempLangues, "(,)"); // diviser la chaine des langues selon le délémiteur ','
            while(tempChaine != NULL)
            {
                valeur.languesExige[StrToInt(tempChaine)] = True;
                tempChaine = strtok(NULL, "(,)");
            }


            // Mise à jour le nombre des annonces de recruteur
            PMaillonRecruteurs adrRecruteur = rechRecruteurNom(listeRecruteurs, valeur.nomDuRecruteur);
            if(adrRecruteur == NULL)
            {
                printf("Vous avez ajouter une annonce depuis le fichier des offres, mais son annonceur n'existe pas dans la liste des recruteurs !!\n");
            }
            else
            {
                (adrRecruteur->val).__nbrAnnonce++;
            }


            aff_valLLC_off(p, valeur);

            // insertion dans la tete
            if(*tete == NULL)
                *tete = p;
            else
                aff_adrLLC_off(q, p);
            q = p;
        }
    fclose(fichier);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief afficher une seule offre (tous les informations)
 *
 * @param off l'offre à afficher
 */
void printOffre(Offre off)
{
    char temp[TAILLE_CHAINE_MAX] = {};

    printf("\t+--------------------------------+\n");
    printf("\t| Nom du recruteur               : %s\n", off.nomDuRecruteur);
    printf("\t| Intitule du poste              : %s\n", off.intituleDuPoste);
    printf("\t| Diplome exige                  : %s\n", off.diplomeExige);
    (off.nbrAnneesEXP == 1) ? printf("\t| Nombre d'annees d'experiences  : %d an\n", off.nbrAnneesEXP) :  printf("\t| Nombre d'annees d'experiences  : %d ans\n", off.nbrAnneesEXP);

    printf("\t| Liste des competences requises :\n");
    for(int i = 0; i < MAX_COMPETENCES; i++)
    {
        if(off.competencesRequises[i])
        {
            decoderCompetence(i, temp);
            printf("\t| ");
            gotoxy(42, wherey());
            printf(":> %s\n", temp);
        }
    }

    printf("\t| Langues exigees                :\n");
    for(int i = 0; i < MAX_LANGUES; i++)
    {
        if(off.languesExige[i])
        {
            decoderLangue(i, temp);
            printf("\t| ");
            gotoxy(42, wherey());
            printf(":> %s\n", temp);
        }
    }

    printf("\t| Date de publication            : %d/%d/%d\n", off.datePublication.jour, off.datePublication.mois, off.datePublication.annee);
    printf("\t| Delai d'envoi des candidatures : %d/%d/%d\n", off.delaiEnvoi.jour, off.delaiEnvoi.mois, off.delaiEnvoi.annee);

    printf("\t+--------------------------------+\n\n");
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief afficher la liste des offres
 *
 * @param tete la tête de la liste des offres à afficher
 */
void afficher_LLC_off(PMaillonOffres tete)
{
    if(tete == NULL)
    {
        printf("\tLa liste des offres est vide, rien a afficher!\n");
        return;
    }

    PMaillonOffres p = tete;
    gotoxy(16, wherey());
    printf("La 1-ere offre: \n");
    printOffre(valeurLLC_off(p));

    int i = 2;
    for(p = suivantLLC_off(tete); p != NULL; p = suivantLLC_off(p))
    {
        gotoxy(16, wherey());
        printf("La %d-eme offre: \n", i);
        printOffre(valeurLLC_off(p));
        i++;
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief libérer (supprimer) toute la liste des offres sans l'archiver
 *
 * @param tete la tête de la liste des offres à libérer (supprimer)
 */
void libererTous_LLC_off(PMaillonOffres *tete)
{
    while (*tete != NULL)
    {
        PMaillonOffres p = *tete;
        *tete = suivantLLC_off(*tete);
        libererLLC_off(p);
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief calculer la taille de la liste des offres
 *
 * @param tete la tête de la liste qu'on veut calculer sa taille
 * @return int la taille de la liste (le nombre des éléments)
 */
int taille_LLC_off(PMaillonOffres tete)
{
    int cpt = 0;
    for(PMaillonOffres p = tete; p != NULL; p = suivantLLC_off(p))
        cpt++;
    return cpt;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Tester si deux offres sont identique
 *
 * @param off1 la première offre
 * @param off2 la deuxième offre
 * @return Bool le résultat de la comparaison entre les deux offres
 */
Bool eq_off(Offre off1, Offre off2)
{
    // comparer le nom du recruteur
    if(! comparerStr(off1.nomDuRecruteur, off2.nomDuRecruteur))
        return False;

    // comparer l'intitulé du poste
    if(! comparerStr(off1.intituleDuPoste, off2.intituleDuPoste))
        return False;

    // comparer le diplôme éxigé
    if(! comparerStr(off1.diplomeExige, off2.diplomeExige))
        return False;

    // comparer le nombre d'années d'expériences
    if(off1.nbrAnneesEXP != off2.nbrAnneesEXP)
        return False;

    // comparer les compétences requises
    for(int i = 0; i < MAX_COMPETENCES; i++)
    {
        if((off1.competencesRequises[i] != off2.competencesRequises[i]))
            return False;
    }

    // comparer les langue
    for(int i = 0; i < MAX_LANGUES; i++)
    {
        if((off1.languesExige[i] != off2.languesExige[i]))
            return False;
    }

    // comparer la date de publication
    if(datecmp(off1.datePublication, off2.datePublication) != 0)
        return False;

    // comparer le délai d'envoi
    if(datecmp(off1.delaiEnvoi, off2.delaiEnvoi) != 0)
        return False;


    return True;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief permet à l'utilisateur de créer une nouvelle offre
 *
 * @param listeRecruteurs la liste des recruteurs pour modifier le nombre des annonces
 * @param Recruteur_Existe booléen pour connaître si le recruteur existe dans la liste des recruteurs ou il est nouveau recruteur
 * @return Offre l'offre crée
 */
Offre creatOffre(PMaillonRecruteurs listeRecruteurs, Bool *Recruteur_Existe)
{
    Offre off;

    system("cls");
    printf("\n\n\t\t\t    Creation d'une nouvelle offre :  \n\n\n");

    printf("Entrer le nom du recruteur: ");
    fflush(stdin);
    fgets(off.nomDuRecruteur, TAILLE_CHAINE_MAX, stdin);
    off.nomDuRecruteur[strlen(off.nomDuRecruteur) - 1] = 0;
    fflush(stdin);


    // mise à jour la liste des recreteurs après la creation d'une nouvelle offre
    PMaillonRecruteurs adrRecruteur = rechRecruteurNom(listeRecruteurs, off.nomDuRecruteur); // rechercher et accéder au recruteur dans la liste des recruteurs
    if(adrRecruteur == NULL) // si le recruteur n'existe pas
    {
        *Recruteur_Existe = False;
        return off; // ATTENTION ! valeur aléatoire à ne pas utiliser !! il faut vérifier la vaiable Recruteur_Existe
    }
    else
    {
        (adrRecruteur->val).__nbrAnnonce++; // incrémentation de nombre des annonces du recruteur s'il existe
        *Recruteur_Existe = True;
    }

    system("cls");
    printf("\n\n\t\t\t    Creation d'une nouvelle offre :  \n\n\n");

    printf("Entrer l'intitule du poste: ");
    fflush(stdin);
    fgets(off.intituleDuPoste, TAILLE_CHAINE_MAX, stdin);
    off.intituleDuPoste[strlen(off.intituleDuPoste) - 1] = 0;
    fflush(stdin);

    system("cls");
    printf("\n\n\t\t\t    Creation d'une nouvelle offre :  \n\n\n");

    printf("Dipome: ");
    fflush(stdin);
    fgets(off.diplomeExige, TAILLE_CHAINE_MAX, stdin);
    off.diplomeExige[strlen(off.diplomeExige) - 1] = 0;
    fflush(stdin);

    system("cls");
    printf("\n\n\t\t\t    Creation d'une nouvelle offre :  \n\n\n");

    printf("Entrer le nombre d'annees d'experiences: ");
scan1:
    fflush(stdin);
    system("color 07");
    int inputs = scanf("%d", &off.nbrAnneesEXP);
    if((inputs != 1) || (off.nbrAnneesEXP < 0))
    {
        system("color 47");
        printf("\033[A\33[2K\rEntrer le nombre d'annees d'experiences: ");
        goto scan1;
    }
    fflush(stdin);

    system("cls");
    printf("\n\n\t\t\t    Creation d'une nouvelle offre :  \n\n\n");

    scanCompetences(off.competencesRequises);

    system("cls");
    printf("\n\n\t\t\t    Creation d'une nouvelle offre :  \n\n\n");

    scanLangues(off.languesExige);

scan2:
    system("cls");
    system("color 07");
    printf("\n\n\t\t\t    Creation d'une nouvelle offre :  \n\n\n");

    printf("Entrer la date de publication : \n");
    scanDate(&off.datePublication);

    printf("\n\n\n\rEntrer le delai d'envoi de candidature : \n");
    scanDate(&off.delaiEnvoi);

    if(datecmp(off.datePublication, off.delaiEnvoi) > 0)
    {
        system("color 47");
        printf("\n\n\n\tATTENTION !! Impossible d'avoir un delai d'envoi avant la date de publication !!\n");
        printf("\n\tAppuyez sur une touche pour re-entrer les deux dates: de publication et de delai d'envoi ... ");
        getch();
        goto scan2;
    }

    fflush(stdin);
    return off;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief permet à l'utilisateur de modifier une offre
 * 
 * @param offre l'offre a modifier (passage par variable)
 */
void modifOffre(Offre *offre)
{
    Offre backup = *offre;
    int inputs = 0, choix = 0;

debut:
    system("cls");
    system("color 07");
    printf("\n\n\t\t\t    Modification des informations de l'offre :  \n\n\n");

    printf("\tVoici les informations de l'offre:\n");
    printOffre(*offre);

    printf("\n\t\t    Quelle est l'information de l'offre que vous voulez modifier :  \n\n\n");

    printf("\t1\tL'intitule du poste\n");
    printf("\t2\tLe diplome exige\n");
    printf("\t3\tLe nombre d'annees d'experiences\n");
    printf("\t4\tLes competences requises\n");
    printf("\t5\tLes langues exigees\n");
    printf("\t6\tLa date de publication\n");
    printf("\t7\tLe delai d'envoi des candidatures\n");
    textcolor(LIGHTGREEN);
    printf("\t8\tFin du modification\n");
    textcolor(LIGHTGRAY);

    printf("\n\n\t\tEntrer votre choix: ");
    fflush(stdin);
    inputs = scanf("%d", &choix);
    fflush(stdin);

    if ((inputs != 1) || (choix < 1) || (choix > 8))
    {
        system("color 47");
        goto debut;
    }

    switch (choix)
    {
        case 1:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations de l'offre :  \n\n\n");
            printf("Entrer le nouveau intitule du poste: ");
            fflush(stdin);
            fgets(offre->intituleDuPoste, TAILLE_CHAINE_MAX, stdin);
            offre->intituleDuPoste[strlen(offre->intituleDuPoste) - 1] = 0;
            fflush(stdin);
            goto debut;
            break;
        }

        case 2:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations de l'offre :  \n\n\n");
            printf("Le nouveau dipome: ");
            fflush(stdin);
            fgets(offre->diplomeExige, TAILLE_CHAINE_MAX, stdin);
            offre->diplomeExige[strlen(offre->diplomeExige) - 1] = 0;
            fflush(stdin);
            goto debut;
            break;
        }

        case 3:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations de l'offre :  \n\n\n");
            printf("Entrer le nouveau nombre d'annees d'experiences: ");
scan1:
            fflush(stdin);
            system("color 07");
            int inputs = scanf("%d", &offre->nbrAnneesEXP);
            if((inputs != 1) || (offre->nbrAnneesEXP < 0))
            {
                system("color 47");
                printf("\033[A\33[2K\rEntrer le nouveau nombre d'annees d'experiences: ");
                goto scan1;
            }
            fflush(stdin);
            goto debut;
            break;
        }

        case 4:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations de l'offre :  \n\n\n");
            scanCompetences(offre->competencesRequises);
            goto debut;
            break;
        }

        case 5:
        {
            system("cls");
            printf("\n\n\t\t\t    Modification des informations de l'offre :  \n\n\n");
            scanLangues(offre->languesExige);
            goto debut;
            break;
        }

        case 6:
        {
scan2:
            system("cls");
            system("color 07");
            printf("\n\n\t\t\t    Modification des informations de l'offre :  \n\n\n");
            printf("Entrer la nouvelle date de publication : \n");
            scanDate(&offre->datePublication);
            if(datecmp(offre->datePublication, offre->delaiEnvoi) > 0)
            {
                system("color 47");
                printf("\n\n\n\tATTENTION !! Impossible d'avoir une date de publication apres le delai d'envoi des candidatures !!\n");
                printf("\n\tAppuyez sur une touche pour re-entrer la date de publication ... ");
                getch();
                goto scan2;
            }
            goto debut;
            break;
        }

        case 7:
        {
scan3:
            system("cls");
            system("color 07");
            printf("\n\n\t\t\t    Modification des informations de l'offre :  \n\n\n");
            printf("Entrer le nouveau delai d'envoi des candidatures  : \n");
            scanDate(&offre->delaiEnvoi);
            if(datecmp(offre->datePublication, offre->delaiEnvoi) > 0)
            {
                system("color 47");
                printf("\n\n\n\tATTENTION !! Impossible d'avoir un delai d'envoi des candidatures avant la date de publication !!\n");
                printf("\n\tAppuyez sur une touche pour re-entrer le delai d'envoi des candidatures ... ");
                getch();
                goto scan3;
            }
            goto debut;
            break;
        }

        case 8:
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
                    *offre = backup;
                    fflush(stdin);
                    textcolor(LIGHTGRAY);
                    return;
                }
                deleteConsoleLines(1);
            }
            break;
        }

        default:
            goto debut;
            break;
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief insertion d'une offre au début (dans la tête) de la liste des offres
 *
 * @param tete la tête de la liste dans laquelle on veut insérer (passage par variable)
 * @param offre l'offre à insérer
 */
void insererOffre_LLC_off(PMaillonOffres *tete, Offre offre)
{
    PMaillonOffres p;
    allouerLLC_off(&p);
    aff_valLLC_off(p, offre);
    aff_adrLLC_off(p,*tete);
    *tete = p;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief accès par position au éléments de la liste des offres
 *
 * @param tete la tête de la liste des offres
 * @param position la position de l'offre dans la liste (commence par 1)
 * @return PMaillonOffres l'adresse du maillon de l'offre (NULL s'il n'existe pas)
 */
PMaillonOffres accesPos_LLC_off(PMaillonOffres tete, int position)
{
    PMaillonOffres p = tete;
    int i = 1;

    while((p != NULL) && (i < position))
    {
        p = suivantLLC_off(p);
        i++;
    }

    return p;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief suppression par position des éléments de la liste des offres
 *
 * @param tete la tête de la liste des offres (passage par variable)
 * @param position la position de l'offre à supprimer
 */
void suppressionPos_LLC_off(PMaillonOffres *tete, int position)
{
    PMaillonOffres p, q;

    if(position == 1) // suppression de la tête
    {
        p = *tete;
        *tete = suivantLLC_off(*tete);
        libererLLC_off(p);
    }
    else if(position > 1) // le cas générale
    {
        p = accesPos_LLC_off(*tete, position - 1);
        if(p != NULL)
        {
            q = suivantLLC_off(p);
            if(q != NULL)
            {
                aff_adrLLC_off(p, suivantLLC_off(q));
                libererLLC_off(q);
            }
        }
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief calculer la fréquence (nombre de répétitions) de l'intitulé du poste dans une liste des offres
 *
 * @param tete la tête de la liste des offres
 * @param poste l'intitulé  du poste
 * @return int le nombre de répétitions du poste dans la liste des offres
 */
int freqPoste_LLC_off(PMaillonOffres tete, const char poste[])
{
    int cpt = 0;

    for(PMaillonOffres p = tete; p != NULL; p = suivantLLC_off(p))
    {
        if(strcmp(valeurLLC_off(p).intituleDuPoste, poste) == 0)
            cpt++;
    }

    return cpt;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief mettre deux listes des offres dans une seul nouvelle liste des offres
 *
 * @param liste1 la première liste
 * @param liste2 la deuxième liste
 * @return PMaillonOffres pointeur vers la tête de la liste résultat
 */
PMaillonOffres union_LLC_off(PMaillonOffres liste1, PMaillonOffres liste2)
{
    PMaillonOffres liste = NULL; // initialiser la tete de liste résultat

    for(PMaillonOffres p = liste1; p != NULL; p = suivantLLC_off(p)) // l'ajout de la premiere liste
    {
        insererOffre_LLC_off(&liste, valeurLLC_off(p));
    }

    for(PMaillonOffres p = liste2; p != NULL; p = suivantLLC_off(p)) // l'ajout de la deuxième liste
    {
        insererOffre_LLC_off(&liste, valeurLLC_off(p));
    }

    return liste;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief chercher le poste le plus fréquent dans une liste des offres
 *
 * @param tete la tête de la liste des offres
 * @param postePlusFreq l'intitulé du poste le plus fréquent (passage par variable)
 */
void postePlusFreq_LLC_off(PMaillonOffres tete, char postePlusFreq[])
{
    // Déclarations et initialisations
    char max[TAILLE_CHAINE_MAX];
    strcpy(max, valeurLLC_off(tete).intituleDuPoste);
    int max_freq = freqPoste_LLC_off(tete, valeurLLC_off(tete).intituleDuPoste);

    // Parcourir la liste des offres
    for(PMaillonOffres p = suivantLLC_off(tete); p != NULL; p = suivantLLC_off(p))
    {
        int freq = freqPoste_LLC_off(p, valeurLLC_off(p).intituleDuPoste); // calculer la fréquence de l'élément actuel

        if(freq > max_freq) // vérification du max
        {
            max_freq = freq;
            strcpy(max, valeurLLC_off(p).intituleDuPoste);
        }
    }

    strcpy(postePlusFreq, max);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief accès par valeur de l'ititulé du poste à un maillon de la liste des offres
 *
 * @param tete la tête de la liste des offres
 * @param poste l'intitulé du poste
 * @param p pointeur vers le premier maillon qui contient l'intitulé du poste (passange par variable)
 * @param precedent pointeur vers le maillon précédent de 'p' (passage par variable)
 */
void accesValPoste_LLC_off(PMaillonOffres tete, char poste[], PMaillonOffres *p, PMaillonOffres *precedent)
{
    Bool trouv = False;
    *precedent = NULL;
    *p = tete;

    while((!trouv) && (*p != NULL))
    {
        if(strcmp(poste, valeurLLC_off(*p).intituleDuPoste) == 0)
            trouv = True;
        else
        {
            *precedent = *p;
            *p = suivantLLC_off(*p);
        }
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief éclater les offres d'emploi selon le nombre d'années d'expérience (>= ou < à 5), en deux nouveaux listes
 *
 * @param tete la liste à éclater
 * @param liste1 la première liste qui contient nbrAnneesEXP >= 5 (passage par variable)
 * @param liste2 la deuxième liste qui contient nbrAnneesEXP < 5 (passage par variable)
 */
void eclaterEXP_LLC_off(PMaillonOffres tete, PMaillonOffres *liste1, PMaillonOffres *liste2)
{
    *liste1 = NULL;
    *liste2 = NULL;
    for(PMaillonOffres p = tete; p != NULL; p = suivantLLC_off(p))
    {
        if(valeurLLC_off(p).nbrAnneesEXP >= 5)
            insererOffre_LLC_off(liste1, valeurLLC_off(p)); // ajouter dans la première liste
        else
            insererOffre_LLC_off(liste2, valeurLLC_off(p)); // ajouter dans la deuxième liste
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief permuter deux valeurs de deux maillons dans une liste des offres
 *
 * @param p premier maillon
 * @param q deuxième maillon
 */
void permute_LLC_off(PMaillonOffres p, PMaillonOffres q)
{
    Offre temp = valeurLLC_off(p);
    aff_valLLC_off(p, valeurLLC_off(q));
    aff_valLLC_off(q, temp);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief calculer le nombre des compétences requises pour une offre
 *
 * @param offre une offre
 * @return int le nombre des compétences requises pour l'offre
 */
int nbrCompetences_off(Offre offre)
{
    int cpt = 0;

    for(int i = 0; i < MAX_COMPETENCES; i++)
    {
        if(offre.competencesRequises[i] == True)
            cpt++;
    }

    return cpt;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief trier une liste des offres selon le nombre de compétences par la méthode de tri par bulle
 *
 * @param tete la tête de la liste à trier
 */
void triBullesNbrCompetences_LLC_off(PMaillonOffres tete)
{
    if(tete == NULL) // la liste est vide !! Rien à trier
        return;

    PMaillonOffres p, q, w = NULL;
    Bool perm;

    do
    {
        perm = False;
        p = tete;
        q = suivantLLC_off(p);

        while(q != w)
        {
            if(nbrCompetences_off(valeurLLC_off(p)) < nbrCompetences_off(valeurLLC_off(q))) // ordre croissant
            {
                permute_LLC_off(p, q);
                perm = True;
            }

            p = q;
            q = suivantLLC_off(q);
        }

        w = p;

    } while (perm);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief fusioner deux listes des offres dans une nouvlle liste selon le nombre de compétences
 *
 * @param tete la tête de la liste résultat (passage par variable)
 * @param liste1 la première liste
 * @param liste2 la deuxième liste
 */
void fusionNbrCompetences_LLC_off(PMaillonOffres *tete, PMaillonOffres liste1, PMaillonOffres liste2)
{
    PMaillonOffres p1 = liste1, p2 = liste2, p = NULL, q = NULL;
    *tete = NULL;

    while((p1 != NULL) && (p2 != NULL))
    {
        if(nbrCompetences_off(valeurLLC_off(p1)) > nbrCompetences_off(valeurLLC_off(p2))) // ordre croissant
        {
            allouerLLC_off(&q);
            aff_valLLC_off(q, valeurLLC_off(p1));

            if(*tete == NULL)
            {
                *tete = q;
                p = q;
            }
            else
            {
                aff_adrLLC_off(p, q);
                p = q;
            }

            p1 = suivantLLC_off(p1);
        }
        else
        {
            allouerLLC_off(&q);
            aff_valLLC_off(q, valeurLLC_off(p2));

            if(*tete == NULL)
            {
                *tete = q;
                p = q;
            }
            else
            {
                aff_adrLLC_off(p, q);
                p = q;
            }

            p2 = suivantLLC_off(p2);
        }
    }

    while(p1 != NULL)
    {
        allouerLLC_off(&q);
        aff_valLLC_off(q, valeurLLC_off(p1));

        if(*tete == NULL)
        {
            *tete = q;
            p = q;
        }
        else
        {
            aff_adrLLC_off(p, q);
            p = q;
        }

        p1 = suivantLLC_off(p1);
    }

    while(p2 != NULL)
    {
        allouerLLC_off(&q);
        aff_valLLC_off(q, valeurLLC_off(p2));

        if(*tete == NULL)
        {
            *tete = q;
            p = q;
        }
        else
        {
            aff_adrLLC_off(p, q);
            p = q;
        }

        p2 = suivantLLC_off(p2);
    }

    aff_adrLLC_off(p, NULL);
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
