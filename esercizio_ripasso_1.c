#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Processo principale avviato. PID = %d\n", getpid());

    int pid = fork();

    if (pid < 0) {
        // Errore nella creazione del processo
        perror("Errore nella fork");
        exit(1);
    }

    if (pid == 0) {
        // ---- PROCESSO FIGLIO ----
        printf("\n[FIGLIO] Sono il processo figlio!\n");
        printf("[FIGLIO] Mio PID = %d\n", getpid());
        printf("[FIGLIO] PID del padre = %d\n", getppid());

        printf("[FIGLIO] Simulo lavoro con sleep(2)...\n");
        sleep(2);

        int risultato = 10 * 5;
        printf("[FIGLIO] Calcolo: 10 * 5 = %d\n", risultato);

        printf("[FIGLIO] Terminazione con codice 42.\n");
        exit(42);  
    }
    else {
        // ---- PROCESSO PADRE ----
        printf("\n[PADRE] Sono il processo padre.\n");
        printf("[PADRE] Mio PID = %d\n", getpid());
        printf("[PADRE] PID del figlio = %d\n", pid);

        int status;
        printf("[PADRE] Attendo la terminazione del figlio...\n");

        wait(&status);

        printf("[PADRE] Il figlio è terminato.\n");

        // Analisi dello status
        if (WIFEXITED(status)) {
            int codice = WEXITSTATUS(status);
            printf("[PADRE] Il figlio è terminato normalmente.\n");
            printf("[PADRE] Codice di uscita = %d\n", codice);
        }
        else if (WIFSIGNALED(status)) {
            int segnale = WTERMSIG(status);
            printf("[PADRE] Il figlio è stato terminato da un segnale.\n");
            printf("[PADRE] Segnale = %d\n", segnale);
        }

        printf("[PADRE] Fine esecuzione.\n");
    }

    return 0;
}
