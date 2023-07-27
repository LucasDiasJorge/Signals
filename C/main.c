#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signal) {
    printf("Sinal %d recebido\n", signal);
    if(signal == 15){
        exit(0);
    }
}

int main() {

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // processo filho
        printf("Filho iniciado com PID %d\n", getpid());
        signal(SIGTERM, signal_handler);
        while (1) {
            printf("Processo filho rodando...\n");
            sleep(1);
        }
    } else {
        // processo pai
        printf("Pai iniciado com PID %d\n", getpid());
        sleep(5);
        printf("Enviando sinal SIGSTOP para o processo filho...\n");
        kill(pid, SIGSTOP);
        sleep(5);
        printf("Enviando sinal SIGCONT para o processo filho...\n");
        kill(pid, SIGCONT);
        sleep(5);
        printf("Enviando sinal SIGTERM para o processo filho...\n");
        kill(pid, SIGTERM);
        wait(NULL);
        printf("Processo filho finalizado\n");
    }
    return 0;
}
