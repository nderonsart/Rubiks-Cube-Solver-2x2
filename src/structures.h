/**
 * Projet Rubik's Cube 
 * - Module contenant les structures et fonctions d'affichages du cube -
 * @author Nicolas Deronsart
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LINE 2

#define CGREEN "\033[0;32m"
#define CYELLOW "\033[0;93m"
#define CBLUE "\033[0;34m"
#define CWHITE "\033[0m"
#define CORANGE "\033[0;33m"
#define CRED "\033[0;31m"



/** Enumération contenant les couleurs du Rubik's Cube*/
typedef enum {GREEN, YELLOW, BLUE, WHITE, ORANGE, RED } Color;


/** Enumération contenant les faces du Rubik's Cube*/
typedef enum {FRONT, DOWN, BACK, UP, LEFT, RIGHT } Faces;



/** 
 * Type représentant une matrice cubique contenant les faces du Rubik's Cube composée de:
 * - 6 tableaux représentants les faces contenant chacune:
 * - LINE lignes contenant chacune:
 * - LINE entier représentant les couleurs des faces
*/
typedef int RCube[6][LINE][LINE];

/**
 * Fonction qui initialise correctement un Rubik's Cube
 * @param cube rubik's cube
*/
void createRCube(RCube*);



/**
 * Fonction qui affiche le nom de la couleur
 * @param n la valeur dont l'on cherche le nom
 * @param file le fichier où afficher la couleur
*/
void colorName(int, FILE*);

/**
 * Fonction qui affiche un Rubik's Cube sous le forme de son patron dans un fichier
 * @param cube le rubik's cube
 * @param file le fichier où mettre le rubik's cube
*/
void printPatternRCube(RCube, FILE*);



/**
 * Structure représentant un maillon de la liste chaînée contenant : 
 * - rotation, le nom de la rotation à effectuer
 * - state, l'état actuel du cube après rotation
 * - next, un pointeur vers le noeud suivant
*/
typedef struct ListNode ListNode;
struct ListNode {
    char* rotation;
    RCube state;
    ListNode* next;
};

/**
 * Fonction qui alloue et retourne un nouveau noeud de liste chaînée contenant une occurence d'un mot
 * @param rotation le mot contenu dans le noeud
 * @param state l'état actuel du cube après la rotation
 * @return le noeud de liste chaînée créé
*/
ListNode* newListNode(char*, RCube);


/**
 * Structure représentant la liste chaînée contenant : 
 * - len, la taille actuelle de la liste chaînée
 * - first, un pointeur vers le premier noeud de la liste 
*/
typedef struct {
    int len;
    ListNode* first;
} List;

/**
 * Fonction qui alloue et retourne une nouvelle liste contenant un premier noeud représentant l'état initial du cube
 * @param state l'état du cube
 * @return la liste chaînée vide créée
*/
List* newList(RCube);


/**
 * Fonction qui ajoute un noeud dans la liste chaînée
 * @param list la liste chaînée
 * @param word le mot à ajouter
*/
void addNode(List*, char*, RCube);


/**
 * Fonction qui supprime une liste chaînée
 * @param list la liste chaînée
*/
void deleteList(List*);


/**
 * Fonction qui affiche le détail des étapes de résolution du Rubik's Cube contenu dans la liste chaînée
 * @param list la liste chaînée 
 * @param file le fichier où écrire ces étapes
*/
void printDetail(List*, FILE*);

/**
 * Fonction qui affiche les rotations utilisées pour la résolution du Rubik's Cube contenu dans la liste chaînée
 * @param list la liste chaînée 
 * @param file le fichier où écrire ces rotations
*/
void printRotations(List*, FILE*);


