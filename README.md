# CERINTA
Crearea unui tabel cu pozitiile concurentiilor, in urma obtinerii rezultatelor.
Acest program primeste ca date de intrare informatiile prinvind fiecare concurent, respectiv numele, prenumele si punctajul acestuia.  
Rezultatul final va putea fi vizualizat intr-un fisier Excell, care se va numi "tabelConcurenti.xlt".

# PRINCIPALELE STRUCTURI UTILIZATE

typedef struct {    
  char *nume, *prenume;             
  unsigned int punctaj;         
} concurent; 

typedef struct a{
    concurent x;
    struct a *next;
} clasament;

In concurs sunt inscrisi mai multi concurenti, despre care se stiu numele, prenumele si punctajul obtinut de catre acesta. Pentru a se crea clasamentul, se va utiliza tipul clasament, astfel aici se vor retine concurentii, care au acelasi punctaj.  
Acestea fiind principalele structuri utilizate.

# FUNCTIA MAIN
In main se produc toate operatiile necesare rezolvarii acestui program.
> citirea datelor despre fiecare cocncurent si salvarea acestora intr-un clasament
> afisarea in tabel a concurentiilor
> eliberarea memoriei utilizate de catre program

# BIBLIOTECA
Este utilizata o singura biblioteca "excellLib.h", care contine, atat toatre structurile necesare, cat si includerea bibliotecilor necesare, precum <stdio.h>, <stdlib.h> si <string.h>.  
De asemenea, aici sunt declarate toate functiile create, care prelucreaza citirea sirurilor de caractere si gestionarea concurentiilor.

# TASK
Porgramul primeste de la tastatura informatiile privind fiecare concurent in parte, respectiv numele si prenumele, care sunt percepute ca niste cuvinte, in cazul, in care utilizatorul incearca sa introduca spatii in sir, acesta va fi pus sa reintroduca sirul, dar si punctajul obtinut.

!! FUNCTIILE PENTRU CITIRE -> create.c
!! FUNCTIILE PENTRU GESTIONAREA CONCURENTILOR -> functiList.c

Pentru o usoara gestiune a datelor, concurentii sunt retinuti intr-o lista comuna, in ordine descrescatoare a punctajului obtinut. Lista, care este vazuta un element al unei liste mai mari, care ierarhizeaza listele cu concurenti, dupa punctaje, 2concurenti, care au obtinut acelasi punctaj se vor afla in aceeasi lista.  
In acest mod, la finalizarea citirii, este creat clasamentul final.
> CONCURENTI - CLASAMENT - TOP

Output: ![image](https://github.com/user-attachments/assets/e7b7b7cf-1134-4f5d-8729-51e2870dae42)

Pentru a realiza aceasta formatare in Excell, fara utilizarea unei biblioteci specializate, tabelul va fi construit pe linii.  
Prima linie. Numar Locul 1 Locul 2 ... Locul n  
A doua linie. Nume Prenume Punctaj Nume ... Nume Prenume Punctaj  
A treia linie - Ultima linie. Informatiile concurentiilor (clasamentul propriu-zis)

Concurentii vor fi ordonati descrescator dupa punctaj, de la stanga la dreapta, iar pe coloane vor aparea toti concurentii, care au acelasi punctaj obtinut, astfel in timpul afisarii se va parcurge intreaga lista, dar la o iteratie se vor afisa cate un concurent din fiecare lista, daca aexista, altfel se va afisa - - -.
