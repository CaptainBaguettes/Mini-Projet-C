<h1> Rapport du mini projet C</h1>
<strong>Auteurs :</strong>

<ul>
  <li>1. Teddy VICTORIEN</li>
  <li>2. Wilhem SOREK</li>
  <li>3. Raphaël PAVARD</li>
</ul>

<h2> Introduction </h2><h2>Introduction</h2>
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
<h3>Mes mangas préférés !</h3>
<h2> Retour d'expérience </h2>
<h3> Difficultés rencontrées </h3>
<h4>Le problème de buffer sur le scanf : </h4>
<p>Ce problème est survenue lorsque nous avons initialiser nos premières variables, le buffer ne se vidait pas correctement et renvoyé un type de donnée différent lors d'un second appel à la fonction scanf.</p>
<p>Afin de résoudre cet imprévu nous avons utilisé :</p>
         
    rewind(stdin);
    
<h4><u>Lorsque nous avons essayer d'assigner une chaîne de caractère à une autre :</u></h4>
<p>Afin de réduire la pénibilité du débogage, nous avons voulu instancier à la main un tableau prédéfini, et nous devions assigner à notre class Manga son titre.       Nous avons donc fait :</p>

    Manga->titre = "titre";
<p>Nous avons remarqué que l'on ne pouvait pas assigner à un array. Nous avons donc pensez à for un boucle for et venir remplir le tableau char par char. Cependant il existe un librairie qui nous permet de faire cale de façon plus agréable à l'oeil.</p>

    #include <string.h>
    strcpy(Manga->Titre, "KonoSuba");
    
<h4>Le parcours de tableau :</h4>
<p>Cette difficulté est survenue lorsque nous avons eu l'idée farfelu de parcourir un tableau avec une taille inconnue. 
    

<h2> Conclusion  </h2>
