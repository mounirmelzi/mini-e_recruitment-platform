#ifndef __BIB__AFFICHAGE__H__
#define __BIB__AFFICHAGE__H__


    /* Les modules d'affichage */

    void main_page(void);
    void printStrAnim(int speed, char string[]);
    void loading(void);
    void PRINT_ESI(void);
    void PRINT_INFO(void);
    void fin_programme(void);


    /* Les modules des menu */

    int menu_principal(void);
    int menu_choix1(void);
    int menu_choix2(void);
    int menu_validation_enregistrement(const char chaine[]);
    int menu_choix3(void);
    int menu_validation_suppression(const char chaine[]);
    int menu_choix5(void);
    int menu_validation_affichageOffresDeRecruteur(); // pour choix 7
    int menu_choix9(void); /* Not compeleted !! */
    int menu_validation_recommandation(Offre offre);


    /* Les modules des choix */

    void choix1(PMaillonRecruteurs llc_rec, PMaillonRecruteurs llc_rec_arch, PMaillonOffres llc_off, PMaillonOffres llc_off_arch, PMaillonDemandes llc_dem, PMaillonDemandes llc_dem_arch);
    void choix2(PMaillonRecruteurs *llc_rec, PMaillonOffres *llc_off, PMaillonDemandes *llc_dem);
    void choix3(PMaillonRecruteurs *llc_rec, PMaillonRecruteurs *llc_rec_arch, PMaillonOffres *llc_off, PMaillonOffres *llc_off_arch, PMaillonDemandes *llc_dem, PMaillonDemandes *llc_dem_arch);
    void choix4(PMaillonOffres llc_off, PMaillonRecruteurs llc_rec);
    void choix5(PMaillonRecruteurs llc_rec, PMaillonRecruteurs llc_rec_arch, PMaillonOffres llc_off, PMaillonOffres llc_off_arch, PMaillonDemandes llc_dem, PMaillonDemandes llc_dem_arch);
    void choix6(PMaillonDemandes llc_dem);
    void choix7(PMaillonOffres llc_off, PMaillonRecruteurs llc_rec);
    void choix8(PMaillonOffres llc_off, PMaillonOffres llc_off_arch);
    void choix9(PMaillonOffres *llc_off); /* Not compeleted !! */
    void choix10(PMaillonDemandes llc_dem, PMaillonOffres llc_off);
    void choix11(PMaillonRecruteurs *llc_rec, PMaillonRecruteurs *llc_rec_arch, PMaillonOffres *llc_off, PMaillonOffres *llc_off_arch, PMaillonDemandes *llc_dem, PMaillonDemandes *llc_dem_arch);


#endif
