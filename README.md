# CERINTA
Crearea unui tabel cu pozitiile concurentiilor, in urma obtinerii rezultatelor.
Acest program primeste ca date de intrare informatiile prinvind fiecare concurent, respectiv numele, prenumele si 
punctajul acestuia.
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

In concurs sunt inscrisi mai multi concurenti, despre care se stiu numele, prenumele si punctajul obti
