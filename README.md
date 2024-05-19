CREAREA UNUI FISIER EXCELL, CARE CONTINE CLASAMENTUL CONCURENTILOR IN FUNCTIE DE PUNCTAJUL OBTINUT
•	Se da de la tastatura numarul de concurenti si informatii despre fiecare (nume, prenume, punctaj)
•	Concurentii sunt cititi in ordinea, in care sunt dati, fiind ordonati in timpul citirii intr-o lista de liste, adica se crea o lista principala, care va fi ordonata descrescator dupa punctaj, iar fiecare element al listei va contine o lista cu toti concurentii, care au obtinut acelasi punctaj
ex. Ioan Vlad 10 – Anghelache Vlad 10
    Dan Ioana 8 
    Mihai Cosmin 7 – Branescu Leo 7 
•	Lista poate fi vizualizata ca o matrice
ex. Ioana Vlad 10      Dan Ioana 8 Mihai Cosmin 7
    Anghelache Vlad 10             Branescu Leo 7, unde prima linie reprezinta lista principala, care contine listele date de coloanele cu concurentii, care au acelasi punctaj
•	Pe parcursul citirii, concurentii sunt ordonati in functie de punctaj, astfel apar 4posibilitati de introducere a concurentilor: adaugarea unui concurrent cand lista este goala, adaugarea unui concurrent cu punctaj maxim, adaugarea unui concurrent cu punctaj minim si adaugarea unui concurrent cu punctaj echivalent, adica este deja create o lista pentru acest punctaj
•	In cazul in care lista este COMPLET goala, se va introduce concurentul ca fiind capul listei, daca concurentul are punctaj maxim, respective are un punctaj mai mare decat cei din primul elem al listei, atunci aceasta il va inlocui (ex. Dan Narcis 10, Dan Ioana 9; cum 10>9, atunci Dan Narcis trebuie sa ocupe prima pozitie), daca punctajul este minim, atunci va fi adaugat la final
•	Daca concurentul trebuie sa fie introdus intre 2concurenti sau este deja create o lista corespunzatoare punctajului este necesara parcurgerea intregii liste, astfel se vor face urmatoarele verificari: daca punctajul concurentului este regasit, atunci acesta va fi adaugat ca si cap al listei (ex. Dan Narcis 9 – Dan Ioana 9 – Vlad Ioan 9, Dan Narcis este noul concurent introdus) sau daca punctajul este cuprins intre 2liste (ex. 10 > 8 > 6)
•	Dupa crearea listei se va face afisarea intr-un fisier de tip excell (“tabelConcurenti.xlt”), avand urmatoarea forma: (cea din fisierul excell)
•	Afisarea se va face pe linii, mai intai se numara notele obtinute si se tine cont ca pentru fiecare pozitie se va afisa Nume, Prenume, Punctaj
•	Concurentii vot fi ordonati descrescator dupa punctaj, de la stanga la dreapta, iar pe coloane vor aparea toti concurentii, care au acelasi punctaj obtinut, astfel in timpul afisarii se va parcurge intreaga lista, dar la o iteratie se doar un concurent din lista mica
ex. 2 Ana Maria 10 Toader Vlad 8 - - - Cristian Cristian 5, in cazul de fata – inseamna ca nu exista concurent pe linia 2
