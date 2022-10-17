#ifndef s_this
void* s_this;
#endif

#define $(s) (*((typeof(s)*)(s_this = &s)))
#define func_init(CLASSNAME) CLASSNAME* this = (CLASSNAME*)s_this
#define class typedef struct
#define new(CLASSNAME, name, ...) CLASSNAME name = {}; CLASSNAME ## __const(&name,##__VA_ARGS__)

#define constructor(CLASSNAME, ...) CLASSNAME* CLASSNAME ## __const (CLASSNAME* this_##CLASSNAME ,##__VA_ARGS__)
#define create(CLASSNAME) memset(this_ ## CLASSNAME, 0, sizeof(CLASSNAME))
#define def_func(CLASSNAME, func) this_ ## CLASSNAME->func = CLASSNAME ## _ ## func
#define def_prop(CLASSNAME, prop) this_ ## CLASSNAME->prop
#define return_class(CLASSNAME) return this_ ## CLASSNAME
 