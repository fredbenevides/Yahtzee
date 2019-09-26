// *****************************************************************************
//
// Auteurs : Frederico Benevides et Mirela Holanda
// Nom : testYahtzee.c
// Date : 22 octobre 2018
//
// *****************************************************************************


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "yahtzee.h"

void testNbDeFace(){

	Jet jetTest = {6, 6, 6, 6, 6};
	if (nbDeFace(jetTest, 5) == 30)
		printf("\033[1;32m""nbDeFace test1 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""nbDeFace test1 ECHEC! Attendu pour {6, 6, 6, 6, 6} est 30 mais nbDeFace retourn %d.\n\033[0m", nbDeFace(jetTest, 5));

	if (nbDeFace(jetTest, 0) == 0)
		printf("\033[1;32m""nbDeFace test2 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""nbDeFace test2 ECHEC! Attendu pour {6, 6, 6, 6, 6} est 0 mais nbDeFace retourn %d.\n\033[0m", nbDeFace(jetTest, 0));
}

void testBrelan(){

	Jet jetTest = {1, 1, 1, 2, 6};
	if (brelan(jetTest) == 11)
		printf("\033[1;32m""brelan test1 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""brelan test1 ECHEC! Attendu pour {1, 1, 1, 2, 6} est 11 mais brelan retourn %d.\n\033[0m", brelan(jetTest));

	jetTest.de[0] = 3;

	if (brelan(jetTest) == 0)
		printf("\033[1;32m""brelan test2 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""brelan test2 ECHEC! Attendu pour {3, 1, 1, 2, 6} est 0 mais brelan retourn %d.\n\033[0m", brelan(jetTest));
}

void testCarre(){

	Jet jetTest = {1, 1, 1, 1, 6};
	if (carre(jetTest) == 10)
		printf("\033[1;32m""carre test1 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""carre test1 ECHEC! Attendu pour {1, 1, 1, 1, 6} est 10 mais carre retourn %d.\n\033[0m", carre(jetTest));

	jetTest.de[0] = 3;

	if (carre(jetTest) == 0)
		printf("\033[1;32m""carre test2 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""carre test2 ECHEC! Attendu pour {3, 1, 1, 1, 6} est 0 mais carre retourn %d.\n\033[0m", carre(jetTest));
}

void testMainPleine(){

	Jet jetTest = {1, 1, 1, 2, 2};
	if (mainPleine(jetTest) == 25)
		printf("\033[1;32m""mainPleine test1 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""mainPleine test1 ECHEC! Attendu pour {1, 1, 1, 2, 2} est 25 mais mainPleine retourn %d.\n\033[0m", mainPleine(jetTest));

	jetTest.de[0] = 3;

	if (mainPleine(jetTest) == 0)
		printf("\033[1;32m""mainPleine test2 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""mainPleine test2 ECHEC! Attendu pour {3, 1, 1, 2, 2} est 0 mais mainPleine retourn %d.\n\033[0m", mainPleine(jetTest));
}

void testPetiteSuite(){

	Jet jetTest = {1, 2, 3, 4, 2};
	if (petiteSuite(jetTest) == 30)
		printf("\033[1;32m""petiteSuite test1 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""petiteSuite test1 ECHEC! Attendu pour {1, 2, 3, 4, 2} est 30 mais petiteSuite retourn %d.\n\033[0m", petiteSuite(jetTest));

	jetTest.de[0] = 3;

	if (petiteSuite(jetTest) == 0)
		printf("\033[1;32m""petiteSuite test2 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""petiteSuite test2 ECHEC! Attendu pour {3, 2, 3, 4, 2} est 0 mais petiteSuite retourn %d.\n\033[0m", petiteSuite(jetTest));
}

void testGrandeSuite(){

	Jet jetTest = {6, 2, 3, 4, 5};
	if (grandeSuite(jetTest) == 40)
		printf("\033[1;32m""grandeSuite test1 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""grandeSuite test1 ECHEC! Attendu pour {6, 2, 3, 4, 5} est 40 mais grandeSuite retourn %d.\n\033[0m", grandeSuite(jetTest));

	jetTest.de[0] = 3;

	if (grandeSuite(jetTest) == 0)
		printf("\033[1;32m""grandeSuite test2 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""grandeSuite test2 ECHEC! Attendu pour {3, 2, 3, 4, 5} est 0 mais grandeSuite retourn %d.\n\033[0m", grandeSuite(jetTest));
}

void testYahtzee(){

	Jet jetTest = {6, 6, 6, 6, 6};
	if (yahtzee(jetTest) == 50)
		printf("\033[1;32m""yahtzee test1 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""yahtzee test1 ECHEC! Attendu pour {6, 6, 6, 6, 6} est 50 mais yahtzee retourn %d.\n\033[0m", yahtzee(jetTest));

	jetTest.de[0] = 3;

	if (yahtzee(jetTest) == 0)
		printf("\033[1;32m""yahtzee test2 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""yahtzee test2 ECHEC! Attendu pour {3, 6, 6, 6, 6} est 0 mais yahtzee retourn %d.\n\033[0m", yahtzee(jetTest));
}

void testChance(){

	Jet jetTest = {1, 1, 1, 2, 6};
	if (chance(jetTest) == 11)
		printf("\033[1;32m""chance test1 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""chance test1 ECHEC! Attendu pour {1, 1, 1, 2, 6} est 11 mais chance retourn %d.\n\033[0m", chance(jetTest));

	jetTest.de[0] = 3;

	if (chance(jetTest) == 13)
		printf("\033[1;32m""chance test2 SUCCES\n\033[0m");
	else
		printf("\033[1;31m""chance test2 ECHEC! Attendu pour {3, 1, 1, 2, 6} est 0 mais chance retourn %d.\n\033[0m", chance(jetTest));	
}

void testsUnitaires(){

	testNbDeFace();
	testBrelan();
	testCarre();
	testMainPleine();
	testPetiteSuite();
	testGrandeSuite();
	testYahtzee();
	testChance();
}