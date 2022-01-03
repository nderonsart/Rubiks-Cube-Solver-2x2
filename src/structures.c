/**
 * Projet Rubik's Cube 
 * - Module contenant les structures et fonctions d'affichages du cube -
 * @author Nicolas Deronsart
*/

#include "structures.h"



/**
 * Fonction qui initialise correctement un Rubik's Cube
 * @param cube le rubik's cube
*/
void createRCube(RCube* cube){
    int i, j, k;

    for (i=0; i<6; i++) for (j=0; j<LINE; j++) for (k=0; k<LINE; k++) (*cube)[i][j][k] = i;
}



/**
 * Fonction qui affiche le nom de la couleur
 * @param n la valeur dont l'on cherche le nom
 * @param file le fichier où afficher la couleur
*/
void colorName(int n, FILE* file){
    if (file == stdout){
        if (n == 0) fprintf(file, "%sG%s", CGREEN, CWHITE);
        if (n == 1) fprintf(file, "%sY%s", CYELLOW, CWHITE);
        if (n == 2) fprintf(file, "%sB%s", CBLUE, CWHITE);
        if (n == 3) fprintf(file, "W");
        if (n == 4) fprintf(file, "%sO%s", CORANGE, CWHITE);
        if (n == 5) fprintf(file, "%sR%s", CRED, CWHITE);
    }
    else{
        if (n == 0) fprintf(file, "G");
        if (n == 1) fprintf(file, "Y");
        if (n == 2) fprintf(file, "B");
        if (n == 3) fprintf(file, "W");
        if (n == 4) fprintf(file, "O");
        if (n == 5) fprintf(file, "R");
    }
}

/**
 * Fonction qui affiche un Rubik's Cube sous le forme de son patron dans un fichier
 * @param cube le rubik's cube
 * @param file le fichier où mettre le rubik's cube
*/
void printPatternRCube(RCube cube, FILE* file){
    int j, l, k;

    // Affichage face UP
    for (j=0; j<LINE; j++){
        for (l=0; l<LINE*3+1; l++) fprintf(file, " ");
        for (k=0; k<LINE; k++){
            colorName(cube[UP][j][k], file);
            fprintf(file, "  ");
        } 
        fprintf(file, "\n");
    }
    fprintf(file, "\n");

    // Affichage faces LEFT FRONT RIGHT BACK
    for (j=0; j<LINE; j++){
        for (k=0; k<LINE; k++){ // LEFT
            colorName(cube[LEFT][j][k], file);
            fprintf(file, "  ");
            if (k == LINE-1) fprintf(file, " ");
        }
        for (k=0; k<LINE; k++){ // FRONT
            colorName(cube[FRONT][j][k], file);
            fprintf(file, "  ");
            if (k == LINE-1) fprintf(file, " ");
        }
        for (k=0; k<LINE; k++){ // RIGHT
            colorName(cube[RIGHT][j][k], file);
            fprintf(file, "  ");
            if (k == LINE-1) fprintf(file, " ");
        }
        for (k=0; k<LINE; k++){ // BACK
            colorName(cube[BACK][j][k], file);
            fprintf(file, "  ");
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");

    // Affichage face DOWN
    for (j=0; j<LINE; j++){
        for (l=0; l<LINE*3+1; l++) fprintf(file, " ");
        for (k=0; k<LINE; k++){
            colorName(cube[DOWN][j][k], file);
            fprintf(file, "  ");
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");    
}



/**
 * Fonction qui alloue et retourne un nouveau noeud de liste chaînée contenant une occurence d'un mot
 * @param rotation le mot contenu dans le noeud
 * @param state l'état actuel du cube après la rotation
 * @return le noeud de liste chaînée créé
*/
ListNode* newListNode(char* rotation, RCube state){
    ListNode* node = malloc(sizeof(ListNode));
    node->rotation = malloc(sizeof(char)*3);
    strcpy(node->rotation, rotation);
    for (int i=0; i<6; i++){
        for (int j=0; j<LINE; j++){
            for (int k=0; k<LINE; k++){
                node->state[i][j][k] = state[i][j][k];
            }
        }
    }
    return node;
}

/**
 * Fonction qui alloue et retourne une nouvelle liste contenant un premier noeud représentant l'état initial du cube
 * @param state l'état du cube
 * @return la liste chaînée vide créée
*/
List* newList(RCube state){
    List* list = malloc(sizeof(List));
    list->len = 1;
    list->first = newListNode("Init ", state);
    return list;
}


/**
 * Fonction qui ajoute un noeud dans la liste chaînée
 * @param list la liste chaînée
 * @param word le mot à ajouter
*/
void addNode(List* list, char* rotation, RCube state){
    ListNode* n = list->first;
    while (n->next) n = n->next;

    ListNode* new = newListNode(rotation, state);
    n->next = new;
    list->len++;
}


/**
 * Fonction qui supprime une liste chaînée
 * @param list la liste chaînée
*/
void deleteList(List* list){
    ListNode* n = list->first;
    ListNode* next;
    while (n){
        next = n;
        n->rotation = NULL;
        free(n->rotation);
        n = NULL;
        free(n);
        n = next->next;
    }
    next = NULL;
    free(next);
    n = NULL;
    free(n);

    list->first = NULL;
    free(list->first);
    list = NULL;
    free(list);
}


/**
 * Fonction qui affiche le détail des étapes de résolution du Rubik's Cube contenu dans la liste chaînée
 * @param list la liste chaînée 
 * @param file le fichier où écrire ces étapes
*/
void printDetail(List* list, FILE* file){
    fprintf(file, "----------------------------------------\n");
    int step = 0;
    ListNode* n = malloc(sizeof(ListNode));
    n = list->first;
    while (n){
        fprintf(file, "Etape %d :\n", step-1);
        if (strcmp(" ", n->rotation)) fprintf(file, "Rotation : %s\n", n->rotation);
        fprintf(file, "Etat : \n");
        printPatternRCube(n->state, file);
        n = n->next;
        step++;

        if (n) fprintf(file, "--------------------\n");
    }
    free(n);
    n = NULL;
    fprintf(file, "----------------------------------------\n");
}

/**
 * Fonction qui affiche les rotations utilisées pour la résolution du Rubik's Cube contenu dans la liste chaînée
 * @param list la liste chaînée 
 * @param file le fichier où écrire ces rotations
*/
void printRotations(List* list, FILE* file){
    int step = 0;
    ListNode* n = malloc(sizeof(ListNode));
    n = list->first;
    while (n){
        fprintf(file, "%s", n->rotation);
        n = n->next;
        step++;
    }
    free(n);
    n = NULL;
    fprintf(file, "\n");
}


