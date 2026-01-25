# Raport: Funcții Interzise în libft

## Funcții Detectate

Testul detectează următoarele funcții interzise în bibliotecă:

### 1. `memset` - în `ft_memset.o`
**Cauză:** Compilatorul GCC cu optimizare `-O3` recunoaște bucla din `ft_memset`:
```c
while (len)
    ((unsigned char *)b)[--len] = (unsigned char)c;
```
și o optimizează automat în apel la funcția builtin `memset`.

**De ce este interzisă:**
- libft trebuie să implementeze propriile versiuni ale funcțiilor standard
- Testul verifică dacă biblioteca folosește funcții standard în loc de implementări proprii
- Folosirea funcțiilor builtin înseamnă că nu ai implementat tu funcția

**Soluție:** Adăugare flag `-fno-builtin-memset` în Makefile

---

### 2. `memcpy` - în `ft_strjoin.o`
**Cauză:** Compilatorul optimizează buclele de copiere manuală:
```c
while (i < len1) {
    join[i] = s1[i];
    i++;
}
while (i < len2) {
    join[len1 + i] = s2[i];
    i++;
}
```
și le înlocuiește cu apeluri la `memcpy` builtin pentru performanță.

**De ce este interzisă:**
- Similar cu `memset`, trebuie să folosești implementarea ta `ft_memcpy`
- Optimizarea compilatorului încalcă regula de a nu folosi funcții standard

**Soluție:** 
- Adăugare flag `-fno-builtin-memcpy` în Makefile
- SAU folosire explicită a `ft_memcpy` în loc de bucle manuale

---

### 3. `memcpy` - în `ft_substr.o`
**Cauză:** Similar cu `ft_strjoin`, compilatorul optimizează bucla:
```c
while (i < len) {
    sub[i] = s[start + i];
    i++;
}
```

**Soluție:** 
- Adăugare flag `-fno-builtin-memcpy` în Makefile
- SAU folosire explicită a `ft_memcpy`

---

## Lista Completă de Funcții Interzise

Conform `display_test_result.c`, următoarele funcții sunt interzise:
- `memset`, `bzero`, `memcpy`, `memchr`, `memcmp`
- `strlen`, `strdup`, `strcpy`, `strncpy`
- `strcat`, `strncat`, `strlcat`
- `strchr`, `strrchr`, `strstr`, `strnstr`
- `strcmp`, `strncmp`
- `atoi`

**Motiv:** Aceste funcții trebuie implementate de tine în libft. Testul verifică că nu folosești versiunile standard din biblioteca C.

---

## Soluții Recomandate

### Soluția 1: Flag-uri Compilator (Recomandat)
Adaugă în Makefile flag-urile `-fno-builtin-*` pentru toate funcțiile interzise:
```makefile
-fno-builtin-memset -fno-builtin-memcpy -fno-builtin-bzero \
-fno-builtin-memmove -fno-builtin-memchr -fno-builtin-strlen \
-fno-builtin-strdup -fno-builtin-strcpy -fno-builtin-strncpy \
-fno-builtin-strcat -fno-builtin-strncat -fno-builtin-strlcat \
-fno-builtin-strchr -fno-builtin-strrchr -fno-builtin-strstr \
-fno-builtin-strnstr -fno-builtin-strcmp -fno-builtin-strncmp \
-fno-builtin-atoi
```

### Soluția 2: Folosire Explicită a Funcțiilor ft_*
În loc de bucle manuale, folosește `ft_memcpy`:
```c
// În loc de:
while (i < len) {
    dest[i] = src[i];
    i++;
}

// Folosește:
ft_memcpy(dest, src, len);
```

### Soluția 3: Reducere Optimizare
Schimbă `-O3` cu `-O0` sau `-O1`, dar aceasta reduce performanța.

---

## Verificare

După aplicarea soluției, verifică cu:
```bash
nm -u libft.a | grep -E "_(memset|bzero|memcpy|...)"
```
Nu ar trebui să apară simboluri nedefinite pentru funcțiile interzise.
