Creati o reprezentare a unui obiect de tipul arbore care sa respecte definitiile din fisierul tree.h si node.h.
Pentru a tine lista de copii veti folosi un container de tipul vector sau deque.
Functia Show din clasa Tree afiseaza valorile nodurilor in felul urmator:
* mai intai se afiseaza valoarea nodului curent
* daca nodul curent are copii, se afiseaza valoarea din nodurile copii in ordinea inversa in care au fost adaugate
Fisierele nu contin si include-urile necesare (acestea trebuie sa le adaugati voi).
2pct se dau daca programul compileaza.

Exemplu:
Consideram urmatoarea descriere pentru Nod: valoare(subarbore_copil_1,subarbore_copil_2, ... subarbore_copil_n)
Daca avem urmatorul arbore:

5(1, 2(10, 20(100, 200), 30), 3, 4)

Atunci functia Show va afisa:
5 4 3 2 30 20 200 100 10 1