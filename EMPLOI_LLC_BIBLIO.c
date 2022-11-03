#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lib/BIB_standard.h"
#include "lib/BIB_recruteur.h"
#include "lib/BIB_offre.h"
#include "lib/BIB_demande.h"
#include "lib/conio2.h"
#include "EMPLOI_LLC_BIBLIO.h"


/* Les fonctions du TP */

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

/**
 * @brief supprimer un recruteur de la liste des recruteurs active et le mettre dans la liste archive
 *
 * @param listeActive la tête de la liste des recruteurs active (passage par variable)
 * @param position la position de recruteur à supprimer
 * @param listeArchive la tête de la liste des recruteurs archive (passage par variable)
 * @param listeOffresActive la tête de la liste des offres active (passage par variable)
 * @param listeOffresArchive la tête de la liste des offres archive (passage par variable)
 */
void suppressionRecruteur(PMaillonRecruteurs *listeActive, int position, PMaillonRecruteurs *listeArchive, PMaillonOffres *listeOffresActive, PMaillonOffres *listeOffresArchive)
{
    Recruteur toDelete = valeurLLC_rec(accesPos_LLC_rec(*listeActive, position)); // acceder au recruteur a supprimer
    if(toDelete.__nbrAnnonce == 0)
    {
        insererRecruteur_LLC_rec(listeArchive, toDelete); // ajouter le recruteur dans la liste archive
        suppressionPos_LLC_rec(listeActive, position); // suppression du recruteur de la liste active
    }
    else
    {
        for(int i = 0; i < toDelete.__nbrAnnonce; i++) // supprimer toutes les offres du recruteur
            {
                int cpt = 0; // pour calculer la position de la premi�re offre du recruteur dans la liste des offres

                for(PMaillonOffres p = *listeOffresActive; p != NULL; p = suivantLLC_off(p))
                {
                    cpt++;
                    if(comparerStr(toDelete.nom, valeurLLC_off(p).nomDuRecruteur))
                        break;
                }

                suppressionOffre(listeOffresActive, cpt, listeOffresArchive, listeActive, listeArchive); // le recruteur sera supprimer automatiquement lors la suppression de sa derni�re offre
            }
    }
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

/**
 * @brief supprimer une offre de la liste des offres active et le mettre dans la liste archive
 *
 * @param listeActive la liste des offres active (passage par variable)
 * @param position la position de l'offre � supprimer dans la liste des offres active
 * @param listeArchive la liste des offres archive (passage par variable)
 * @param listeRecruteursActive la liste des recruteurs active (passage par variable)
 * @param listeRecruteurArchive la liste des recruteurs archive (passage par variable)
 */
void suppressionOffre(PMaillonOffres *listeActive, int position, PMaillonOffres *listeArchive, PMaillonRecruteurs *listeRecruteursActive, PMaillonRecruteurs *listeRecruteurArchive)
{
    Offre toDelete = valeurLLC_off(accesPos_LLC_off(*listeActive, position)); // acceder a l'offre a supprimer
    insererOffre_LLC_off(listeArchive, toDelete); // l'ajout � la liste archive (insertion depuis la tete)
    suppressionPos_LLC_off(listeActive, position); // suppression de la liste active

    // mise � jour de la liste des recruteurs:
    PMaillonRecruteurs adrRecruteur = rechRecruteurNom(*listeRecruteursActive, toDelete.nomDuRecruteur);

    if(adrRecruteur == NULL)
        return;

    (adrRecruteur->val).__nbrAnnonce--;
    if(valeurLLC_rec(adrRecruteur).__nbrAnnonce == 0) // Suppression de recruteur de sa liste Active et le mettre dans la liste archive des recruteurs
    {
        insererRecruteur_LLC_rec(listeRecruteurArchive, valeurLLC_rec(adrRecruteur)); // l'ajout � la liste archive
        suppressionPos_LLC_rec(listeRecruteursActive, position_LLC_rec(*listeRecruteursActive, valeurLLC_rec(adrRecruteur))); // supprimer le recruteur de la liste active ...
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief rechercher les offres dont le delai de candidature est toujours valable
 *
 * @param liste_off la liste des offres
 * @param liste_rec la liste des recruteurs
 * @param date la date de recherche
 */
void affichageOffresValables(PMaillonOffres liste_off, PMaillonRecruteurs liste_rec, Date date)
{
    int cpt = 0; // compteur des offres trouv�es

    // parcourir la liste des offres
    for(PMaillonOffres p = liste_off; p != NULL; p = suivantLLC_off(p))
    {
        if( ! (datecmp(valeurLLC_off(p).delaiEnvoi, date) < 0)) // trouver une offre
        {
            textcolor(LIGHTBLUE);
            printf("\t  Intitule de poste    : %s\n", valeurLLC_off(p).intituleDuPoste); // afficher intitul�
            textcolor(WHITE);
            printRecruteur(valeurLLC_rec(rechRecruteurNom(liste_rec, valeurLLC_off(p).nomDuRecruteur))); // afficher recruteur
            cpt++;
        }
    }

    if(cpt == 0) // aucun offre valable trouv�e
    {
        textcolor(LIGHTRED);
        printf("\t\tAucune offre valable trouvee !\n");
    }
    else
    {
        textcolor(LIGHTGREEN);
        printf("\n\tLe nombre des offres valables trouvees est: %d\n", cpt);
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief afficher tous les offres dans une liste des offres entre deux dates données
 *
 * @param tete la tête de la liste des offres
 * @param date_inf la date de début de recherche
 * @param date_sup la date de fin de recherche
 */
void affichageOffresParDates(PMaillonOffres tete, Date date_inf, Date date_sup)
{
    int cpt = 0; // compteur des offres affichees

    for(PMaillonOffres p = tete; p != NULL; p = suivantLLC_off(p))
    {
        Bool condition_inf = ! (datecmp(valeurLLC_off(p).datePublication, date_inf) < 0); // datepub >= date_inf
        Bool condition_sup = ! (datecmp(valeurLLC_off(p).datePublication, date_sup) > 0); // datepub <= date_sup

        if(condition_inf && condition_sup)
        {
            printOffre(valeurLLC_off(p));
            cpt++;
        }
    }

    if(cpt == 0)
    {
        printf("\tAucune offre !\n\n");
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief chercher les offres appartenant a un meme recruteur
 *
 * @param liste_off la liste des offres
 * @param recruteur le recruteur à chercher ses offres
 */
void rechOff_ParRec(PMaillonOffres liste_off, Recruteur recruteur)
{
    char nom_rec[TAILLE_CHAINE_MAX];
    strcpy(nom_rec, recruteur.nom);

    // lower case tous les caract�res du nom du recruteur � rechercher ses offres
    size_t taille_nom_rec = strlen(nom_rec);
    char *lower_nom_rec = calloc(taille_nom_rec+1, sizeof(char));
    for(size_t i = 0; i < taille_nom_rec; i++)
    {
        lower_nom_rec[i] = tolower((unsigned char)nom_rec[i]);
    }

    // lancer la recherche des offres
    for(PMaillonOffres p = liste_off; p != NULL; p = suivantLLC_off(p))
    {
        // lower case tous les caract�res du nom de l'annonceur de l'offre
        size_t lenNomP = strlen(valeurLLC_off(p).nomDuRecruteur);
        char *lowerNomP = calloc(lenNomP+1, sizeof(char));
        for(size_t i = 0; i < lenNomP; i++)
        {
            lowerNomP[i] = tolower((unsigned char)valeurLLC_off(p).nomDuRecruteur[i]);
        }

        if(strcmp(lower_nom_rec, lowerNomP) == 0) // comparer les deux nouveaux noms (lower case)
        {
            printOffre(valeurLLC_off(p));
        }

        free(lowerNomP);
    }

    // free lower_nom_rec
    free(lower_nom_rec);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief afficher les 'x' postes les plus demandes
 *
 * @param listeActive la liste des offres active
 * @param listeArchive la liste des offres archive
 * @param x le nombre des postes plus demades a afficher
 */
void afficherXPosteFreq(PMaillonOffres listeActive, PMaillonOffres listeArchive, int x)
{
    PMaillonOffres liste = union_LLC_off(listeArchive, listeActive);
    if(liste == NULL)
    {
        printf("\n\n\n\n\t Les listes des offres sont vides !! Aucun poste a afficher :(\n");
        return;
    }

    char poste[TAILLE_CHAINE_MAX] = "VIDE";

    (x == 1) ? printf("\tLe poste le plus demandes est: \n\n") : printf("\tLes %d postes les plus demandes sont: \n\n", x);

    for(int i = 0; i < x; i++)
    {
        if(liste == NULL)
        {
            printf("\t Il y a plus de postes :)\n");
            return;
        }

        postePlusFreq_LLC_off(liste, poste);
        printf("\t  Poste %d:\t%s  -->  Nombre de demandes: %d\n", i+1, poste, freqPoste_LLC_off(liste, poste));

        // supprimer tous poste de liste
        PMaillonOffres p = NULL, precedent = NULL;
        accesValPoste_LLC_off(liste, poste, &p, &precedent);

        while(p != NULL)
        {
            // suppression du maillon p
            if(p == liste)
                liste = suivantLLC_off(liste);
            else
                aff_adrLLC_off(precedent, suivantLLC_off(p));
            libererLLC_off(p);

            accesValPoste_LLC_off(liste, poste, &p, &precedent);
        }
    }

    libererTous_LLC_off(&liste);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief �clatement, tri, fusion des listes des offres
 *
 * @param liste_offre la liste des offres originale
 * @param liste_trie la liste des offres tri�e (passage par variable)
 */
void triEclatementOffres(PMaillonOffres liste_offre, PMaillonOffres *liste_trie)
{
    PMaillonOffres liste1, liste2;
    eclaterEXP_LLC_off(liste_offre, &liste1, &liste2);

    triBullesNbrCompetences_LLC_off(liste1);
    triBullesNbrCompetences_LLC_off(liste2);

    fusionNbrCompetences_LLC_off(liste_trie, liste1, liste2);

    libererTous_LLC_off(&liste1);
    libererTous_LLC_off(&liste2);
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

/**
 * @brief supprimer une demande de la liste des demandes active et la mettre dans la liste archive
 *
 * @param listeActive la liste des demandes active
 * @param position la position de la demande dans la liste des demandes active
 * @param listeArchive la liste des demandes archives
 */
void suppressionDemande(PMaillonDemandes *listeActive, int position, PMaillonDemandes *listeArchive)
{
    Demande toDelete = valeurLLC_dem(accesPos_LLC_dem(*listeActive, position)); // acceder a la demande a supprimer
    insererDemande_LLC_dem(listeArchive, toDelete); // l'ajout a la liste archive (insertion depuis la tete)
    suppressionPos_LLC_dem(listeActive, position); // suppression de la liste active
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief afficher tous les demandes dans une liste des demandes entre deux dates donn�es
 *
 * @param tete la tete de la liste des demandes
 * @param date_inf la date de début de recherche
 * @param date_sup la date de fin de recherche
 */
void affichageDemandesParDates(PMaillonDemandes tete, Date date_inf, Date date_sup)
{
    int cpt = 0; // compteur des demandes affichees

    for(PMaillonDemandes p = tete; p != NULL; p = suivantLLC_dem(p))
    {
        Bool condition_inf = ! (datecmp(valeurLLC_dem(p).datePublication, date_inf) < 0); // datepub >= date_inf
        Bool condition_sup = ! (datecmp(valeurLLC_dem(p).datePublication, date_sup) > 0); // datepub <= date_sup

        if(condition_inf && condition_sup)
        {
            printDemande(valeurLLC_dem(p));
            cpt++;
        }
    }

    if(cpt == 0)
    {
        printf("\tAucune demande !\n\n");
    }
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief rechercher les demandeurs ayant 'x' competences et maitrisant une langue 'y'
 *
 * @param tete la tete de la liste des demandes
 * @param x le nombre des competences
 * @param y le code de la langue
 */
void rechercheDemandeurs(PMaillonDemandes tete, int x, int y)
{
    int cpt = 0;
    char langue[TAILLE_CHAINE_MAX] = "";
    decoderLangue(y, langue);

    (x == 1) ? printf("\tLes demandeurs ayant une seule competence et maitrisant la langue \"%s\" sont: \n\n", langue) : printf("\tLes demandeurs ayant %d competences et maitrisant la langue \"%s\" sont: \n\n", x, langue);

    for(PMaillonDemandes p = tete; p != NULL; p = suivantLLC_dem(p))
    {
        if(valeurLLC_dem(p).languesMaitrisees[y] && (nbrCompetences_dem(valeurLLC_dem(p)) == x))
        {
            cpt++;
            printf("\t %d : %s \n", cpt, valeurLLC_dem(p).nomDuDemandeur);
        }
    }

    if(cpt == 0)
        printf("\tAucun demandeur !!\n");
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief construire la liste des demandes qui peuvent correspondre à une offre d'emploi donnee
 *
 * @param demandes la liste des demandes
 * @param offre l'offre a recommander des demandes
 * @param recommandations la liste des recommandations (passage par variable)
 */
void recommanderDemande(PMaillonDemandes demandes, Offre offre, PMaillonDemandes *recommandations)
{
    PMaillonDemandes p = NULL, q = NULL;
    *recommandations = NULL;

    for(PMaillonDemandes pointeur = demandes; pointeur != NULL; pointeur = suivantLLC_dem(pointeur)) // parcourir la liste des demandes
    {
        Demande demande = valeurLLC_dem(pointeur); // recuperer la valeur de demande das chaque maillon

        if(validerDemande(demande, offre))
        {
            if(*recommandations == NULL) // si la liste des recommandations est vide
                insererDemande_LLC_dem(recommandations, demande); // insertion au debut de la liste des recommandations
            else // inserer 'demande' dans la bonne position ! (car la liste des recommandations doit etre triee)
            {
                // rechercher la bonne position de l'insertion
                for(p = *recommandations; p != NULL; p = suivantLLC_dem(p))
                {
                    if((suivantLLC_dem(p) == NULL) || (valeurLLC_dem(suivantLLC_dem(p)).nbrAnneesEXP <= demande.nbrAnneesEXP))
                        break;
                }

                // effectuer l'insertion
                if(p != *recommandations) // le cas generale (si la position de l'insertion != la tete de la liste des recommandations)
                {
                    allouerLLC_dem(&q);
                    aff_valLLC_dem(q, demande);
                    aff_adrLLC_dem(q, suivantLLC_dem(p));
                    aff_adrLLC_dem(p, q);
                }
                else // le cas de l'insertion dans la tete
                {
                    if(valeurLLC_dem(p).nbrAnneesEXP <= demande.nbrAnneesEXP)
                        insererDemande_LLC_dem(recommandations, demande);
                    else
                    {
                        allouerLLC_dem(&q);
                        aff_valLLC_dem(q, demande);
                        aff_adrLLC_dem(q, suivantLLC_dem(*recommandations));
                        aff_adrLLC_dem(*recommandations, q);
                    }
                }
            }
        }
    }
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
