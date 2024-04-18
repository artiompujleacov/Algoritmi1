---

## Task 1

Am initializat left si right in cautarea binara cu pragul minim si maxim
respectiv.Am calculat valoarea mid care ar fi potential alimentarea optima
a sistemului.La fel calculam puterea maxima pentru alimentarea optima la
dreapta si stanga pe interval,pentru a intelege in care parte a intervalului
se afla valoarea optima a alimentarii.Am calculat puterea maxima pentru
alimentarea optima si am returnat-o.

Complexitatea codului este O(log(n)).

## Task 2

Aceasta problema a fost o proiectare a tuturor scenariilor posibile pentru
un tablou.Am ajuns la ideea ca in cazul initial avem 2 cazuri,cand e un
dreptunghi vertical(acesta poate fi colorat in 3 moduri) si 1
orizontal(practic 2) cu 6 moduri.Astfel am inceput cu aceste calcule:

Pentru secventa unde dupa unul vertical urmeaza unul orizontal,numarul se
inmulteste cu 2

Pentru secventa unde dupa unul orizontal urmeaza unul vertical,numarul se
inmulteste cu 1

Pentru secventa unde dupa unul orizontal urmeaza unul orizontal,numarul se
inmulteste cu 3

Pentru secventa unde dupa unul vertical urmeaza unul vertical,numarul se
inmulteste cu 2

Pentru a eficientiza inmultirea,am folosit fast_pow din laboratorul 2 pentru
secvente lungi de dreptunghiuri de acelasi tip.

Complexitatea codului e O(n).

## Task 3

Am inceput cu a verifica fiecare pozitie din vector la egalitate.Daca sunt
egale,se adauga in vectorul comun,daca nu ,se sumeaza elementul precedent la
elementul urmator pentru vectorul al carui element pe pozitia i e mai mic decat
elementul de pe pozitia i din celalalt vector.Daca nu au fost adaugate toate
elementele,atunci nu s-a putut ajunge la vectori identici si se returneaza -1,
altfel lungimea vectorului comun.

Complexitatea codului e O(n+m).Unde n e lungimea primului vector si m e lungimea
celui de al doilea vector.

## Task 4

Am inceput cu o abordare asemanatoare cu greedy,care a presupus sortarea
cuvintelor dupa (aparitiile literei dominante / lungimea cuvantului).Ideea de
rezolvare a fost urmatoarea:
Se incearca fiecare litera ca dominanta,pare ineficient,dar doar pentru literele
gasite in input imi pica testul 16.Se sorteaza cuvintele dupa formula
mentionata,si incep sa adaug cuvintele in ordine in parola.Am gandit o formula
de tipul "(litere dominante - litere ne dominante - 1)" pentru a sti cat spatiu
mai am in parola,iar pentru cuvintele care urmeaza sa fie adaugate
"litere ne dominante - dominante",si astfel se compun toate secventele posibile
care indeplinesc conditia si se alege cea mai lunga.

Totusi implicand sortarea pe baza formulei mentionate,rezolvarea foloseste \
programare dinamica.
Complexitatea e O(n^2 * m),unde n e numarul de cuvinte si m e lungimea maxima a
unui cuvant.

## Task 5

Am folosit programare dinamica la acest task.Am format toate combinatiile cu
preturile posibile si ofertele oferite.Am pastrat doar M elemente in vector
pentru a spori din complexitate.Am folosit o functie de merge pentru a pastra
elementele in ordine crescatoare si nu a pastra duplicate."auto &x" m-a ajutat
sa scad din timpul pentryu testul 31:).Am returnat pretul nr M crescator.

Complexitatea codului e O(n^2 * m),unde n e numarul de oferte si m e numarul de
preturi totale pe care le pastrez in vector.

Pujleacov Artiom 325CB

---
