#include "excellLib.h"
char* citireSir()
{
    char *sir = (char*)malloc(sizeof(char));
    if(!sir)
    {
        printf("variabilei sir nu i s-a putut aloca memorie");
        exit(1);
    }

    char c;
    int k = 0;

    scanf("%c", &c);
    while(c != '\n')
    {
        sir[k++] = c;
        scanf("%c", &c);

        sir = (char*)realloc(sir, sizeof(char) * (k+1));
        if(!sir)
        {
            printf("variabilei sir nu i s-a putut realoca memorie");
            exit(1);
        }
    }
    sir[k] = '\0';
    return sir;
}

concurent* citire()
{
    concurent *x = (concurent*)malloc(sizeof(concurent));
    if(!x)
    {
        printf("variabilei x nu i s-a putut aloca memorie");
        exit(1);
    }
    fflush(stdin);

    printf("Numele concurentului: ");
    x->nume = citireSir();
    while(!strlen(x->nume) || strchr(x->nume, ' '))
    {
        printf("\n!! NUMELE TREBUIE SA FIE FORMAT DINTR-UN SINGUR CUVANT !!\n\n");
        printf("Numele concurentului: ");
        x->nume = citireSir();
    }

    printf("Prenumele concurentului: ");
    x->prenume = citireSir();
    while(!strlen(x->prenume) || strchr(x->prenume, ' '))
    {
        printf("\n!! PRENUMELE TREBUIE SA FIE FORMAT DINTR-UN SINGUR CUVANT !!\n\n");
        printf("Prenumele concurentului: ");
        x->prenume = citireSir();
    }

    printf("Punctajul concurentului: ");
    scanf("%d", &((*x).punctaj));

    return x;
}
