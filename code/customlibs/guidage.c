#include <stdio.h>

void guidage(int* parcours, int size, int n) {
    int i;
    int old = parcours[size - 1];
    int current = parcours[size - 2];
    int diff = current - old;
    if (diff == 1) printf("DROITE\n");
    else {
        if (diff == -1) printf("GAUCHE\n");
        else {
            if (diff == n) printf("BAS\n");
            else printf("HAUT\n");
        }
    }
    for (i = size - 3; i > -1; i--) {
        old = current;
        current = parcours[i];
        diff = current - old;
        if (diff == 1) printf("DROITE\n");
        else {
            if (diff == -1) printf("GAUCHE\n");
            else {
                if (diff == n) printf("BAS\n");
                else {
                    if (diff == -n) printf("HAUT\n");
                    else printf("TP\n");
                }
            }
        }
    }
}
