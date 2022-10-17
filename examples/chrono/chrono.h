#pragma once


#define _CHRONO_NOMALLOC
// Remove comment above to switch to NOMALLOC mode

#ifdef _CHRONO_NOMALLOC
    #define _OBJECTC_NOMALLOC
#endif


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
#ifndef _OBJECTC_NOMALLOC 
    void (*destruct)(); 
#endif
} Chrono;

constructor(Chrono);

#ifndef _OBJECTC_NOMALLOC
destructor(Chrono);
#endif
