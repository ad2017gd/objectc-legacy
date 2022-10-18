#include <stdlib.h>
#include <string.h>

#ifndef __objectc_this
void* __objectc_this;
#endif

#define $(s) (((typeof(s))(__objectc_this = s)))
#define destructor_init func_init
#define destructf(...) void (*destruct)(__VA_ARGS__)
#define func_init(CLASSNAME) CLASSNAME* this = (CLASSNAME*)__objectc_this
#define class typedef struct
#define new(CLASSNAME) CLASSNAME ## __const

#define constructor(CLASSNAME, ...) CLASSNAME* CLASSNAME ## __const (__VA_ARGS__)
#define create(CLASSNAME) CLASSNAME* this_ ## CLASSNAME = (CLASSNAME*)malloc(sizeof(CLASSNAME)); memset(this_ ## CLASSNAME, 0, sizeof(CLASSNAME))
#define destructor(CLASSNAME, ...) void CLASSNAME ## __dest (__VA_ARGS__)
#define default_destructor(CLASSNAME) void CLASSNAME ## __dest () { \
    destructor_init(CLASSNAME); \
    destructor_free; \
}
#define def_func(CLASSNAME, func) this_ ## CLASSNAME->func = CLASSNAME ## _ ## func
#define def_prop(CLASSNAME, prop) this_ ## CLASSNAME->prop
#define def_destruct(CLASSNAME) this_ ## CLASSNAME->destruct = CLASSNAME ## __dest
#define return_class(CLASSNAME) return this_ ## CLASSNAME
#define delete(INSTANCE) $(INSTANCE)->destruct(); 
 
#define destructor_free free(this); this = 0