#ifndef __BIB__RECRUTEUR__H__
#define __BIB__RECRUTEUR__H__


    //--------------------------------------------------------------------------------------------------------
    // Déclarations des structures des données
    //--------------------------------------------------------------------------------------------------------

    /* Définition du type annonceur (recruteur) */

    typedef struct Recruteur
    {
        char nom[TAILLE_CHAINE_MAX];
        char adresse[TAILLE_CHAINE_MAX];
        char mail[TAILLE_CHAINE_MAX];
        char numeroTelephone[TAILLE_CHAINE_MAX];
        int __nbrAnnonce; // lié avec les offres (pour gérer la suppression)
    } Recruteur;


    /* Définition des maillons et la liste des recruteurs */

    typedef struct MaillonRecruteurs
    {
        Recruteur val;
        struct MaillonRecruteurs *adr;
    } ElementListeRecruteurs, *PMaillonRecruteurs; // un maillon, pointeur vers un maillon



    //--------------------------------------------------------------------------------------------------------
    // Déclarations des modules
    //--------------------------------------------------------------------------------------------------------


    /* Définition de la machine abstraite des listes des recruteurs */

    void allouerLLC_rec(ElementListeRecruteurs **rec);
    Recruteur valeurLLC_rec(PMaillonRecruteurs rec);
    PMaillonRecruteurs suivantLLC_rec(PMaillonRecruteurs rec);
    void aff_valLLC_rec(PMaillonRecruteurs rec, Recruteur valeur);
    void aff_adrLLC_rec(PMaillonRecruteurs rec, PMaillonRecruteurs adresse);
    void libererLLC_rec(PMaillonRecruteurs rec);


    /* Les fonctions sur les listes des recruteurs */

    void creat_LLC_rec(PMaillonRecruteurs *tete); // construire la liste des recruteurs à partir de fichier
    void printRecruteur(Recruteur rec); // afficher un seul recruteur (tous les informations)
    void afficher_LLC_rec(PMaillonRecruteurs tete); // afficher la liste des recruteurs
    void libererTous_LLC_rec(PMaillonRecruteurs *tete); // libérer (supprimer) toute la liste des recruteurs sans l'archiver
    int taille_LLC_rec(PMaillonRecruteurs tete); // calculer la taille de la liste des recruteurs

    Recruteur creatRecruteur(void); // permet à l'utilisateur de créer un nouveau recruteur
    void modifRecruteur(Recruteur *recruteur); // permet à l'utilisateur de modifier un recruteur
    void insererRecruteur_LLC_rec(PMaillonRecruteurs *tete, Recruteur recruteur); // insertion d'un recruteur au début (dans la tête) de la liste des recruteurs
    PMaillonRecruteurs rechRecruteurNom(PMaillonRecruteurs tete, char nomRecruteur[]/*String*/); // rechercher un recruteur dans la liste des recruteurs par son nom
    PMaillonRecruteurs accesPos_LLC_rec(PMaillonRecruteurs tete, int position); // accès par position au éléments de la liste des recruteurs
    void suppressionPos_LLC_rec(PMaillonRecruteurs *tete, int position); // suppression par position des éléments de la liste des recruteurs
    int position_LLC_rec(PMaillonRecruteurs tete, Recruteur recruteur); // calculer la position d'un recruteur dans la liste des recruteurs

#endif
