#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid_figlio1, pid_nipote;
    int status;

    printf("PADRE: PID=%d, PPID=%d\n", getpid(), getppid());

  
    pid_figlio1 = fork();
    if (pid_figlio1 < 0) {
        perror("Errore nella fork del FIGLIO 1");
        exit(EXIT_FAILURE);
    }

    if (pid_figlio1 == 0) {
   
        printf("FIGLIO 1: PID=%d, PPID=%d\n", getpid(), getppid());

     
        pid_nipote = fork();
        if (pid_nipote < 0) {
            perror("Errore nella fork del NIPOTE");
            exit(EXIT_FAILURE);
        }

        if (pid_nipote == 0) {
            // Questo è il NIPOTE
            printf("NIPOTE: PID=%d, PPID=%d\n", getpid(), getppid());
            int risultato = 7 * 6;
            printf("NIPOTE: Calcolo 7*6 = %d\n", risultato);
            sleep(1); 
            exit(99); 
        } else {
          
            if (waitpid(pid_nipote, &status, 0) == -1) {
                perror("Errore in waitpid FIGLIO 1");
                exit(EXIT_FAILURE);
            }
            if (WIFEXITED(status)) {
                printf("FIGLIO 1: NIPOTE terminato con codice %d\n", WEXITSTATUS(status));
            }
            exit(50);
        }
    } else {

        if (waitpid(pid_figlio1, &status, 0) == -1) {
            perror("Errore in waitpid PADRE");
            exit(EXIT_FAILURE);
        }
        if (WIFEXITED(status)) {
            printf("PADRE: FIGLIO 1 terminato con codice %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
