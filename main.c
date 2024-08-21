#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#define max 100

typedef struct fichier{
FILE * Fichier;
char nomDeFcihier[20];
}fichier;
typedef struct listDesFichiers{
fichier tab[max];
int longue;
}listDesFichiers;

int main() {
    int k=0;
    listDesFichiers tab1;
    char output_filename[20];
    char ch;

    int c=0;
    while(c<2)
      {
        printf("Entrez le nom du fichier de sortie : ");
        scanf("%s", output_filename);
        const char *filename = output_filename;
        struct stat file_stat;

        if (stat(filename, &file_stat) == 0) {
            printf("Le fichier existe.\n");
            break;
        }
        else
        {
            printf("Le fichier n'existe pas et a ete cree a nouveau..vous aurez une autre chance\n");
            c++;
        }
      }
      if(c==2){
        printf("le programme va ferme.");
        exit(1);
      }


    FILE * output = fopen(output_filename, "a+");


    if (output == NULL) {
        printf("Impossible de creer le fichier de sortie");
        return 3;
    }

    printf("veuillez saisir le nombre de fichiers vous allez creer :");
    scanf("%d",&tab1.longue);

    for (int i=0;i<tab1.longue;i++)

    {

        printf("veuillez saisir le nom de fichier num : %d\n",i+1);
        printf("le fichier doit etre en format .txt\n");

        scanf("%s",tab1.tab[i].nomDeFcihier);
        tab1.tab[i].Fichier = fopen(tab1.tab[i].nomDeFcihier,"w+");


         if (tab1.tab[i].Fichier==NULL) {
            printf("Impossible de creer le fichier source num : %d!!",i+1);
            return 1;
        }

            for(int j=0;j<i;j++)
                {
                if(!strcmp(tab1.tab[i].nomDeFcihier,tab1.tab[j].nomDeFcihier))
                {
                    printf("Ce fichier existe!\n");i--;
                    k++;
                }
               }

               if(k==2)
                {
                    printf("vous navez pas dautre chance!.");
                     exit(0);
                    break;
               }
               if(k==0)
                {
                    printf("Entrez le contenu du  fichier source. Terminez par Ctrl+D:\n");

                    while ((ch = getchar()) != EOF) {
                        fputc(ch, tab1.tab[i].Fichier);
                    }
                    fclose(tab1.tab[i].Fichier);

                    tab1.tab[i].Fichier = fopen(tab1.tab[i].nomDeFcihier,"r");
                    while ((ch = fgetc(tab1.tab[i].Fichier)) != EOF)
                    {
                        fputc(ch, output);
                    }
                fclose(tab1.tab[i].Fichier);

                }

    }
    fclose(output);
    printf("Fusion terminee avec succes. Le contenu des fichiers source a ete fusionne dans %s.\n", output_filename);

    return 0;
}
