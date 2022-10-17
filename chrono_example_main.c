
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include "examples/chrono/chrono.h"

int main() {
    
    #ifndef _CHRONO_NOMALLOC
    printf("CHRONO: MALLOC\n\n");

    Chrono* timer = new(Chrono)();
    printf("Waiting 1s\n");
    Sleep(1000);
    printf("elapsed: %f (%s)\n", $(timer)->elapsed(), $(timer)->running ? "RUNNING" : "STOPPED");
    $(timer)->start();
    Sleep(2000);
    printf("elapsed: %f (%s)\n", $(timer)->elapsed(), $(timer)->running ? "RUNNING" : "STOPPED");
    Sleep(2000);
    printf("elapsed: %f (%s)\n", $(timer)->elapsed(), $(timer)->running ? "RUNNING" : "STOPPED");
    $(timer)->stop();
    Sleep(3000);
    printf("elapsed: %f (%s)\n", $(timer)->elapsed(), $(timer)->running ? "RUNNING" : "STOPPED");
    $(timer)->start();
    Sleep(4000);
    printf($(timer)->running ? "(RUNNING)\n" : "(STOPPED)\n");
    printf("elapsed: %f, expected: 8s\n", $(timer)->elapsed());
    printf("elapsed: %f, expected: 8s\n", $(timer)->elapsed());

    delete(timer);
    

    #else
    printf("CHRONO: NO MALLOC\n\n");

    new(Chrono,timer);
    printf("Waiting 1s\n");
    Sleep(1000);
    printf("elapsed: %f (%s)\n", $(timer).elapsed(), $(timer).running ? "RUNNING" : "STOPPED");
    $(timer).start();
    Sleep(2000);
    printf("elapsed: %f (%s)\n", $(timer).elapsed(), $(timer).running ? "RUNNING" : "STOPPED");
    Sleep(2000);
    printf("elapsed: %f (%s)\n", $(timer).elapsed(), $(timer).running ? "RUNNING" : "STOPPED");
    $(timer).stop();
    Sleep(3000);
    printf("elapsed: %f (%s)\n", $(timer).elapsed(), $(timer).running ? "RUNNING" : "STOPPED");
    $(timer).start();
    Sleep(4000);
    printf($(timer).running ? "(RUNNING)\n" : "(STOPPED)\n");
    printf("elapsed: %f, expected: 8s\n", $(timer).elapsed());
    printf("elapsed: %f, expected: 8s\n", $(timer).elapsed());

    #endif

}