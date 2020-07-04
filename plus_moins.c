#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int plus_moins(int choix_joueur, int valeur)
{
    if(choix_joueur == valeur)
    {
        printf("Bingo!, Vous avez trouver la valeur.\n");
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

        int choix_joueur;
        int valeur = rand() % 101;
        printf("\nDevinez le chiffre:\n");
        {
            do
            {
                scanf("%d",&choix_joueur);
                plus_moins(choix_joueur,valeur);
            }while (choix_joueur != valeur);

        }

}
