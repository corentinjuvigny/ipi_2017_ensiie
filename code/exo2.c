#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "liste.h"
#define INFINITY INT_MAX //le plus grand entier possible en C sur cette machine

/*@requires : d non nul
 *@assigns  : nmini
 *@ensures  : renvoie l'élément de poid minimum dans d qui ne soit pas dans visite
 */
int minimum(liste visite, int* d, int n);

/* @requires : G et un tableau alloué de taille au moins n
 * @assigns  : liste visite de taille variable
 * @ensures  : renvoie INFINITY s'il n'existe pas de chemin entre s et t dans le graphe G, un entier quelconque mais inférieur à INFINITY sinon
 */
int dijkstra(int** G, int* d, int n, int s, int t);

/* @requires : G et d non nuls
 * @assigns  : liste chemin de taille variable
 * @ensures : Prend en entrée une matrice d'adjacence,
 * un vecteur d'entiers correspondant au chemin de dijkstra associé,
 * les noeux de départ et d'arrivée. Renvoie une liste correspondant au chemin à parcourir entre les deux noeux
 */ 
liste cheminDijkstra(int** G, int* d, int s, int t, int n); 

int main()
{
    int n, s, t;
    scanf("%d",&n);
    int ** matrix = (int**)malloc(n*sizeof(int*));
    int i,j;

    for(i = 0; i < n; i++) {
        int* line = (int*)malloc(n * sizeof(int));
        matrix[i] = line;
        for(j = 0; j < n; j++) {
            scanf("%d", &line[j]);
        }
    }
    scanf("%d", &s);
    scanf("%d", &t);
    s--;
    t--;
    /* mon code */
    if (s == t) {
        printf("%d\n", s + 1); /*car le plus court chemin pour aller de soi-même à soi-même est de passer par soi-même*/
        goto coda;
    }
    int* d = (int*)malloc(n * sizeof(int));
    int resultat = dijkstra(matrix, d, n, s, t); 
    if (resultat == INFINITY) printf("Not connected\n");
    else {
        liste chemin = cheminDijkstra(matrix, d, s, t, n);
        while (!isEmptyl(chemin)) printf("%d\n", pull(&chemin) + 1);
        freel(chemin);
    }
    free(d);
    goto coda;
    /*fin de mon code*/
coda :
    for(i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return EXIT_SUCCESS;
}

int minimum(liste visite, int* d, int n)
{
    int i;
    int mini = INFINITY;
    int nmini = 0;
    for (i = 0; i < n; i++) {
        if (!isInl(visite, i) && d[i] < mini) {
            mini = d[i];
            nmini = i;
        }
    }
    return nmini;
}

int dijkstra(int** G, int* d, int n, int s, int t)
{
    int j, u, v;
    liste visite = initl();
    for (j = 0; j < n; j++) d[j] = INFINITY;
    d[s] = 0;
    push(&visite, s);
    for (j = 0; j < n; j++) {
        if (G[s][j] != -1) d[j] = G[s][j];
    }
    while (nbrOfElement(visite) != n + 1) {
        u = minimum(visite, d, n);
        push(&visite, u);
        if (u == t) {
            freel(visite);
            return d[t];
        }
        /* modifie d en modifiant les valeurs des successeurs de v */
        for (v = 0; v < n; v++) {
            if (G[u][v] != -1) {
                if (d[v] > d[u] + G[u][v]) {
                    d[v] = d[u] + G[u][v];
                }
            }
        }
    }
    freel(visite);
    return INFINITY;
}

liste cheminDijkstra(int** G, int* d, int s, int t, int n)
{
    int i;
    liste chemin = initl();
    int v = t;
    while (v != s) {
        push(&chemin, v);
        for (i = 0; i < n; i++) {
            if (G[i][v] == d[v] - d[i] && !isInl(chemin, i) && G[i][v] != -1) {
                v = i;
                break;
            }
        }
    }
    push(&chemin, v);
    return chemin;
}
