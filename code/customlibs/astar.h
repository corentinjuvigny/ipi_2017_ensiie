#ifndef ASTAR
#define ASTAR
#include "liste.h"

/*structure utilisée pour retrouver la position de la clé et de la porte*/
typedef struct {
    int i, j, k;
} pos_cle;

/*structure utilisée par a* pour représenter le coût d'un sommet*/
typedef struct {
    int cout;
    int heuristique;
    int cout_heuristique;
} node;

/* @requires : matrix non nulle, n < 1000
 * @assigns  : tableau tp[10], tableau tab taille n * n * 8, un entier num_of_p
 * @ensures  : créer un tableau tab tel que pour tout i dans [0;n*n - 1] et pour tout j dans [0;8[ t[i][j] = u où u s'il existe un sommet entre u et i et compléter par des -1. Si présence de clé il met dans cle[0] la position de la clé et dans cle[1] celle de la porte. Enfin enregistre le nombre de '.' dans num_of_p
 */
int** a_voisination(char matrix[1000][1002], int n, pos_cle[2], int *num_of_p);

/* @requires : None
 * @assigns  : None
 * @ensures  : renvoie la valeur de |x2 -x1| + |y2 - y1|
 */
int distance_manathan(int x1, int y1, int x2, int y2);

/* @requires : taille de d >= n, liste visite doit être trié par ordre croissante
 * @assigns  : un maillon de chaîne d'une liste d'entier
 * @ensures  : ajoute un élément qui contient l'entier noeud à la liste visite en triant soit par rapport à l'heuristique s'il y a beaucoups de points accessibles soit par rapport au coût heuristique dans le cas contraire et renvoie cette liste.
 */
liste a_insertion_triee(node *d, liste visite, int noeux, int n, int num_of_p);

/* @requires : size(d) > n, closelist triée par ordre croissant à l'exeption de son élément modif (modif peut ne pas être dans closelist)
 * @assigns  : un maillon de chaîne d'une liste d'entier
 * @ensures  : renvoie une version mise à jour de closelist de façon à être trié
 */
liste update_closelist(node* d, liste closelist, int modif, int n, int num_of_p);

/* @requires : matrix non nul, size(G) >= n * 8, size(d) >= n, size(predecesseur) >= n
 * @assigns  : liste visite de taille n au max, closelist taille n - 1 au max 
 * @ensures  : assigne pour tout i dans [0; n - 1] le numéro du prédécesseur de i dans predecesseur[i] et à d[i] les coûts du sommets i. Renvoie le coût heuristique de t s'il existe un chemin entre s et t, INFINITY sinon.
 */
int astar(int** G, node* d, int* predecesseur, int n, int s, int t, int num_of_p);

/* @requires : predecesseur non nul et contenant s et t
 * @assigns  : liste chemin
 * @ensures  : renvoie le chemin entre s et t
 */
liste cheminDijkstrafinal(int* predecesseur, int s, int t);

/* @requires : matrix non nul, size(tab) >= n * n *2, size(chemin) = n * n, cle soit rempli
 * @assigns  : trois listes resultats, trois tableaux de node, six tableaux d'entiers relatifs
 * @ensures  : si le labyrinthe a moins de 10000 noeuds, essaye de trouver une chemin entre le début et la fin du labyrinthe sans passer par la clé (et donc par la porte). Si ce chemin est non nul et qu'il contient moins d'éléments que le temps t demandé, alors affiche les mouvements à suivre sur stdout puis exit le programme sans erreur. Si ces conditions ne sont pas remplies il créé un processus fils qui va réaliser trouver puis afficher sur stdout le chemin entre le début et la clé avant de se suicider tandis que le père va calculer le chemin entre la clé et la sortie en considérant que la porte peut être traversée. Puis il attend que son fils lui renvoie le signal de sa mort pour afficher à son tour le chemn à parcourir puis exit sans erreur. 
 */
void a_CheminAvecCle(char matrix[1000][1002], int** tab, int* chemin, int m, pos_cle cle[2], int size, int t, int n, int num_of_p);

#endif
