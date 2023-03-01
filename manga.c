#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct structure_manga
{
    char Titre[50];
    int age;
    float prix;
};
typedef struct structure_manga MANGA;

// Exercice 1
MANGA *create_manga()
{
    MANGA *manga = (MANGA *)malloc(sizeof(MANGA));

    printf("Titre du manga :");
    rewind(stdin);
    gets(manga->Titre);
    printf("Age : ");
    rewind(stdin);
    scanf("%d", &manga->age);
    printf("Prix : ");
    rewind(stdin);
    scanf("%f", &manga->prix);
    return manga;
}

// Exercice 2
void info_manga(MANGA m)
{
    float total = 0;
    printf("Titre : %s \n", m.Titre);
    printf("Age :  %d \n", m.age);
    printf("Prix : %f \n", m.prix);
}

MANGA *add_n_manga(int n_mangas)
{
    MANGA *fav_mangas = (MANGA *)malloc(sizeof(MANGA) * n_mangas);
    for (int i = 0; i < n_mangas; i++)
    {
        MANGA *m = create_manga();
        char c = getchar();
        *(fav_mangas + i) = *m;
    }
    return fav_mangas;
}

MANGA **add_n_manga_adresse(int n_mangas)
{
    MANGA **fav_mangas = (MANGA **)malloc(sizeof(MANGA *) * n_mangas);
    for (int i = 0; i < n_mangas; i++)
    {
        MANGA *m = create_manga();
        *(fav_mangas + i) = m;
    }
    return fav_mangas;
}

void consulter_favoris(MANGA *mangas, int n)
{
    for (int i = 0; i < n; i++)
    {
        info_manga(*(mangas + i));
    }
}

int nb_mangas_lettre(MANGA *mangas, int n, char lettre)
{
    int compteur = 0;
    for (int i = 0; i < n; i++)
    {
        MANGA m = *(mangas + i);
        if (m.Titre[0] == lettre)
        {
            compteur++;
        }
    }
    return compteur;
}

void sorted_by_age(MANGA *mangas, int age, int n)
{
    MANGA *sorted_list = (MANGA *)malloc(sizeof(MANGA) * sizeof(mangas));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        MANGA m = *(mangas + i);
        if (m.age >= age)
        {
            *(sorted_list + count) = m;
            count++;
        }
    }
    for (int i2 = 0; i2 < count; i2++)
    {
        info_manga(*(sorted_list + i2));
    }
}

float prix_Manga(MANGA *mangas, char *titre, int n)
{
    float prix;
    for (int i = 0; i < n; i++)
    {
        MANGA m = *(mangas + i);
        if (strcmp(m.Titre, titre) == 0)
        {
            prix = m.prix;
        }
    }
    return prix;
}

void add_manga_panier(MANGA *panier, MANGA manga, int nb)
{
    printf("%s", manga.Titre);
    realloc(panier, nb * (sizeof(MANGA)));

    printf("%s", manga.Titre);
    *(panier + nb) = manga;
}

MANGA *init_tab()
{
    MANGA *fav_mangas = (MANGA *)malloc(sizeof(MANGA) * 3);
    MANGA *m1 = malloc(sizeof(MANGA));
    MANGA *m2 = malloc(sizeof(MANGA));
    MANGA *m3 = malloc(sizeof(MANGA));

    strcpy(m1->Titre, "SAO");
    m1->prix = 7.52;
    m1->age = 16;

    strcpy(m2->Titre, "KonoSuba");
    m2->prix = 7.48;
    m2->age = 14;

    strcpy(m3->Titre, "Shadow");

    m3->prix = 7.94;
    m3->age = 15;

    *(fav_mangas + 0) = *m1;
    *(fav_mangas + 1) = *m2;
    *(fav_mangas + 2) = *m3;
    return fav_mangas;
}
// Exercice 4
void menu()
{
    printf("Combien de mangas voulez vous ajouter ?\n");
    int nb = 3;
    rewind(stdin);
    // scanf("%d", &nb);
    MANGA *mangaFav = init_tab(); // add_n_manga(nb);
    MANGA *panier = (MANGA *)malloc(sizeof(MANGA));
    int taille_panier = 0;
    bool exit = true;

    while (exit)
    {
        printf("1 pour consulter tous les mangas.\n");
        printf("2 pour filtrer les mangas a partir d'un age.\n");
        printf("3 pour compter le nombre de manga qui commence par une lettre.\n");
        printf("4 pour chercher le prix d'un manga\n");
        printf("5 pour calculer votre panier\n");
        printf("6 pour quitter l\'application \n");
        int choix = 0;
        int age; // pour l'option 2;
        char lettre;
        char titre[50]; // pour l'option 4
        bool exit2 = true;
        rewind(stdin);
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            consulter_favoris(mangaFav, nb);
            break;
        case 2:
            printf("Age demandé pour le tri : \n");
            rewind(stdin);
            scanf("%d", &age);
            sorted_by_age(mangaFav, age, nb);
            break;
        case 3:
            printf("Quelle lettre voulez vous chercher ?");
            rewind(stdin);
            scanf("%c", &lettre);
            int nb_manga = nb_mangas_lettre(mangaFav, nb, lettre);
            printf("Il y a %d manga(s) qui commence(nt) par la lettre %c\n", nb_manga, lettre);
            break;
        case 4:
            printf("Indiquez le titre : \n");
            rewind(stdin);
            scanf("%s", &titre);
            float prix = prix_Manga(mangaFav, titre, nb);
            printf("Le prix de %s est de %.2f euros \n", titre, prix);
            break;
        case 5:
            while (exit2)
            {
                printf("1 pour consulter tous les mangas.\n");
                printf("2 pour ajouter un manga à votre panier\n");
                printf("3 pour consulter votre panier\n");
                printf("4 pour confirmer votre panier\n");
                float total = 0;
                int choix2 = 0;
                rewind(stdin);
                scanf("%d", &choix2);
                char titre_add[50];
                switch (choix2)
                {
                case 1:
                    consulter_favoris(mangaFav, nb);
                    break;
                case 2:
                    printf("Titre du manga :\n");
                    rewind(stdin);
                    scanf("%s", &titre_add);
                    for (int i = 0; i < nb; i++)
                    {

                        MANGA m = *(mangaFav + i);

                        if (strcmp(titre_add, m.Titre) == 0)
                        {
                            taille_panier++;
                            add_manga_panier(panier, m, taille_panier);
                        }
                    }
                    break;
                case 3:
                    for (int i = 0; i < taille_panier; ++i)
                    {
                        // Décaler l'index de 1
                        MANGA manga = *(panier + i + 1);
                        info_manga(manga);
                    }
                    break;
                case 4:
                    // Parcourt la liste de manga récupere le prix et l'additionne dans une variable total
                    for (int i = 0; i < taille_panier; ++i)
                    {
                        MANGA manga = *(panier + i + 1);
                        total = total + manga.prix;
                    }
                    // Affiche la variable total
                    printf("Le prix total de votre panier est de : %f €\n", total);
                    exit2 = false;
                }
            }
            break;
        case 6:
            exit = false;
            break;
        }
    }
}

int main()
{

    menu();
    return 0;
}