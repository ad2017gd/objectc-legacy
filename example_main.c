
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

#include "examples/chrono/chrono.h"
#include "examples/rectangle/rectangle.h"

int main() {
    #ifndef _OBJECTC_NOMALLOC
    printf("RECTANGLE: MALLOC\n\n");
    ORectangle* rect = new(ORectangle)(4,5);
    printf("RECTANGLE : WIDTH = %f, HEIGHT = %f ; expected: 4,5\n", rect->width, rect->height);
    printf("RECTANGLE AREA = %f ; expected: 20\n", $(rect)->area());
    #else
    printf("RECTANGLE: MALLOC\n\n");
    new(ORectangle,rect,4,5);
    printf("RECTANGLE : WIDTH = %f, HEIGHT = %f ; expected: 4,5\n", rect.width, rect.height);
    printf("RECTANGLE AREA = %f ; expected: 20\n", $(rect).area());
    #endif




    #ifndef _OBJECTC_NOMALLOC
    printf("\n\n----------------------------\n\nCHRONO: MALLOC\n\n");

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
    Sleep(1000);
    printf("elapsed: %f, expected: 9s\n", $(timer)->elapsed());
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
    Sleep(1000);
    printf("elapsed: %f, expected: 9s\n", $(timer).elapsed());

    #endif

}