<h1> Rapport du mini projet C</h1>
<strong>Auteurs :</strong>

<ul>
  <li>1. Teddy VICTORIEN</li>
  <li>2. Wilhem SOREK</li>
  <li>3. Raphaël PAVARD</li>
</ul>

<h2>Introduction</h2>
<p>Dans le cadre des exercices demandés en cours, nous avons réalisé deux fichiers en C que nous allons vous décrire dans ce rapport.</p>
<p>Ce rapport sera divisé selon ces deux fichiers :</p>

<strong>1.</strong> Ma première structure de données !

<strong>2.</strong> Mes mangas préférés !

<h2>Présentation des codes</h2>
<h3>Partie 1 : Ma première structure de données !</h3>
<strong>Exercice 1 :</strong>

>Écrire une fonction qui demande à un utilisateur de saisir un caractère et construit la structure correspondante.

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

<p><code>rewind(stdin);</code> est utilisé pour vider le buffer clavier.</p>
<strong>Exercice 2 :</strong>

>Écrire une fonction qui initialise un tableau de n structures struct ASCII_letter.

    ASCII_Letter *init_tab(int n)
    {
        printf("========================================\n");
        printf("EXERCICE 2\n");
        printf("Initialisation d'un tableau de structure ASCI_Letter\n");
        return (ASCII_Letter *)malloc(n * sizeof(ASCII_Letter));
    }

<strong>Exercice 3 :</strong>

>Écrire une fonction qui à partir d’une chaîne caractères saisie par un utilisateur remplit un tableau de structures déjà initialisé.

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

<strong>Exercice 4 :</strong>

>Définir une nouvelle structure struct codage1 qui enregistre deux caractères. Le caractère et le caractère qui se situe à une distance égale à n.

    codage1 *init_codage(int n)
    {
        printf("========================================\n");
        printf("EXERCICE 4\n");
        printf("Initialisation d'un tableau de structure codage1\n");
        return (codage1 *)malloc(n * sizeof(codage1));
    }

<strong>Exercice 5 :</strong>

>Écrire une fonction qui à partir d’une chaîne caractères saisie par un utilisateur remplit un tableau de n structures struct codage1.

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

<strong>Exercice 6 :</strong>

>Écrire une fonction qui permet de renvoyer le nombre de fois qu’une structure apparaît dans un tableau de type struct codage1.

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

<strong>Fonctions d'affichage</strong>

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

<strong>Fonctions diverses</strong>

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

<strong>Fonction principale</strong>

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

<h3>Partie 2 : Mes mangas préférés !</h3>
<strong>Exercice 1 :</strong>

>Une fonction qui permet de créer une structure avec les données saisies par l’utilisateur. Cette fonction retourne l’adresse de la structure créée.
    
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

<strong>Exercice 2 :</strong>

>Une fonction qui permet de créer une structure avec les données saisies par l’utilisateur. Cette fonction retourne l’adresse de la structure créée.

    void info_manga(MANGA m)
    {
        float total = 0;
        printf("Titre : %s \n", m.Titre);
        printf("Age :  %d \n", m.age);
        printf("Prix : %f \n", m.prix);
    }

<strong>Exercice 3a :</strong>

>Une fonction qui permet à un utilisateur d’ajouter un nombre fini (n) de ses MANGA préférés. Le tableau contient des structures MANGA.

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

<strong>Exercice 3b :</strong>

>Une fonction qui permet à un utilisateur d’ajouter un nombre fini (n) de ses MANGA préférés. Le tableau contient les adresses des structures MANGA.

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

<strong>Exercice 4 :</strong>

>Une fonction « menu ».

    void menu()
    {
        // L'utilisateur renseigne son tableau de manga favoris
        printf("Combien de mangas voulez vous ajouter ?\n");
        // Nombre de manga dans le tableau
        int nb;
        rewind(stdin);
        scanf("%d", &nb);
        // l'utilisateur créer n mangas
        MANGA *mangaFav = add_n_manga(nb);
        // Panier utilisé pour la partie 4.e
        MANGA *panier = (MANGA *)malloc(sizeof(MANGA));
        // taille du tableau
        int taille_panier = 0;
        // Variable de condition pour permettre à l'utilisateur de quitter l'utilisateur
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
            case 1: // 4.a
                consulter_favoris(mangaFav, nb);
                break;
            case 2: // 4.b
                printf("Age demandÃ© pour le tri : \n");
                rewind(stdin);
                scanf("%d", &age);
                sorted_by_age(mangaFav, age, nb);
                break;
            case 3: // 4.c
                printf("Quelle lettre voulez vous chercher ?");
                rewind(stdin);
                scanf("%c", &lettre);
                int nb_manga = nb_mangas_lettre(mangaFav, nb, lettre);
                printf("Il y a %d manga(s) qui commence(nt) par la lettre %c\n", nb_manga, lettre);
                break;
            case 4: // 4.d
                printf("Indiquez le titre : \n");
                rewind(stdin);
                scanf("%s", &titre);
                float prix = prix_Manga(mangaFav, titre, nb);
                printf("Le prix de %s est de %.2f euros \n", titre, prix);
                break;
            case 5: // 4.e
                while (exit2)
                {
                    printf("1 pour consulter tous les mangas.\n");
                    printf("2 pour ajouter un manga Ã  votre panier\n");
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
                            // Decaler l'index de 1
                            MANGA manga = *(panier + i + 1);
                            info_manga(manga);
                        }
                        break;
                    case 4:
                        // Parcourt la liste de manga rÃ©cupere le prix et l'additionne dans une variable total
                        for (int i = 0; i < taille_panier; ++i)
                        {
                            MANGA manga = *(panier + i + 1);
                            total = total + manga.prix;
                        }
                        // Affiche la variable total
                        printf("Le prix total de votre panier est de : %.2f euros\n", total);
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

<strong>Exercice 4a :</strong>

>Une fonction « menu », donnant la possibilité à un utilisateur de : Afficher les informations de tous les MANGA stockés dans le tableau.

    void consulter_favoris(MANGA *mangas, int n)
    {
        for (int i = 0; i < n; i++)
        {
            info_manga(*(mangas + i));
        }
    }

<strong>Exercice 4b :</strong>

>Une fonction « menu », donnant la possibilité à un utilisateur de : Afficher les informations de tous les MANGA qui sont accessibles à partir d’un certain âge donné en paramètre.

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

<strong>Exercice 4c :</strong>

>Une fonction « menu », donnant la possibilité à un utilisateur de : Compter le nombre de MANGA ayant un titre qui commence par une lettre donnée en paramètre.


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

<strong>Exercice 4d :</strong>

>Une fonction « menu », donnant la possibilité à un utilisateur de : Chercher un MANGA en donnant en paramètres le tableau de structure et le titre du MANGA. La fonction doit renvoyer le prix du MANGA donné.

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

<strong>Exercice 4e :</strong>

>Une fonction « menu », donnant la possibilité à un utilisateur de : Avoir le prix total (somme), de certains MANGA choisis par un utilisateur.


    void add_manga_panier(MANGA *panier, MANGA manga, int nb)
    {
        realloc(panier, nb * (sizeof(MANGA)));
        *(panier + nb) = manga;
    }


<h2> Retour d'expérience </h2>
<h3> Difficultés rencontrées </h3>
<h4>Le problème de buffer sur le scanf : </h4>
<p>Ce problème est survenue lorsque nous avons initialiser nos premières variables, le buffer ne se vidait pas correctement et renvoyé un type de donnée différent lors d'un second appel à la fonction scanf.</p>
<p>Afin de résoudre cet imprévu nous avons utilisé :</p>
         
    rewind(stdin);
    
<h4>Lorsque nous avons essayer d'assigner une chaîne de caractère à une autre :</h4>
<p>Afin de réduire la pénibilité du débogage, nous avons voulu instancier à la main un tableau prédéfini, et nous devions assigner à notre class Manga son titre.       Nous avons donc fait :</p>

    Manga->titre = "titre";
<p>Nous avons remarqué que l'on ne pouvait pas assigner à un array. Nous avons donc pensez à for un boucle for et venir remplir le tableau char par char. Cependant il existe un librairie qui nous permet de faire cale de façon plus agréable à l'oeil.</p>

    #include <string.h>
    strcpy(Manga->Titre, "KonoSuba");
    
<h4>Le parcours de tableau :</h4>
<p>Cette difficulté est survenue lorsque nous avons eu l'idée farfelu de parcourir un tableau avec une taille inconnue. On avait pensé à une solution qui pouvait fonctionner. Il s'agissait de se dire qu'un array est une suite d'allocation d'un élément de même type, et donc on prenait l'adresse du premier élément et on incrémenté en vérifiant si il s'agissait bien du même type. Cependant cette solution peut s'avérer fausse si les éléments stockés après la dernière valeur de mon array sont du même type. </b>
Nous avons donc rechercher un moyen de pouvoir parcourir un array et la solution pour laquelle nous avons opté, est de créer une variable et de l'incrémenter à chaque ajout d'élément.

<h3> Ce que l'on a apprit :</h3>
<h4>La rigoureusité :</h4>
<p>Si il y a un point sur lequel on est tous d'accord c'est sur la difficultés d'appréhension du langage C. Cependant cela nous a permis de développer une rigueur et un regard interogateur quand à la gestion des variables et de leurs cycle de vie et avoir une vision critique sur nos prochains codes malgré la présence du garbage collector, surtout dans une période ou le numérique responsable est omniprésent dans les processus de développement de beaucoup d'entreprise, ou la gestion de la mémoire occupe une place très importante.</p>

<h4>La face caché des langages récents :</h4>
<p>Pour être tout à fait franc, nous avons pas mal râlé sur ce TP en ne comprennant pas pourquoi les langages plus récents n'était pas aussi dûr à appréhender.En faisans des recherches nous nous sommes rendu compte que les langages tel que JAVA ou encore PYTHON était tiré du C. En en regardant de plus prêt, même si JAVA nous permet de connaître la taille d'un tableau avec le .length, l'action qu'il fait derrière reste la même que ce que nous avons du faire en C. Pour résumer cette partie, 
cela nous a permi de mieux comprendre ce qu'il se passe derrière les langages récent que nous utilisons.</p>
  
<h4>Nos amis les pointeurs :</h4>
<pLa grande majorité des difficulté d'appréhension que nous avons eu se situe au niveau des notions de pointeurs, d'adrese mémoire etc...</p>
<p>Cependant comme expliqué dans le point juste au dessus, beaucoup de langages plus récent fonctionne de la même façon, mais cache cette partie. Cet exercice a été très formateurs dans la compréhension et l'application de cet immense notion qu'est les pointeurs.</p>
   
<h2> Conclusion </h2>
<p>Afin de résumé notre resenti sur cet exercice, on peut dire que cet exercice s'est avéré difficile à prendre en main car les notions sont assez récentes pour nous trois. Les mettres en pratiques à trois avec aucun "experts" s'est avéré un peu compliqué et démotivants quelques fois. Mais cette difficultés d'appréhension a aussi permis de développer un aspect critique dans notre travail du quotidien. C'est plutôt avec fiertè que nous avonc réussi à aller au bout de ces exercices.</p>

