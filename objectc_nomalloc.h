#include <string.h>


#ifndef __objectc_this
void* __objectc_this;
#endif

#define $(s) (*((typeof(s)*)(__objectc_this = &s)))
#define func_init(CLASSNAME) CLASSNAME* this = (CLASSNAME*)__objectc_this
#define class typedef struct
#define new(CLASSNAME, name, ...) CLASSNAME name = {}; CLASSNAME ## __const(&name,##__VA_ARGS__)

#define constructor(CLASSNAME, ...) CLASSNAME* CLASSNAME ## __const (CLASSNAME* this_##CLASSNAME ,##__VA_ARGS__)
#define create(CLASSNAME) memset(this_ ## CLASSNAME, 0, sizeof(CLASSNAME))
#define def_func(CLASSNAME, func) this_ ## CLASSNAME->func = CLASSNAME ## _ ## func
#define def_prop(CLASSNAME, prop) this_ ## CLASSNAME->prop
#define return_class(CLASSNAME) return this_ ## CLASSNAME


// NOP DESTRUCTOR DEFINES (NOT AVAILABLE IN THIS MODE)


#define destructf(...)
#ifdef __attribute__ 
#define destructor(CLASSNAME, ...) void _OBJC_UN_ ## __COUNTER__ ## __attribute__((deprecated)) __attribute__((cold)) ()
#else
#define destructor(CLASSNAME, ...) void _OBJC_UN_ ## __COUNTER__ ()
#endif
#define default_destructor(CLASSNAME)
#define destructor_init(CLASSNAME) CLASSNAME* this = 0; return
#define def_destruct(CLASSNAME)
#define destructor_free
 