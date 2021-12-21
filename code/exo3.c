#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "liste.h"
#include "astar.h"
#include "guidage.h"

int main()
{
    int i, n, m, timer, nbrofel, size = 0, num_of_p = 0;
    int** atab;
    int* chemin;
    int* predecesseur;
    node* d;
    pos_cle cle[2];

    scanf("%d",&n);
    fgetc(stdin);  
    char matrix[1000][1002] = { "" };
    for(i = 0; i < n; i++){
        fgets(matrix[i], 1002, stdin);
    }
    scanf("%d", &timer);
    fgetc(stdin);
    m = n * n;
    cle[0].k = 0;
    cle[1].k = 0;
    atab = a_voisination(matrix, n, cle, &num_of_p);
    d = (node*)malloc(m * sizeof(node)); 
    predecesseur = (int*)malloc(m * sizeof(int));
    chemin = (int*)malloc(m * sizeof(int));
    if (cle[0].k != 0) {
        a_CheminAvecCle(matrix, atab, chemin, m, cle, size, m - 1, n, num_of_p);
        goto memoryHandler;
    }
    astar(atab, d, predecesseur, m, 0, m - 1, num_of_p);
    liste resultat = cheminDijkstrafinal(predecesseur, 0, m - 1);
    nbrofel = nbrOfElement(resultat);
    while (!isEmptyl(resultat)) {
        chemin[nbrofel - size - 1] = pull(&resultat);
        size++;
    }
    guidage(chemin, size, n);

memoryHandler:
    free(d);
    free(predecesseur);
    free(chemin);
    for (i = 0; i < m; i++) free(atab[i]);
    free(atab);

    return EXIT_SUCCESS;
}
