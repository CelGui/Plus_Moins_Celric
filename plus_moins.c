#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int plus_moins(int choix_joueur, int valeur)
{
    if(choix_joueur == valeur)
    {
        printf("Bingo! Vous avez trouver la valeur.\n");
    }

    else if(choix_joueur > valeur)
    {
        printf("La valeur est plus petite\n");
    }

    else
    {
        printf("La valeur est plus grande.\n");
    }


}


int main()
{
        printf("Bienvenue, Ce jeu consiste a deviner la valeur cachE!\n");
        printf("Bonne Chance!\n");
        printf("=====================================================\n");


        srand (time(NULL));
        int valeur = rand() % 101;
        int mode;
        printf("\nMode de difficulte: \nFacile = nombre d'essaie illimite\nMoyen = nombre d'essaie --> 25\nDifficile = nombre d'essaie --> 10\n");
        printf("\nEntrer la difficulte: ( Facile = 1, Moyen = 2, Difficile = 3)\n");
        scanf("%d", &mode);

        printf("\nDevinez le chiffre:\n");


        int choix_joueur;
        int essai = 1;

        switch(mode)
        {
         case 1:
                do
                {
                        printf("essai %d\n", essai);
                        essai++;
                        scanf("%d", &choix_joueur);
                        plus_moins(choix_joueur,valeur);
                }while (choix_joueur != valeur);
                break;


         case 2:

                do
                {
                         printf("essai %d\n", essai);
                         scanf("%d", &choix_joueur);
                         plus_moins(choix_joueur,valeur);

                         if (essai == 25)
                         {
                                 printf("Desole,vous avez perdu!");
                                 printf("Le chiffre est %d,\n",valeur);
                                 break;
                         }

                         essai++;

                 }while (choix_joueur != valeur);
                 break;

         case 3:
                do
                {
                        printf("essai %d\n", essai);
                        scanf("%d", &choix_joueur);
                        plus_moins(choix_joueur,valeur);

                        if (essai == 10)
                        {
                                printf("Desole,vous avez perdu!");
                                printf("Le chiffre est %d,\n",valeur);
                                break;
                        }

                        essai++;

                }while (choix_joueur != valeur);
                break;

        default:
                printf("Erreur!!!  Vous devrez choisir entre 1,2 et 3.\n");
                break;

     }

}



