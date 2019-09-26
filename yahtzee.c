// *****************************************************************************
//
// Auteurs : Frederico Benevides et Mirela Holanda
// Nom : yahtzee.c 
// Date : 22 octobre 2018
//
// *****************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "yahtzee.h"


int lancerDes(int nbDe){

  Jet jet;
  return jet.de[nbDe] = rand() % MAX + MIN;
}

void ecranDebut(Record record[]){
	system ("clear");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                              YAHTZEE             YAHTZEE      YAHTZEE||||YAHTZEE          YAHTZEE       YAHTZEE       YAHTZEE|||||||YAHTZEE       YAHTZEE||YAHTZEE||       YAHTZEE||YAHTZEE       YAHTZEE||YAHTZEE\n");
	printf("                               YAHTZEE           YAHTZEE       YAHTZEE||||YAHTZEE          YAHTZEE       YAHTZEE       YAHTZEE|||||||YAHTZEE       YAHTZEE||YAHTZEE||       YAHTZEE||YAHTZEE       YAHTZEE||YAHTZEE\n");
	printf("                                YAHTZEE         YAHTZEE        YAHTZEE    YAHTZEE          YAHTZEE       YAHTZEE              YAHTZEE                      YAHTZEE||        YAHTZEE                YAHTZEE\n");
	printf("                                 YAHTZEE       YAHTZEE        YAHTZEE      YAHTZEE         YAHTZEE       YAHTZEE              YAHTZEE                     YAHTZEE||         YAHTZEE                YAHTZEE\n");
	printf("                                  YAHTZEE     YAHTZEE         YAHTZEE      YAHTZEE         YAHTZEE       YAHTZEE              YAHTZEE                    YAHTZEE||          YAHTZEE                YAHTZEE\n");
	printf("                                   YAHTZEE   YAHTZEE          YAHTZEE||||||YAHTZEE         YAHTZEE|||||||YAHTZEE              YAHTZEE                   YAHTZEE||           YAHTZEE||||||          YAHTZEE||||||\n");
	printf("                                        YAHTZEE              YAHTZEE||||||||YAHTZEE        YAHTZEE|||||||YAHTZEE              YAHTZEE                  YAHTZEE||            YAHTZEE||||||          YAHTZEE||||||\n");
	printf("                                        YAHTZEE              YAHTZEE        YAHTZEE        YAHTZEE       YAHTZEE              YAHTZEE                 YAHTZEE||             YAHTZEE                YAHTZEE\n");
	printf("                                        YAHTZEE              YAHTZEE        YAHTZEE        YAHTZEE       YAHTZEE              YAHTZEE                YAHTZEE||              YAHTZEE                YAHTZEE\n");
	printf("                                        YAHTZEE             YAHTZEE          YAHTZEE       YAHTZEE       YAHTZEE              YAHTZEE               YAHTZEE||               YAHTZEE                YAHTZEE\n");
	printf("                                        YAHTZEE             YAHTZEE          YAHTZEE       YAHTZEE       YAHTZEE              YAHTZEE              YAHTZEE||YAHTZEE||       YAHTZEE||YAHTZEE       YAHTZEE||YAHTZEE\n");
	printf("                                        YAHTZEE             YAHTZEE          YAHTZEE       YAHTZEE       YAHTZEE              YAHTZEE              YAHTZEE||YAHTZEE||       YAHTZEE||YAHTZEE       YAHTZEE||YAHTZEE\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                                                                                                          RECORD\n");
	printf("                                                                                                                     ================\n");
	printf("                                                                                                                     Nom        Score\n");
	printf("                                                                                                                     %s\t%.5d\n", record[0].name, record[0].maxScore);
	printf("                                                                                                                     %s\t%.5d\n", record[1].name, record[1].maxScore);
	printf("                                                                                                                     %s\t%.5d\n", record[2].name, record[2].maxScore);
	printf("                                                                                                                     %s\t%.5d\n", record[3].name, record[3].maxScore);
	printf("                                                                                                                     %s\t%.5d\n", record[4].name, record[4].maxScore);
	sleep(5);

}

int combienFaces(Jet jet, int face){
	
	int nbChaqueFace[] = {0, 0, 0, 0, 0, 0};
	
	for (int i = 0; i <= 5; i++)
   		for (int j = 0; j < 5; j++)
    	if (jet.de[j] == i+1)
    		nbChaqueFace[i]++;

    return nbChaqueFace[face];
}

int nbDeFace(Jet jet, int face){
	return (combienFaces(jet, face) * (face + 1));
}

int brelan(Jet jet){
	
	int somme = 0;
	for (int i = 0; i < 5; i++)
		somme += jet.de[i];
	for (int i = 0; i < 6; i++)
	if (combienFaces(jet, i) >= 3)
		return somme;

	return 0;
}

int carre(Jet jet){
	
	int somme = 0;
	for (int i = 0; i < 5; i++)
		somme += jet.de[i];
	
	for (int i = 0; i < 6; i++)
		if (combienFaces(jet, i) >= 4)
			return somme;

	return 0;
}

int mainPleine(Jet jet){
	
	int j = 0;
	int k = 0;

	for (int i = 0; i < 6; i++)
	{
		if (combienFaces(jet, i) == 0)
			j++;
		if (combienFaces(jet, i) == 1)
			k++;
	}
	
	if (j >= 4 && k == 0)
		return POINTAGE_MAIN_PLEINE;

	return 0;
}

int petiteSuite(Jet jet){

  int j = 0;
  for (int i = 0; i < 6; i++)
  {
    if (combienFaces(jet, i) > 0)
    {
      j++;
      if (j == 4)
        return POINTAGE_PETITE_SUITE;
    }
    else
      j = 0;
  }
  return 0;
}

int grandeSuite(Jet jet){

int j = 0;
  for (int i = 0; i < 6; i++)
  {
    if (combienFaces(jet, i) > 0)
    {
      j++;
      if (j == 5)
        return POINTAGE_GRANDE_SUITE;
    }
    else
      j = 0;
  }
  return 0;
}

int yahtzee(Jet jet){

  for (int i = 0; i < 6; i++)
    if (combienFaces(jet, i) == 5)
      return POINTAGE_YAHTZEE;
  return 0;
}

int chance(Jet jet){
  int somme = 0;
  for (int i = 0; i < 5; i++)
    somme += jet.de[i];
  return somme;
}

int convertCharInt(char charJeter, int i){

  if (charJeter == '0')
    return 0;
  return 1;
}

void imprimerDe(Jet jet){

  for (int i = 1; i <= 5; i++)
    printf(" +-----+   ");
  printf("\n");
  for (int i = 1; i <= 5; i++)
  {
    if (jet.de[i-1] == 1)
      printf(" |     |   ");
    if ((jet.de[i-1] == 2) || (jet.de[i-1] == 3))
      printf(" |    O|   ");
    if ((jet.de[i-1] == 4) || (jet.de[i-1] == 5) || (jet.de[i-1] == 6))
      printf(" |O   O|   ");
  }
  printf("\n");
  for (int i = 1; i <= 5; i++)
  {
    if ((jet.de[i-1] == 1) || (jet.de[i-1] == 3) || (jet.de[i-1] == 5))
      printf(" |  O  |   ");
    if ((jet.de[i-1] == 2) || (jet.de[i-1] == 4))
      printf(" |     |   ");
    if (jet.de[i-1] == 6)
      printf(" |O   O|   ");
  }
  printf("\n");
  for (int i = 1; i <= 5; i++)
  {
    if (jet.de[i-1] == 1)
      printf(" |     |   ");
    if ((jet.de[i-1] == 2) || (jet.de[i-1] == 3))
      printf(" |O    |   ");
    if ((jet.de[i-1] == 4) || (jet.de[i-1] == 5) || (jet.de[i-1] == 6))
      printf(" |O   O|   ");
  }
  printf("\n");
  for (int i = 1; i <= 5; i++)
    printf(" +-----+   ");
  printf("\n");
}

void validerChoix(int vieDeChoix, int choix){
  if (vieDeChoix != 0)
    printf("Joué a déja été choisi.\n");
  if (choix == INVALIDE)
    printf("Choix invalide.\n");
}

int imprimerChoix(Jet jet){
  char selection[5];
  printf("\n\n"
    " *************************************************\n"
    " *       QUEL POINTAGE VOULEZ-VOUS GARDER?       *\n"
    " *************************************************\n"
    " * Face(1) : %.2d     *        (B)relan = %.2d\t *\n"
    " * Face(2) : %.2d     *         (C)arré = %.2d\t *\n"
    " * Face(3) : %.2d     *   (M)ain Pleine = %.2d\t *\n"
    " * Face(4) : %.2d     *  (P)etite suite = %.2d\t *\n"
    " * Face(5) : %.2d     *  (G)rande suite = %.2d\t *\n"
    " * Face(6) : %.2d     *       (Y)ahtzee = %.2d\t *\n"
    " *                  *        C(h)ance = %.2d\t *\n"
    " *************************************************\n",
    nbDeFace(jet, 0), brelan(jet), nbDeFace(jet, 1),
    carre(jet), nbDeFace(jet, 2), mainPleine(jet),
    nbDeFace(jet, 3), petiteSuite(jet), nbDeFace(jet, 4),
    grandeSuite(jet), nbDeFace(jet, 5), yahtzee(jet),
    chance(jet));
  scanf("%s", &selection[0]);
  if (selection[1] != '\0')
  	return INVALIDE;
  switch(selection[0])
  {
    case '1': return FACE1;
    case '2': return FACE2;
    case '3': return FACE3;
    case '4': return FACE4;
    case '5': return FACE5;
    case '6': return FACE6;
    case 'B':
    case 'b': return BRELAN;
    case 'C':
    case 'c': return CARRE;
    case 'M':
    case 'm': return MAIN_PLAINE;
    case 'P':
    case 'p': return PETITE_SUITE;
    case 'G':
    case 'g': return GRANDE_SUITE;
    case 'Y':
    case 'y': return YAHTZEE;
    case 'H':
    case 'h': return CHANCE;
    default: return INVALIDE;
  }
}

void imprimerEcran (Jet jet){

imprimerDe(jet);
printf("\n"
  " ***************************************************\n"
  " *   Face 1 : %.2d     *         (B)relan = %.2d\t   *\n"
  " *   Face 2 : %.2d     *          (C)arré = %.2d\t   *\n"
  " *   Face 3 : %.2d     *    (M)ain Pleine = %.2d\t   *\n"
  " *   Face 4 : %.2d     *   (P)etite suite = %.2d\t   *\n"
  " *   Face 5 : %.2d     *   (G)rande suite = %.2d\t   *\n"
  " *   Face 6 : %.2d     *        (Y)ahtzee = %.2d\t   *\n"
  " *                   *         C(h)ance = %.2d\t   *\n"
  " ***************************************************\n",
  nbDeFace(jet, FACE1), brelan(jet), nbDeFace(jet, FACE2),
  carre(jet), nbDeFace(jet, FACE3), mainPleine(jet),
  nbDeFace(jet, FACE4), petiteSuite(jet), nbDeFace(jet, FACE5),
  grandeSuite(jet), nbDeFace(jet, FACE6), yahtzee(jet),
  chance(jet));

}

Jet tour(){
  Jet jetDansTour;
  Jet jeter;
  char charJeter [5];

  for (int i = 0; i < 5; i++)
    jetDansTour.de[i] = lancerDes(i);
  printf("\n");
  imprimerEcran(jetDansTour);
  printf("\n");
  for (int i = 0; i < 2; i++)
  {
    printf("Quels dés voulez-vous jeter à nouveau? (0 pour garder, 1 pour jeter)\n");
    
    for (int i = 0; i < 5; i++)
    scanf(" %c", &charJeter[i]);
    for(int i = 0; i < 5; i++)
      jeter.de[i] = convertCharInt(charJeter[i], i+1);
    for (int i = 0; i < 5; i++)
      if (jeter.de[i])
        jetDansTour.de[i] = lancerDes(i);
    printf("\n");
    if (i == 0)
      imprimerEcran(jetDansTour);
    else
      imprimerDe(jetDansTour);
    printf("\n");
  }
  return jetDansTour;
}

int sommeSuperieure(int choisi, TabScore tab){
  int sommePartieSuperieure;
  for (int i = 0; i < BRELAN; i++)
    sommePartieSuperieure += tab.obtenu[choisi];
  return sommePartieSuperieure;
}

int sommeInferieure(int choisi, TabScore tab){
  int sommeInferieure;
  for (int i = BRELAN; i < BONUS; i++)
    sommeInferieure += tab.obtenu[choisi];
  return sommeInferieure;
}

int sommeTotal(TabScore score){
  int total;

  for (int i = FACE1; i < INVALIDE; i++)
    total += score.obtenu[i];
  return total;
}

void feuilleDeScore(int tours, int scorePartieSuperieure, int scorePartieInferieure, int total, TabScore score){

printf("\n"
"************************************************************************************\n"
"*                              FEUILLE DE SCORE TOUR %.2d/%d                         *\n"
"************************************************************************************\n\n"

"**********  Partie supérieure **********    **********  Partie inférieure **********\n"
"*                                      *    *                                      *\n"
"*                Face 1 : %.2d           *    *               Brelan : %.2d\t           *\n"
"*                Face 2 : %.2d           *    *                Carré : %.2d\t           *\n"
"*                Face 3 : %.2d           *    *          Main Pleine : %.2d\t           *\n"
"*                Face 4 : %.2d           *    *         Petite suite : %.2d\t           *\n"
"*                Face 5 : %.2d           *    *         Grande suite : %.2d\t           *\n"
"*                Face 6 : %.2d           *    *              Yahtzee : %.2d\t           *\n"
"*                Bonus  : %.2d           *    *               Chance : %.2d\t           *\n"
"*                                      *    *                                      *\n"
"*     Somme partie supérieure : %.3d    *    *     Somme partie inferieure : %.3d\t   *\n"
"****************************************    ****************************************\n\n"

"************************************************************************************\n"
"*                                  Score = %.3d\t                                   *\n"
"************************************************************************************\n"
 ,tours, BONUS, score.obtenu[FACE1], score.obtenu[BRELAN], score.obtenu[FACE2], score.obtenu[CARRE], score.obtenu[FACE3],
 score.obtenu[MAIN_PLAINE], score.obtenu[FACE4], score.obtenu[PETITE_SUITE], score.obtenu[FACE5], score.obtenu[GRANDE_SUITE],
 score.obtenu[FACE6], score.obtenu[YAHTZEE], score.obtenu[BONUS], score.obtenu[CHANCE], scorePartieSuperieure,
 scorePartieInferieure, total);

  sleep(5);
 }

void ordonner(Record records[]){
  Record maxTemp;
  Record temp;
  for (int i = 0; i < 5; i++)
  {
    maxTemp = records[i];
    for (int j = i+1; j < 5; j++)
      if (records[j].maxScore > maxTemp.maxScore)
      {
        temp = records[i];
        records[i] = records[j];
        records[j] = temp;
      }
  }
}