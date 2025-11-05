#include <stdio.h>

struct FRAZIONE {
    int numeratore;
    int denominatore;
};

void semplificaFrazione(int numero_originale, int denominatore_originale, int *numero_semplificato, int *denominatore_semplificato) {
    *numero_semplificato = numero_originale;  
    *denominatore_semplificato = denominatore_originale; 
}

int sommaFrazioni(struct FRAZIONE f1, struct FRAZIONE f2, struct FRAZIONE *risultato) {
    if (f1.denominatore == 0 || f2.denominatore == 0) {
        return -1; 
    }

    int N = f1.numeratore * f2.denominatore + f2.numeratore * f1.denominatore;
    int D = f1.denominatore * f2.denominatore;

    semplificaFrazione(N, D, &((*risultato).numeratore), &((*risultato).denominatore));
    return 0;
}

int main() {
    struct FRAZIONE f1 = {3, 4};
    struct FRAZIONE f2 = {1, 2};
    struct FRAZIONE risultato;

    sommaFrazioni(f1, f2, &risultato);
    printf("Risultato: %d/%d\n", risultato.numeratore, risultato.denominatore);

    return 0;
}
