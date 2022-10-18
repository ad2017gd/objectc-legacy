#pragma once

#include "../../objectc.h"
#include <time.h>
#include <stdbool.h>


class {
    bool running;

    clock_t __l_ast;
    clock_t __t_ime;

    double (*elapsed)();
    void (*start)();
    double (*stop)();
    destructf();
} Chrono;

constructor(Chrono);
destructor(Chrono);
