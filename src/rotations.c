/**
 * Projet Rubik's Cube 
 * - Module contenant les rotations -
 * @author Nicolas Deronsart
*/

#include "rotations.h"



// Rotation des faces

/**
 * Fonction qui effectue une rotation d'une face suite à un mouvement gauche sur le Rubik's Cube
 * @param cube le rubik's cube
 * @param face la face qui subit la rotation
*/
void rotationFaceLeft(RCube* cube, int face){
    int j, k;

    int tmp2[LINE][LINE];
    for (j=0; j<LINE; j++) for (k=0; k<LINE; k++) tmp2[j][k] = (*cube)[face][j][k];

    for (k=0; k<LINE; k++) (*cube)[face][0][k] = tmp2[k][LINE-1];
    for (j=0; j<LINE; j++) (*cube)[face][j][0] = tmp2[0][LINE-1-j];
    for (k=0; k<LINE; k++) (*cube)[face][LINE-1][k] = tmp2[k][0];
    for (j=0; j<LINE; j++) (*cube)[face][j][LINE-1] = tmp2[LINE-1][LINE-1-j];
}

/**
 * Fonction qui effectue une rotation d'une face suite à un mouvement droit sur le Rubik's Cube
 * @param cube le rubik's cube
 * @param face la face qui subit la rotation
*/
void rotationFaceRight(RCube* cube, int face){
    int j, k;

    int tmp2[LINE][LINE];
    for (j=0; j<LINE; j++) for (int k=0; k<LINE; k++) tmp2[j][k] = (*cube)[face][j][k];

    for (k=0; k<LINE; k++) (*cube)[face][0][k] = tmp2[LINE-1-k][0];
    for (j=0; j<LINE; j++) (*cube)[face][j][0] = tmp2[LINE-1][j];
    for (k=0; k<LINE; k++) (*cube)[face][LINE-1][k] = tmp2[LINE-1-k][LINE-1];
    for (j=0; j<LINE; j++) (*cube)[face][j][LINE-1] = tmp2[0][j];
}



// Rotation gauche

/**
 * Fonction qui effectue une rotation gauche vers le haut sur le Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationLeftUp(RCube* cube, List* list){
    int j;

    int tmp[LINE];
    for (j=0; j<LINE; j++) tmp[j] = (*cube)[FRONT][j][0];

    for (j=0; j<LINE; j++) (*cube)[FRONT][j][0] = (*cube)[DOWN][j][0];
    for (j=0; j<LINE; j++) (*cube)[DOWN][j][0] = (*cube)[BACK][LINE-1-j][LINE-1];
    for (j=0; j<LINE; j++) (*cube)[BACK][LINE-1-j][LINE-1] = (*cube)[UP][j][0]; 
    for (j=0; j<LINE; j++) (*cube)[UP][j][0] = tmp[j];

    rotationFaceLeft(cube, LEFT);

    addNode(list, "L' ", *cube);
}

/**
 * Fonction qui effectue une rotation gauche vers le bas sur le Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationLeftDown(RCube* cube, List* list){
    int j;

    int tmp[LINE];
    for (j=0; j<LINE; j++) tmp[j] = (*cube)[FRONT][j][0];

    for (j=0; j<LINE; j++) (*cube)[FRONT][j][0] = (*cube)[UP][j][0];
    for (j=0; j<LINE; j++) (*cube)[UP][j][0] = (*cube)[BACK][LINE-1-j][LINE-1];
    for (j=0; j<LINE; j++) (*cube)[BACK][LINE-1-j][LINE-1] = (*cube)[DOWN][j][0]; 
    for (j=0; j<LINE; j++) (*cube)[DOWN][j][0] = tmp[j];

    rotationFaceRight(cube, LEFT);

    addNode(list, "L ", *cube);
}


// Rotation droite 

/**
 * Fonction qui effectue une rotation droite vers le haut sur le Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationRightUp(RCube* cube, List* list){
    int j;

    int tmp[LINE];
    for (j=0; j<LINE; j++) tmp[j] = (*cube)[FRONT][j][LINE-1];

    for (j=0; j<LINE; j++) (*cube)[FRONT][j][LINE-1] = (*cube)[DOWN][j][LINE-1];
    for (j=0; j<LINE; j++) (*cube)[DOWN][j][LINE-1] = (*cube)[BACK][LINE-1-j][0];
    for (j=0; j<LINE; j++) (*cube)[BACK][LINE-1-j][0] = (*cube)[UP][j][LINE-1];
    for (j=0; j<LINE; j++) (*cube)[UP][j][LINE-1] = tmp[j];

    rotationFaceRight(cube, RIGHT);

    addNode(list, "R ", *cube);
}

/**
 * Fonction qui effectue une rotation droite vers le bas sur le Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationRightDown(RCube* cube, List* list){
    int j;

    int tmp[LINE];
    for (j=0; j<LINE; j++) tmp[j] = (*cube)[FRONT][j][LINE-1];

    for (j=0; j<LINE; j++) (*cube)[FRONT][j][LINE-1] = (*cube)[UP][j][LINE-1];
    for (j=0; j<LINE; j++) (*cube)[UP][j][LINE-1] = (*cube)[BACK][LINE-1-j][0];
    for (j=0; j<LINE; j++) (*cube)[BACK][LINE-1-j][0] = (*cube)[DOWN][j][LINE-1];
    for (j=0; j<LINE; j++) (*cube)[DOWN][j][LINE-1] = tmp[j];

    rotationFaceLeft(cube, RIGHT);

    addNode(list, "R' ", *cube);
}


// Rotation dessus

/**
 * Fonction qui effectue une rotation sur le dessus vers la gauche du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationUpLeft(RCube* cube, List* list){
    int k;

    int tmp[LINE];  
    for (k=0; k<LINE; k++) tmp[k] = (*cube)[FRONT][0][k];

    for (k=0; k<LINE; k++) (*cube)[FRONT][0][k] = (*cube)[RIGHT][0][k];
    for (k=0; k<LINE; k++) (*cube)[RIGHT][0][k] = (*cube)[BACK][0][k];
    for (k=0; k<LINE; k++) (*cube)[BACK][0][k] = (*cube)[LEFT][0][k];
    for (k=0; k<LINE; k++) (*cube)[LEFT][0][k] = tmp[k];

    rotationFaceRight(cube, UP);

    addNode(list, "U ", *cube);
}

/**
 * Fonction qui effectue une rotation sur le dessus vers la droite du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationUpRight(RCube* cube, List* list){
    int k;

    int tmp[LINE];  
    for (k=0; k<LINE; k++) tmp[k] = (*cube)[FRONT][0][k];

    for (k=0; k<LINE; k++) (*cube)[FRONT][0][k] = (*cube)[LEFT][0][k];
    for (k=0; k<LINE; k++) (*cube)[LEFT][0][k] = (*cube)[BACK][0][k];
    for (k=0; k<LINE; k++) (*cube)[BACK][0][k] = (*cube)[RIGHT][0][k];
    for (k=0; k<LINE; k++) (*cube)[RIGHT][0][k] = tmp[k];

    rotationFaceLeft(cube, UP);

    addNode(list, "U' ", *cube);
}


// Rotation dessous

/**
 * Fonction qui effectue une rotation sur le dessous vers la gauche du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationDownLeft(RCube* cube, List* list){
    int k;

    int tmp[LINE];  
    for (k=0; k<LINE; k++) tmp[k] = (*cube)[FRONT][LINE-1][k];

    for (k=0; k<LINE; k++) (*cube)[FRONT][LINE-1][k] = (*cube)[RIGHT][LINE-1][k];
    for (k=0; k<LINE; k++) (*cube)[RIGHT][LINE-1][k] = (*cube)[BACK][LINE-1][k];
    for (k=0; k<LINE; k++) (*cube)[BACK][LINE-1][k] = (*cube)[LEFT][LINE-1][k];
    for (k=0; k<LINE; k++) (*cube)[LEFT][LINE-1][k] = tmp[k];

    rotationFaceLeft(cube, DOWN);

    addNode(list, "D' ", *cube);
}

/**
 * Fonction qui effectue une rotation sur le dessous vers la droite du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationDownRight(RCube* cube, List* list){
    int k;

    int tmp[LINE];  
    for (int k=0; k<LINE; k++) tmp[k] = (*cube)[FRONT][LINE-1][k];

    for (k=0; k<LINE; k++) (*cube)[FRONT][LINE-1][k] = (*cube)[LEFT][LINE-1][k];
    for (k=0; k<LINE; k++) (*cube)[LEFT][LINE-1][k] = (*cube)[BACK][LINE-1][k];
    for (k=0; k<LINE; k++) (*cube)[BACK][LINE-1][k] = (*cube)[RIGHT][LINE-1][k];
    for (k=0; k<LINE; k++) (*cube)[RIGHT][LINE-1][k] = tmp[k];

    rotationFaceRight(cube, DOWN);

    addNode(list, "D ", *cube);
}


// Rotation devant

/**
 * Fonction qui effectue une rotation sur le devant vers la gauche du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationFrontLeft(RCube* cube, List* list){
    int j, k;

    int tmp[LINE];  
    for (k=0; k<LINE; k++) tmp[k] = (*cube)[UP][LINE-1][k];

    for (k=0; k<LINE; k++) (*cube)[UP][LINE-1][k] = (*cube)[RIGHT][k][0];
    for (j=0; j<LINE; j++) (*cube)[RIGHT][j][0] = (*cube)[DOWN][0][LINE-1-j];
    for (k=0; k<LINE; k++) (*cube)[DOWN][0][k] = (*cube)[LEFT][k][LINE-1];
    for (j=0; j<LINE; j++) (*cube)[LEFT][j][LINE-1] = tmp[LINE-1-j];

    rotationFaceLeft(cube, FRONT);

    addNode(list, "F' ", *cube);
}

/**
 * Fonction qui effectue une rotation sur le devant vers la droite du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationFrontRight(RCube* cube, List* list){
    int j, k;

    int tmp[LINE];  
    for (k=0; k<LINE; k++) tmp[k] = (*cube)[UP][LINE-1][k];

    for (k=0; k<LINE; k++) (*cube)[UP][LINE-1][k] = (*cube)[LEFT][LINE-1-k][LINE-1];
    for (j=0; j<LINE; j++) (*cube)[LEFT][j][LINE-1] = (*cube)[DOWN][0][j];
    for (k=0; k<LINE; k++) (*cube)[DOWN][0][k] = (*cube)[RIGHT][LINE-1-k][0];
    for (j=0; j<LINE; j++) (*cube)[RIGHT][j][0] = tmp[j];

    rotationFaceRight(cube, FRONT);

    addNode(list, "F ", *cube);
}


// Rotation arrière

/**
 * Fonction qui effectue une rotation sur l'arrière vers la gauche du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationBackLeft(RCube* cube, List* list){
    int j, k;

    int tmp[LINE];  
    for (k=0; k<LINE; k++) tmp[k] = (*cube)[UP][0][k];

    for (k=0; k<LINE; k++) (*cube)[UP][0][k] = (*cube)[RIGHT][k][LINE-1];
    for (j=0; j<LINE; j++) (*cube)[RIGHT][j][LINE-1] = (*cube)[DOWN][LINE-1][LINE-1-j];
    for (k=0; k<LINE; k++) (*cube)[DOWN][LINE-1][k] = (*cube)[LEFT][k][0];
    for (j=0; j<LINE; j++) (*cube)[LEFT][j][0] = tmp[LINE-1-j];

    rotationFaceRight(cube, BACK);

    addNode(list, "B ", *cube);
}

/**
 * Fonction qui effectue une rotation sur l'arrière vers la droite du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationBackRight(RCube* cube, List* list){
    int j, k;

    int tmp[LINE];  
    for (k=0; k<LINE; k++) tmp[k] = (*cube)[UP][0][k];

    for (k=0; k<LINE; k++) (*cube)[UP][0][k] = (*cube)[LEFT][LINE-1-k][0];
    for (j=0; j<LINE; j++) (*cube)[LEFT][j][0] = (*cube)[DOWN][LINE-1][j];
    for (k=0; k<LINE; k++) (*cube)[DOWN][LINE-1][k] = (*cube)[RIGHT][LINE-1-k][LINE-1];
    for (j=0; j<LINE; j++) (*cube)[RIGHT][j][LINE-1] = tmp[j];

    rotationFaceLeft(cube, BACK);

    addNode(list, "B' ", *cube);
}



// Mélange du Rubik's Cube

/**
 * Fonction qui mélange le Rubik's Cube pour en obtenir un aléatoire
 * @param cube le rubik's cube
 * @param rotations le nombre de rotations
*/
List* randomRCube(RCube* cube, int rotations){
    List* listRandom = newList(*cube);
    srand(time(NULL));
    for (int i=0; i<rotations; i++){
        int r = rand() % 5;

        if (r == 0) rotationLeftUp(cube, listRandom);
        if (r == 1) rotationRightUp(cube, listRandom);
        if (r == 2) rotationUpLeft(cube, listRandom);
        if (r == 3) rotationDownLeft(cube, listRandom);
        if (r == 4) rotationFrontLeft(cube, listRandom);
    }

    return listRandom;
}


