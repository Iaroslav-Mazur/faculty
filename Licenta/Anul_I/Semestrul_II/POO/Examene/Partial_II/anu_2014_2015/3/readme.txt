Creati o clasa care sa reprezinte un graf.
Un graf este format dintr-o multime de puncte si o multime de muchii.
Un nod(punct) este caracterizat prin coordonatele sale intr-un spatiu bidimensional (x,y), o valoare si alte atribute pe care o sa le adaugati voi.
O muchie este caracterizata prin indecsii celor doua puncte din graf pe care le uneste.
Fisierele nu contin si include-urile necesare (acestea trebuie sa le adaugati voi).
Un graf este conex daca intre oricare doua noduri alese aleator exista un drum. Cea mai simpla metoda sa verificati acest lucru se face in felul urmator:
1) atribuiti la fiecare nod o culoare de inceput (-1)
2) luati un nod random din lista
3) setati culoarea nodului la 0
4) luati lista de vecini si daca vreunul dintre ei are culoarea -1 repetati pasul 3
5) dupa ce ati terminat de parcurs graf-ul in acest mod, daca mai exista un nod care sa aiba culoarea -1, atunci graf-ul NU este conex
2pct se dau daca programul compileaza.
Pentru stocarea cuvintelor veti folosi containere STL.