#ifndef LISTE_FLOAT
#define LISTE_FLOAT
#include <stdio.h>

typedef struct flink* fliste;

struct flink {
    float s;
    fliste next;
};

/*creer une fliste vide*/
fliste initlf();

/*test si la fliste est vide*/
int isEmptylf(fliste);

/*ajoute l'int dans la fliste*/
void pushf(fliste*, float);

/*renvoie le dernier element de la fliste et le supprime de la liste*/
float pullf(fliste*);

/*renvoie 1 si l'entier est dans la fliste, 0 sinon*/
int isInlf(fliste, int);

/*renvoie la copie de la fliste l mais dans le sens oppose des elements*/
fliste copylf(fliste); 

/*affiche la fliste l sur le flux stderr*/
void printflf(fliste);

/*renvoie 1 si k se trouve dans les i premieres flistes contenues dans V*/
int isInprecf(fliste*, int, int);

/*renvoie le nombre d'élément de la fliste V*/
int nbrOfElementf(fliste);

/*libère l'espace mémoire de la liste l*/
void freelf(fliste*);

#endif
