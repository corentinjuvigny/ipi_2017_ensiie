#ifndef GUIDAGE
#define GUIDAGE

/* @requires : parcours contient size éléments qui représentent les sommets un chemin dans labyrinthe classé de la fin du chemin à son début
 * @assigns  : None
 * @ensures  : renvoie sur le flux stdout GAUCHE, DROITE, HAUT, BAS, TP correspondant aux déplacements à effectuer pour suivre le parcours donné
 */ 
void guidage(int* parcours, int size, int n);

#endif
