# Duomenu apdorojimas
# Kaip paleisti:
+ Susikompiliuoti naudojant makefile t.y parasius komanda "make run" i komandine eilute.
+ Paleisti programa. (defaultinis pavadinimas - test)
# v0.1
+ Visu duomenu ivedimas ir skaiciavimas, studentu sk - neribotas, duomenis vedami iki tol kol vartotojas nusprendzia sustoti, su pazymiais viskas taip pat.
+ Prideta papildoma funkcija (jei vartotojas tarkim varda ir pavarde paraso taip - vARDenis PAVARDEnis. Programa issaugos - Vardenis Pavardenis)
# v0.2
+ Prideta galimybe skaityti is failo - kursiokai.txt
+ Surusiavimas pagal vardus, jei vardai lygus - pavardes
# v0.3
+ Visos naudojamos funkcijos atskirame .cpp faile
+ Panaudojas try-catch
# v0.4
+ Prideta galimybe susigeneruoti sabloniniu vardu ir pavardziu spartos analizei atlikti.
+ Rusiavimas tu sugeneruotu duomenu i failus vargsai.txt ir kieti.txt

|   Stud. sk.   |   Generavimas   |   Nuskaitymas   |   Rusiavimas   |   Isvedimas   | 
| ------------- |:-------------:| -----:|-----:|-----:|
| 10000 | 0.0468461 sec. |0.124994 sec. |   0 sec. |   0.140621 sec. |
| 100000 | 0.42184 sec. | 1.28993 sec. |   0.0468736 sec. | 1.36299 sec. |

P.S. Studentu skaicius prasideda nuo 10000, kadangi pries tai programa veikdavo labai greitai ir visur rodydavo 0.

# v0.5
+ Programa pateikta 3 variantais t.y naudojant skirtingus konteinerius - vector,deque ir list.

Viskas buvo matuojama naudojant 100000 studentu. Strategija tokia - sukuriami 2 nauji konteinerai vargsai ir kieti. I juos pushinami tam tikri studentai. Suskircius juos trinamas pradinis konteineris, kuris turejo visus 100000 studentu.

|   Konteineris   |   Nuskaitymas   |   Rusiavimas   |
|-----:|-----:|-----:|
|   **Vector** |   1.28993 sec. | 0.0468736 sec. | 
|   **Deque** |   1.3219 sec. | 0.0468746 sec. | 
|   **List** |   1.26558 sec. | 0.0625055 sec. | 
# v1
+ Programa padaryta pagal 2 strategija.
+ Pateikti 3 jos variantai.
+ Pamatytas zenklus skirtumas tarp vector,deque ir list. Vector pasirodė prasčiausiai, deque kiek geriau, o list greitesnis uz juos apie 20 kartu.
