#ifndef __BIB__DEMANDE__H__
#define __BIB__DEMANDE__H__


    //--------------------------------------------------------------------------------------------------------
    // Déclarations des structures des données
    //--------------------------------------------------------------------------------------------------------

    /* Définition du type annonce (demande) */

    typedef struct Demande
    {
        char nomDuDemandeur[TAILLE_CHAINE_MAX];
        Date datePublication;
        char diplome[MAX_DIPLOME][TAILLE_CHAINE_MAX]; // tableau des chaînes de caractères (chaque diplôme dans une case c-à-d: chaîne de caractères)
        int nbrAnneesEXP;
        Competences competences;
        Langues languesMaitrisees;
    } Demande;


    /* Définition de la liste des demandes */

    typedef struct MaillonDemandes
    {
        Demande val;
        struct MaillonDemandes *adr;
    } ElementListeDemandes, *PMaillonDemandes; // un maillon, pointeur vers un maillon



    //--------------------------------------------------------------------------------------------------------
    // Déclarations des modules
    //--------------------------------------------------------------------------------------------------------


    /* Définition de la machine abstraite des listes des demandes */

    void allouerLLC_dem(ElementListeDemandes **dem);
    Demande valeurLLC_dem(PMaillonDemandes dem);
    PMaillonDemandes suivantLLC_dem(PMaillonDemandes dem);
    void aff_valLLC_dem(PMaillonDemandes dem, Demande valeur);
    void aff_adrLLC_dem(PMaillonDemandes dem, PMaillonDemandes adresse);
    void libererLLC_dem(PMaillonDemandes dem);


    /* Les fonctions sur les listes des demandes */

    void creat_LLC_dem(PMaillonDemandes *tete); // construire la liste des demandes à partir de fichier
    void printDemande(Demande dem); // afficher une seule demande (tous les informations)
    void afficher_LLC_dem(PMaillonDemandes tete); // afficher la liste des demandes
    void libererTous_LLC_dem(PMaillonDemandes *tete); // libérer (supprimer) toute la liste des demandes sans l'archiver
    int taille_LLC_dem(PMaillonDemandes tete); // calculer la taille de la liste des demandes
    Bool eq_dem(Demande dem1, Demande dem2); // Tester si deux demandes sont identique

    Demande creatDemande(void); // permet à l'utilisateur de créer une nouvelle demande
    void modifDemande(Demande *demande); // permet à l'utilisateur de modifier une demande
    void insererDemande_LLC_dem(PMaillonDemandes *tete, Demande demande); // insertion d'une demande au début (dans la tête) de la liste des demandes
    PMaillonDemandes accesPos_LLC_dem(PMaillonDemandes tete, int position); // accès par position au éléments de la liste des demandes
    void suppressionPos_LLC_dem(PMaillonDemandes *tete, int position); // suppression par position des éléments de la liste des demandes
    int nbrCompetences_dem(Demande demande); // calculer le nombre des compétences maitrisées par un demandeur

    Bool verifierLangues(Demande demande, Offre offre); // vérifier si la demande satisfait la critère suivante: maitrisant au moins une langue requise
    Bool verifierCompetences(Demande demande, Offre offre); // vérifier si la demande satisfait la critère suivante: ayant au moins 2 compétences requises
    Bool verifierDiplomes(Demande demande, Offre offre); // vérifier si la demande satisfait la critère suivante: même diplôme ou plus
    Bool validerDemande(Demande demande, Offre offre); // valider une demande selon les critères : même diplôme ou plus, ayant au moins 2 compétences requises, maitrisant au moins une langue requise

#endif
