# 2-uzduotis

**Programa, skaičiuojanti studentų galutinį balą pagal jų namų darbų vidurkius arba medianas ir egzaminą; juos suskirsto į "kietus" ir "minkštus" pagal jų galutinį balą.**

**Norint paleisti programą, reikia:** 
  * atsisiųsti **main.cpp**, **func.cpp**, **header.hpp** ir **Makefile**
  * paleisti programą, kompiliuojančią kodą (Visual Studio, Visual Studio Code ir t.t.)
  * per **terminal**'ą nukeliauti su **cd** komanda į aplanką, kuriame yra atsiųstas failas
  * **terminal**'e parašyti "**mingw32-make**"
  * **terminal**'e parašyti "**./ats**"
  
**Programos veikimas:**
  * Pasirinkti ar norima, kad duomenų failai būtų sugeneruoti
  * Pasirinkti ar skaityti duomenis iš failo (jei taip, tai nurodyti failą ir keliauti į paskutinį žingsnį)
  * Pasirinkti ar balus generuoti atsitiktinai
  * Įrašyti studento vardą ir pavardę
  * Jei balai negeneruojami atsitiktinai, tai juos įrašyti
  * Pasirinkti ar pridėti naują studentą (jei taip, tai viskas kartojasi nuo 2 žingsnio)
  * Pasirinkti studentų rūšiavimo būdą

Setup:
* CPU - AMD Ryzen 5 2600
* RAM - 16 GB
* SSD

#### 1 Strategija

Konteinerio skirstymo laikas (s) į du naujus to paties tipo konteinerius. 
| Konteineriai             | 1.000 | 10.000 | 100.000 | 1.000.000 |
| :---------------------------- | :------ | :------ | :-------- | :--------- | 
| vector  | 0.0010 | 0.0074 | 0.0709   | 0.7125   |
| list  | 0.0004 | 0.0070 | 0.0714   | 0.6914    |
| deque | 0.0005 | 0.0059 | 0.0609   | 0.5859    | 

---

#### 2 Strategija

Konteinerio skirstymo laikas (s), kai sename konteineryje paliekami pažengę studentai, o į naują perkeliami atsilikę studentai.

| Konteineriai  | 1.000  | 10.000  | 100.000 | 1.000.000 | 
| :---------------------------- | :------ | :------ | :-------- | :--------- |
| vector | 0.0009 | 0.0089 | 0.0920  | 0.8604   | 
| list  | 0.0015 | 0.0094 | 0.0969   | 0.9609    | 
| deque| 0.0010 | 0.0084 | 0.0890   | 0.9125    | 

---

### Duomenų nuskaitymo iš failo laikai
| Konteineris   | 1.000  | 10.000  |100.000 | 1.000.000 |
| :---------- | :------ | :------ | :------ | :-------- |
| vector  | 0.0035 | 0.0235  | 0.2275 | 2.2210   |
| list   | 0.0030 | 0.0240  | 0.2315 | 2.2835  | 
| deque | 0.0030 | 0.0245  | 0.2260 | 2.2360   | 

---

[v1.0](https://github.com/MatasValiunas/2-uzduotis/tree/v1.0) - yra 2 būdai skirstyti studentus.

[v0.5](https://github.com/MatasValiunas/2-uzduotis/tree/v0.5) - pridėta galimybė talpinti duomenis ne tik vektoriuose, bet ir list'uose ir deque'uose.

[v0.4](https://github.com/MatasValiunas/2-uzduotis/tree/v0.4) - pridėta galimybė generuoti duomenų failus, studentai pagal savo galutinį balą skirstomi į 2 grupes, matuojamas tam tikrų operacijų atlikimo laikas.

[v0.3](https://github.com/MatasValiunas/2-uzduotis/tree/v0.3) - sukurti header, Makefile ir kiti cpp failai dėl paprastesnio naudojimo. Pridėtas failo skaitymo tikrinimas (try, catch).

[v0.2](https://github.com/MatasValiunas/2-uzduotis/tree/v0.2) - galima rinktis ar duomenis vesti ranka, ar skaityti iš failo. Skaitant iš failo, programa automatiškai apskaičiuoja kiek yra namų darbų. Taip pat yra išvedimas į failą. Yra vardų rūšiavimas.

[v0.1](https://github.com/MatasValiunas/2-uzduotis) - galima skaičiuoti vidurkius ir medianas tiek su masyvais (mas.cpp), tiek su vektoriais (vekt.cpp). Yra atsitiktinių skaičių generavimas.
