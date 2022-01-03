/**
 * Projet Rubik's Cube - C Avancé
 * - Module principal -
 * @author Nicolas Deronsart
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "rotations.h"



// Résolution du Rubik's Cube 2*2


// 1ère étape : la première face

/**
 * Stocke la position du coin recherché
 * @param cube le rubik's cube
 * @param color1 la 1ère couleur du coin
 * @param color2 la 2ème couleur du coin
 * @param color3 la 3ème couleur du coin
 * @param face l'entier où stocker le numéro de la face où se trouve la couleur 1
 * @param line l'entier où stocker le numéro de la ligne où se trouve la couleur 1
 * @param col l'entier où stocker le numéro de la colonne où se trouve la couleur 1
*/
void cornerPosition(RCube* cube, int color1, int color2, int color3, int* face, int* line, int* col){

    // Face FRONT
    if (((*cube)[FRONT][0][0]==color1) && ((*cube)[UP][1][0]==color2) && ((*cube)[LEFT][0][1]==color3)){ *face=FRONT; *line=0; *col=0; return;}
    if (((*cube)[FRONT][0][1]==color1) && ((*cube)[RIGHT][0][0]==color2) && ((*cube)[UP][1][1]==color3)){ *face=FRONT; *line=0; *col=1; return;}
    if (((*cube)[FRONT][1][0]==color1) && ((*cube)[LEFT][1][1]==color2) && ((*cube)[DOWN][0][0]==color3)){ *face=FRONT; *line=1; *col=0; return;}
    if (((*cube)[FRONT][1][1]==color1) && ((*cube)[DOWN][0][1]==color2) && ((*cube)[RIGHT][1][0]==color3)){ *face=FRONT; *line=1; *col=1; return;}

    // Face DOWN
    if (((*cube)[DOWN][0][0]==color1) && ((*cube)[FRONT][1][0]==color2) && ((*cube)[LEFT][1][1]==color3)){ *face=DOWN; *line=0; *col=0; return;}
    if (((*cube)[DOWN][0][1]==color1) && ((*cube)[RIGHT][1][0]==color2) && ((*cube)[FRONT][1][1]==color3)){ *face=DOWN; *line=0; *col=1; return;}
    if (((*cube)[DOWN][1][0]==color1) && ((*cube)[LEFT][1][0]==color2) && ((*cube)[BACK][1][1]==color3)){ *face=DOWN; *line=1; *col=0; return;}
    if (((*cube)[DOWN][1][1]==color1) && ((*cube)[BACK][1][0]==color2) && ((*cube)[RIGHT][1][1]==color3)){ *face=DOWN; *line=1; *col=1; return;}

    // Face BACK 
    if (((*cube)[BACK][0][0]==color1) && ((*cube)[UP][0][1]==color2) && ((*cube)[RIGHT][0][1]==color3)){ *face=BACK; *line=0; *col=0; return;}
    if (((*cube)[BACK][0][1]==color1) && ((*cube)[LEFT][0][0]==color2) && ((*cube)[UP][0][0]==color3)){ *face=BACK; *line=0; *col=1; return;}
    if (((*cube)[BACK][1][0]==color1) && ((*cube)[RIGHT][1][1]==color2) && ((*cube)[DOWN][1][1]==color3)){ *face=BACK; *line=1; *col=0; return;}
    if (((*cube)[BACK][1][1]==color1) && ((*cube)[DOWN][1][0]==color2) && ((*cube)[LEFT][1][0]==color3)){ *face=BACK; *line=1; *col=1; return;}

    // Face UP 
    if (((*cube)[UP][0][0]==color1) && ((*cube)[BACK][0][1]==color2) && ((*cube)[LEFT][0][0]==color3)){ *face=UP; *line=0; *col=0; return;}
    if (((*cube)[UP][0][1]==color1) && ((*cube)[RIGHT][0][1]==color2) && ((*cube)[BACK][0][0]==color3)){ *face=UP; *line=0; *col=1; return;}
    if (((*cube)[UP][1][0]==color1) && ((*cube)[LEFT][0][1]==color2) && ((*cube)[FRONT][0][0]==color3)){ *face=UP; *line=1; *col=0; return;}
    if (((*cube)[UP][1][1]==color1) && ((*cube)[FRONT][0][1]==color2) && ((*cube)[RIGHT][0][0]==color3)){ *face=UP; *line=1; *col=1; return;}

    // Face LEFT 
    if (((*cube)[LEFT][0][0]==color1) && ((*cube)[UP][0][0]==color2) && ((*cube)[BACK][0][1]==color3)){ *face=LEFT; *line=0; *col=0; return;}
    if (((*cube)[LEFT][0][1]==color1) && ((*cube)[FRONT][0][0]==color2) && ((*cube)[UP][1][0]==color3)){ *face=LEFT; *line=0; *col=1; return;}
    if (((*cube)[LEFT][1][0]==color1) && ((*cube)[BACK][1][1]==color2) && ((*cube)[DOWN][1][0]==color3)){ *face=LEFT; *line=1; *col=0; return;}
    if (((*cube)[LEFT][1][1]==color1) && ((*cube)[DOWN][0][0]==color2) && ((*cube)[FRONT][1][0]==color3)){ *face=LEFT; *line=1; *col=1; return;}

    // Face RIGHT 
    if (((*cube)[RIGHT][0][0]==color1) && ((*cube)[UP][1][1]==color2) && ((*cube)[FRONT][0][1]==color3)){ *face=RIGHT; *line=0; *col=0; return;}
    if (((*cube)[RIGHT][0][1]==color1) && ((*cube)[BACK][0][0]==color2) && ((*cube)[UP][0][1]==color3)){ *face=RIGHT; *line=0; *col=1; return;}
    if (((*cube)[RIGHT][1][0]==color1) && ((*cube)[FRONT][1][1]==color2) && ((*cube)[DOWN][0][1]==color3)){ *face=RIGHT; *line=1; *col=0; return;}
    if (((*cube)[RIGHT][1][1]==color1) && ((*cube)[DOWN][1][1]==color2) && ((*cube)[BACK][1][0]==color3)){ *face=RIGHT; *line=1; *col=1; return;}

}

/**
 * Fonction qui résout la première face, la blanche, du Rubik's Cube 2*2
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void firstFace(RCube* cube, List* list){
    int face, line, col;
    
    // Placer le premier coin WHITE, BLUE, ORANGE
    cornerPosition(cube, WHITE, BLUE, ORANGE, &face, &line, &col);
    while (!((face == WHITE) && (line == 0) && (col == 0))){
        if (face == FRONT){
            if (line == 0){ if (col == 1) rotationFrontLeft(cube, list); rotationLeftUp(cube, list);}
            else if (line == 1){ if (col == 0) rotationFrontRight(cube, list); else if (col == 1){ rotationFrontLeft(cube, list); rotationFrontLeft(cube, list);} rotationLeftUp(cube, list);}
        }
        if (face == DOWN){
            if (line == 0){ rotationLeftUp(cube, list); if (col == 1) rotationFrontLeft(cube, list); rotationLeftUp(cube, list);}
            else if (line == 1){ if (col == 0){ rotationLeftUp(cube, list); rotationFrontRight(cube, list);} else if (col == 1){ rotationRightUp(cube, list); rotationFrontLeft(cube, list); rotationFrontLeft(cube, list);} rotationLeftUp(cube, list);}
        }
        if (face == BACK){
            if (line == 0){ if (col == 0) rotationBackLeft(cube, list); rotationLeftDown(cube, list); }
            else if (line == 1){ if (col == 0){ rotationBackLeft(cube, list); rotationBackLeft(cube, list);} else if (col == 1){ rotationBackRight(cube, list);} rotationLeftDown(cube, list);}
        }
        if (face == UP){ rotationUpRight(cube, list); if ((line == 1) && (col == 1)) rotationUpRight(cube, list);}
        if (face == LEFT){
            if (line == 0){ rotationUpRight(cube, list); if (col == 1) rotationFrontLeft(cube, list); rotationLeftUp(cube, list);}
            else if (line == 1){ rotationDownRight(cube, list); rotationFrontRight(cube, list); if (col == 1) rotationFrontRight(cube, list); rotationLeftUp(cube, list);}
        }
        if (face == RIGHT){
            if (line == 0){ rotationUpLeft(cube, list); if (col == 1) rotationFrontLeft(cube, list); rotationLeftUp(cube, list);}
            else if (line == 1){ rotationDownLeft(cube, list); rotationFrontRight(cube, list); if (col == 1) rotationFrontRight(cube, list); rotationLeftUp(cube, list);}
        }
        cornerPosition(cube, WHITE, BLUE, ORANGE, &face, &line, &col);
    }

    // Placer le deuxième coin WHITE, RED, BLUE  
    cornerPosition(cube, WHITE, RED, BLUE, &face, &line, &col);
    while (!((face == WHITE) && (line == 0) && (col == 1))){
        if (face == FRONT){
            if (line == 0){ if (col == 0) rotationFrontRight(cube, list); rotationRightUp(cube, list);}
            else if (line == 1){ rotationFrontLeft(cube, list); if (col == 0) rotationFrontLeft(cube, list); rotationRightUp(cube, list);}
        }
        if (face == DOWN){
            if (line == 0){ if (col == 0) rotationDownRight(cube, list); rotationRightUp(cube, list); rotationRightUp(cube, list);}
            else if (line == 1){ rotationDownLeft(cube, list); if (col == 0) rotationDownLeft(cube, list); rotationRightUp(cube, list); rotationRightUp(cube, list);}
        }
        if (face == BACK){ 
            if (line == 0){ rotationRightUp(cube, list); rotationRightUp(cube, list); rotationFrontLeft(cube, list); rotationRightUp(cube, list);}
            else if (line == 1){ if (col == 0) rotationRightDown(cube, list); else if (col == 1){ rotationDownLeft(cube, list); rotationDownLeft(cube, list); rotationFrontLeft(cube, list); rotationRightUp(cube, list);}}
        }
        if (face == UP){
            if (col == 0){ rotationFrontLeft(cube, list); rotationDownRight(cube, list);}
            else if (col == 1){ rotationFrontRight(cube, list); rotationDownLeft(cube, list); rotationFrontLeft(cube, list);}
            rotationFrontLeft(cube, list); rotationRightUp(cube, list);
        }
        if (face == LEFT){
            if (line == 0){ rotationFrontRight(cube, list); rotationRightDown(cube, list); rotationFrontLeft(cube, list); rotationRightUp(cube, list);}
            else if (line == 1){ rotationDownRight(cube, list); rotationFrontLeft(cube, list); if (col == 0) rotationFrontLeft(cube, list); rotationRightUp(cube, list);}
        } 
        if (face == RIGHT){
            if (line == 0){ rotationRightDown(cube, list); if (col == 1) rotationRightDown(cube, list); rotationDownLeft(cube, list); rotationFrontLeft(cube, list); rotationFrontLeft(cube, list); rotationRightUp(cube, list);}
            else if (line == 1){ rotationDownLeft(cube, list); rotationFrontLeft(cube, list); if (col == 0) rotationFrontLeft(cube, list); rotationRightUp(cube, list);} 
        }
        cornerPosition(cube, WHITE, RED, BLUE, &face, &line, &col);
    }

    // Placer le 3ème coin WHITE, ORANGE, GREEN
    cornerPosition(cube, WHITE, ORANGE, GREEN, &face, &line, &col);
    while (!((face == WHITE) && (line == 1) && (col == 0))){
        if (face == FRONT){
            if (line == 0){ if (col == 0){ rotationFrontLeft(cube, list); rotationFrontLeft(cube, list);} else if (col == 1) rotationFrontRight(cube, list); rotationDownLeft(cube, list); rotationFrontRight(cube, list);}
            else if (line == 1){ if (col == 0) rotationFrontLeft(cube, list); rotationDownLeft(cube, list); rotationFrontRight(cube, list);}
        }
        if (face == DOWN){
            if (line == 0){ if (col == 0) rotationDownRight(cube, list); rotationFrontLeft(cube, list); rotationFrontLeft(cube, list);}
            else if (line == 1){ rotationDownLeft(cube, list); if (col == 0) rotationDownLeft(cube, list); rotationFrontLeft(cube, list); rotationFrontLeft(cube, list);}
        }
        if (face == BACK){
            rotationDownLeft(cube, list);
            if (col == 0) { rotationDownLeft(cube, list); rotationFrontLeft(cube, list);  rotationDownLeft(cube, list); rotationFrontRight(cube, list);}
            else if (col == 1) rotationFrontLeft(cube, list);
        }
        if (face == UP){ rotationFrontRight(cube, list); rotationDownLeft(cube, list); rotationFrontLeft(cube, list); rotationDownLeft(cube, list); rotationFrontRight(cube, list);}
        if (face == LEFT){
            if (line == 0){ rotationFrontLeft(cube, list); rotationDownRight(cube, list); rotationFrontRight(cube, list);}
            else if (line == 1){ if (col == 0){ rotationDownRight(cube, list); rotationFrontLeft(cube, list); rotationDownLeft(cube, list);}}
            rotationFrontRight(cube, list);
        }
        if (face == RIGHT){
            if (line == 0) rotationFrontLeft(cube, list);
            else if (line == 1){ rotationDownLeft(cube, list); if (col == 0) rotationFrontLeft(cube, list); rotationDownLeft(cube, list); rotationFrontRight(cube, list);}
        }
        cornerPosition(cube, WHITE, ORANGE, GREEN, &face, &line, &col);
    }

    // Placer le dernier coin WHITE, GREEN, RED
    cornerPosition(cube, WHITE, GREEN, RED, &face, &line, &col);
    if (!((face == WHITE) && (line == 1) && (col == 1))){
        // Tout d'abord placer le coin en [FRONT][1][1] ou [DOWN][0][1] ou [RIGHT][1][0]
        if (face == FRONT){
            if (line == 0){ rotationRightDown(cube, list); rotationDownRight(cube, list); rotationRightUp(cube, list);}
            else if (line == 1) if (col == 0) rotationDownRight(cube, list);
        }
        if (face == DOWN){
            if (line == 0){ if (col == 0) rotationDownRight(cube, list);}
            else if (line == 1){ if (col == 0) rotationDownLeft(cube, list); rotationDownLeft(cube, list);}
        }
        if (face == BACK){ if (line == 1){ rotationDownLeft(cube, list); if (col == 1) rotationDownLeft(cube, list);}}
        if (face == LEFT){ if (col == 0){ rotationDownLeft(cube, list); rotationDownLeft(cube, list);} else if (col == 1) rotationDownRight(cube, list);}
        if (face == RIGHT){
            if (line == 0){ if (col == 0){ rotationFrontRight(cube, list); rotationDownLeft(cube, list); rotationFrontLeft(cube, list);}}
            else if (line == 1){ if (col == 1) rotationDownLeft(cube, list);}
        }

        // Puis appliquer les algorithmes de résolution pour finir la face
        cornerPosition(cube, WHITE, GREEN, RED, &face, &line, &col);
        if (face == FRONT){ rotationFrontRight(cube, list); rotationDownRight(cube, list); rotationFrontLeft(cube, list);}
        else if (face == RIGHT){ rotationRightDown(cube, list); rotationDownLeft(cube, list); rotationRightUp(cube, list);}
        else if (face == DOWN){ rotationRightDown(cube, list); rotationDownRight(cube, list); rotationDownRight(cube, list); rotationRightUp(cube, list); rotationDownRight(cube, list); rotationRightDown(cube, list); rotationDownLeft(cube, list); rotationRightUp(cube, list);}
        cornerPosition(cube, WHITE, GREEN, RED, &face, &line, &col);
    }
}


// 2ème étape : la deuxième face

/**
 * Indique le nombre d'éléments bien positionnés sur une face
 * @param cube le rubik's cube
 * @param face la face sur laquelle on compte
 * @return le nombre d'éléments
*/
int numberCorrectIn(RCube* cube, int face){
    int number = 0;

    if ((*cube)[face][0][0] == face) number++;
    if ((*cube)[face][0][1] == face) number++;
    if ((*cube)[face][1][0] == face) number++;
    if ((*cube)[face][1][1] == face) number++;

    return number;
}

/**
 * Fonction qui résout la deuxième face, la jaune, du Rubik's Cube 2*2
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void secondFace(RCube* cube, List* list){
    // On observe les différents cas possibles pour appliquer les algorithmes
    // On compte le nombre de case jaunes bien placées
    int numberCorrect = numberCorrectIn(cube, YELLOW);

    if (numberCorrect == 0){
        while ((*cube)[FRONT][1][0] != YELLOW) rotationDownLeft(cube, list);
        if ((*cube)[FRONT][1][1] == YELLOW){
            if ((*cube)[BACK][1][1] == YELLOW){
                rotationRightUp(cube, list); rotationRightUp(cube, list); rotationDownLeft(cube, list); rotationDownLeft(cube, list); rotationRightUp(cube, list);
                rotationDownLeft(cube, list); rotationDownLeft(cube, list); rotationRightUp(cube, list); rotationRightUp(cube, list);
            }
            else{
                rotationDownLeft(cube, list); rotationBackLeft(cube, list); rotationRightUp(cube, list); rotationDownRight(cube, list); rotationRightDown(cube, list); rotationDownLeft(cube, list);
                rotationRightUp(cube, list); rotationDownRight(cube, list); rotationRightDown(cube, list); rotationDownLeft(cube, list); rotationBackRight(cube, list);
            }
        }
        else{
            rotationDownLeft(cube, list); rotationDownLeft(cube, list); rotationBackLeft(cube, list); rotationRightUp(cube, list); rotationDownRight(cube, list); rotationRightDown(cube, list); 
            rotationDownLeft(cube, list); rotationRightUp(cube, list); rotationDownRight(cube, list); rotationRightDown(cube, list); rotationDownLeft(cube, list); rotationBackRight(cube, list);
        }
    }
    else if (numberCorrect == 1){
        while ((*cube)[YELLOW][0][0] != YELLOW) rotationDownLeft(cube, list);
        if ((*cube)[FRONT][1][1] == YELLOW){
            rotationRightDown(cube, list); rotationDownLeft(cube, list); rotationRightUp(cube, list); rotationDownLeft(cube, list); 
            rotationRightDown(cube, list); rotationDownRight(cube, list); rotationDownRight(cube, list); rotationRightUp(cube, list);
        }
        else{
            rotationDownRight(cube, list); rotationLeftDown(cube, list); rotationDownRight(cube, list); rotationLeftUp(cube, list); rotationDownRight(cube, list); 
            rotationLeftDown(cube, list); rotationDownRight(cube, list); rotationDownRight(cube, list); rotationLeftUp(cube, list);
        }
    }
    else if (numberCorrect == 2){
        while ((*cube)[YELLOW][1][1] != YELLOW) rotationDownLeft(cube, list); 
        if ((*cube)[YELLOW][1][0] == YELLOW) rotationDownLeft(cube, list);
        if ((*cube)[YELLOW][0][1] == YELLOW){
            if ((*cube)[FRONT][1][0] == YELLOW){
                rotationRightUp(cube, list); rotationDownRight(cube, list); rotationRightDown(cube, list); rotationDownLeft(cube, list);
                rotationRightDown(cube, list); rotationBackLeft(cube, list); rotationRightUp(cube, list); rotationBackRight(cube, list);
            }
            else{ rotationBackLeft(cube, list); rotationRightUp(cube, list); rotationDownRight(cube, list); rotationRightDown(cube, list); rotationDownLeft(cube, list); rotationBackRight(cube, list);}
        }
        else{
            if ((*cube)[RIGHT][1][0] != YELLOW){ rotationDownLeft(cube, list); rotationDownLeft(cube, list);}
            rotationBackLeft(cube, list); rotationRightUp(cube, list); rotationDownLeft(cube, list); rotationRightDown(cube, list); rotationDownLeft(cube, list);
            rotationRightUp(cube, list); rotationDownRight(cube, list); rotationRightDown(cube, list); rotationBackRight(cube, list);
        }
    }
}


// 3ème et dernière étape : permuter les dernières pièces

/**
 * Fonction qui indique si le Rubik's Cube est résolu
 * @param cube le rubik's cube
 * @return 1 si il est résolu, 0 sinon
*/
int solved(RCube* cube){
    int i, j, color, k;

    for (i=0; i<6; i++){
        for (j=0; j<LINE; j++){
            color = (*cube)[i][j][0];
            for (k=0; k<LINE; k++) if ((*cube)[i][j][k] != color) return 0;
        }
    }
    return 1;
}

/**
 * Indique la face dans la ligne basse du cube contenant 2 pièces de même couleur côte à côte
 * @param cube le rubik's cube
 * @return la face où se trouve les pièces côte à côte, -1 si il n'y en a pas
*/
int correct2Pieces(RCube* cube){
    for (int i=0; i<6; i++){
        if (((*cube)[LEFT][1][0] == i) && ((*cube)[LEFT][1][1] == i)) return LEFT;
        if (((*cube)[FRONT][1][0] == i) && ((*cube)[FRONT][1][1] == i)) return FRONT;
        if (((*cube)[RIGHT][1][0] == i) && ((*cube)[RIGHT][1][1] == i)) return RIGHT;
        if (((*cube)[BACK][1][0] == i) && ((*cube)[BACK][1][1] == i)) return BACK;
    }
    return -1;
}

/**
 * Fonction qui effectue l'algorithme nécessaire pour effectuer la dernière étape de la résolution
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void algoLastStep(RCube* cube, List* list){
    rotationRightDown(cube, list); rotationBackLeft(cube, list); rotationRightDown(cube, list); rotationFrontRight(cube, list); rotationFrontRight(cube, list);
    rotationRightUp(cube, list); rotationBackRight(cube, list); rotationRightDown(cube, list); rotationFrontRight(cube, list); 
    rotationFrontRight(cube, list); rotationRightUp(cube, list); rotationRightUp(cube, list); rotationDownLeft(cube, list);
}

/**
 * Fonction qui permute les dernières pièces du Rubik's Cube 2*2 mal placées à l'aide d'algorithmes 
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void permutingLastPieces(RCube* cube, List* list){
    if (solved(cube)) return;

    // On cherche 2 pièces bien placées dans la ligne basse du Rubik's Cube
    int face = correct2Pieces(cube);

    if (face == -1){
        algoLastStep(cube, list);
        face = correct2Pieces(cube);
    }

    // On place ces 2 pièces sur la bonne face;
    int color = ((*cube)[face][1][0]);
    while (numberCorrectIn(cube, color) != 4) rotationDownLeft(cube, list);
    if (solved(cube)) return;

    // On termine la résolution du cube
    if (color != FRONT){ while ((*cube)[FRONT][0][0] != color){ rotationUpLeft(cube, list); rotationDownLeft(cube, list);}}

    algoLastStep(cube, list);
}


// Résolution

/**
 * Fonction qui résout le Rubik's Cube 2*2
 * @param cube le rubik's cube
 * @param list la liste des rotations associée au cube
*/
void solveRCube(RCube* cube, List* list){
    if (solved(cube)) return;

    firstFace(cube, list);
    secondFace(cube, list);
    permutingLastPieces(cube, list);

    if (!solved(cube)){ fprintf(stderr, "Error\n"); printPatternRCube(*cube, stdout); exit(1);}
}



// Fonction principale permettant de lancer l'interface
int main(void){
    int choice, stop, error, choice2, rotations, iteration, average, i;
    FILE* fileStateRubiksCube = fopen("txts/StateRubiksCube.txt", "w");
    FILE* fileDetails = fopen("txts/Details.txt", "w");
    FILE* fileRotations = fopen("txts/Rotations.txt", "w");

    printf("##################################################\n");
    printf("##           Rubik's Cube 2*2 Solver            ##\n");
    printf("##################################################\n\n");
    printf("Bienvenue dans ce résolveur de Rubik's Cube 2*2\n\n");
    
    printf("Que souhaitez-vous faire ?\n");
    printf("1- Manipulation libre d'un Rubik's Cube\n");
    printf("2- Mélange aléatoire d'un Rubik's Cube\n");
    printf("3- Obtenir la moyenne du nombre de coups pour résoudre un Rubik's Cube 2*2\n");
    printf("0- Quitter\n");
    printf("Votre choix : ");

    choice = -1;
    while (choice<0 || choice>3) scanf("%d", &choice);

    RCube* cube = malloc(sizeof(RCube));
    createRCube(cube);
    List* list = newList(*cube);
    while (choice != 0){
        printf("\n--------------------\n\n");
        if (choice == 1){
            createRCube(cube);
            deleteList(list);
            list = newList(*cube);
            printf("Voici le cube créé :\n\n");
            printPatternRCube(*cube, stdout);

            stop = 0;
            while (!stop){
                printf("\n- Rotations possibles : F, F', R, R', U, U', L, L', D, D', B, B'\n");
                printf("- Pour arrêter choisir 0\n");
                printf("- Pour sauvegarder l'état choisir 1\n");
                printf("Quelle rotation voulez vous effectuer ? ");
                error = 1;
                while (error){
                    char* rotation = malloc(sizeof(char)*2);
                    scanf("%s", rotation);
                    error = 0;
                    if (strcmp(rotation, "F") == 0) rotationFrontRight(cube, list);
                    else if (strcmp(rotation, "F'") == 0) rotationFrontLeft(cube, list);
                    else if (strcmp(rotation, "R") == 0) rotationRightUp(cube, list);
                    else if (strcmp(rotation, "R'") == 0) rotationRightDown(cube, list);
                    else if (strcmp(rotation, "U") == 0) rotationUpLeft(cube, list);
                    else if (strcmp(rotation, "U'") == 0) rotationUpRight(cube, list);
                    else if (strcmp(rotation, "L") == 0) rotationLeftDown(cube, list);
                    else if (strcmp(rotation, "L'") == 0) rotationLeftUp(cube, list);
                    else if (strcmp(rotation, "D") == 0) rotationDownRight(cube, list);
                    else if (strcmp(rotation, "D'") == 0) rotationDownLeft(cube, list);
                    else if (strcmp(rotation, "B") == 0) rotationBackLeft(cube, list);
                    else if (strcmp(rotation, "B'") == 0) rotationBackRight(cube, list);
                    else if (strcmp(rotation, "0") == 0) stop = 1;
                    else if (strcmp(rotation, "1") == 0){
                        printPatternRCube(*cube, fileStateRubiksCube);
                        printf("\tL'état du Rubik's Cube a été sauvegardé dans le fichier StateRubiksCube.txt\n");
                    }
                    else{ 
                        printf("\nEntrée invalide...\n"); 
                        error = 1;
                    }
                    free(rotation);
                    rotation = NULL;
                }

                if (!stop){
                    printf("\nNouvel état du cube :\n\n");
                    printPatternRCube(*cube, stdout);
                }
            }

            choice2 = 0;
            printf("Voulez-vous essayer le programme sur ce mélange ? (1 = Oui / 0 = Non) ");
            scanf("%d", &choice2);
            if (choice2 == 1){
                deleteList(list);
                list = newList(*cube);
                printf("\n...Résolution...\n");
                solveRCube(cube, list);
                printf("\nRésolution effectuée en %d rotations\n", list->len-1);
                printf("Etat final du Rubik's Cube :\n\n");
                printPatternRCube(*cube, stdout);

                choice2 = 0;
                printf("Voulez-vous voir les détails de la résolution du cube ? (1 = Oui / 0 = Non) ");
                scanf("%d", &choice2);
                if (choice2 == 1){
                    choice2 = -1;
                    printf("\tIci ou dans un fichier ? (1 = Ici / 0 = Fichier) ");
                    while (choice2<0 || choice2>1) scanf("%d", &choice2);
                    if (choice2 == 1) printDetail(list, stdout);
                    else{
                        printDetail(list, fileDetails);
                        printf("\tLes détails de la résolution ont été sauvegardés dans le fichier Details.txt\n");
                    }
                }

                choice2 = 0;
                printf("Voulez-vous voir les rotations nécessaires pour la résolution du cube ? (1 = Oui / 0 = Non) ");
                scanf("%d", &choice2);
                if (choice2 == 1){
                    choice2 = -1;
                    printf("\tIci ou dans un fichier ? (1 = Ici / 0 = Fichier) ");
                    while (choice2<0 || choice2>1) scanf("%d", &choice2);
                    if (choice2 == 1) printRotations(list, stdout);
                    else{
                        printRotations(list, fileRotations);
                        printf("\tLes rotations nécessaires pour la résolution ont été sauvegardé dans le fichier Rotations.txt\n");
                    }
                }
            }
        }
        else if (choice == 2){
            createRCube(cube);
            deleteList(list);
            list = newList(*cube);

            rotations = 0;
            printf("Combien de rotations voulez-vous effectuer sur le cube ? ");
            while (rotations<=0) scanf("%d", &rotations);

            randomRCube(cube, rotations);
            addNode(list, "Random ", *cube);
            printf("\nVoici le cube mélangé par %d rotations :\n\n", rotations);
            printPatternRCube(*cube, stdout);

            choice2 = 0;
            printf("Voulez-vous sauvegarder l'état de ce cube ? (1 = Oui / 0 = Non) ");
            scanf("%d", &choice2);
            if (choice2 == 1){
                printPatternRCube(*cube, fileStateRubiksCube);
                printf("\tL'état du Rubik's Cube a été sauvegardé dans le fichier StateRubiksCube.txt\n");
            }

            printf("\n...Résolution...\n");
            solveRCube(cube, list);
            printf("\nRésolution effectuée en %d rotations\n", list->len-2);
            printf("Etat final du Rubik's Cube :\n\n");
            printPatternRCube(*cube, stdout);

            choice2 = 0;
            printf("Voulez-vous voir les détails de la résolution du cube ? (1 = Oui / 0 = Non) ");
            scanf("%d", &choice2);
            if (choice2 == 1){
                choice2 = -1;
                printf("\tIci ou dans un fichier ? (1 = Ici / 0 = Fichier) ");
                while (choice2<0 || choice2>1) scanf("%d", &choice2);
                if (choice2 == 1) printDetail(list, stdout);
                else{
                    printDetail(list, fileDetails);
                    printf("\tLes détails de la résolution ont été sauvegardés dans le fichier Details.txt\n");
                }
            }

            choice2 = 0;
            printf("Voulez-vous voir les rotations nécessaires pour la résolution du cube ? (1 = Oui / 0 = Non) ");
            scanf("%d", &choice2);
            if (choice2 == 1){
                choice2 = -1;
                printf("\tIci ou dans un fichier ? (1 = Ici / 0 = Fichier) ");
                while (choice2<0 || choice2>1) scanf("%d", &choice2);
                if (choice2 == 1) printRotations(list, stdout);
                else{
                    printRotations(list, fileRotations);
                    printf("\tLes rotations nécessaires pour la résolution ont été sauvegardé dans le fichier Rotations.txt\n");
                }
            }
        }
        else{
            printf("Sur combien d'itérations voulez-vous tester la résolution ? ");
            iteration = 0;
            while (iteration<1 || iteration>1000000) scanf("%d", &iteration);

            printf("\n\t...Calcul en cours...\n");
            
            average = 0;
            for (i=0; i<iteration; i++){
                deleteList(list);
                list = newList(*cube);
                createRCube(cube);
                randomRCube(cube, 32);
                solveRCube(cube, list);
                average += list->len - 2;
            }
            average/=iteration;
            printf("\nLa moyenne obtenue sur %d itérations est de %d \n", iteration, average);
        }

        printf("\n--------------------\n\n");
        printf("Que souhaitez-vous faire ?\n");
        printf("1- Manipulation libre d'un Rubik's Cube\n");
        printf("2- Mélange aléatoire d'un Rubik's Cube\n");
        printf("3- Obtenir la moyenne du nombre de coups pour résoudre un Rubik's Cube 2*2\n");
        printf("0- Quitter\n");
        printf("Votre choix : ");

        choice = -1;
        while (choice<0 || choice>3) scanf("%d", &choice);
    }
    printf("\n\nAurevoir et à bientôt !\n");

    free(cube);
    cube = NULL;
    deleteList(list);

    fclose(fileStateRubiksCube);
    fclose(fileDetails);
    fclose(fileRotations);

    return 1;
}


