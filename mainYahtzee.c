// *****************************************************************************
//
// Auteurs : Frederico Benevides et Mirela Holanda
// Nom : mainYahtzee.c
// Date :22 octobre 2018
//
// Joue Yahtzee.
//
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "yahtzee.h"
#include "testYahtzee.h"

int main(int argc, char** argv)
{
  Jet jet;
  int choisi;
  TabScore score = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int vie[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int somme = 0;
  int sommePartieSuperieure = 0;
  int sommePartieInferieure = 0;
  int scoreTotal = 0;
  char sortie = 'n';
  Record record[] = {{"Rebecca", 0}, {"Mirela", 0}, {"Fred", 0}, {"Zuckerberg", 0}, {"Gates", 0}};

  if ((argc > 1) && (argv[1][0] == 'T') && (argv[1][1] == 'E') && (argv[1][2] == 'S') && (argv[1][3] == 'T'))
  { 
    system("clear");
    testsUnitaires();
    return 0;
  }

  FILE * fp;
  fp = fopen ("record.txt", "a");
  fclose(fp);

  srand(time(NULL));
  while ((sortie != 'O') && (sortie != 'o'))
  {
    FILE * fp;
    fp = fopen ("record.txt", "r+");
    for (int i = 0; i <= DERNIER_DETENTEUR_RECORD; i++)
    fscanf(fp, "%s %d", record[i].name, &record[i].maxScore);
    fclose(fp);

    ecranDebut(record);

    for (int i = PREMIER_TOUR; i <= DERNIER_TOUR; i++)
    {
      system("clear");
      printf("\n --------------------- TOUR %.2d ---------------------\n", i );
      jet = tour();
      choisi = imprimerChoix(jet);
      while ((choisi == INVALIDE) || (vie[choisi] != 0))
      {
        validerChoix(vie[choisi], choisi);
        imprimerDe(jet);
        choisi = imprimerChoix(jet);
      }
      switch(choisi)
      {
        case FACE1:
          score.obtenu[choisi] = nbDeFace(jet, FACE1);
          break;
        case FACE2:
          score.obtenu[choisi] = nbDeFace(jet, FACE2);
          break;
        case FACE3:
          score.obtenu[choisi] = nbDeFace(jet, FACE3);
          break;
        case FACE4:
          score.obtenu[choisi] = nbDeFace(jet, FACE4);
          break;
        case FACE5:
          score.obtenu[choisi] = nbDeFace(jet, FACE5);
          break;
        case FACE6:
          score.obtenu[choisi] = nbDeFace(jet, FACE6);
          break;
        case BRELAN:
          score.obtenu[choisi] = brelan(jet);
          break;
        case CARRE:
          score.obtenu[choisi] = carre(jet);
          break;
        case MAIN_PLAINE:
          score.obtenu[choisi] = mainPleine(jet);
          break;
        case PETITE_SUITE:
          score.obtenu[choisi] = petiteSuite(jet);
          break;
        case GRANDE_SUITE:
          score.obtenu[choisi] = grandeSuite(jet);
          break;
        case YAHTZEE:
          score.obtenu[choisi] = yahtzee(jet);
          break;
        case CHANCE:
          score.obtenu[choisi] = chance(jet);
          break;
      }
      vie[choisi]++;
      if (choisi < BRELAN)
        sommePartieSuperieure += score.obtenu[choisi];
      else if (choisi < BONUS)
        sommePartieInferieure += score.obtenu[choisi];
      if (sommePartieSuperieure >= GAGNER_BONUS)
        score.obtenu[BONUS] = VALEUR_BONUS;
      scoreTotal = sommePartieInferieure + sommePartieSuperieure + score.obtenu[BONUS];
      feuilleDeScore(i, sommePartieSuperieure, sommePartieInferieure, scoreTotal, score);
    }
    if (scoreTotal > record[DERNIER_DETENTEUR_RECORD].maxScore)
    {
      record[DERNIER_DETENTEUR_RECORD].maxScore = scoreTotal;
      printf("Nouveau record. Tapez votre nom. ");
      scanf("%s", record[DERNIER_DETENTEUR_RECORD].name);
      ordonner(record);
      FILE * fp;
      fp = fopen ("record.txt", "w+");
      for (int i = 0; i <= DERNIER_DETENTEUR_RECORD; i++)
        fprintf(fp, "%s %d", record[i].name, record[i].maxScore);
        fclose(fp);
    }
    printf("Voulez-vous sortir?\n(O)ui / (N)on\n");
    scanf(" %c", &sortie);
    for (int i = 0; i < INVALIDE; i++)
      score.obtenu[i] = 0;
    for (int i = 0; i < DERNIER_TOUR; i++)
      vie[i] = 0;
    somme = 0;
    sommePartieSuperieure = 0;
    sommePartieInferieure = 0;
    scoreTotal = 0;
  }
}