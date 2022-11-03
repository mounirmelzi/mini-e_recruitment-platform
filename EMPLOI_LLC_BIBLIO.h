#ifndef EMPLOI_LLC_BIBLIO_H_INCLUDED
#define EMPLOI_LLC_BIBLIO_H_INCLUDED


    //--------------------------------------------------------------------------------------------------------
    // Les modules de TP
    //--------------------------------------------------------------------------------------------------------

    // Les modules sur les recruteurs

    void suppressionRecruteur(PMaillonRecruteurs *listeActive, int position, PMaillonRecruteurs *listeArchive, PMaillonOffres *listeOffresActive, PMaillonOffres *listeOffresArchive); // supprimer un recruteur de la liste des recruteurs active et le mettre dans la liste archive

    // Les modules sur les offres

    void suppressionOffre(PMaillonOffres *listeActive, int position, PMaillonOffres *listeArchive, PMaillonRecruteurs *listeRecruteursActive, PMaillonRecruteurs *listeRecruteurArchive); // supprimer une offre de la liste des offres active et le mettre dans la liste archive
    void affichageOffresValables(PMaillonOffres liste_off, PMaillonRecruteurs liste_rec, Date date); // rechercher les offres dont le délai de candidature est toujours valable
    void affichageOffresParDates(PMaillonOffres tete, Date date_inf, Date date_sup); // afficher tous les offres dans une liste des offres entre deux dates données
    void rechOff_ParRec(PMaillonOffres liste_off, Recruteur recruteur); // chercher les offres appartenant à un même recruteur
    void afficherXPosteFreq(PMaillonOffres listeActive, PMaillonOffres listeArchive, int x); // afficher les 'x' postes les plus demandés
    void triEclatementOffres(PMaillonOffres liste_offre, PMaillonOffres *liste_trie); // éclatement, tri, fusion des listes des offres

    // Les modules sur les demande

    void suppressionDemande(PMaillonDemandes *listeActive, int position, PMaillonDemandes *listeArchive); // supprimer une demande de la liste des demandes active et la mettre dans la liste archive
    void affichageDemandesParDates(PMaillonDemandes tete, Date date_inf, Date date_sup); // afficher tous les demandes dans une liste des demandes entre deux dates données
    void rechercheDemandeurs(PMaillonDemandes tete, int x, int y); // rechercher les demandeurs ayant 'x' compétences et maitrisant une langue 'y'
    void recommanderDemande(PMaillonDemandes demandes, Offre offre, PMaillonDemandes *recommandations); // construire la liste des demandes qui peuvent correspondre à une offre d'emploi donnée


#endif // EMPLOI_LLC_BIBLIO_H_INCLUDED
