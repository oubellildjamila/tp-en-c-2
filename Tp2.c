#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50

/* Remplit le tableau avec des entiers aléatoires entre 1 et 200 */
void initialisation(int T[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        T[i] = rand() % 200 + 1;
    }
}

/* Affiche le tableau */
void afficher(int T[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");
}

/* Tri par insertion */
void tri_insertion(int T[], int n) {
    int i, j, x;
    for (i = 1; i < n; i++) {
        x = T[i];                      /* on mémorise T[i] */
        j = i;
        while (j > 0 && T[j - 1] > x) {
            T[j] = T[j - 1];           /* on décale vers la droite */
            j = j - 1;
        }
        T[j] = x;                      /* on place x dans le "trou" */
    }
}

int main(void) {
    int T[N];

    srand(time(NULL));                 /* une seule fois dans le programme */

    initialisation(T, N);

    printf("Tableau initial :\n");
    afficher(T, N);

    tri_insertion(T, N);

    printf("\nTableau trie :\n");
    afficher(T, N);

    return 0;
}
