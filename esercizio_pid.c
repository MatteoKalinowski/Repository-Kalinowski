#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    pid_t pid, wpid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        exit(67);  // Child exits with a custom status code 100
    } else {
        // Parent process
        printf("Parent process: PID = %d, created child PID = %d\n", getpid(), pid);

        // Parent waits for child to finish
        wpid = wait(&status);
        if (wpid == -1) {
            perror("wait failed");
            exit(1);
        }

        if (WIFEXITED(status)) {
            printf("Child with PID %d exited with status %d\n", wpid, WEXITSTATUS(status));
        } else {
            printf("Child with PID %d did not exit normally\n", wpid);
        }
    }

    return 0;
}
