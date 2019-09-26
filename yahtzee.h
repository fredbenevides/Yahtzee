// *****************************************************************************
//
// Auteurs : Frederico Benevides et Mirela Holanda
// Nom : yahtzee.h 
// Date : 22 octobre 2018
//
// Liste de tous les fonctions et documentation necessaires pour trouver le  
// pointage donné pour un jet, pour faire l'interation avec l'usager et autres 
// fonctions necessaires pour exécuter le joue Yahtzee.
// 
// *****************************************************************************

#pragma once

#define PREMIER_TOUR 1
#define DERNIER_TOUR 13
#define GAGNER_BONUS 63
#define VALEUR_BONUS 35
#define DERNIER_DETENTEUR_RECORD 4
#define POINTAGE_MAIN_PLEINE 25
#define POINTAGE_PETITE_SUITE 30
#define POINTAGE_GRANDE_SUITE 40
#define POINTAGE_YAHTZEE 50
#define MIN 1
#define MAX 6
typedef struct Jet Jet;
struct Jet{
   int de[5];
};

typedef struct Record Record;
struct Record{
  char name[10];
  int maxScore;
};

typedef struct TabScore TabScore;
struct TabScore{
  int obtenu[14];
};

enum joue {FACE1 = 0, FACE2, FACE3, FACE4, FACE5, FACE6, BRELAN, CARRE, MAIN_PLAINE, PETITE_SUITE, GRANDE_SUITE, YAHTZEE, CHANCE, BONUS, INVALIDE};

// *****************************************************************************
// lancerDes
//
// C'est la fonction pour lancer le dé.
//
// INPUT :
//     Un entier entre 0 et 5 exclusivement qui sont correspondant a chaque dé du jet.
// 
//
// OUTPUT :
//     La face du dé entre 1 et 6.
//     
// *****************************************************************************
int lancerDes(int nbDe);

// *****************************************************************************
// ecranDebut
//
// Fonction pour imprimer l'écran du debut.
//
// INPUT :
//      
//
// OUTPUT :
//     
//     
// *****************************************************************************
void ecranDebut();

// *****************************************************************************
// combienFaces
//
// Compte combien de fois la face est dans le jet
//
// INPUT :
//     jet : cinq dés.
// 	   int : face qui serait compté.
//
// OUTPUT :
//     Combien de fois qui la face choisi apparaître dans le jet.
//
// *****************************************************************************
int combienFaces(Jet jet, int face);

// *****************************************************************************
// nbDeFace 
//
// Calcule le pointage pour la figure "face"
//
// INPUT :
//     jet : cinq dés.
//     face : la face a comptabiliser.
//
// OUTPUT :
//     le pointage pour face dans jet. Le pointage est le produit de face et du
//     nombre de des dans jets qui valent face.
//
// *****************************************************************************
int nbDeFace(Jet jet, int face);

// *****************************************************************************
// brelan
//
// Calcule le pointage pour la figure "brelan"
//
// INPUT :
//     jet : cinq dés.
//
// OUTPUT :
//     le pointage pour brelan dans jet. Un brelan est trois faces
//     identiques. Il vaut la somme de dés.
//
// *****************************************************************************
int brelan(Jet jet);

// *****************************************************************************
// carre
//
// Calcule le pointage pour la figure "carre"
//
// INPUT :
//      jet : cinq dés.
//
// OUTPUT :
//     le pointage pour carre dans jet. Un carre est quatres faces
//     identiques. Il vaut la somme des dés.
//
// *****************************************************************************
int carre(Jet jet);

// *****************************************************************************
// mainPleine
//
// Calcule le pointage pour la figure "main pleine"
//
// INPUT :
//      jet : cinq dés.
//
// OUTPUT :
//     le pointage pour main pleine dans jet. Une main pleine est trois faces
//     identiques et deux faces identiques. Elle vaut 25 points.
//
// *****************************************************************************
int mainPleine(Jet jet);

// *****************************************************************************
// petiteSuite
//
// Calcule le pointage pour la figure "petite suite"
//
// INPUT :
//     jet : cinq dés.
//
// OUTPUT :
//     le pointage pour petite suite dans jet. Une petite suite vaut 30
//     points. Il y a trois petites suites possibles : 1,2,3,4 ou 2,3,4,5 ou
//     3,4,5,6. L’ordre des dés n’a pas d’importance
//
// *****************************************************************************
int petiteSuite(Jet jet);

// *****************************************************************************
// grandeSuite
//
// Calcule le pointage pour la figure "grande suite"
//
// INPUT :
//     jet : cinq dés.
//
// OUTPUT :
//     le pointage pour grande suite dans jet. Une grande suite vaut 40
//     points. Il y a deux grandes suites possibles : 1,2,3,4,5 ou
//     2,3,4,5,6. L’ordre des dés n’a pas d’importance.
//
// *****************************************************************************
int grandeSuite(Jet jet);

// *****************************************************************************
// yahtzee
//
// Calcule le pointage pour la figure "yahtzee"
//
// INPUT :
//     jet : cinq dés.
//
// OUTPUT :
//     le pointage pour yahtzee dans jet. Un yahtzee est cinq des identiques. Il
//     vaut 50 points.
//
// *****************************************************************************
int yahtzee(Jet jet);

// *****************************************************************************
// chance 
//
// Calcule le pointage pour la figure "chance"
//
// INPUT :
//     jet : cinq dés.
//
// OUTPUT : 
//     le pointage pour chance est la somme des faces.
//
// *****************************************************************************
int chance(Jet jet);

// *****************************************************************************
// convertCharInt 
//
// Faire la convertion de char en entier
//
// INPUT :
//     Un tableau de char
//
// OUTPUT : 
//     0 ou 1
// 
// *****************************************************************************
int convertCharInt(char charJeter, int i);

// *****************************************************************************
// imprimerDe
//
// imprime l'écran de les dés du jet
//
// INPUT :
//     Jet
//
// OUTPUT : 
//     
// *****************************************************************************
void imprimerDe(Jet jet);

// *****************************************************************************
// validerChoix
//
// Faire la validation de la joué choisi
//
// INPUT :
//     Deux entiers : Un des entiers est le choix actuel de l'utilisateur et 
//                    l'autre est indiqué le jeu(la pièce) a été choisi 
//					  précédemment.
//
// OUTPUT : 
//     
//
// *****************************************************************************
void validerChoix(int vieDeChoix, int choix);

// *****************************************************************************
// imprimerChoix
//
// Faire l'impression d'un tableau (écran) avec les pointages possibles.
// Et faire la capture de la choix d'usager.
//
// INPUT :
//     jet : cinq dés.
//
// OUTPUT : 
//     Retourne un entier correspondant à joué ou si le choix est invalide,
// 	   selon le "enum joue".
//
// *****************************************************************************
int imprimerChoix(Jet jet);

// *****************************************************************************
// imprimerEcran
//
// Faire l'impression d'un tableau (écran) avec les pointages possibles.
//
// INPUT :
//     jet : cinq dés.
//
// OUTPUT : 
//     
// *****************************************************************************
void imprimerEcran (Jet jet);

// *****************************************************************************
// tour
//
// La fonction roule les 5 dés, l'utilisateur peut choisir quels dés il 
// veut garder et la fonction roule un autre fois les dés a partir des
// choix de l'utilisateur. 
//
// INPUT :
//
// OUTPUT : 
//     Jet : 5 dés.
//
// *****************************************************************************
Jet tour();

// *****************************************************************************
// sommeSuperieure
//
// Calcule la somme de la partie superieure(De Face 1 jusqu'à la Face 6)
//
// INPUT :
//     Un entier : la choix d'utilisateur 
//	   Un struct : TabScore qui est correspondant à la pointage obtennu en
// 				   tous les joués.
//
// OUTPUT : 
//     Un entier : qui est la somme de la partie superieure.
//
// *****************************************************************************
int sommeSuperieure(int choisi, TabScore tab);

// *****************************************************************************
// sommeInferieure
//
// Calcule la somme de la partie inferieure(De Brelan jusqu'à Chance)
//
// INPUT :
//     Un entier : la choix d'utilisateur 
//	   Un struct : TabScore qui est correspondant à la pointage obtennu en
// 				   tous les joués.
//
// OUTPUT : 
//     Un entier : qui est la somme de la partie inferieure.
//
// *****************************************************************************
int sommeInferieure(int choisi, TabScore tab);

// *****************************************************************************
// sommeTotal
//
// Calcule le pointage totale
//
// INPUT :
//     Un struct : TabScore qui est correspondant à la pointage obtennu en
// 				   tous les joués.
//
// OUTPUT : 
//     Un entier : le pointage totale
//
// *****************************************************************************
int sommeTotal(TabScore score);

// *****************************************************************************
// feuilleDeScore
//
// Imprime la feuille de score avec la pointage obtennu à chaque tour
//
// INPUT :
//     Quatre entiers : tours (le tour), scorePartieSuperieure (le totale de 
//						la partie superieure), scorePartieInferieure (le totale 
//						de la partie inferieure) et total (la pointage totale).
//	   Un tableau : TabScore qui est correspondant à la pointage obtennu en
// 				    tous les joués.
//
// OUTPUT : 
//     
//
// *****************************************************************************
void feuilleDeScore(int tours, int scorePartieSuperieure, int scorePartieInferieure, int total, TabScore score);

// *****************************************************************************
// ordonner
//
// La fonction reçoit un tableau de cinq structs du type Record et ordonne d'un
// façon diminuante pour le membre maxScore
//
// INPUT :
//     Un tableau de structs du type Record
//
// OUTPUT : 
//     
//
// *****************************************************************************
void ordonner(Record records[]);