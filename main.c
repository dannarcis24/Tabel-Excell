#include "excellLib.h"
void afisare(List *cap)
{
    FILE *f = fopen("tabelConcurenti.xlt", "wt");
    if(!f)
    {
        printf("fisierul tabelConcurenti.xlt nu s-a putut deschide");
        exit(1);
    }
    unsigned int nr = 0, ct = 0;

    fprintf(f, "%s\t\t", "Numar");
    for(register List *p = cap; p; p = p->next)
    {
        unsigned int val = 0;

        fprintf(f, "%s %d\t\t\t", "Locul", ++nr);

        for(register clasament *q = p->loc; q; q = q->next)
            val++;

        if(val > ct)
            ct = val;
    }
    fprintf(f, "\n\t");
    for(register List *p = cap; p; p = p->next)
        fprintf(f, "%s\t%s\t%s\t", "Nume", "Prenume","Punctaj");

    fprintf(f, "\n");
    for(nr = 1; nr <= ct; nr++)
    {
        fprintf(f, "%d" ".\t", nr);

        for(register List *p = cap; p; p = p->next)
            if(p->loc)
            {
                clasament *q;

                q = p->loc;
                fprintf(f, "%s\t%s\t%d\t", q->x.nume, q->x.prenume, q->x.punctaj);
                p->loc = q->next;
            }
            else
                fprintf(f, "\t\t\t");

        fprintf(f, "\n");
    }

    fclose(f);
}

int main()
{
    List *cap;
    unsigned int n;

    cap = (List*)malloc(sizeof(List));
    if(!cap)
    {
        printf("variabilei cap nu i s-a putut aloca memorie");
        return 1;
    }
    (*cap).loc = (clasament*)malloc(sizeof(clasament));
    if(!(*cap).loc)
    {
        printf("variabilei cap->loc nu i s-a putut aloca memorie");
        return 1;
    }

    cap->next = NULL;
    cap->loc->next = NULL;
    cap->loc->x.punctaj = -1;

    printf("Hai sa citim concurentii\nNumarul de concurenti este: ");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        printf("Concurentul %d\n", i+1);
        concurent *a = citire();
        printf("\n");

        ordConcurenti(&cap, a);
    }

    afisare(cap);
    delList(&cap);

    return 0;
}

