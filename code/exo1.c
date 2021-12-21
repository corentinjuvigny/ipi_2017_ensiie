#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#define LARGEUR

/*@requires : V non nul
 *@assigns  : none
 *@ensures  : renvoie 1 si k se trouve dans les i premieres listes contenues dans V
 */
int isInprec_1(liste* V, int i, int k);

/*@requires : None
 *@assigns  : V tableau de taille n x 1 de listes de taille variable et size contenant le nombre d'éléments dans V
 *@ensures  : creer la liste des Vi. Si t appartient est dans V alors size vaut le nombre d'éléments de V. Sinon il vaut n + 1.
 */
void creation_Vliste_1(int** matrix, int n, int s, int t, liste** Vliste, int *size);

/*@requires : liste et tableau non nuls.
 *@assigns  : tableau d'entier de taille size.
 *@ensures  : reconstruit le parcours entre t et s à partir de la Vliste et de la matrice d'adjacenceet le renvoie sous forme d'un tableau dont le premier élément est la fin du parcours et le dernier le début. Renvoie NULL si le chemin est n'existe pas, donc si n > nbr_nodes.
 */
int* parcours_en_largeur_1(int** matrix, liste* V, int n, int t);


int main()
{
    int i,j;
    int n, s, t;
    scanf("%d",&n);
    int** matrix = (int**) malloc(n*sizeof(int*));

    for (i = 0; i < n; i++) {
        int* line = (int*) malloc(n * sizeof(int));
        matrix[i] = line;
        for(j = 0; j < n; j++) {
            scanf("%d", line + j);
        }
    }

    scanf("%d", &s);
    scanf("%d", &t);
    s--;
    t--;

    /*partie personnelle */
    int size;
    liste *S;
    creation_Vliste_1(matrix, n, s, t, &S, &size);
    int* parcours = parcours_en_largeur_1(matrix, S, size, t);
    if (parcours == NULL) {
        printf("Not connected\n"); /* par définition de parcours_en_largeur */
    }
    else {
        for (i = size - 1; i > -1; i--) {
            fprintf(stdout,"%d\n", parcours[i] + 1);
        }
    }

    for (i = 0; i < size; i++) freel(S[i]);
    free(S);
    free(parcours);
    
    /* fin de ma partie personelle */
    for(i = 0; i < n; i++)
      free(matrix[i]);
    free(matrix);

    return EXIT_SUCCESS;
}

/*fonction de parcours*/

int isInprec_1(liste* V, int i, int k)
{
    int j;
    for (j = 0; j < i; j++) {
        if (isInl(V[j], k) == 1) return 1;
    }
    return 0;
}

void creation_Vliste_1(int** matrix, int n, int s, int t, liste** Vliste, int *size) 
{
    int k;
    int node = s;
    int i = 1;
    liste* V = (liste*)malloc(n * sizeof(liste)); //tableau de liste contenant les listes des sommets voisins
    liste m = initl();
    push(&m, s);
    V[0] = m;
    /*printfl(V[0]);*/
    while (!isInl(V[i - 1], t)) { // tant que l'arrivé n'est pas dans la dernère liste créé ou qu'il y est plus de listes que de sommets
        V[i] = initl();
        m = V[i - 1];
        if (m == NULL) { /* si V[i - 1] = NULL cela signifie que les éléments de V[i - 2] n'ont pas
                            de nouveaux antécédents, et donc comme t n'as toujours pas été trouvé
                            c'est donc que s et t ne sont pas reliés
                            on arrete donc ici la fonction et on dit que size = n + 1 pour afficher
                            ensuite : Not Connected
                         */
            *size = 0;
            for (k = 0; k < i - 1; k++) freel(V[k]);
            free(V);
            *Vliste = NULL;
            return;
        }
        while (!isEmptyl(m)) {
            node = m->s;
            for (k = 0; k < n; k++) {
                if (matrix[node][k] == 1 && !isInprec_1(V, i, k)) {
                    push(V + i, k);  //si le sommet est relié à un sommet précédent et n'est pas présent dans des V[i] antérieurs on l'ajoute au V actuel 
                }
            }
            m = m->next;
        }
        i++;
    }
    *Vliste =  V;
    *size = i;
}

int* parcours_en_largeur_1(int** matrix, liste* V, int n, int t)
{
    int i, b;
    if ( !V )
       return NULL; // cas Not Connected par construction de la fonction Vliste
    liste m;
    int* parcours = (int*)malloc(n * sizeof(int));
    parcours[0] = t;
    for (i = n - 1 ; i > 0; i--) {
        m = copyl(V[i - 1]);
        while (!isEmptyl(m)) {
            b = pull(&m);
            if (matrix[b][parcours[n - i - 1]] == 1) {
                parcours[n - i] = b; // on reconstruit le chemin
            }
        }
        if ( m )
           freel(m);
    }
    return parcours;
}
