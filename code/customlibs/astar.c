#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "astar.h"
#include "liste.h"
#include "guidage.h"
#define N 8
#define INFINITY INT_MAX
#define add(tab,x,k,l) for(l = 0; l < N; l++) {\
                            if (tab[k][l] == -1) {\
                                tab[k][l] = x;\
                                break;\
                            }\
                        }

int** a_voisination(char matrix[1000][1002], int n, pos_cle cle[2], int *num_of_p)
{
    int i,j,k,l;
    int m = n * n;
    int tp[10] = {0,0,0,0,0,0,0,0,0,0};
    int** tab = malloc(m * sizeof(int*));
    for (i = 0; i < m; i++) tab[i] = malloc(N * sizeof(int));
    for (i = 0; i < m; i++) for (j = 0; j < N; j++) tab[i][j] = -1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            k = i * n + j;
            switch (matrix[i][j]) {
                case 'E' :
                    goto relierVoisin;
                case '.' :
                    (*num_of_p)++;
                    goto relierVoisin;
                case '*' :
                    if (!tp[0]) tp[0] = k;
                    else {
                        add(tab,tp[0],k,l);
                        add(tab,k,tp[0],l);
                    }
                    goto relierVoisin;
                case '%' :
                    if (!tp[1]) tp[1] = k;
                    else {
                        add(tab,tp[1],k,l);
                        add(tab,k,tp[1],l);
                    }
                    goto relierVoisin;
                case '$' :
                    if (!tp[2]) tp[2] = k;
                    else {
                        add(tab,tp[2],k,l);
                        add(tab,k,tp[2],l);
                    }
                    goto  relierVoisin;
                case '#' :
                    if (!tp[3]) tp[3] = k;
                    else {
                        add(tab,tp[3],k,l);
                        add(tab,k,tp[3],l);
                    }
                    goto relierVoisin;
                case '&' :
                    if (!tp[4]) tp[4] = k;
                    else {
                        add(tab,tp[4],k,l);
                        add(tab,k,tp[4],l);
                    }
                    goto relierVoisin;
                case '+' :
                    if (!tp[5]) tp[5] = k;
                    else { 
                        add(tab,tp[5],k,l);
                        add(tab,k,tp[5],l);
                    }
                    goto relierVoisin;
                case '-' :
                    if (!tp[6]) tp[6] = k;
                    else {
                        add(tab,tp[6],k,l);
                        add(tab,k,tp[6],l);
                    }
                    goto relierVoisin;
                case '@' :
                    if (!tp[7]) tp[7] = k;
                    else {
                        add(tab, tp[7], k, l);
                        add(tab, k, tp[7], l);
                    }
                    goto relierVoisin;
                case '^' :
                    if (!tp[8]) tp[8] = k;
                    else {
                        add(tab,tp[8],k,l);
                        add(tab,k,tp[8],l);
                    }
                    goto relierVoisin;
                case '!' :
                    if (!tp[9]) tp[9] = k;
                    else {
                        add(tab,tp[9],k,l);
                        add(tab,k,tp[9],l);
                    }
                    goto relierVoisin;
                case 'a' :
                    cle[0].k = k;
                    cle[0].i = i;
                    cle[0].j = j;
                    goto relierVoisin;
                case 'A' :
                    cle[1].k = k;
                    cle[1].i = i;
                    cle[1].j = j;
                    break;
                default :
                    break;
relierVoisin :
                if (j != n - 1) {
                    if (matrix[i][j + 1] != 'X' && matrix[i][j + 1] != 'A') {
                        for (l = 0; l < 8; l++) {
                            if (tab[k][l] == -1) {
                                tab[k][l] = k + 1;
                                break;
                            }
                        }
                        for (l = 0; l < 8; l++) {
                            if (tab[k + 1][l] == -1) {
                                tab[k + 1][l] = k;
                                break;
                            }
                        }
                    }
                }
                if (i != n - 1) {
                    if (matrix[i + 1][j] != 'X' && matrix[i + 1][j] != 'A') {
                        for (l = 0; l < 8; l++) {
                            if (tab[k][l] == -1) {
                                tab[k][l] = k + n;
                                break;
                            }
                        }
                        for (l = 0; l < 8; l++) {
                            if (tab[k + n][l] == -1) {
                                tab[k + n][l] = k;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return tab;
}

int distance_manathan(int x1, int y1, int x2, int y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
}

liste a_insertion_triee(node* d, liste visite, int noeud, int n, int num_of_p)
{
    liste l = visite;
    liste m = malloc(sizeof(struct link)); //on crée un maillon contenant le noeud
    liste ant = initl();                        //maillon précédent
    m->s = noeud;
    if (isEmptyl(l)) return m;
    while (!isEmptyl(l)) {
        if (isEmptyl(l->next)) {
            l->next = m;
            m->next = NULL;
            break;
        }
        if (num_of_p == n - 2) {
            if (d[noeud].heuristique < d[l->next->s].heuristique) {
                m->next = l;
                if (isEmptyl(ant)) return m; //m devient le premier élément de la liste car il est le plus petit
                ant->next = m;
                break;
            }
        }
        else {
            if (d[noeud].cout_heuristique < d[l->next->s].cout_heuristique) {
                m->next = l;
                if (isEmptyl(ant)) return m;
                ant->next = m;
                break;
            }
        }
        ant = l;
        l = l->next;
        }
    return visite;
}

liste update_closlist (node* d, liste closelist,  int modif, int n, int num_of_p)
{
    liste temp = initl();
    if (closelist == NULL) {
        push(&temp,modif);
        return temp;
    }
    rm_l(&closelist,modif);
    temp = a_insertion_triee(d,closelist,modif,n,num_of_p);
    return temp;
}

int astar(int** G, node* d, int* predecesseur, int n, int s, int t, int num_of_p)
{
    int l, u, v;
    int i, j, it, jt;
    jt = t % n;
    it = (t - jt) / n;
    liste visite = initl();
    liste closelist = initl();
    for (l = 0; l < n; l++) { //on initialise le coût de tous les sommets à INFINITY
        d[l].cout = INFINITY;
        j = l % n;
        i = (l - j) / n;
        d[l].heuristique = distance_manathan(i, j, it, jt);
        d[l].cout_heuristique = INFINITY;
    }
    d[s].cout = 0;
    push(&visite, s);
    for (l = 0; l < N; l++) { // on initialise les sommets voisins du sommet de départ
        if (G[s][l] == -1) break;
        d[l].cout = G[s][l];
        d[G[s][l]].cout = 1;
        j = G[s][l] % n;
        i = (G[s][l] - s) / n;
        d[G[s][l]].cout_heuristique = d[G[s][l]].cout +  d[G[s][l]].heuristique;
        predecesseur[G[s][l]] = s;
        closelist = update_closlist(d,closelist,G[s][l],n,num_of_p);
    }
    while (!isEmptyl(closelist)) {
        u = pull(&closelist); //sommet de coût_heuristique minimal dans la closelist
        push(&visite, u); 
        if (u == t) {
            freel(visite);
            freel(closelist);
            return d[t].cout_heuristique; //on a atteint le sommet final
        }
        /* modifie d en modifiant les valeurs des successeurs de v */
        for (v = 0; v < N; v++) {
            if (G[u][v] == -1) break;
            if (d[G[u][v]].cout_heuristique > d[u].cout_heuristique + 1) {
                d[G[u][v]].cout_heuristique = d[u].cout_heuristique + 1;
                predecesseur[G[u][v]] = u;
                closelist = update_closlist(d,closelist,G[u][v],n,num_of_p); //on retrie la closeList
            }
        }
    }
    freel(visite);
    freel(closelist);
    return INFINITY; //on n'a jamais atteint le sommet d'arrivé
}

liste cheminDijkstrafinal(int* predecesseur, int s, int t)
{
    liste chemin = initl();
    int v = t;
    while (v != s) {
        push(&chemin, v);
        v = predecesseur[v];
    }
    push(&chemin, v);
    return chemin;
}

void a_CheminAvecCle(char matrix[1000][1002], int** tab, int* chemin, int m, pos_cle cle[2], int size, int t, int n, int num_of_p)
{
    liste resultatSansC;
    liste resultatjC;
    liste resultatAC;
    node* d = malloc(m * sizeof(node));
    int* chemin2 = malloc(m * sizeof(int));
    int* predecesseur_sans_c = malloc(m * sizeof(int));
    int* chemin3 = malloc(m * sizeof(int));
    int* predecesseur_j_c = malloc(m * sizeof(int));
    int* predecesseur_ap_c = malloc(m * sizeof(int));
    int size2,nbrofel;
    int pid,wstatus;
    int l;
    if (m  < 100000) {
        if ((pid = astar(tab, d, predecesseur_sans_c,m,0,m - 1,num_of_p))!= INFINITY) {
            resultatSansC = cheminDijkstrafinal(predecesseur_sans_c,0,m - 1);
            nbrofel = nbrOfElement(resultatSansC);
            size = 0;
            while (!isEmptyl(resultatSansC)) {
                chemin[nbrofel - size - 1] = pull(&resultatSansC);
                size++;
            }
            if (size <= t + 1) {
                guidage(chemin, size, n);
                free(d);
                free(chemin2);
                free(chemin3);
                free(predecesseur_j_c);
                free(predecesseur_ap_c);
                free(predecesseur_sans_c);
                return;
            }
        }
    }
    if ((pid = fork()) == 0) {
        astar(tab,d,predecesseur_j_c,m,0,cle[0].k,num_of_p);
        resultatjC = cheminDijkstrafinal(predecesseur_j_c,0,cle[0].k);
        int nbrofel2 = nbrOfElement(resultatjC);
        size2 = 0;
        while (!isEmptyl(resultatjC)) {
            chemin2[nbrofel2 - size2 - 1] = pull(&resultatjC);
            size2++;
        }
        guidage(chemin2, size2, n);
        free(d);
        free(chemin2);
        free(chemin3);
        free(predecesseur_j_c);
        free(predecesseur_ap_c);
        free(predecesseur_sans_c);
        return;
    }
    if (pid < 0) {
        fprintf(stderr, "%d : erreur d'ouverture du fils %d : %s\n", getpid(), pid, strerror(errno));
        exit(EXIT_FAILURE);
    }
    if (cle[1].j != n - 1) {
        if (matrix[cle[1].i][cle[1].j + 1] != 'X') {
            add(tab,cle[1].k,cle[1].k + 1,l);
            add(tab,cle[1].k + 1,cle[1].k,l);
        }
    }
    if (cle[1].i != m - 1) {
        if (matrix[cle[1].i + 1][cle[1].j] != 'X') {
            add(tab,cle[1].k,cle[1].k + n,l);
            add(tab,cle[1].k + n,cle[1].k,l);
        }
    }
    if (cle[1].j != 0) {
        if (matrix[cle[1].i][cle[1].j - 1] != 'X') {
            add(tab,cle[1].k,cle[1].k - 1,l);
            add(tab,cle[1].k - 1,cle[1].k,l);
        }
    }
    if (cle[1].i != 0) {
        if (matrix[cle[1].i - 1][cle[1].j] != 'X') {
            add(tab,cle[1].k,cle[1].k - n,l);
            add(tab,cle[1].k - n,cle[1].k,l);
        }
    }
    astar(tab, d, predecesseur_ap_c,m,cle[0].k, m - 1,num_of_p);
    resultatAC = cheminDijkstrafinal(predecesseur_ap_c,cle[0].k,m - 1);
    nbrofel = nbrOfElement(resultatAC);
    size = 0;
    while (!isEmptyl(resultatAC)) {
        chemin3[nbrofel - size - 1] = pull(&resultatAC);
        size++;     
    }
    wait(&wstatus);
    guidage(chemin3,size,n);
    free(d);
    free(chemin2);
    free(chemin3); 
    free(predecesseur_j_c);
    free(predecesseur_ap_c);
    free(predecesseur_sans_c);
    return;
}
