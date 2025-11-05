#include <stdio.h>
int calcolototalepasseggeri(int identificativo, int numerofermate) {
    int numeropasseggeri; // variabile per memorizzare i passeggeri che salgono a ogni fermata
    int tot = 0;          // variabile per sommare il totale dei passeggeri
    // ciclo che viene ripetuto per ogni fermata
    for (int i = 0; i < numerofermate; i++) {
        // domando all'utente il numero di persone che salgono su questa fermata
        printf("inserisci il numero di passeggeri saliti alla fermata %d: ", i + 1);
        scanf("%d", &numeropasseggeri);
        tot += numeropasseggeri; // aggiungo il numero appena inserito al totale
    }
    return tot; // restituisco il valore totale dei passeggeri saliti dall'inizio del percorso fino alla fine
}
int main() {
    int identificativo, numerofermate, totalepasseggeri;
    // ciclo che si ripete fino a quando non inserisco "0"
    while (1) {
        // viene richiesto l'identificativo del bys
        printf("inserisci identificativo autobus (0 per terminare): ");
        scanf("%d", &identificativo);
        // se l'identificativo corrisponde a 0, termino il ciclo, che corrisponde tra l'altro alla fine del programma
        if (identificativo == 0) {
            break;
        }
        // chiedo il numero di fermate per quel bus
        printf("inserisci numero di fermate: ");
        scanf("%d", &numerofermate);
        // richiamo la funzione per calcolare il totale passeggeri
        totalepasseggeri = calcolototalepasseggeri(identificativo, numerofermate);
        // printo il risultato per l'autobus corrente
        printf("autobus %d: totale passeggeri saliti = %d\n", identificativo, totalepasseggeri);
    }
    // messaggio finale di chiusura del programma
    printf("programma terminato.\n");
    return 0;
}
