#ifndef __BIB__OFFRE__H__
#define __BIB__OFFRE__H__


    //--------------------------------------------------------------------------------------------------------
    // Déclarations des structures des données
    //--------------------------------------------------------------------------------------------------------

    /* Définition du type annonce (offre) */

    typedef struct Offre
    {
        char nomDuRecruteur[TAILLE_CHAINE_MAX];
        char intituleDuPoste[TAILLE_CHAINE_MAX];
        char diplomeExige[TAILLE_CHAINE_MAX];
        int nbrAnneesEXP;
        Competences competencesRequises;
        Langues languesExige;
        Date datePublication;
        Date delaiEnvoi;
    } Offre;


    /* Définition des maillons et la liste des offres */

    typedef struct MaillonOffres
    {
        Offre val;
        struct MaillonOffres *adr;
    } ElementListeOffres, *PMaillonOffres; // un maillon, pointeur vers un maillon



    //--------------------------------------------------------------------------------------------------------
    // Déclarations des modules
    //--------------------------------------------------------------------------------------------------------


    /* Définition de la machine abstraite des listes des offres */

    void allouerLLC_off(ElementListeOffres **off);
    Offre valeurLLC_off(PMaillonOffres off);
    PMaillonOffres suivantLLC_off(PMaillonOffres off);
    void aff_valLLC_off(PMaillonOffres off, Offre valeur);
    void aff_adrLLC_off(PMaillonOffres off, PMaillonOffres adresse);
    void libererLLC_off(PMaillonOffres off);


    /* Les fonctions sur les listes des offres */

    void creat_LLC_off(PMaillonOffres *tete, PMaillonRecruteurs listeRecruteurs); // construire la liste des offres à partir de fichier
    void printOffre(Offre off); // afficher une seule offre (tous les informations)
    void afficher_LLC_off(PMaillonOffres tete); // afficher la liste des offres
    void libererTous_LLC_off(PMaillonOffres *tete); // libérer (supprimer) toute la liste des offres sans l'archiver
    int taille_LLC_off(PMaillonOffres tete); // calculer la taille de la liste des offres
    Bool eq_off(Offre off1, Offre off2); // Tester si deux offres sont identique

    Offre creatOffre(PMaillonRecruteurs listeRecruteurs, Bool *Recruteur_Existe); // permet à l'utilisateur de créer une nouvelle offre
    void modifOffre(Offre *offre); // permet à l'utilisateur de modifier une offre
    void insererOffre_LLC_off(PMaillonOffres *tete, Offre offre); // insertion d'une offre au début (dans la tête) de la liste des offres
    PMaillonOffres accesPos_LLC_off(PMaillonOffres tete, int position); // accès par position au éléments de la liste des offres
    void suppressionPos_LLC_off(PMaillonOffres *tete, int position); // suppression par position des éléments de la liste des offres
    int freqPoste_LLC_off(PMaillonOffres tete, const char poste[]); // calculer la fréquence (nombre de répétitions) de l'intitulé du poste dans une liste des offres
    PMaillonOffres union_LLC_off(PMaillonOffres liste1, PMaillonOffres liste2); // mettre deux listes des offres dans une seul nouvelle liste des offres
    void postePlusFreq_LLC_off(PMaillonOffres tete, char postePlusFreq[]); // chercher le poste le plus fréquent dans une liste des offres
    void accesValPoste_LLC_off(PMaillonOffres tete, char poste[], PMaillonOffres *p, PMaillonOffres *precedent); // accès par valeur de l'ititulé du poste à un maillon de la liste des offres
    void eclaterEXP_LLC_off(PMaillonOffres tete, PMaillonOffres *liste1, PMaillonOffres *liste2); // éclater les offres d'emploi selon le nombre d'années d'expérience (>= ou < à 5), en deux nouveaux listes
    void permute_LLC_off(PMaillonOffres p, PMaillonOffres q); // permuter deux valeurs de deux maillons dans une liste des offres
    int nbrCompetences_off(Offre offre); // calculer le nombre des compétences requises pour une offre
    void triBullesNbrCompetences_LLC_off(PMaillonOffres tete); // trier une liste des offres selon le nombre de compétences par la méthode de tri par bulle
    void fusionNbrCompetences_LLC_off(PMaillonOffres *tete, PMaillonOffres liste1, PMaillonOffres liste2); // fusioner deux listes des offres dans une nouvlle liste selon le nombre de compétences

#endif
