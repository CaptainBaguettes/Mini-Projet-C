#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ASCII_Letter
{
    char letter;
    int code;
} ASCII_Letter;

typedef struct codage1
{
    ASCII_Letter lettre;
    ASCII_Letter crypte;
} codage1;

void affiche_lettre(ASCII_Letter L)
{
    printf("%d %c\n", L.code, L.letter);
}

void affiche_tab(ASCII_Letter *tab, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        affiche_lettre(*(tab + i));
    }
}

void affiche_codage(codage1 *tab, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        affiche_lettre((*(tab + i)).crypte);
    }
}

// EXERCICE 1
ASCII_Letter create_ascii()
{
    printf("========================================\n");
    printf("EXERCICE 1\n");
    ASCII_Letter ascii;
    char letter;
    printf("Saisir une lettre : \n");
    rewind(stdin);
    scanf("%c", &letter);
    ascii.letter = letter;
    ascii.code = (int)letter;
    return ascii;
}

// EXERCICE 2
ASCII_Letter *init_tab(int n)
{
    printf("========================================\n");
    printf("EXERCICE 2\n");
    printf("Initialisation d'un tableau de structure ASCI_Letter\n");
    return (ASCII_Letter *)malloc(n * sizeof(ASCII_Letter));
}

// EXERCICE 3
void remplir_tab(ASCII_Letter *tab, char *chaine)
{
    printf("========================================\n");
    printf("EXERCICE 3\n");
    printf("Remplissage d'un tableau de structure ASCI_Letter\n");
    int i;
    for (i = 0; i < strlen(chaine); i++)
    {
        (*(tab + i)).letter = *(chaine + i);
        (*(tab + i)).code = (int)*(chaine + i);
    }
}

// EXERCICE 4
codage1 *init_codage(int n)
{
    printf("========================================\n");
    printf("EXERCICE 4\n");
    printf("Initialisation d'un tableau de structure codage1\n");
    return (codage1 *)malloc(n * sizeof(codage1));
}

// EXERCICE 5
codage1 *cryptage(codage1 *tab, char *chaine, int n)
{
    printf("========================================\n");
    printf("EXERCICE 5\n");
    printf("Remplissage d'un tableau de structure codage1\n");
    ASCII_Letter *structure = init_tab(strlen(chaine));
    remplir_tab(structure, chaine);
    int i;
    for (i = 0; i < strlen(chaine); i++)
    {
        (*(tab + i)).lettre = (*(structure + i));
        (*(tab + i)).crypte.letter = n + (*(structure + i)).letter;
        (*(tab + i)).crypte.code = n + (*(structure + i)).letter;
    }
    return tab;
}

// EXERCICE 6
int occurences(codage1 *tab, ASCII_Letter unASCII_letter, int compteur)
{
    printf("========================================\n");
    printf("EXERCICE 6\n");
    int i;
    int retour = 0;
    char str;
    char str2;

    for (i = 0; i < compteur; ++i)
    {

        if ((*(tab + i)).lettre.letter == unASCII_letter.letter)
        {
            retour = retour + 1;
        }
    }
    printf("Nombre d'occurences : %d\n", retour);
    return retour;
}

char *creerChaine()
{
    char *chaine = (char *)malloc(sizeof(char));
    printf("\nTapez une chaine: ");
    scanf("%s", chaine);

    return chaine;
}

int compterString(char *chaine)
{
    int m;
    int charcount;

    charcount = 0;
    for (m = 0; chaine[m]; m++)
    {
        if (chaine[m] != ' ')
        {
            charcount++;
        }
    }

    return charcount;
}

int main()
{
    affiche_lettre(create_ascii());

    char *chaine = creerChaine();
    int compteur = compterString(chaine);
    printf("%d", compteur);
    ASCII_Letter *tab = init_tab(strlen(chaine));
    remplir_tab(tab, chaine);

    affiche_tab(tab, strlen(chaine));

    codage1 *tab1 = init_codage(strlen(chaine));
    tab1 = cryptage(tab1, chaine, 5);
    affiche_codage(tab1, strlen(chaine));

    occurences(tab1, create_ascii(), compteur);
    return 0;
}