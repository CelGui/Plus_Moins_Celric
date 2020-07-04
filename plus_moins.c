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
	printf("La valeur est plus petite.\n");
    }
    else
    {
	printf("La valeur est plus grande.\n");
    }
}

int main()
{
        printf("Bienvenue dans le jeu Plus_Moins.\nIl consiste a trouver la valeur cachE!\n");
        printf("=========================== ***[ Bonne Chance ]*** =============================\n");


	int nombre_de_joueur;
	printf("\nEntrez le nombre de joueur pour le jeu (1 ou 2): ");
	scanf("%d", &nombre_de_joueur);

	int nombre_de_tour;
	printf("Entrez le nombre de tour que vous voulez jouer: ");
	scanf("%d", &nombre_de_tour);

	int tour = 1;


	if (nombre_de_joueur == 1)
	{
		printf("\nMode de difficulte: \nFacile = nombre d'essaie illimite\nMoyen = nombre d'essai 25 \nDifficile = nombre d'essai 10\n");
		int choix_joueur;

		while (tour <= nombre_de_tour)
		{
			printf("\nTour %d:\n", tour);
			srand (time(NULL));
			int valeur = rand() % 100 + 1;

			int mode;
			printf("Entrez la difficulte: (Facile = 1, Moyen = 2, Difficile = 3)\n");
			scanf("%d", &mode);

			printf("\nDevinez le chiffre:\n");

			int essai = 1;

			switch(mode)
			{
				case 1:

					do
					{
						printf("essai %d\n", essai);
						essai++;
						scanf("%d", &choix_joueur);
						plus_moins(choix_joueur, valeur);
					}while (choix_joueur != valeur);
					break;

				case 2:
					do
					{
						printf("essai %d\n", essai);
						scanf("%d", &choix_joueur);
						plus_moins(choix_joueur, valeur);

						if (essai == 25)
						{
							printf("Vous avez perdu! Le chiffre est %d.\n", valeur);
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
						plus_moins(choix_joueur, valeur);

						if (essai == 10)
						{
							printf("Vous avez perdu! Le chiffre est %d.\n", valeur);
							break;
						}

						essai++;
					}while (choix_joueur != valeur);
					break;

				default:
					printf("Erreur!! Vous deviez choisir entre 1, 2 et 3.\n");
					break;
			}

			tour++;

		}
	}

	else if (nombre_de_joueur == 2)
	{
		int choix_joueur;

		int score_joueur1, score_joueur2;
		int joueur1 = 0;
		int joueur2 = 0;

		while (tour <= nombre_de_tour)
		{
			int nombre_essai;
			printf("\nTour %d: Entrez le nombre d'essai: ",tour);
			scanf("%d", &nombre_essai);

			while (nombre_essai < 10)
			{
				printf("Le nombre d'essai doit etre minimum 10. Veuillez reessayer, merci!!\n");
				scanf("%d", &nombre_essai);
			}

			int joueur = 1;

			while (joueur < 3)
			{
				int score = nombre_essai;

				srand (time(NULL));
				int valeur = rand() % 100 + 1;

				printf("\n*** [ Joueur %d ] ***\n", joueur);
				printf("\nDevinez le chiffre:\n");

				int essai = 1;

				do
				{
					printf("essai %d\n", essai);
					scanf("%d", &choix_joueur);
					plus_moins(choix_joueur, valeur);
					score--;

					if (essai == nombre_essai)
					{
						score = 0;
						printf("Vous avez perdu! Le chiffre est %d.\n", valeur);
						break;
					}

					essai++;
				}while (choix_joueur != valeur);

				if (joueur == 1)
				{
					joueur1 = joueur1 + score;
					score_joueur1 = score;
					printf("\nLe score de joueur1 est %d.\n", score_joueur1);
				}

				else
				{
					joueur2 = joueur2 + score;
					score_joueur2 = score;
					printf("\nLe score de joueur2 est %d.\n", score_joueur2);
				}

				joueur++;

			}

			tour++;

		}

                printf("\n============================================\n");
		printf("\nScore totale de joueur1: %d\n", joueur1);
		printf("Score totale de joueur2: %d\n", joueur2);
                printf("\n============================================\n");

		if (joueur1 > joueur2)
		{
			printf("\n\n***** Felicitations Joueur 1!! Vous etes le gagnant. *****\n");
		}

		else
		{
			printf("\n\n***** Felicitations Joueur 2!! Vous etes le gagnant. ******\n");
		}

	}

	else
	{
		printf("Erreur!! Le choix doit etre 1 ou 2.\n");
	}

}
