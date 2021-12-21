#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

liste initl() {
    return NULL;
}

int isEmptyl(liste l)
{
    return l == NULL;
}

void push(liste *l, int i)
{
    liste q = (liste)malloc(sizeof(*q));
    q->s = i;
    q->next = *l;
    *l = q;
}

int pull(liste *l)
{
    int s;
    if (!isEmptyl(*l)) {
        liste q = *l;
        s = (*l)->s;
        *l = (*l)->next;
        free(q);
    } else s = 0;
    return s;
}

int isInl(liste l, int k)
{
    liste m = l;
    while (!isEmptyl(m)) {
        if (m->s == k) return 1;
        m = m->next;
    }
    return 0;
}

void rm_l(liste *l, int i)
{
    liste ant = initl();
    liste p = *l;
    while (!isEmptyl(p)) {
        if (p->s == i) {
            if (isEmptyl(ant)) {
                *l = p->next;
                free(p);
            }
            else {
                ant->next = p->next;
                free(p);
            }
            break;
        }
        ant = p;
        p = p->next;
    }
}

liste copyl(liste l)
{
    liste m = initl();
    liste current = l;
    while (!isEmptyl(current)) {
        push(&m,current->s);
        current = current->next;
    }
    return m;
}

void printfl(liste l)
{
    liste current = l;
    while (current != NULL) {
        fprintf(stderr,"-> [%3d]",current->s);
        current = current->next;
    }
    fprintf(stderr,"\n");
}

/*fonction de parcours*/

int isInprec(liste* V, int i, int k)
{
    int j;
    for (j = 0; j < i; j++) {
        if (isInl(V[j], k) == 1) return 0;
    }
    return 1;
}

int nbrOfElement(liste l)
{
    int n = 0;
    liste q = l;
    while (!isEmptyl(q)) {
        n++;
        q = q->next;
    }
    return n;
}

void freel(liste l)
{
    liste q;
    while (!isEmptyl(l)) {
        q = l;
        l = l->next;
        free(q);
    }
}
