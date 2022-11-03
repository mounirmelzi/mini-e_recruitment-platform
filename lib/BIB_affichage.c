#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <synchapi.h>

#include "BIB_standard.h"
#include "BIB_recruteur.h"
#include "BIB_offre.h"
#include "BIB_demande.h"
#include "BIB_affichage.h"
#include "../EMPLOI_LLC_BIBLIO.h"
#include "conio2.h"


/* Les modules d'affichage */

//--------------------------------------------------------------------------------------------------------


void main_page(void)
{
    int speed = 5000;
    system("cls");
    system("color f0");
    textbackground(WHITE);
    textcolor(BLACK);
    printStrAnim(1000, "  +----------------------------------------------------------------------------------------------------------------+\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |       "); textcolor(BLUE); printStrAnim(speed, "\033[4mLe premier TP d'Algorithmique et structures de donnees dynamiques sur la gestion des e-recrutements"); textcolor(BLACK); printf("      |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printStrAnim(speed, "  |                                             Realise par : "); textcolor(LIGHTBLUE); printf("MELZI Mounir"); textcolor(BLACK); printf("                                         |\n");
    printf("  |                                                                                                                |\n");
    printStrAnim(speed, "  |                                                 Greoupe : "); textcolor(LIGHTBLUE); printf("02"); textcolor(BLACK); printf("                                                   |\n");
    printf("  |                                                                                                                |\n");
    printStrAnim(speed, "  |                                                 Section : "); textcolor(LIGHTBLUE); printf("A"); textcolor(BLACK); printf("                                                    |\n");
    printf("  |                                                                                                                |\n");
    printStrAnim(speed, "  |                                  Sous la supervision de : "); textcolor(LIGHTBLUE); printf("Madame TEMGLIT Nacera"); textcolor(BLACK); printf("                                |\n");
    printf("  |                                                                                                                |\n");
    printStrAnim(speed, "  |                                     Annee universitaire : "); textcolor(LIGHTBLUE); printf("2021/2022"); textcolor(BLACK); printf("                                            |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printStrAnim(1000, "  +----------------------------------------------------------------------------------------------------------------+\n");

    int x,y;
    gotoxy(5,2);
    x=wherex();
    y=wherey();
    gotoxy(x,y);
    printStrAnim(1, " ______  _____  __ ");
    gotoxy(x,y+1);
    printStrAnim(speed, "|  ____|/ ____||__|");
    gotoxy(x,y+2);
    printStrAnim(speed, "| |__  | (___   __ ");
    gotoxy(x,y+3);
    printStrAnim(speed, "|  __|  \\___ \\ |  |");
    gotoxy(x,y+4);
    printStrAnim(speed, "| |____ ____) ||  |");
    gotoxy(x,y+5);
    printStrAnim(speed, "|______|_____/ |__|");
    textcolor(LIGHTBLUE);
    gotoxy(x+15,y);
    printStrAnim(speed, " __");
    gotoxy(x+15,y+1);
    printStrAnim(speed, "|__|");
    textcolor(BLACK);
    gotoxy(x+21,y+1);
    printStrAnim(speed, "ecole nationale");
    gotoxy(x+21,y+3);
    printStrAnim(speed, "Superieure");
    gotoxy(x+21,y+5);
    printStrAnim(speed, "d'Informatique");

    gotoxy(1, 29);
    printf("\t\t\t\t    ");
    pause();
    return;
}

//--------------------------------------------------------------------------------------------------------

void printStrAnim(int speed, char string[])
{
    char *c = string;
    while(*c != 0)
    {
        printf("%c", *c);
        c++;
        usleep(speed);//90000
    }
}

//--------------------------------------------------------------------------------------------------------

void loading(void)
{
    consoleCursor(False);
    int len;
    char str[] = "\\|/-";
    int j = 0;
    int x = wherex(), y = wherey();
    char load[36] = {};
    strcpy(load, "  Loading  ");
    while(True)
    {
        len = strlen(load);
        if (len>=35)
            break;
        gotoxy(x, y);
        printf("%c", str[j++]);
        Sleep(200);
        printf("%s", load);
        load[len] = '.';
        if(j == 4)
            j = 0;
    }

    consoleCursor(True);
    printf("  100 %c ", 37);
}

//--------------------------------------------------------------------------------------------------------

void PRINT_ESI(void)
{
    printf("\n");
    system("color f1");
    int delay = 50;
    printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                  @@@@@@@@@@      @@        @@@@@@@@@@@@@@@\n");Sleep(delay);
    printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@@@@@@@@@@ @@@         @@@@@@@@@@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@@@@@@@@@@@@@@@@@@@@@@           @@@@@@@       @@@@@@@@@@@           @@@@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@                 @@@@@         @@@@@              @@@@@@@            @@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@                    @@@@        @@@@                 @@@@@@           @@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@                    @@@       @@@@@                  @@@@@          @@@@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@          @@@        @@       @@@@@@                   @@@          @@@@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@          @@@                  @@@@@@@                  @@          @@@@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@         @@@@                  @@@@@@@@@@@                          @@@@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@        @@@@@                    @@@@@@@@@@@@@@@                    @@@@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@@@@@@@@@@@@@@                      @@@@@@@@@@@@@@@@@                @@@@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@@@@@@@@@@@@@@                         @@@@@@@@@@@@@@@@@@            @@@@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@        @@@@@                               @@@@@@@@@@@@@@          @@@@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@         @@@@                                     @@@@@@@@@         @@@@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@          @@@                @@@@                    @@@@@@@        @@@@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@          @@@         @@@    @@@@                     @@@@@@        @@@@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@                     @@@@     @@@@                     @@@@@        @@@@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@                    @@@@      @@@@@@                   @@@@@         @@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@                  @@@@@@       @@@@@@                 @@@@@           @@@@@\n");Sleep(delay);
    printf("\t\t     @@@@@@                @@@@@@@        @@@@@@@@@            @@@@@@          @@@@@@@\n");Sleep(delay);
    printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@ @@@@@@@@@@@@@@@@@@@@@        @@@@@@@@@@@@@\n");Sleep(delay);
    printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@    @@@@@@@@@@@@@@@@          @@@@@@@@@@@@@@@\n\n");Sleep(delay);

    printf("\033[4;34m\n\t\t\t\t\t\t\tTP 1  ALSDD");
    textbackground(WHITE);
    textcolor(BLUE);
    printf("\n\n\t\t\t\t\t");
    loading();
    speak("Welcome to the program, press any key to continue");
    printf("\n\t\t\t\t\tAppuyez sur une touche pour commencer ... ");
    getch();
}

//--------------------------------------------------------------------------------------------------------

void PRINT_INFO(void)
{
    system("cls");
    system("color 07");
    textbackground(BLACK);
    char chaine[256] = "";
    int i = 2;

    textcolor(WHITE);
    printf("  +----------------------------------------------------------------------------------------------------------------+\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  |                                                                                                                |\n");
    printf("  +----------------------------------------------------------------------------------------------------------------+\n");//27

    gotoxy(4,i);
    textcolor(LIGHTRED);
    FILE *fichier = fopen("INFO.txt", "r");

        if(fichier == NULL)
        {
            printf("Probleme d'ouverture de fichier!\n");
            exit(EXIT_FAILURE);
        }

        while(! feof(fichier))
        {
            fgets(chaine, 256, fichier);
            printStrAnim(40000, chaine);
            strcpy(chaine, "");
            i++;
            gotoxy(4, i);

            if(i > 11)
                textcolor(LIGHTBLUE);
        }

    fclose(fichier);


    gotoxy(1, 29);
    printf("\t\t\t\t    ");
    textcolor(WHITE);
    pause();
    system("color 07");
}

//--------------------------------------------------------------------------------------------------------

void fin_programme(void)
{
    consoleCursor(FALSE);
    system("cls");
    system("color f0");
    textbackground(WHITE);
    int i = 0;
    int maxColors = 3;
    int colors[] = {LIGHTBLUE, BLUE, BLACK};
    int speed = 10;
    while(1)
    {
        if(isPressedEnter())
            if(isPressedEnter())
                break;

        gotoxy(1,1);
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                  @@@@@@@@@@      @@        @@@@@@@@@@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@@@@@@@@@@ @@@         @@@@@@@@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@@@@@@@@@@@@@@@@@@@@@@           @@@@@@@       @@@@@@@@@@@           @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                 @@@@@         @@@@@              @@@@@@@            @@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@                    @@@@        @@@@                 @@@@@@           @@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                    @@@       @@@@@                  @@@@@          @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@        @@       @@@@@@                   @@@          @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@                  @@@@@@@                  @@          @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@         @@@@                  @@@@@@@@@@@                          @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@        @@@@@                    @@@@@@@@@@@@@@@                    @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@@@@@@@@@@@@@@                      @@@@@@@@@@@@@@@@@                @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@@@@@@@@@@@@@@                         @@@@@@@@@@@@@@@@@@            @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@        @@@@@                               @@@@@@@@@@@@@@          @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@         @@@@                                     @@@@@@@@@         @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@                @@@@                    @@@@@@@        @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@         @@@    @@@@                     @@@@@@        @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@                     @@@@     @@@@                     @@@@@        @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                    @@@@      @@@@@@                   @@@@@         @@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@                  @@@@@@       @@@@@@                 @@@@@           @@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                @@@@@@@        @@@@@@@@@            @@@@@@          @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@ @@@@@@@@@@@@@@@@@@@@@        @@@@@@@@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@    @@@@@@@@@@@@@@@@          @@@@@@@@@@@@@@@\n\n");

        textcolor(BLUE);
        printf("\n\t\t\t\t\t\tMerci pour l'utilisation du mon TP\n\n");

        textcolor(RED);
        printf("\t\033[4mRealise par :");

        textcolor(LIGHTRED);
        printf(" MELZI MOUNIR    ");

        textcolor(RED);
        printf("\033[4mGroupe :");

        textcolor(LIGHTRED);
        printf(" 02    ");

        textcolor(RED);
        printf("\033[4mSection :");

        textcolor(LIGHTRED);
        printf(" A    ");

        textcolor(RED);
        printf("\033[4mSous la supervision de :");

        textcolor(LIGHTRED);
        printf(" Madame TEMGLIT Nacera \n\n");

        textcolor(BLUE);
        printf("\t\t\t\t\t\tAppuyez sur ENTRER pour sortir ... ");
    }
    speak("Thanks for using my program");
    system("color 07");
    system("cls");
    exit(0); // Sortit du programme !!
}

//--------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------

/* Les modules des menu */

//--------------------------------------------------------------------------------------------------------

int menu_principal(void)
{
debut:
    system("color 07");
    system("cls");
    int choix = 0;
    textcolor(WHITE);
    printf("\n\t\t\t    \033[4mMenu  principal :\n\n\n");
    textcolor(LIGHTCYAN);
    printf("\t1  -->  Afficher les annonces / les annonceurs\n\n");
    printf("\t2  -->  Enregistrer une nouvelle annonce / un nouvel annonceur (recruteur)\n\n");
    printf("\t3  -->  Supprimer une annonce / un annonceur (recruteur)\n\n");
    printf("\t4  -->  Afficher les offres dont le delai de condidature est toujours valables\n\n");
    printf("\t5  -->  Afficher les annonces entre deux dates donnees\n\n");
    printf("\t6  -->  Rechercher les demandeurs ayant 'X' competences et maitrisant une langue 'Y'\n\n");
    printf("\t7  -->  Chercher les offres appartenant a un meme annonceur (recruteur)\n\n");
    printf("\t8  -->  Afficher les 'X' postes les plus demandes\n\n");
    printf("\t9  -->  Trier les offres d'emploi selon le nombre de competences\n\n");
    printf("\t10 -->  Recommander des demandes qui peuvent correspondre a une offre d'emploi donnee\n\n");
    printf("\t11 -->  Quitter le programme\n\n");

    textcolor(WHITE);
    printf("\n\t\tEntrer votre choix: ");
    textcolor(CYAN);
    scanf("%d", &choix);
    fflush(stdin);

    if ((choix < 1) || (choix > 11))
    {
        system("color 47");
        goto debut;
    }

    system("color 07");
    return choix;
}

//--------------------------------------------------------------------------------------------------------

int menu_choix1(void)
{
debut:
    system("color 07");
    system("cls");
    int choix = 0;
    textcolor(WHITE);
    printf("\n\n\t\t\t    \033[4mAfficher les annonces / les annonceurs :\n\n\n");
    textcolor(LIGHTCYAN);
    printf("\t1  -->  Afficher la liste active des recruteurs\n\n");
    printf("\t2  -->  Afficher la liste active des offres\n\n");
    printf("\t3  -->  Afficher la liste active des demandes\n\n");
    printf("\t4  -->  Afficher la liste archive des recruteurs\n\n");
    printf("\t5  -->  Afficher la liste archive des offres\n\n");
    printf("\t6  -->  Afficher la liste archive des demandes\n\n");
    printf("\t7  -->  Retour au menu principal\n\n");

    textcolor(WHITE);
    printf("\n\n\n\t\tEntrer votre choix: ");
    textcolor(CYAN);
    scanf("%d", &choix);
    fflush(stdin);

    if ((choix < 1) || (choix > 7))
    {
        system("color 47");
        goto debut;
    }

    system("color 07");
    return choix;
}

//--------------------------------------------------------------------------------------------------------

int menu_choix2(void)
{
debut:
    system("color 07");
    system("cls");
    int choix = 0;
    textcolor(WHITE);
    printf("\n\n\t\t\t    \033[4mEnregistrer une nouvelle annonce / un nouvel annonceur :\n\n\n");
    textcolor(LIGHTCYAN);
    printf("\t1  -->  Enregistrer un nouvel annonceur (recruteur)\n\n");
    printf("\t2  -->  Enregistrer une nouvelle offre\n\n");
    printf("\t3  -->  Enregistrer une nouvelle demande\n\n");
    printf("\t4  -->  Retour au menu principal\n\n");

    textcolor(WHITE);
    printf("\n\n\n\t\tEntrer votre choix: ");
    textcolor(CYAN);
    scanf("%d", &choix);
    fflush(stdin);

    if ((choix < 1) || (choix > 4))
    {
        system("color 47");
        goto debut;
    }

    system("color 07");
    return choix;
}

//--------------------------------------------------------------------------------------------------------

int menu_validation_enregistrement(const char chaine[])
{
debut:
    system("color 07");
    system("cls");
    int choix = 0;

    printf("\n\n\t\t\t    Voulez-vous vraiment enregistrer %s dans la liste active :  \n\n\n", chaine);

    printf("\t1\tOui, Enregistrer %s\n", chaine);
    printf("\t2\tNon, modifier les informations de %s\n", chaine);
    printf("\t3\tNon, retour au menu precedent (menu de l'enregistrement des donnes)\n");
    printf("\t4\tNon, retour au menu principal\n");


    printf("\n\n\n\t\tEntrer votre choix: ");
    scanf("%d", &choix);
    fflush(stdin);

    if ((choix < 1) || (choix > 4))
    {
        system("color 47");
        goto debut;
    }

    return choix;
}

//--------------------------------------------------------------------------------------------------------

int menu_choix3(void)
{
debut:
    system("color 07");
    system("cls");
    int choix = 0;
    textcolor(WHITE);
    printf("\n\n\t\t\t    \033[4mSupprimer une annonce / un annonceur :\n\n\n");
    textcolor(LIGHTCYAN);
    printf("\t1  -->  Supprimer un annonceur (recruteur)\n\n");
    printf("\t2  -->  Supprimer une offre\n\n");
    printf("\t3  -->  Supprimer une demande\n\n");
    printf("\t4  -->  Retour au menu principal\n\n");

    textcolor(WHITE);
    printf("\n\n\n\t\tEntrer votre choix: ");
    textcolor(CYAN);
    scanf("%d", &choix);
    fflush(stdin);

    if ((choix < 1) || (choix > 4))
    {
        system("color 47");
        goto debut;
    }

    system("color 07");
    return choix;
}

//--------------------------------------------------------------------------------------------------------

int menu_validation_suppression(const char chaine[])
{
debut:
    system("color 07");
    system("cls");
    int choix = 0;

    printf("\n\n\t\t\t    Voulez-vous vraiment supprimer %s de la liste active :  \n\n\n", chaine);

    printf("\t1\tOui, Supprimer %s\n", chaine);
    printf("\t2\tNon, choisir autre %s a supprimer\n", chaine);
    printf("\t3\tNon, retour au menu precedent (suppression d'une autre structure de donnes)\n");
    printf("\t4\tNon, retour au menu principal\n");


    printf("\n\n\n\t\tEntrer votre choix: ");
    scanf("%d", &choix);
    fflush(stdin);

    if ((choix < 1) || (choix > 4))
    {
        system("color 47");
        goto debut;
    }

    return choix;
}

//--------------------------------------------------------------------------------------------------------

int menu_choix5(void)
{
debut:
    system("color 07");
    system("cls");
    int choix = 0;
    textcolor(WHITE);
    printf("\n\n\t\t\t    \033[4mAfficher toutes les annonces entre deux dates donnees :\n\n\n");
    textcolor(LIGHTCYAN);
    printf("\t1  -->  Afficher toutes les offres actives entre deux dates donnes\n\n");
    printf("\t2  -->  Afficher toutes les offres archives entre deux dates donnes\n\n");
    printf("\t3  -->  Afficher toutes les demandes actives entre deux dates donnes\n\n");
    printf("\t4  -->  Afficher toutes les demandes archives entre deux dates donnes\n\n");
    printf("\t5  -->  Afficher toutes les offres (actives/archives) entre deux dates donnes\n\n");
    printf("\t6  -->  Afficher toutes les demandes (actives/archives) entre deux dates donnes\n\n");
    printf("\t7  -->  Afficher toutes les annonces (offres/demandes) active entre deux dates donnes\n\n");
    printf("\t8  -->  Afficher toutes les annonces (offres/demandes) archive entre deux dates donnes\n\n");
    printf("\t9  -->  Afficher toutes les annonces entre deux dates donnes\n\n");
    printf("\t10 -->  Retour au menu principal\n");

    textcolor(WHITE);
    printf("\n\n\n\t\tEntrer votre choix: ");
    textcolor(CYAN);
    scanf("%d", &choix);
    fflush(stdin);

    if ((choix < 1) || (choix > 10))
    {
        system("color 47");
        goto debut;
    }

    system("color 07");
    return choix;
}

//--------------------------------------------------------------------------------------------------------

int menu_validation_affichageOffresDeRecruteur()
{
    int choix = 0;

    printf("\t1\tOui, afficher tous ces offres\n");
    printf("\t2\tNon, choisir autre recruteur\n");
    printf("\t3\tNon, retour au menu principal\n\n\n\n");

debut:
    system("color 07");
    printf("\t\tEntrer votre choix: ");
    scanf("%d", &choix);
    fflush(stdin);

    if ((choix < 1) || (choix > 3))
    {
        system("color 47");
        deleteConsoleLines(-2);
        goto debut;
    }

    return choix;
}

//--------------------------------------------------------------------------------------------------------

int menu_choix9(void)
{
debut:
    system("color 07");
    system("cls");
    int choix = 0;
    textcolor(WHITE);
    printf("\n\n\t\t\t    \033[4mTrier les offres d'emploi selon le nombre de competences :\n\n\n\n\n");
    textcolor(LIGHTCYAN);
    printf("\t1  -->  Effectuer le tri selon la methode de tri par eclatement et fusion\n\n");
    printf("\t2  -->  Effectuer le tri selon la methode de tri par bulles\n\n");
    printf("\t3  -->  Retour au menu principal\n\n");

    textcolor(WHITE);
    printf("\n\n\n\t\tEntrer votre choix: ");
    textcolor(CYAN);
    scanf("%d", &choix);
    fflush(stdin);

    if ((choix < 1) || (choix > 3))
    {
        system("color 47");
        goto debut;
    }

    system("color 07");
    return choix;
}

//--------------------------------------------------------------------------------------------------------

int menu_validation_sauvegardeTri(void)
{
debut:
    system("color 07");
    system("cls");
    int choix = 0;

    printf("\n\n\t\t\t    Que voulez-vous faire :  \n\n\n");

    printf("\t1\tAfficher la liste triee sans la sauvegarder\n");
    printf("\t2\tSauvegarder la liste triee (Remplacer la liste original par la liste triee)\n");
    printf("\t3\tRetour au menu principal\n");


    printf("\n\n\n\t\tEntrer votre choix: ");
    scanf("%d", &choix);
    fflush(stdin);

    if ((choix < 1) || (choix > 3))
    {
        system("color 47");
        goto debut;
    }

    return choix;
}

//--------------------------------------------------------------------------------------------------------

int menu_validation_recommandation(Offre offre)
{
debut:
    system("color 07");
    system("cls");
    int choix = 0;

    printf("\n\n\t\tVoulez-vous vraiment recommander des demandes a cette offre ?  \n\n");
    printOffre(offre);
    printf("\n\n");

    printf("\t1\tOui, Construire la liste des demandes qui peuvent correspondre a cette offre d'emploi\n");
    printf("\t2\tNon, choisir autre offre pour la recommander des demandes\n");
    printf("\t3\tNon, retour au menu principal\n");

    printf("\n\n\n\t\tEntrer votre choix: ");
    scanf("%d", &choix);
    fflush(stdin);

    if ((choix < 1) || (choix > 3))
    {
        system("color 47");
        goto debut;
    }

    return choix;
}

//--------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------


/* Les modules des choix */

//--------------------------------------------------------------------------------------------------------

void choix1(PMaillonRecruteurs llc_rec, PMaillonRecruteurs llc_rec_arch, PMaillonOffres llc_off, PMaillonOffres llc_off_arch, PMaillonDemandes llc_dem, PMaillonDemandes llc_dem_arch)
{
    int choix;
debut:

    choix = menu_choix1();

    switch (choix)
    {
    case 1:
        system("cls");
        printf("\n\n\t\t\t    la liste active des recruteurs :  \n\n\n");
        afficher_LLC_rec(llc_rec);
        break;

    case 2:
        system("cls");
        printf("\n\n\t\t\t    la liste active des offres :  \n\n\n");
        afficher_LLC_off(llc_off);
        break;

    case 3:
        system("cls");
        printf("\n\n\t\t\t    la liste active des demandes :  \n\n\n");
        afficher_LLC_dem(llc_dem);
        break;

    case 4:
        system("cls");
        printf("\n\n\t\t\t    la liste archive des recruteurs :  \n\n\n");
        afficher_LLC_rec(llc_rec_arch);
        break;

    case 5:
        system("cls");
        printf("\n\n\t\t\t    la liste archive des offres :  \n\n\n");
        afficher_LLC_off(llc_off_arch);
        break;

    case 6:
        system("cls");
        printf("\n\n\t\t\t    la liste archive des demandes :  \n\n\n");
        afficher_LLC_dem(llc_dem_arch);
        break;

    case 7:
        return;
        break;

    default:
        break;
    }


    printf("\n\n");
    pause();


choisir: // apr�s l'affichage d'une liste

    system("color 07");
    system("cls");
    choix = 0;

    printf("\n\n\n\n\n");
    printf("\t1\tAfficher une autre liste\n");
    printf("\t2\tRetour au menu principal\n");

    printf("\n\n\n\t\tEntrer votre choix: ");
    scanf("%d", &choix);
    fflush(stdin);

    if ((choix < 1) || (choix > 2))
    {
        system("color 47");
        goto choisir;
    }

    if(choix == 1)
        goto debut;
    else if(choix == 2)
        return;
}

//--------------------------------------------------------------------------------------------------------

void choix2(PMaillonRecruteurs *llc_rec, PMaillonOffres *llc_off, PMaillonDemandes *llc_dem)
{
    int choix;
debut:

    choix = menu_choix2();

    switch(choix)
    {
        case 1:
        {
            // Début case 1
            Recruteur recruteur = creatRecruteur();

            system("cls");
            system("color 2f");
            printf("\n\n\tLa creation du recruteur suivant est terminee avec succes!\n\n");
            printRecruteur(recruteur);
            printf("\n\n\t");
            pause();

validation_recruteur:
            choix = menu_validation_enregistrement("le recruteur");

            if(choix == 1)
            {
                // Vérification de l'unicité
                for(PMaillonRecruteurs p = *llc_rec; p != NULL; p = suivantLLC_rec(p))
                {
                    if(comparerStr(valeurLLC_rec(p).nom, recruteur.nom))
                    {
                        system("color 47");
                        printf("\n\n\n\tATTENTION !! Ce recruteur existe deja dans la liste des recruteurs\n");
                        printf("\n\tAppuyez sur une touche pour revenir au menu principal ... ");
                        getch();
                        return;
                    }
                }

                // La vérification est trminée, Début de l'insertion
                insererRecruteur_LLC_rec(llc_rec, recruteur);
                system("color 2f");
                printf("\n\n\n\tL'enregistrement du recruteur suivant dans la liste active est termine avec succes!\n\n");
                printRecruteur(recruteur);
            }
            else if(choix == 2)
            {
                modifRecruteur(&recruteur);
                system("cls");
                system("color 2f");
                printf("\n\n\t\tLa modification du recruteur est terminee avec succes!\n\n");
                printf("\n\tVoici les informations du recruteur apres la modification: \n");
                printRecruteur(recruteur);
                printf("\n\n\t");
                pause();
                goto validation_recruteur;
            }
            else if(choix == 3)
            {
                goto debut;
            }
            else if(choix == 4)
            {
                return;
            }
            // Fin case 1
            break;
        }


        case 2:
        {
            // Début case 2
            Bool Recruteur_Existe = False;
            Offre offre = creatOffre(*llc_rec, &Recruteur_Existe);

            if(! Recruteur_Existe) // Erreur le recruteur n'existe pas !!
            {
                system("color 47");
                printf("\n\n\n\tATTENTION !! Le recruteur de cette offre n'existe pas dans la liste des recruteur\n");
                printf("\tVeuillez enregistrer d'abord ce recruteur puis re-enregistrer cette offre\n");
                printf("\tVous pouvez aussi cosulter la liste active des recruteurs pour connaitre les recruteurs disponibles\n");
                printf("\n\tAppuyez sur une touche pour revenir au menu principal ... ");
                getch();
                return;
            }

            system("cls");
            system("color 2f");
            printf("\n\n\tLa creation de l'offre suivante est terminee avec succes!\n\n");
            printOffre(offre);
            printf("\n\n\t");
            pause();

validation_offre:
            choix = menu_validation_enregistrement("l'offre");

            if(choix == 1)
            {
                // Vérification de l'unicité
                for(PMaillonOffres p = *llc_off; p != NULL; p = suivantLLC_off(p))
                {
                    if(eq_off(valeurLLC_off(p), offre))
                    {
                        system("color 47");
                        printf("\n\n\n\tATTENTION !! Cette offre existe deja dans la liste des offres\n");
                        printf("\n\tAppuyez sur une touche pour revenir au menu principal ... ");
                        getch();
                        return;
                    }
                }

                // La vérification est trminée, Début de l'insertion
                insererOffre_LLC_off(llc_off, offre);
                system("color 2f");
                printf("\n\n\n\tL'enregistrement de l'offre suivante dans la liste active est termine avec succes!\n\n");
                printOffre(offre);
            }
            else if(choix == 2)
            {
                modifOffre(&offre);
                system("cls");
                system("color 2f");
                printf("\n\n\t\tLa modification de l'offre est terminee avec succes!\n\n");
                printf("\n\tVoici les informations de l'offre apres la modification: \n");
                printOffre(offre);
                printf("\n\n\t");
                pause();
                goto validation_offre;
            }
            else if(choix == 3)
            {
                goto debut;
            }
            else if(choix == 4)
            {
                return;
            }

            // Fin case 2
            break;
        }


        case 3:
        {
            // Début case 3
            Demande demande = creatDemande();

            system("cls");
            system("color 2f");
            printf("\n\n\tLa creation de la demande suivante est terminee avec succes!\n\n");
            printDemande(demande);
            printf("\n\n\t");
            pause();

validation_demande:
            choix = menu_validation_enregistrement("la demande");

            if(choix == 1)
            {
                // Vérification de l'unicité
                for(PMaillonDemandes p = *llc_dem; p != NULL; p = suivantLLC_dem(p))
                {
                    if(eq_dem(valeurLLC_dem(p), demande))
                    {
                        system("color 47");
                        printf("\n\n\n\tATTENTION !! Cette demande existe deja dans la liste des demandes\n");
                        printf("\n\tAppuyez sur une touche pour revenir au menu principal ... ");
                        getch();
                        return;
                    }
                }

                // La vérification est trminée, Début de l'insertion
                insererDemande_LLC_dem(llc_dem, demande);
                system("color 2f");
                printf("\n\n\n\tL'enregistrement de la demande suivante dans la liste active est termine avec succes!\n");
                printDemande(demande);
            }
            else if(choix == 2)
            {
                modifDemande(&demande);
                system("cls");
                system("color 2f");
                printf("\n\n\t\tLa modification du demande est terminee avec succes!\n\n");
                printf("\n\tVoici les informations du demande apres la modification: \n");
                printDemande(demande);
                printf("\n\n\t");
                pause();
                goto validation_demande;
            }
            else if(choix == 3)
            {
                goto debut;
            }
            else if(choix == 4)
            {
                return;
            }
            // Fin case 3
            break;
        }


        case 4:
        {
            return;
            break;
        }


        default:
            break;
    }


    // Le traitement après l'insertion des données dans les listes
    printf("\n\n");
    pause();


choisir: // aprés l'Enregistrement d'une nouvelle annonce / un nouvel annonceur

    system("color 07");
    system("cls");
    choix = 0;

    printf("\n\n\n\n\n");
    printf("\t1\tEnregistrer autre annonce / annonceur\n");
    printf("\t2\tRetour au menu principal\n");

    printf("\n\n\n\t\tEntrer votre choix: ");
    scanf("%d", &choix);
    fflush(stdin);

    if ((choix < 1) || (choix > 2))
    {
        system("color 47");
        goto choisir;
    }

    if(choix == 1)
        goto debut;
    else if(choix == 2)
        return;
}

//--------------------------------------------------------------------------------------------------------

void choix3(PMaillonRecruteurs *llc_rec, PMaillonRecruteurs *llc_rec_arch, PMaillonOffres *llc_off, PMaillonOffres *llc_off_arch, PMaillonDemandes *llc_dem, PMaillonDemandes *llc_dem_arch)
{
    int choix;
debut:

    choix = menu_choix3();

    switch(choix)
    {
        case 1:
        {
            // Début case 1
supprimer_recruteur:
            system("cls");
            printf("\n\n\t\t\t    Suppression d'un recruteur :  \n\n\n\n\n");

            int taille_liste_recruteur = taille_LLC_rec(*llc_rec);
            if(taille_liste_recruteur == 0)
            {
                system("color 47");
                printf("\tATTENTION !! La liste des recruteurs active est vide!\n");
                printf("\n\tPas de recruteurs a supprimer !!\n");

                printf("\n\n\t\tAppuyez sur une touche pour revenir au menu principal ...");
                getch();
                return;
            }

            printf("\tLa liste des recruteurs active: \n\n\n");
            afficher_LLC_rec(*llc_rec);
            printf("\n\n\n\t\t\t\tVoici la liste des recruteurs active !\n\n");
position_recruteur:
            system("color 07");
            printf("\tEntrer la position du recruteur que vous voulez supprimer de la liste active des recruteurs: ");

            int position = 0;
            fflush(stdin);
            int inputs = scanf("%d", &position); // récupérer la position de la suppression
            fflush(stdin);

            if((inputs != 1) || (position < 1) || (position > taille_liste_recruteur))
            {
                system("color 47");
                deleteConsoleLines(-2);
                goto position_recruteur;
            }

            Recruteur toDelete = valeurLLC_rec(accesPos_LLC_rec(*llc_rec, position));
            // confirmer la suppression
            system("cls");
            printf("\n\n\tVous avez choisit de supprimer le recruteur suivant: \n\n");
            printRecruteur(toDelete);
            printf("\n\n\t");
            pause();
            deleteConsoleLines(-2);

            choix = menu_validation_suppression("recruteur");

            if(choix == 1)
            {
                system("color 2f");
                suppressionRecruteur(llc_rec, position, llc_rec_arch, llc_off, llc_off_arch);
                printf("\n\n\n\tLa suppression du recruteur suivant est termine avec succes!\n\n");
                printRecruteur(toDelete);
            }
            else if(choix == 2)
            {
                goto supprimer_recruteur;
            }
            else if(choix == 3)
            {
                goto debut;
            }
            else if(choix == 4)
            {
                return;
            }
            // Fin case 1
            break;
        }

        case 2:
        {
            // Début case 2
supprimer_offre:
            system("cls");
            printf("\n\n\t\t\t    Suppression d'une offre :  \n\n\n\n\n");

            int taille_liste_offre = taille_LLC_off(*llc_off);
            if(taille_liste_offre == 0)
            {
                system("color 47");
                printf("\tATTENTION !! La liste des offres active est vide!\n");
                printf("\n\tPas d'offres a supprimer !!\n");

                printf("\n\n\t\tAppuyez sur une touche pour revenir au menu principal ...");
                getch();
                return;
            }

            printf("\tLa liste des offres active: \n\n\n");
            afficher_LLC_off(*llc_off);
            printf("\n\n\n\t\t\t\tVoici la liste des offres active !\n\n");
position_offre:
            system("color 07");
            printf("\tEntrer la position de l'offre que vous voulez supprimer de la liste active des offres: ");

            int position = 0;
            fflush(stdin);
            int inputs = scanf("%d", &position); // récupérer la position de la suppression
            fflush(stdin);

            if((inputs != 1) || (position < 1) || (position > taille_liste_offre))
            {
                system("color 47");
                deleteConsoleLines(-2);
                goto position_offre;
            }

            Offre toDelete = valeurLLC_off(accesPos_LLC_off(*llc_off, position));
            // confirmer la suppression
            system("cls");
            printf("\n\n\tVous avez choisit de supprimer l'offre suivante: \n\n");
            printOffre(toDelete);
            printf("\n\n\t");
            pause();
            deleteConsoleLines(-2);

            choix = menu_validation_suppression("offre");

            if(choix == 1)
            {
                system("color 2f");
                suppressionOffre(llc_off, position, llc_off_arch, llc_rec, llc_rec_arch);
                printf("\n\n\n\tLa suppression de l'offre suivante est termine avec succes!\n\n");
                printOffre(toDelete);
            }
            else if(choix == 2)
            {
                goto supprimer_offre;
            }
            else if(choix == 3)
            {
                goto debut;
            }
            else if(choix == 4)
            {
                return;
            }
            // Fin case 2
            break;
        }

        case 3:
        {
            // Début case 3
supprimer_demande:
            system("cls");
            printf("\n\n\t\t\t    Suppression d'une demande :  \n\n\n\n\n");

            int taille_liste_demande = taille_LLC_dem(*llc_dem);
            if(taille_liste_demande == 0)
            {
                system("color 47");
                printf("\tATTENTION !! La liste des demandes active est vide!\n");
                printf("\n\tPas de demandes a supprimer !!\n");

                printf("\n\n\t\tAppuyez sur une touche pour revenir au menu principal ...");
                getch();
                return;
            }

            printf("\tLa liste des demandes active: \n\n\n");
            afficher_LLC_dem(*llc_dem);
            printf("\n\n\n\t\t\t\tVoici la liste des demandes active !\n\n");
position_demande:
            system("color 07");
            printf("\tEntrer la position de la demande que vous voulez supprimer de la liste active des demandes: ");

            int position = 0;
            fflush(stdin);
            int inputs = scanf("%d", &position); // récupérer la position de la suppression
            fflush(stdin);

            if((inputs != 1) || (position < 1) || (position > taille_liste_demande))
            {
                system("color 47");
                deleteConsoleLines(-2);
                goto position_demande;
            }

            Demande toDelete = valeurLLC_dem(accesPos_LLC_dem(*llc_dem, position));
            // confirmer la suppression
            system("cls");
            printf("\n\n\tVous avez choisit de supprimer la demande suivante: \n\n");
            printDemande(toDelete);
            printf("\n\n\t");
            pause();
            deleteConsoleLines(-2);

            choix = menu_validation_suppression("demande");

            if(choix == 1)
            {
                system("color 2f");
                suppressionDemande(llc_dem, position, llc_dem_arch);
                printf("\n\n\n\tLa suppression de la demande suivante est termine avec succes!\n\n");
                printDemande(toDelete);
            }
            else if(choix == 2)
            {
                goto supprimer_demande;
            }
            else if(choix == 3)
            {
                goto debut;
            }
            else if(choix == 4)
            {
                return;
            }
            // Fin case 3
            break;
        }

        case 4:
        {
            return;
            break;
        }

        default:
            break;
    }

    // Le traitement après la suppression des données des listes
    printf("\n\n");
    pause();


choisir: // aprés la suppression d'une annonce / un annonceur

    system("color 07");
    system("cls");
    choix = 0;

    printf("\n\n\n\n\n");
    printf("\t1\tSupprimer autre annonce / annonceur\n");
    printf("\t2\tRetour au menu principal\n");

    printf("\n\n\n\t\tEntrer votre choix: ");
    scanf("%d", &choix);
    fflush(stdin);

    if ((choix < 1) || (choix > 2))
    {
        system("color 47");
        goto choisir;
    }

    if(choix == 1)
        goto debut;
    else if(choix == 2)
        return;

}

//--------------------------------------------------------------------------------------------------------

void choix4(PMaillonOffres llc_off, PMaillonRecruteurs llc_rec)
{
    textcolor(LIGHTGRAY);
    textbackground(BLACK);

    system("cls");
    printf("\n\n\t\t    Rechercher les offres dont le delai de condidature est toujours valable :  \n\n\n\n\n\t");

    // demander à l'utilisateur d'entrer la date de recherche
    printf("\tVeuillez entrer la date pour laquelle on effectue la recherche s'il vous plait; \n\n");
    printf("\tPar exemple vous pouvez entrer la date d'aujourd'hui\n");
    printf("\tet nous allons vous afficher les offres qui sont valables pour aujourd'hui\n\n\n\n\n");

    Date date;
    scanDate(&date);

    system("cls");
    printf("\n\n\t\t    Rechercher les offres dont le delai de condidature est toujours valable :  \n\n\n\t");
    printf("\tLes offres valables le %d/%d/%d sont : \n\n\n", date.jour, date.mois, date.annee);

    affichageOffresValables(llc_off, llc_rec, date);

    textcolor(LIGHTGRAY);
    textbackground(BLACK);
    printf("\n\n\tAppuyez sur une touche pour revenir au menu principal ... ");
    getch();
    system("color 07");
    return;
}

//--------------------------------------------------------------------------------------------------------

void choix5(PMaillonRecruteurs llc_rec, PMaillonRecruteurs llc_rec_arch, PMaillonOffres llc_off, PMaillonOffres llc_off_arch, PMaillonDemandes llc_dem, PMaillonDemandes llc_dem_arch)
{
    int choix;
    Date date_inf, date_sup;

debut:

    choix = menu_choix5();

    switch(choix)
    {
        case 1:
        {
            // debut case 1
            system("cls");
            printf("\n\n\t\t    Afficher toutes les offres actives entre deux dates donnes : \n\n\n\n");
            printf("\tVeuillez entrer les deux dates pour lesquelles on effectue la recherche s'il vous plait : \n\n\n\n\n");
            printf("Entrer la premiere date : \n");
            scanDate(&date_inf);
            printf("\n\n\rEntrer la deuxieme date : \n");
            scanDate(&date_sup);
            if(datecmp(date_inf, date_sup) > 0) // permuter les deux dates si date_inf > date_sup
            {
                Date date_temp = date_inf;
                date_inf = date_sup;
                date_sup = date_temp;
            }

            // l'affichage des annonces entre les deux dates
            system("cls");
            printf("\n\n\t\t    Afficher toutes les offres actives entre deux dates donnes : \n\n\n\n\n\n");

            textcolor(LIGHTCYAN);
            printf("Appuyez sur une touche pour lancer l'affichage de toutes les offres actives ...");
            getch();
            deleteConsoleLines(-3);
            printf("\tLes offres actives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageOffresParDates(llc_off, date_inf, date_sup);
            // fin case 1
            break;
        }

        case 2:
        {
            // debut case 2
            system("cls");
            printf("\n\n\t\t    Afficher toutes les offres archives entre deux dates donnes : \n\n\n\n");
            printf("\tVeuillez entrer les deux dates pour lesquelles on effectue la recherche s'il vous plait : \n\n\n\n\n");
            printf("Entrer la premiere date : \n");
            scanDate(&date_inf);
            printf("\n\n\rEntrer la deuxieme date : \n");
            scanDate(&date_sup);
            if(datecmp(date_inf, date_sup) > 0) // permuter les deux dates si date_inf > date_sup
            {
                Date date_temp = date_inf;
                date_inf = date_sup;
                date_sup = date_temp;
            }

            // l'affichage des annonces entre les deux dates
            system("cls");
            printf("\n\n\t\t    Afficher toutes les offres archives entre deux dates donnes : \n\n\n\n\n\n");

            textcolor(CYAN);
            printf("Appuyez sur une touche pour lancer l'affichage de toutes les offres archives ...");
            getch();
            deleteConsoleLines(-3);
            printf("\tLes offres archives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageOffresParDates(llc_off_arch, date_inf, date_sup);
            // fin case 2
            break;
        }

        case 3:
        {
            // debut case 3
            system("cls");
            printf("\n\n\t\t    Afficher toutes les demandes actives entre deux dates donnes : \n\n\n\n");
            printf("\tVeuillez entrer les deux dates pour lesquelles on effectue la recherche s'il vous plait : \n\n\n\n\n");
            printf("Entrer la premiere date : \n");
            scanDate(&date_inf);
            printf("\n\n\rEntrer la deuxieme date : \n");
            scanDate(&date_sup);
            if(datecmp(date_inf, date_sup) > 0) // permuter les deux dates si date_inf > date_sup
            {
                Date date_temp = date_inf;
                date_inf = date_sup;
                date_sup = date_temp;
            }

            // l'affichage des annonces entre les deux dates
            system("cls");
            printf("\n\n\t\t    Afficher toutes les demandes actives entre deux dates donnes : \n\n\n\n\n\n");

            textcolor(LIGHTMAGENTA);
            printf("Appuyez sur une touche pour lancer l'affichage de toutes les demandes actives ...");
            getch();
            deleteConsoleLines(-3);
            printf("\tLes demandes actives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageDemandesParDates(llc_dem, date_inf, date_sup);
            // fin case 3
            break;
        }

        case 4:
        {
            // debut case 4
            system("cls");
            printf("\n\n\t\t    Afficher toutes les demandes archives entre deux dates donnes : \n\n\n\n");
            printf("\tVeuillez entrer les deux dates pour lesquelles on effectue la recherche s'il vous plait : \n\n\n\n\n");
            printf("Entrer la premiere date : \n");
            scanDate(&date_inf);
            printf("\n\n\rEntrer la deuxieme date : \n");
            scanDate(&date_sup);
            if(datecmp(date_inf, date_sup) > 0) // permuter les deux dates si date_inf > date_sup
            {
                Date date_temp = date_inf;
                date_inf = date_sup;
                date_sup = date_temp;
            }

            // l'affichage des annonces entre les deux dates
            system("cls");
            printf("\n\n\t\t    Afficher toutes les demandes archives entre deux dates donnes : \n\n\n\n\n\n");

            textcolor(MAGENTA);
            printf("Appuyez sur une touche pour lancer l'affichage de toutes les demandes archives ...");
            getch();
            deleteConsoleLines(-3);
            printf("\tLes demandes archives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageDemandesParDates(llc_dem, date_inf, date_sup);
            // fin case 4
            break;
        }

        case 5:
        {
            // debut case 5
            system("cls");
            printf("\n\n\t\t    Afficher toutes les offres (actives/archives) entre deux dates donnes : \n\n\n\n");
            printf("\tVeuillez entrer les deux dates pour lesquelles on effectue la recherche s'il vous plait : \n\n\n\n\n");
            printf("Entrer la premiere date : \n");
            scanDate(&date_inf);
            printf("\n\n\rEntrer la deuxieme date : \n");
            scanDate(&date_sup);
            if(datecmp(date_inf, date_sup) > 0) // permuter les deux dates si date_inf > date_sup
            {
                Date date_temp = date_inf;
                date_inf = date_sup;
                date_sup = date_temp;
            }

            // l'affichage des annonces entre les deux dates
            system("cls");
            printf("\n\n\t\t    Afficher toutes les offres (actives/archives) entre deux dates donnes : \n\n\n\n\n\n");

            textcolor(LIGHTCYAN);
            printf("Appuyez sur une touche pour commencer a afficher toutes les offres actives ...");
            getch();
            deleteConsoleLines(-3);
            printf("\tLes offres actives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageOffresParDates(llc_off, date_inf, date_sup);

            textcolor(CYAN);
            printf("Appuyez sur une touche pour continuer a afficher toutes les offres archives ...");
            getch();
            deleteConsoleLines(-2);
            printf("\n\tLes offres archives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageOffresParDates(llc_off_arch, date_inf, date_sup);
            // fin case 5
            break;
        }

        case 6:
        {
            // debut case 6
            system("cls");
            printf("\n\n\t\t    Afficher toutes les demandes (actives/archives) entre deux dates donnes : \n\n\n\n");
            printf("\tVeuillez entrer les deux dates pour lesquelles on effectue la recherche s'il vous plait : \n\n\n\n\n");
            printf("Entrer la premiere date : \n");
            scanDate(&date_inf);
            printf("\n\n\rEntrer la deuxieme date : \n");
            scanDate(&date_sup);
            if(datecmp(date_inf, date_sup) > 0) // permuter les deux dates si date_inf > date_sup
            {
                Date date_temp = date_inf;
                date_inf = date_sup;
                date_sup = date_temp;
            }

            // l'affichage des annonces entre les deux dates
            system("cls");
            printf("\n\n\t\t    Afficher toutes les demandes (actives/archives) entre deux dates donnes : \n\n\n\n\n\n");

            textcolor(LIGHTMAGENTA);
            printf("Appuyez sur une touche pour commencer a afficher toutes les demandes actives ...");
            getch();
            deleteConsoleLines(-3);
            printf("\tLes demandes actives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageDemandesParDates(llc_dem, date_inf, date_sup);

            textcolor(MAGENTA);
            printf("Appuyez sur une touche pour continuer a afficher toutes les demandes archives ...");
            getch();
            deleteConsoleLines(-2);
            printf("\n\tLes demandes archives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageDemandesParDates(llc_dem_arch, date_inf, date_sup);
            // fin case 6
            break;
        }

        case 7:
        {
            // debut case 7
            system("cls");
            printf("\n\n\t\t    Afficher toutes les annonces (offres/demandes) active entre deux dates donnes : \n\n\n\n");
            printf("\tVeuillez entrer les deux dates pour lesquelles on effectue la recherche s'il vous plait : \n\n\n\n\n");
            printf("Entrer la premiere date : \n");
            scanDate(&date_inf);
            printf("\n\n\rEntrer la deuxieme date : \n");
            scanDate(&date_sup);
            if(datecmp(date_inf, date_sup) > 0) // permuter les deux dates si date_inf > date_sup
            {
                Date date_temp = date_inf;
                date_inf = date_sup;
                date_sup = date_temp;
            }
            // l'affichage des annonces entre les deux dates
            system("cls");
            printf("\n\n\t\t    Afficher toutes les annonces (offres/demandes) active entre deux dates donnes : \n\n\n\n\n\n");

            textcolor(LIGHTCYAN);
            printf("Appuyez sur une touche pour commencer a afficher toutes les offres actives ...");
            getch();
            deleteConsoleLines(-3);
            printf("\tLes offres actives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageOffresParDates(llc_off, date_inf, date_sup);

            textcolor(LIGHTMAGENTA);
            printf("Appuyez sur une touche pour continuer a afficher toutes les demandes actives ...");
            getch();
            deleteConsoleLines(-2);
            printf("\n\tLes demandes actives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageDemandesParDates(llc_dem, date_inf, date_sup);
            // fin case 7
            break;
        }

        case 8:
        {
            // debut case 8
            system("cls");
            printf("\n\n\t\t    Afficher toutes les annonces (offres/demandes) archive entre deux dates donnes : \n\n\n\n");
            printf("\tVeuillez entrer les deux dates pour lesquelles on effectue la recherche s'il vous plait : \n\n\n\n\n");
            printf("Entrer la premiere date : \n");
            scanDate(&date_inf);
            printf("\n\n\rEntrer la deuxieme date : \n");
            scanDate(&date_sup);
            if(datecmp(date_inf, date_sup) > 0) // permuter les deux dates si date_inf > date_sup
            {
                Date date_temp = date_inf;
                date_inf = date_sup;
                date_sup = date_temp;
            }

            // l'affichage des annonces entre les deux dates
            system("cls");
            printf("\n\n\t\t    Afficher toutes les annonces (offres/demandes) archive entre deux dates donnes : \n\n\n\n\n\n");

            textcolor(CYAN);
            printf("Appuyez sur une touche pour commencer a afficher toutes les offres archives ...");
            getch();
            deleteConsoleLines(-3);
            printf("\tLes offres archives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageOffresParDates(llc_off_arch, date_inf, date_sup);

            textcolor(MAGENTA);
            printf("Appuyez sur une touche pour continuer a afficher toutes les demandes archives ...");
            getch();
            deleteConsoleLines(-2);
            printf("\n\tLes demandes archives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageDemandesParDates(llc_dem_arch, date_inf, date_sup);
            // fin case 8
            break;
        }

        case 9:
        {
            // debut case 9
            system("cls");
            printf("\n\n\t\t    Afficher toutes les annonces entre deux dates donnes : \n\n\n\n");
            printf("\tVeuillez entrer les deux dates pour lesquelles on effectue la recherche s'il vous plait : \n\n\n\n\n");
            printf("Entrer la premiere date : \n");
            scanDate(&date_inf);
            printf("\n\n\rEntrer la deuxieme date : \n");
            scanDate(&date_sup);
            if(datecmp(date_inf, date_sup) > 0) // permuter les deux dates si date_inf > date_sup
            {
                Date date_temp = date_inf;
                date_inf = date_sup;
                date_sup = date_temp;
            }

            // l'affichage des annonces entre les deux dates
            system("cls");
            printf("\n\n\t\t    Afficher toutes les annonces entre deux dates donnes : \n\n\n\n\n\n");

            textcolor(LIGHTCYAN);
            printf("Appuyez sur une touche pour commencer a afficher toutes les offres actives ...");
            getch();
            deleteConsoleLines(-3);
            printf("\tLes offres actives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageOffresParDates(llc_off, date_inf, date_sup);

            textcolor(CYAN);
            printf("Appuyez sur une touche pour continuer a afficher toutes les offres archives ...");
            getch();
            deleteConsoleLines(-2);
            printf("\n\tLes offres archives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageOffresParDates(llc_off_arch, date_inf, date_sup);

            textcolor(LIGHTMAGENTA);
            printf("Appuyez sur une touche pour continuer a afficher toutes les demandes actives ...");
            getch();
            deleteConsoleLines(-2);
            printf("\n\tLes demandes actives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageDemandesParDates(llc_dem, date_inf, date_sup);

            textcolor(MAGENTA);
            printf("Appuyez sur une touche pour continuer a afficher toutes les demandes archives ...");
            getch();
            deleteConsoleLines(-2);
            printf("\n\tLes demandes archives publiees entre %d/%d/%d et %d/%d/%d sont : \n\n", date_inf.jour, date_inf.mois, date_inf.annee, date_sup.jour, date_sup.mois, date_sup.annee);
            affichageDemandesParDates(llc_dem_arch, date_inf, date_sup);
            // fin case 9
            break;
        }

        case 10:
        {
            return;
            break;
        }

        default:
            break;
    }

    // Traitement commun apres l'affichage d'une liste entre deux dates données
    textcolor(LIGHTGRAY);
    printf("\n\n\t");
    pause();
    goto debut;
}

//--------------------------------------------------------------------------------------------------------

void choix6(PMaillonDemandes llc_dem)
{
    textcolor(LIGHTGRAY);
    textbackground(BLACK);

    int inputs, nbrCompetences, codeLangue;

    system("cls");
    printf("\n\n\t\t    Rechercher les demandeurs ayant 'x' competences et maitrisant une langue 'y' :  \n\n\n\n\n");

    // demander de l'utilisateur d'entrer le nombre de competences
scan_competences:
    system("color 07");
    printf("\tVeuillez entrer le nombre de competences des demandeurs que vous voulez rechercher: ");
    fflush(stdin);
    inputs = scanf("%d", &nbrCompetences);

    if((inputs != 1) || (nbrCompetences < 0))
    {
error_competences:
        system("color 47");
        deleteConsoleLines(-2);
        goto scan_competences;
    }

    if(nbrCompetences > MAX_COMPETENCES)
    {
        system("color 47");
        printf("\n\n\n\n\t\tLe nombre des competences maximum est %d !!\n", MAX_COMPETENCES);
        printf("\t\tAppuyez sur une touche pour re-entrer le nombre des competences ... ");
        getch();

        deleteConsoleLines(-6);
        goto error_competences;
    }

    // demander de l'utilisateur d'entrer la langue
    printf("\n\n\tVoici les langues disponibles et leur code sous la forme: code --> langue: \n");
    afficherLanguesCodes(); // afficher les code des langues à l'utilisateur
    printf("\n\n");

scan_langue:
    printf("\tEntrer le code de la langue maitrisee par les demandeurs que vous voulez rechercher: ");
    fflush(stdin);
    system("color 07");
    inputs = scanf("%d", &codeLangue);
    if((inputs != 1) || (codeLangue < 0) || (codeLangue > NOMBRE_LANGUES - 1))
    {
        system("color 47");
        deleteConsoleLines(-2);
        goto scan_langue;
    }

    // Afficher les demandeurs trouvés
    system("cls");
    printf("\n\n\t\t    Rechercher les demandeurs ayant 'x' competences et maitrisant une langue 'y' :  \n\n\n\n\n");
    rechercheDemandeurs(llc_dem, nbrCompetences, codeLangue);

    textcolor(LIGHTGRAY);
    textbackground(BLACK);
    printf("\n\n\tAppuyez sur une touche pour revenir au menu principal ... ");
    getch();
    system("color 07");
    fflush(stdin);
    return;
}

//--------------------------------------------------------------------------------------------------------

void choix7(PMaillonOffres llc_off, PMaillonRecruteurs llc_rec)
{
    char nomRecruteur[TAILLE_CHAINE_MAX] = "";
    int cpt, choix;

debut:
    system("cls");
    printf("\n\n\t\t    Chercher les offres appartenant a un meme recruteur :  \n\n\n\n\n");

    // Entrer le nom de l'utilisateur a afficher ses offres
    printf("\tVoici les recruteurs dispnibles : \n");
    cpt = 0;
    for(PMaillonRecruteurs p = llc_rec; p != NULL; p = suivantLLC_rec(p))
    {
        cpt++;
        printf("\t  %d: %s\n", cpt, valeurLLC_rec(p).nom);
    }

    printf("\n\n\tVeuillez entrer le nom du recruteur que vous voulez afficher ces offres\n");
error:
    system("color 07");
    printf("\t nom du recruteur: ");
    fflush(stdin);
    fgets(nomRecruteur, TAILLE_CHAINE_MAX, stdin);
    nomRecruteur[strlen(nomRecruteur) - 1] = 0;

    PMaillonRecruteurs adrRecruteur = rechRecruteurNom(llc_rec, nomRecruteur);
    if(adrRecruteur == NULL)
    {
        system("color 47");
        printf("\n\n\n\n\t\tATTENTION !! Ce recruteur n'existe pas dans la liste active des recruteurs !!\n");
        printf("\t\tAppuyez sur une touche pour re-entrer le nom du recruteur ... ");
        getch();
        deleteConsoleLines(-7);
        goto error;
    }

    // Confirmer le recruteur
    system("cls");
    printf("\n\n\t\t    Chercher les offres appartenant a un meme recruteur :  \n\n\n\n\n");
    printf("\tVoulez-vous vraimment afficher toutes les offres de ce recruteur ? \n");
    printRecruteur(valeurLLC_rec(adrRecruteur));
    printf("\n\n");
    choix = menu_validation_affichageOffresDeRecruteur();

    switch(choix)
    {
    case 1:
        system("cls");
        printf("\n\n\t\t    Chercher les offres appartenant a un meme recruteur :  \n\n\n");
        printf("\tLes offres de %s sont: \n\n", valeurLLC_rec(adrRecruteur).nom);
        rechOff_ParRec(llc_off, valeurLLC_rec(adrRecruteur));
        printf("\tAppuyez sur une touche pour revenir au menu principal ... ");
        getch();
        break;

    case 2:
        goto debut;
        break;

    case 3:
        return;
        break;

    default:
        break;
    }
}

//--------------------------------------------------------------------------------------------------------

void choix8(PMaillonOffres llc_off, PMaillonOffres llc_off_arch)
{
    int inputs, x;

    system("cls");
    printf("\n\n\t\t    Afficher les postes les plus demandes :  \n\n\n\n\n");

    printf("\n\n\tVeuillez entrer le nombre des postes plus demandes a afficher\n");
error:
    system("color 07");
    printf("\t nombre des postes: ");
    fflush(stdin);
    inputs = scanf("%d", &x);
    if((inputs != 1) || (x < 0))
    {
        system("color 47");
        deleteConsoleLines(-2);
        goto error;
    }

    system("cls");
    printf("\n\n\t\t    Afficher les postes les plus demandes :  \n\n\n");
    afficherXPosteFreq(llc_off, llc_off_arch, x); // améliorer l'affichage (et traitement du maximum) !!

    printf("\n\n\n\t\tAppuyez sur une touche pour revenir au menu principal ... ");
    getch();
    fflush(stdin);
}

//--------------------------------------------------------------------------------------------------------

void choix9(PMaillonOffres *llc_off)
{
    // afficher la liste trée et lui donner le choix de l'enregistrer (remplacer les liste origine par la liste trée)
    // donner le choix a l'utilisateur d'enregistrer la liste tréer a la place des liste actuels ou non

    int choix;
    PMaillonOffres liste_triee = NULL;

    choix = menu_choix9();

    switch(choix)
    {
        case 1:
            triEclatementOffres(*llc_off, &liste_triee);
            break;

        case 2:
            liste_triee = union_LLC_off(*llc_off, NULL); // copier la liste des offres dans la liste triee
            triBullesNbrCompetences_LLC_off(liste_triee); // trier la liste
            break;

        case 3:
            return;
            break;

        default:
            break;
    }

    // a la fin de tri : ...
    // enregistrer les changement ou non ?...
menu:
    choix = menu_validation_sauvegardeTri();

    system("cls");
    printf("\n\n\t\t\t    Trier les offres d'emploi selon le nombre de competences :  \n\n\n");

    switch(choix)
    {
        case 1:
        {
            printf("\tLa liste des offres triee selon le nombre de competences est: \n\n");
            afficher_LLC_off(liste_triee);
            printf("\n\n\t\tAppuyez sur une touche pour revenir au menu precedent ... ");
            getch();
            goto menu;
            break;
        }

        case 2:
        {
            libererTous_LLC_off(llc_off);
            *llc_off = liste_triee;
            system("color 2f");
            printf("\n\n\n\n\t\tLe sauvegarde de la liste triee est terminer avec succes !\n");
            printf("\t\tVous pouvez consulter la liste des offres active pour voire les changement\n");
            printf("\n\n\n\n\t\t\tAppuyez sur une touche pour revenir au menu principal ... ");
            getch();
            return;
            break;
        }

        case 3:
        {
            libererTous_LLC_off(&liste_triee);
            return;
            break;
        }

        default:
            break;
    }
}

//--------------------------------------------------------------------------------------------------------

void choix10(PMaillonDemandes llc_dem, PMaillonOffres llc_off)
{
    PMaillonDemandes Recommandations = NULL;
    Offre offre;
    int choix;

debut:
    system("cls");
    printf("\n\n\t\t    Recommander des demandes qui peuvent correspondre a une offre d'emploi :  \n\n\n\n\n");

    int taille_liste_offre = taille_LLC_off(llc_off);
    if(taille_liste_offre == 0)
    {
        system("color 47");
        printf("\tATTENTION !! La liste des offres active est vide!\n");
        printf("\n\tIl y'a aucune offre pour la recommander des demandes !!\n");
        printf("\tVeuillez construire la liste des offres active d'abord\n");

        printf("\n\n\t\tAppuyez sur une touche pour revenir au menu principal ...");
        getch();
        return;
    }

    printf("\tLa liste des offres active: \n\n\n");
    afficher_LLC_off(llc_off);
    printf("\n\n\n\t\t\t\tVoici la liste des offres active !\n\n");
position_offre:
    system("color 07");
    printf("\tEntrer la position de l'offre que vous voulez la recommander des demandes: ");

    int position = 0;
    fflush(stdin);
    int inputs = scanf("%d", &position); // récupérer la position de l'offre
    fflush(stdin);

    if((inputs != 1) || (position < 1) || (position > taille_liste_offre))
    {
        system("color 47");
        deleteConsoleLines(-2);
        goto position_offre;
    }

    offre = valeurLLC_off(accesPos_LLC_off(llc_off, position));

    choix = menu_validation_recommandation(offre);
    switch(choix)
    {
        case 1:
        {
            system("cls");
            printf("\n\n\t\t    Recommander des demandes qui peuvent correspondre a une offre d'emploi :  \n\n\n");
            recommanderDemande(llc_dem, offre, &Recommandations);

            textcolor(LIGHTGREEN);
            printf("\tLa liste des demandes qui peuvent correspondre l'offre d'emploi suivante est: \n\n");
            textcolor(LIGHTCYAN);
            printOffre(offre);
            textcolor(LIGHTGREEN);
            printf("\tLA LISTE DES DEMANDES (Tries par le nombre d'annes d'experience): \n\n");
            textcolor(LIGHTMAGENTA);
            afficher_LLC_dem(Recommandations);
            textcolor(LIGHTGRAY);

            break;
        }

        case 2:
            goto debut;

        case 3:
            return;

        default:
            break;
    }

    libererTous_LLC_dem(&Recommandations);
    textcolor(WHITE);
    printf("\n\n\t\t\tAppuyez sur une touche pour revenir au menu principal ... ");
    textcolor(LIGHTGRAY);
    getch();
}

//--------------------------------------------------------------------------------------------------------

void choix11(PMaillonRecruteurs *llc_rec, PMaillonRecruteurs *llc_rec_arch, PMaillonOffres *llc_off, PMaillonOffres *llc_off_arch, PMaillonDemandes *llc_dem, PMaillonDemandes *llc_dem_arch)
{
    consoleCursor(False);
    system("cls");
    system("color 0d");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tVoulez-vous vraiment fermer le programme ?\n");
    while(True)
    {
        printf("\t\t\tAppuyez sur \"ECHAP\" pour fermer le programme et sur \"ENTRER\" pour continuer ... ");
        int key = getch();
        if(key == 27) // ECHAP 27
        {
            break;
        }
        else if(key == 13) // ENTRER 13
        {
            consoleCursor(True);
            return;
        }
        deleteConsoleLines(1);
    }

    libererTous_LLC_rec(llc_rec);
    libererTous_LLC_rec(llc_rec_arch);
    libererTous_LLC_off(llc_off);
    libererTous_LLC_off(llc_off_arch);
    libererTous_LLC_dem(llc_dem);
    libererTous_LLC_dem(llc_dem_arch);
    fin_programme();
}

//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------
