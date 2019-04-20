# Duomenu apdorojimas
# Kaip paleisti:
+ Susikompiliuoti naudojant makefile t.y parasius komanda `make run` i komandine eilute. (Veikia tik su mac ir unix OS)
+ Paleisti programa parasius komanda `./test`.
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
+ Programa padaryta pagal 3 strategijas.
+ Pateikti 3 jos variantai su 3 skirtingais konteineriais.

|   Konteineris   |   1 Strategija   |    2 Strategija     |    3 Strategija     |
|-----:|-----:|-----:|-----:|
|   **Vector** |  0.0468736 sec. | 178.082 sec. | 0.0312524 sec. | 
|   **Deque** |  0.0468746 sec. | 90.0643 sec. | 0.0468746 sec. | 
|   **List** |   0.0625055 sec. | 0.0312511 sec. | - | 

Naudojamas studentu skaicius - 100000. Naudojant 1 strategija (kurioje neefektyviai naudojama atmintis) Vector ir Deque konteineriai pasirode geriau. Taciau pritaikius 2 strategija kurioje atmintis naudojama zymiai efektyviau t.y trinant nereikalingus duomenis rusiuojant Vector pasirode blogiausiai, Deque ta darba atliko praktiskai 2x greciau! O List visai apie 6000x greiciau! Panaudojus 3 strategija (naudojant stable_partition) Vector konteineris pasirode ne ka blogiau nei List. (Pabandziau ir Deque su stable_partition, rezultatas pasidare taip pat zymiai geresnis, taciau ne toks geras kaip su Vector ar List.
