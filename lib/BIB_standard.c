#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

#include "BIB_standard.h"
#include "BIB_recruteur.h"
#include "BIB_offre.h"
#include "BIB_demande.h"
#include "conio2.h"


/**
 * @brief Transformer une chaîne de caractères numériques en entier
 *
 * @param string la chaîne à transformer
 * @return int ( l'entier correspondant à la chaîne de caractères )
 */
int StrToInt(char *string)
{
    int digit, power = 1, nombre = 0;

    for(int i = strlen(string) - 1; i >= 0; i--)
    {
        digit = string[i] - 48;
        nombre += digit * power;
        power *= 10;
    }

    return nombre;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Tester l'égalité entre deux chaînes de caractères sans tenir compte au majuscule et minuscule
 *
 * @param string1 la première chaîne de caractères
 * @param string2 la deuxième chaîne de caractères
 * @return Bool Vrai si les deux chaînes sont égaux, Faux sinon
 */
Bool comparerStr(char *string1, char *string2)
{
    // lower case string 1
    size_t lenString1 = strlen(string1);
    char *lowerString1 = calloc(lenString1+1, sizeof(char));
    for(int i = 0; i < lenString1; i++)
        lowerString1[i] = tolower((unsigned char)string1[i]);

    // lower case string 2
    size_t lenString2 = strlen(string2);
    char *lowerString2 = calloc(lenString2+1, sizeof(char));
    for(int i = 0; i < lenString2; i++)
        lowerString2[i] = tolower((unsigned char)string2[i]);

    // comparer les deux lower case
    Bool result = (strcmp(lowerString1, lowerString2) == 0);

    // libérer les chaîne crées
    free(lowerString1);
    free(lowerString2);

    // retourner le résultat de comparaison
    return result;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief remplir un tableau des compétences par l'utilisateur
 *
 * @param tabCompetences le tableau des compétences à remplir
 */
void scanCompetences(Competences tabCompetences)
{
    int nbrCompetences = 0;
    int inputs;

    printf("Combien de competences voulez-vous remplir ? : ");
scan1:
    fflush(stdin);
    system("color 07");
    inputs = scanf("%d", &nbrCompetences);
    if((inputs != 1) || (nbrCompetences < 0))
    {
error1:
        system("color 47");
        printf("\033[A\33[2K\rCombien de competences voulez-vous remplir ? : ");
        goto scan1;
    }

    if(nbrCompetences > MAX_COMPETENCES)
    {
        system("color 47");
        printf("\n\n\n\n\t\tLe nombre des competences maximum est %d !!\n", MAX_COMPETENCES);
        printf("\t\tAppuyez sur une touche pour re-entrer le nombre des competences a remplir ... ");
        getch();

        printf("\33[2K\033[A\33[2K\33[2K\033[A\33[2K\33[2K\033[A\33[2K\33[2K\033[A\33[2K\33[2K\033[A\33[2K\r");
        goto error1;
    }

    // initialistation de tableau des compétences
    for(int i = 0; i < MAX_COMPETENCES; i++)
        tabCompetences[i] = False;

    // remplir le tableau des compétences par l'utilisateur
    if(nbrCompetences == 0)
    {
        fflush(stdin);
        return;
    }

    int reponse;

    printf("\n\tVoici les competences disponibles et leur code sous la forme: code --> competence: \n");
    afficherCompetencesCodes(); // afficher les code des competences à l'utilisateur

    printf("\n\n");
    for(int i = 0; i < nbrCompetences; i++)
    {
        printf("\tEntrer la competence (Le code de la competence) numero %d : ", i+1);
scan2:
        fflush(stdin);
        system("color 07");
        inputs = scanf("%d", &reponse);
        if((inputs != 1) || (reponse < 0) || (reponse > NOMBRE_COMPETENCES - 1))
        {
            system("color 47");
            printf("\033[A\33[2K\r\tEntrer la competence (Le code de la competence) numero %d : ", i+1);
            goto scan2;
        }

        tabCompetences[reponse] = True;
        printf("\033[A\33[2K\r");
    }

    fflush(stdin);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief remplir le tableau des langues par l'utilisateur
 *
 * @param tabLangues le tableau des langues à remplir
 */
void scanLangues(Langues tabLangues)
{
    int nbrLangues = 0;
    int inputs;

    printf("Combien de langues voulez-vous remplir ? : ");
scan1:
    fflush(stdin);
    system("color 07");
    inputs = scanf("%d", &nbrLangues);
    if((inputs != 1) || (nbrLangues < 0))
    {
error1:
        system("color 47");
        printf("\033[A\33[2K\rCombien de langues voulez-vous remplir ? : ");
        goto scan1;
    }

    if(nbrLangues > MAX_LANGUES)
    {
        system("color 47");
        printf("\n\n\n\n\t\tLe nombre des langues maximum est %d !!\n", MAX_LANGUES);
        printf("\t\tAppuyez sur une touche pour re-entrer le nombre des langues a remplir ... ");
        getch();

        printf("\33[2K\033[A\33[2K\33[2K\033[A\33[2K\33[2K\033[A\33[2K\33[2K\033[A\33[2K\33[2K\033[A\33[2K\r");
        goto error1;
    }

    // initialistation de tableau des langues
    for(int i = 0; i < MAX_LANGUES; i++)
        tabLangues[i] = False;

    // remplir le tableau des langues par l'utilisateur
    if(nbrLangues == 0)
    {
        fflush(stdin);
        return;
    }

    int reponse;

    printf("\n\tVoici les langues disponibles et leur code sous la forme: code --> langue: \n");
    afficherLanguesCodes(); // afficher les code des langues à l'utilisateur

    printf("\n\n");
    for(int i = 0; i < nbrLangues; i++)
    {
        printf("\tEntrer la langue (Le code de la langue) numero %d : ", i+1);
scan2:
        fflush(stdin);
        system("color 07");
        inputs = scanf("%d", &reponse);
        if((inputs != 1) || (reponse < 0) || (reponse > NOMBRE_LANGUES - 1))
        {
            system("color 47");
            printf("\033[A\33[2K\r\tEntrer la langue (Le code de la langue) numero %d : ", i+1);
            goto scan2;
        }

        tabLangues[reponse] = True;
        printf("\033[A\33[2K\r");
    }

    fflush(stdin);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief remplir le tableau des diplômes par l'utilisateur
 *
 * @param diplomes le tableau des diplômes à remplir
 */
void scanDiplomes(char diplomes[MAX_DIPLOME][TAILLE_CHAINE_MAX])
{
    int nbrDiplomes;
    printf("Combien de diplomes avez-vous ? : ");
scan:
    fflush(stdin);
    system("color 07");
    int inputs = scanf("%d", &nbrDiplomes);

    if((inputs != 1) || (nbrDiplomes < 0))
    {
error:
        system("color 47");
        printf("\033[A\33[2K\rCombien de diplomes avez-vous ? : ");
        goto scan;
    }

    if(nbrDiplomes > MAX_DIPLOME)
    {
        system("color 47");
        printf("\n\n\n\n\t\tLe nombre des diplomes maximum est %d !!\n", MAX_DIPLOME);
        printf("\t\tAppuyez sur une touche pour re-entrer le nombre de vos diplomes ... ");
        getch();

        printf("\33[2K\033[A\33[2K\33[2K\033[A\33[2K\33[2K\033[A\33[2K\33[2K\033[A\33[2K\33[2K\033[A\33[2K\r");
        goto error;
    }

    // initialistation de tableau des diplômes
    for(int i = 0; i < MAX_DIPLOME; i++)
        strcpy(diplomes[i], "");

    // remplir le tableau des diplômes par l'utilisateur
    for(int i = 0; i < nbrDiplomes; i++)
    {
        printf("Entrer le diplome numero %d : ", i+1);
        fflush(stdin);
        fgets(diplomes[i], TAILLE_CHAINE_MAX, stdin);
        diplomes[i][strlen(diplomes[i]) - 1] = 0;

        if(strcmp(diplomes[i], "") == 0) // si l'utilisateur a entrer un diplôme vide !
            i--;
    }

    fflush(stdin);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief fonction qui permet à l'utilisateur d'entrer une date
 *
 * @param date la date à entrer
 */
void scanDate(Date *date)
{
    printf("\tDate (jj/mm/aaaa): ");
scan:
    fflush(stdin);
    system("color 07");
    int inputs = scanf("%d/%d/%d", &date->jour, &date->mois, &date->annee);

    if(inputs != 3)
    {
error:
        system("color 47");
        printf("\033[A\33[2K\r\tDate (jj/mm/aaaa): ");
        goto scan;
    }

    // controle de la date
    if((date->jour < 1) || (date->mois < 1) || (date->mois > 12))
        goto error;

    // traitement du février
    if((date->annee % 4 == 0) && (date->annee % 100 != 0)) // 29 février
    {
        if((date->mois == 2) && (date->jour > 29))
            goto error;
    }
    else // 28 février
    {
        if((date->mois == 2) && (date->jour > 28))
            goto error;
    }

    if((date->mois == 4) || (date->mois == 6) || (date->mois == 9) || (date->mois == 11)) // traitement du 30 jour
    {
        if(date->jour > 30)
            goto error;
    }
    else if(date->mois != 2) // traitement du 31 jour
    {
        if(date->jour > 31)
            goto error;
    }

    fflush(stdin);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Comparer entre deux dates
 *
 * @param date1 la première date à comparer
 * @param date2 la deuxième date à comparer
 * @return int ( 0 -> (=) | 1 -> (>) | -1 -> (<) )
 */
int datecmp(Date date1, Date date2)
{
    if(date1.annee > date2.annee)
        return 1;
    else if((date1.annee == date2.annee) && (date1.mois > date2.mois))
        return 1;
    else if((date1.annee == date2.annee) && (date1.mois == date2.mois) && (date1.jour > date2.jour))
        return 1;
    else if((date1.annee == date2.annee) && (date1.mois == date2.mois) && (date1.jour == date2.jour))
        return 0;
    return -1; // else
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief afficher les langues et leurs codes depuis le fichier
 *
 */
void afficherLanguesCodes(void)
{
    char langue[TAILLE_CHAINE_MAX] = {};
    int code;

    FILE *fichier = fopen("code/CodeLangues.txt", "r");
        if(fichier == NULL)
        {
            printf("Probleme d'ouverture de fichier!\n");
            exit(EXIT_FAILURE);
        }

        while(!feof(fichier))
        {
            fscanf(fichier, "%d - %[^\n]% s\n", &code, langue); // %[^\n]% s\n : pour résoudre le problème des espaces
            printf("\t Code: %d\t-->  %s\n", code, langue);
        }
    fclose(fichier);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief afficher les compétences et leurs codes depuis le fichier
 *
 */
void afficherCompetencesCodes(void)
{
    char competence[TAILLE_CHAINE_MAX] = {};
    int code;

    FILE *fichier = fopen("code/CodeCompetences.txt", "r");
        if(fichier == NULL)
        {
            printf("Probleme d'ouverture de fichier!\n");
            exit(EXIT_FAILURE);
        }

        while(!feof(fichier))
        {
            fscanf(fichier, "%d - %[^\n]% s\n", &code, competence); // %[^\n]% s\n : pour résoudre le problème des espaces
            printf("\t Code: %d\t-->  %s\n", code, competence);
        }
    fclose(fichier);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief trouver la langue correspondante à un code donné
 *
 * @param code le code de la langue
 * @param langue la chaîne de caractères qui contient la langue (passage par variable)
 */
void decoderLangue(const int code, char langue[])
{
    int codeInFile;
    Bool trouv = False;

    FILE *fichier = fopen("code/CodeLangues.txt", "r");
        if(fichier == NULL)
        {
            printf("Probleme d'ouverture de fichier!\n");
            exit(EXIT_FAILURE);
        }

        while(!feof(fichier) && !trouv) // parcourir le fichier ligne par ligne et chercher le code
        {
            fscanf(fichier, "%d - %[^\n]% s\n", &codeInFile, langue); // %[^\n]% s\n : pour résoudre le problème des espaces
            if(codeInFile == code) // trouver le code de la langue
            {
                trouv = True;
            }
        }
    fclose(fichier);

    if(trouv == False)
        strcpy(langue, "Langue non Trouvee !!\n");
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief trouver la compétence correspondante à un code donné
 *
 * @param code le code de la compétence
 * @param competence la chaîne de caractères qui contient la compétence (passage par variable)
 */
void decoderCompetence(int code, char competence[])
{
    int codeInFile;
    Bool trouv = False;

    FILE *fichier = fopen("code/CodeCompetences.txt", "r");
        if(fichier == NULL)
        {
            printf("Probleme d'ouverture de fichier!\n");
            exit(EXIT_FAILURE);
        }

        while(!feof(fichier) && !trouv) // parcourir le fichier ligne par ligne et chercher le code
        {
            fscanf(fichier, "%d - %[^\n]% s\n", &codeInFile, competence); // %[^\n]% s\n : pour résoudre le problème des espaces
            if(codeInFile == code) // trouver le code de la compétence
            {
                trouv = True;
            }
        }
    fclose(fichier);

    if(trouv == False)
        strcpy(competence, "Competence non Trouvee !!\n");
}


//--------------------------------------------------------------------------------------------------------

/**
 * @brief permettre à l'utilisateur d'entrer le code d'une langue
 *
 * @return int le code de la langue
 */
int get_langue(void)
{
    int code;

    printf("Voici la liste des langues disponibles: \n");
    printf("Elle est de la forme: code - langue\n\n");
    afficherLanguesCodes();

    printf("Veuillez entrer s'il vous plait le code de la langue choisit : ");
    scanf("%d", &code);

    while ((code < 0) || (code > NOMBRE_LANGUES - 1)) // vérification du code entré par l'utilisateur
    {
        printf("Desole, le code que vous avez entrer n'est pas disponible !!\n");
        printf("Veuillez re-entrer le code s'il vous plait : ");
        scanf("%d", &code);
    }

    return code;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief permettre à l'utilisateur d'entrer le code d'une compétence
 *
 * @return int le code de la compétence
 */
int get_competence(void)
{
    int code;

    printf("Voici la liste des competences disponibles: \n");
    printf("Elle est de la forme: code - competence\n");
    afficherCompetencesCodes();

    printf("Veuillez entrer s'il vous plait le code de la competence choisit : ");
    scanf("%d", &code);

    while ((code < 0) || (code > NOMBRE_COMPETENCES - 1)) // vérification du code entré par l'utilisateur
    {
        printf("Desole, le code que vous avez entrer n'est pas disponible !!\n");
        printf("Veuillez re-entrer le code s'il vous plait : ");
        scanf("%d", &code);
    }

    return code;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief pauser le programme durant l'execution
 * 
 */
void pause(void)
{
    printf("Appuyez sur une touche pour continuer ... ");
    getch();
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief detection du clique sur le bouton ENTRER
 * 
 * @return Bool vrai si il a clique sur ENTRER, faux sinon
 */
Bool isPressedEnter(void)
{
    if(GetAsyncKeyState(VK_RETURN))
        return True;
    return False;
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Afficher et masquer le curseur dans la console
 * 
 * @param show la variable de commande
 */
void consoleCursor(Bool show)
{
    const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(handle, &cci);
    cci.bVisible = show;
    SetConsoleCursorInfo(handle, &cci);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief Supprimer des lignes affichees dans la console
 * 
 * @param number_of_lines_to_delete le nombre de lignes a effacer (peut etre negative: la suppression se fait dans le sens inverse)
 */
void deleteConsoleLines(int number_of_lines_to_delete)
{
    const int n = abs(number_of_lines_to_delete);
    int y = wherey(), cpt = 0;

    for(int i = 0; i < n; i++)
    {
        // supprimer la ligne courante dans la console
        printf("\33[2K\r");

        // bouger le curseur vers la ligne suivante
        (number_of_lines_to_delete > 0) ? gotoxy(wherex(), wherey()+1) : gotoxy(wherex(), wherey()-1);
        if(wherey() == 1)
            cpt++;
    }

    // mise à jour la position de curseur
    if(cpt > 1)
        gotoxy(1, wherey());
    else
        (y <= wherey()) ? gotoxy(1, y) : gotoxy(1, wherey()+1);
}

//--------------------------------------------------------------------------------------------------------

/**
 * @brief permet au system d'exploitation de lire une chaine de caracteres
 * 
 * @param string la chaine de caracteres a dire
 */
void speak(char string[])
{
    char chaine[256];
    sprintf(chaine,"echo m=\"%s\" > file.vbs",string);
    system(chaine);
    sprintf(chaine,"echo CreateObject(\"SAPI.SpVoice\").Speak m >> file.vbs");
    system(chaine);
    sprintf(chaine,"file.vbs");
    system(chaine);
    remove("file.vbs");
}

//--------------------------------------------------------------------------------------------------------
