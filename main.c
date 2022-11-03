#include <stdio.h>
#include <stdlib.h>

#include "lib/BIB_standard.h"
#include "lib/BIB_recruteur.h"
#include "lib/BIB_offre.h"
#include "lib/BIB_demande.h"
#include "lib/BIB_affichage.h"
#include "lib/conio2.h"

int main(void)
{
    PRINT_ESI();

    PMaillonRecruteurs liste_rec = NULL, liste_rec_arch = NULL;
    creat_LLC_rec(&liste_rec);
    PMaillonOffres liste_off = NULL, liste_off_arch = NULL;
    creat_LLC_off(&liste_off, liste_rec);
    PMaillonDemandes liste_dem = NULL, liste_dem_arch = NULL;
    creat_LLC_dem(&liste_dem);
    int choix;

    main_page();
    PRINT_INFO();

menu:

    choix = menu_principal();

    switch (choix)
    {
    case 1: // Afficher les annonces / les annonceurs
        choix1(liste_rec, liste_rec_arch, liste_off, liste_off_arch, liste_dem, liste_dem_arch);
        break;

    case 2: // Enregistrer une nouvelle annonce / un nouvel annonceur
        choix2(&liste_rec, &liste_off, &liste_dem);
        break;

    case 3: // Supprimer une annonce / un annonceur
        choix3(&liste_rec, &liste_rec_arch, &liste_off, &liste_off_arch, &liste_dem, &liste_dem_arch);
        break;

    case 4: // Afficher les offres valables
        choix4(liste_off, liste_rec);
        break;

    case 5: // Afficher toutes les annonces entre deux date donnees
        choix5(liste_rec, liste_rec_arch, liste_off, liste_off_arch, liste_dem, liste_dem_arch);
        break;

    case 6: // Rechercher les demandeurs par competences et langue
        choix6(liste_dem);
        break;

    case 7: // Afficher les offres d'un recruteur
        choix7(liste_off, liste_rec);
        break;

    case 8: // Afficher les postes les plus demandes
        choix8(liste_off, liste_off_arch);
        break;

    case 9: // Trier les offres d'emploi selon le nombre de competences
        choix9(&liste_off);
        break;

    case 10: // Recommander des demandes qui peuvent correspondre a une offre d'emploi
        choix10(liste_dem, liste_off);
        break;

    case 11: // Quitter le programme
        choix11(&liste_rec, &liste_rec_arch, &liste_off, &liste_off_arch, &liste_dem, &liste_dem_arch);
        break;

    default:
        goto menu;
    }

    goto menu;
    return 0;
}
