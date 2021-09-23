# Blockchain
## **Išvados**
- [x] nepriklausomai nuo Input'o, Output'ai visada yra vienodo dydžio, o to paties failo hash'as yra tas pats
- [x] greitas, efektyvus :tada:
- [x] Maišos funkcijos įėjimas (angl. input) gali būti bet kokio dydžio simbolių eilutė
- [x] Maišos funkcijos išėjimas (angl. output) visuomet yra to paties, fiksuoto, dydžio rezultatas

| Input  | Output |
| ------------- | ------------- |
| labas  | 6C61626173DBF6E1F4B8DFE3FAE5AAD9EEE9EFBED9F4FCEBABC2E5EEEDA6D1EF  |
| sveiki  | 737665696B69A7AAFDD4D8CBABAAF5C2C5CEADB3E6CDDCD0A3BFE6C5CACDA6B9  |
- [x] Maišos funkcija yra deterministinė

| Input  | Output |
| ------------- | ------------- |
| taip  | 74616970BBF6CDB0A4EBC3B2B1E2CDAAB1EFD6A9A0F0CBA7A2E5C2A9BAE5CFB2  |
| taip  | 74616970BBF6CDB0A4EBC3B2B1E2CDAAB1EFD6A9A0F0CBA7A2E5C2A9BAE5CFB2  |
- [x] Iš hash funkcijos rezultato (output'o) praktiškai neįmanoma atgaminti pradinio įvedimo (input'o)
Naudojamos bitset XOR operacijos, pakeičiamos bitų vietos
```
bitset<8> bs4(s[i]);
bitset<8> bar(stringas[i]);
bitset<8> bs3(bs4 <<= 2);
bitset<8> rez(bs3 ^= bar);
```
**Nepavykę dalykai:**
- ***Vidurinėje pozicijoje pakeitus simbolį hashas liko tas pats***
- ***Nepavyko susigeneruoti 100k simbolių eilučių kur skirtųsi tik vienu simboliu***
## **Pirma užduotis**
- **Du failai, skirtingas vienas simbolis**

![This is an image](/assets/vienas.png)\
![This is an image](/assets/vienas2.png)\
- **>1000 atsitiktinai sugeneruoti failai**

![This is an image](/assets/simboliai1.png)\
![This is an image](/assets/simboliai2.png)\
- **>1000 vidurinėje pozicijoje skirtingi failai**

![This is an image](/assets/skiriasi1.png)\
![This is an image](/assets/skiriasi2.png)\
- **Tuščias failas**

![This is an image](/assets/tusciasfailas.png)

## **Antra užduotis**
**Hashuoti konstitucija.txt failą užtruko:**

![This is an image](/assets/konsti.png)

## **Trečia užduotis**
**Ar sutampa hashai su 25 000 po 500 simbolių:**

![This is an image](/assets/sutapimai500.png)\
**Ar sutampa hashai su 25 000 po 1000 simbolių:**

![This is an image](/assets/sutapimai1000.png)
