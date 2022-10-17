
#include "chrono.h"
#include <string.h>

void __chrono_update(Chrono* this) {
    if(this->running) {
        this->__t_ime += clock() - this->__l_ast;
        this->__l_ast = clock();
    }
}

void Chrono_start() {
    func_init(Chrono);
    this->__l_ast = clock();
    __chrono_update(this);
    this->running = 1;
}

double Chrono_stop() {
    func_init(Chrono);
    __chrono_update(this);
    this->running = 0;
    return (this->__t_ime)/(double)CLOCKS_PER_SEC;
}

double Chrono_elapsed() {
    func_init(Chrono);
    __chrono_update(this);
    return (this->__t_ime)/(double)CLOCKS_PER_SEC;
}

constructor(Chrono) {
    create(Chrono);                                 // create(Chrono);
    def_func(Chrono,elapsed);                       // this_Chrono->elapsed = Chrono_elapsed;
    def_func(Chrono,start);                         // this_Chrono->start = Chrono_start;
    def_func(Chrono,stop);                // OR     // this_Chrono->stop = Chrono_stop;
#ifndef _OBJECTC_NOMALLOC
    def_destruct(Chrono);                           // this_Chrono->destruct = Chrono__dest;
#endif
    def_prop(Chrono,running) = 0;
    return_class(Chrono);                           // return this_Chrono;
}

#ifndef _OBJECTC_NOMALLOC

destructor(Chrono) {
    destructor_init(Chrono);
    this->elapsed = 0;
    this->running = 0;
    destructor_free;
}

#endif