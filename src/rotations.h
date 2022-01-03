/**
 * Projet Rubik's Cube 
 * - Module contenant les rotations -
 * @author Nicolas Deronsart
*/

#include "structures.h"



// Rotation des faces

/**
 * Fonction qui effectue une rotation d'une face suite à un mouvement gauche sur le Rubik's Cube
 * @param cube le rubik's cube
 * @param face la face qui subit la rotation
*/
void rotationFaceLeft(RCube*, int);

/**
 * Fonction qui effectue une rotation d'une face suite à un mouvement droit sur le Rubik's Cube
 * @param cube le rubik's cube
 * @param face la face qui subit la rotation
*/
void rotationFaceRight(RCube*, int);



// Rotation gauche

/**
 * Fonction qui effectue une rotation gauche vers le haut sur le Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationLeftUp(RCube*, List*);

/**
 * Fonction qui effectue une rotation gauche vers le bas sur le Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationLeftDown(RCube*, List*);


// Rotation droite 

/**
 * Fonction qui effectue une rotation droite vers le haut sur le Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationRightUp(RCube*, List*);

/**
 * Fonction qui effectue une rotation droite vers le bas sur le Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationRightDown(RCube*, List*);


// Rotation dessus

/**
 * Fonction qui effectue une rotation sur le dessus vers la gauche du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationUpLeft(RCube*, List*);

/**
 * Fonction qui effectue une rotation sur le dessus vers la droite du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationUpRight(RCube*, List*);


// Rotation dessous

/**
 * Fonction qui effectue une rotation sur le dessous vers la gauche du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationDownLeft(RCube*, List*);

/**
 * Fonction qui effectue une rotation sur le dessous vers la droite du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationDownRight(RCube*, List*);


// Rotation devant

/**
 * Fonction qui effectue une rotation sur le devant vers la gauche du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationFrontLeft(RCube*, List*);

/**
 * Fonction qui effectue une rotation sur le devant vers la droite du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationFrontRight(RCube*, List*);


// Rotation arrière

/**
 * Fonction qui effectue une rotation sur l'arrière vers la gauche du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationBackLeft(RCube*, List*);

/**
 * Fonction qui effectue une rotation sur l'arrière vers la droite du Rubik's Cube
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void rotationBackRight(RCube*, List*);



// Mélange du Rubik's Cube

/**
 * Fonction qui mélange le Rubik's Cube pour en obtenir un aléatoire
 * @param cube le rubik's cube
 * @param rotations le nombre de rotations
*/
List* randomRCube(RCube*, int);


