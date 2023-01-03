#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int num) {
    write(STDOUT_FILENO, "I won't die!\n", 13);
}

int main() {

    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    signal(SIGKILL, handler);

    while(1) {
        sleep(1);
        printf("PID = %d\n",getpid());
    }

    return 0;
}
