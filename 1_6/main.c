#include <stdio.h>
#include <stdlib.h>
#define max 100
#define lon 20

typedef struct noms {
    char nom[lon];
} noms;

typedef struct ListeDesNoms {
    noms tab[max];
    int longue;
} ListeDesNoms;
int compareNoms(const void *a, const void *b) {
    return strcmp(((noms *)a)->nom, ((noms *)b)->nom);
}
int main() {
    ListeDesNoms tab1;
    printf("Veuillez saisir le nombre de noms que vous allez ajouter : ");
    int nbr;
    scanf("%d", &nbr);
    FILE* f1 = fopen("f1.txt", "a+");
    FILE* f2 = fopen("f2.txt", "a+");

    char nom[20];
    int i = 0;

    for (i = 0; i < nbr; i++) {
        printf("Etudiant num %d:", i + 1);
        scanf("%s", nom);
        fprintf(f1, "%s\n", nom);
    }

    rewind(f1);
    int j = 0;

    while (j < max && fscanf(f1, "%s", tab1.tab[j].nom) != EOF) {
        j++;
    }

    tab1.longue = j;


    for (i = 0; i < tab1.longue; i++) {
        printf("Nom %d : %s\n", i, tab1.tab[i].nom);
    }
  qsort(tab1.tab, tab1.longue, sizeof(noms), compareNoms);


    rewind(f1);
    for (i = 0; i < tab1.longue; i++) {
        fprintf(f2, "%s\n", tab1.tab[i].nom);
    }
    fclose(f1);
    fclose(f2);

    return 0;
}
