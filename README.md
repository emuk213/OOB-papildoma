# OOB-papildoma

1. main.cpp - main programos failas
2. MyLib.h - įtrauktos reikalingos bibliotekos
3. Functions.cpp - failas, kuriame realizuotos funckijos
4. Wrds.h - realizuota `Wrds` klasė, surašytos funkcijų deklaracijos.

Šioje programoje yra 4 funkcijos:
* read - nuskaito tekstą iš pateikto failo, sudeda juos į `map` konteinerį ir skaičiuoja žodžių pasikartojimą bei žymi eilutes, kuriose yra tas žodis (naudojama aibė `set`).
* removePunctuation - pašalina simbolius iš žodžio pradžios ir pabaigos, pvz kablelis. Taip pat visas raides paverčia mažosiom. Grąžina "švarų" žodį.
* findURL - nuskaito teksta ir jame suranda visus **www.**, **http://** ir **svetainė.com** pavidalo URL adresus.
* output - funkcija išveda į naują txt failą žodžius, kurie pasikartojo daugiau nei kartą, jų pasikartojimo tekste kiekį ir kuriose eilutėse jie yra.
