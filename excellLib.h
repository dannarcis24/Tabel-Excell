#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *nume, *prenume;
    unsigned int punctaj;
} concurent;

typedef struct a{
    concurent x;
    struct a *next;
} clasament;

typedef struct b{
    clasament *loc;
    struct b *next;
} List;

// FUNCTII SIRURI
char* citireSir();

// FUNCTII CREARE LISTA
concurent* citire();
void addBegin(List**, concurent*);
void addEnd(List*, concurent*);
void addConcurent(clasament**, concurent*);
void ordConcurenti(List**, concurent*);
void delList(List**);
