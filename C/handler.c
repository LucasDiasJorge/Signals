#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signalHandler(int sig) {
    printf("Signal %d received. Exiting application.\n", sig);
    exit(0); // Optionally, you can add an exit call to terminate the program gracefully.
}

int main(){

    // Register signal handles to catch CTRL-C, etc.
    signal(SIGABRT, &signalHandler);
    signal(SIGTERM, &signalHandler);
    signal(SIGINT, &signalHandler);

    while(1){
        printf("Running\n");
    }

    return 0;
}