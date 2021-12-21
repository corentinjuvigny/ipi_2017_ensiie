#ifndef LIST
#define LIST
#include <stdio.h>

typedef struct link* liste;
struct link {
    int s;
    liste next;
};

/*creer une liste vide*/
liste initl();

/*test si la liste est vide*/
int isEmptyl(liste);

/*ajoute l'int dans la liste*/
void push(liste*, int);

/*renvoie le dernier element de la liste et le supprime de la liste*/
int pull(liste*);

/*renvoie 1 si l'entier est dans la liste, 0 sinon*/
int isInl(liste, int);

/*supprime l'élément i dans la liste*/
void rm_l(liste*, int);

/*renvoie la copie de la liste l mais dans le sens oppose des elements*/
liste copyl(liste); 

/*affiche la liste l sur le flux stderr*/
void printfl(liste);

/*renvoie 1 si k se trouve dans les i premieres listes contenues dans V*/
int isInprec(liste*, int, int);

/*renvoie le nombre d'élément de la liste V*/
int nbrOfElement(liste);

/*libere l'espace memoire alloue a l*/
void freel(liste);

#endif
