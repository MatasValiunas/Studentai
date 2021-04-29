# Studentai

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

#### 1 Strategija (O1)

Konteinerio skirstymo laikas (s) į du naujus to paties tipo konteinerius. 
| Konteineriai             |  10.000 | 100.000 | 1.000.000 |
| :---------------------------- |:------ | :-------- | :--------- | 
| vector  |  0.0020 | 0.0209   | 0.2059   |
| list  |  0.0025 | 0.0285   | 0.2600    |
| deque |  0.0014 | 0.0174   | 0.1630    | 

---

#### 1 Strategija (O2)

Konteinerio skirstymo laikas (s) į du naujus to paties tipo konteinerius. 
| Konteineriai             |  10.000 | 100.000 | 1.000.000 |
| :---------------------------- |:------ | :-------- | :--------- | 
| vector  |  0.0019 | 0.0210   | 0.2069   |
| list  |  0.0024 | 0.0264   | 0.2560    |
| deque |  0.0014 | 0.0180   | 0.1649    | 

---

#### 1 Strategija (O3)

Konteinerio skirstymo laikas (s) į du naujus to paties tipo konteinerius. 
| Konteineriai             |  10.000 | 100.000 | 1.000.000 |
| :---------------------------- |:------ | :-------- | :--------- | 
| vector  |  0.0019 | 0.0220   | 0.2070   |
| list  |  0.0025 | 0.0265   | 0.2530    |
| deque |  0.0014 | 0.0184   | 0.1590    | 

---

#### 2 Strategija (O2)

Konteinerio skirstymo laikas (s), kai sename konteineryje paliekami pažengę studentai, o į naują perkeliami atsilikę studentai.
| Konteineriai              | 10.000 | 100.000 | 1.000.000 |
| :---------------------------- | :------ | :-------- | :--------- | 
| vector  | 0.0024 | 0.0265   | 0.2280   |
| list  |  0.0024 | 0.0260   | 0.2315    |
| deque |  0.0024 | 0.0274   | 0.2525    | 

---

#### Klasių ir struktūrų palyginimas (1 Strategija, deque)

|             |  10.000 | 100.000 | 1.000.000 |
| :---------------------------- | :------ | :-------- | :--------- | 
| Klasė   | 0.0014 | 0.0180   | 0.1649   |
| Struktūra  | 0.0059 | 0.0609   | 0.5859    |

---

### Duomenų nuskaitymo iš failo laikai
| Konteineris   | 1.000  | 10.000  |100.000 | 1.000.000 |
| :---------- | :------ | :------ | :------ | :-------- |
| vector  | 0.0035 | 0.0235  | 0.2275 | 2.2210   |
| list   | 0.0030 | 0.0240  | 0.2315 | 2.2835  | 
| deque | 0.0030 | 0.0245  | 0.2260 | 2.2360   | 

---

[v1.5](https://github.com/MatasValiunas/Studentai/tree/v1.5) - studentų klasė išvesta iš naujos virtualios žmogaus klasės.

[v1.2](https://github.com/MatasValiunas/Studentai/tree/v1.2) - realizuotas **Rule of 3**.

[v1.1](https://github.com/MatasValiunas/Studentai/tree/v1.1) - studentai nuo šiol laikomi ne struktūrose, o klasėse.

[v1.0](https://github.com/MatasValiunas/Studentai/tree/v1.0) - yra 2 būdai skirstyti studentus.

[v0.5](https://github.com/MatasValiunas/Studentai/tree/v0.5) - pridėta galimybė talpinti duomenis ne tik vektoriuose, bet ir list'uose ir deque'uose.

[v0.4](https://github.com/MatasValiunas/Studentai/tree/v0.4) - pridėta galimybė generuoti duomenų failus, studentai pagal savo galutinį balą skirstomi į 2 grupes, matuojamas tam tikrų operacijų atlikimo laikas.

[v0.3](https://github.com/MatasValiunas/Studentai/tree/v0.3) - sukurti header, Makefile ir kiti cpp failai dėl paprastesnio naudojimo. Pridėtas failo skaitymo tikrinimas (try, catch).

[v0.2](https://github.com/MatasValiunas/Studentai/tree/v0.2) - galima rinktis ar duomenis vesti ranka, ar skaityti iš failo. Skaitant iš failo, programa automatiškai apskaičiuoja kiek yra namų darbų. Taip pat yra išvedimas į failą. Yra vardų rūšiavimas.

[v0.1](https://github.com/MatasValiunas/Studentai/tree/v0.1) - galima skaičiuoti vidurkius ir medianas tiek su masyvais (mas.cpp), tiek su vektoriais (vekt.cpp). Yra atsitiktinių skaičių generavimas.
