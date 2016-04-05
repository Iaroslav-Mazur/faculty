Creati o clasa Eval cu care puteti sa evaluati expresii matematice simple.
* O expresie matematica simpla este formata din numere intregi din intervalul [0..9] si operatori simpli (+,-)
* Orice alt caracter care apare intr-o expresia matematica este invalid si invalideaza expresia
* exemple de expresii valide "1+1", "1+5-2", "1-9+2+3+2-2+4"
* exemple de expresii invalida "1++1", "10+2" (10 nu e in intervalul [0..9]), "2+2+", ultimul + nu e ok, "1*3" (* nu e operator valid)

Trebuie sa creati clasa Eval (eval.h si eval.cpp) care sa implementeze clasa AbstractEval.
Se acorda 2 pct pentru implementarea corecta a acestei clase (membri in clasa si constructor).

Fisierele nu contin si include-urile necesare (acestea trebuie sa le adaugati voi).
2pct se dau daca programul compileaza.
Pentru stocarea expresiei si analiza ei veti folosi containere STL.