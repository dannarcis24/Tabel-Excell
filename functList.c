#include "excellLib.h"
void addBegin(List **BigList, concurent *elem)
{
    if((*BigList)->loc->x.punctaj == -1)
    {
        (*BigList)->loc->x = *elem;
        (*BigList)->loc->next = NULL;
        return;
    }

    List *nod = (List*)malloc(sizeof(List));
    if(!nod)
    {
        printf("variabilei nod nu i s-a putut aloca memorie");
        exit(1);
    }
    nod->loc = (clasament*)malloc(sizeof(clasament));
    if(!nod->loc)
    {
        printf("variabilei nod->loc nu i s-a putut aloca memorie");
        exit(1);
    }

    nod->loc->x = *elem;
    nod->loc->next = NULL;
    nod->next = *BigList;
    *BigList = nod;
}

void addEnd(List *BigList, concurent *elem)
{
    if(!BigList)
    {
        printf("lista BigList este goala");
        exit(1);
    }

    List *nod = (List*)malloc(sizeof(List));
    if(!nod)
    {
        printf("variabilei nod nu i s-a putut aloca memorie");
        exit(1);
    }
    nod->loc = (clasament*)malloc(sizeof(clasament));
    if(!nod->loc)
    {
        printf("variabilei nod->loc nu i s-a putut aloca memorie");
        exit(1);
    }

    nod->loc->x = *elem;
    nod->loc->next = NULL;
    nod->next = NULL;

    List *p;
    for(p = BigList; p->next; p = p->next)
        ;
    p->next = nod;
}

void addConcurent(clasament **list, concurent *elem)
{
    clasament *nod = (clasament*)malloc(sizeof(clasament));
    if(!nod)
    {
        printf("variabilei nod nu i s-a putut aloca memorie");
        exit(1);
    }
    nod->x = *elem;
    nod->next = *list;
    *list = nod;
}

void ordConcurenti(List **BigList, concurent *elem)
{
    if((*BigList)->loc->x.punctaj == -1 || (*BigList)->loc->x.punctaj < elem->punctaj)
    {
        addBegin(BigList, elem);
        return;
    }

    for(register List *p = *BigList; p; p = p->next)
        if(p->loc->x.punctaj == elem->punctaj)
        {
            addConcurent(&p->loc, elem);
            return;
        }
        else
            if(p->next)
                if(p->loc->x.punctaj > elem->punctaj && p->next->loc->x.punctaj < elem->punctaj)
                {
                    List *nod = (List*)malloc(sizeof(List));
                    if(!nod)
                    {
                        printf("variabilei nod nu i s-a putut aloca memorie");
                        exit(1);
                    }
                    nod->loc = (clasament*)malloc(sizeof(clasament));
                    if(!nod->loc)
                    {
                        printf("variabilei nod->loc nu i s-a putut aloca memorie");
                        exit(1);
                    }

                    nod->loc->x = *elem;
                    nod->loc->next = NULL;
                    nod->next = p->next;
                    p->next = nod;
                    return;
                }

    addEnd(*BigList, elem);
}

void delList(List **BigList)
{
    while(*BigList)
    {
        List *p;

        p = *BigList;
        *BigList = p->next;

        while(p->loc)
        {
           clasament *q;

           q = p->loc;
           p->loc = q->next;

           free(q->x.nume);
           free(q->x.prenume);
           free(q);
        }

        free(p);
    }

    free(*BigList);
    *BigList = NULL;
}
