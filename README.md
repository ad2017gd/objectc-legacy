<div align="center">
<h1> objectc.h - Header-only macro library for Object Oriented Programming </h2>
</div>

# Objects

Objects are either stack-allocated or heap-allocated structs.

# Syntax

Due to the limitations of the C Preprocessor, one can not get really pleasing object syntax, but something usable can be made.
For example one must assign the function pointers in the constructor, it cannot be done automatically.

## Calling class functions

Other object oriented programming libraries (or other implementations) take a reference to the class as a parameter, even if you are calling the function from a struct field. To fix that, this library implements the `$(s)` macro. It expands to `(((typeof(s))(s_this = s)))`, basically returning itself but also saving the instance in a global `s_this` variable. **This implementation makes this library NOT thread safe and only compatible with compilers that support `typeof`**.

```c
double square_area = $(square).area();
```

# Malloc, or no malloc

By defining `_OBJECTC_NOMALLOC` before including objectc.h you can choose to use stack-allocated structs.

## Code differences
- **MALLOC**cated classes are pointers by default (fields accessed using `->`)
- **MALLOC**cated classes can have destructors `void (*destruct)(...)`

One example for handling both for your own library is found in `examples/chrono`.

## Class declarations

```c
#define class typedef struct
```
This results:
```c
class {
    int ClassParameter;
    void (*ClassFunction)();
#ifndef _OBJECTC_NOMALLOC
    void (*destruct)();
#endif
} ClassName;
```

## Function naming scheme

To use `def_func(CLASSNAME, func)` in a constructor, functions must respect the following scheme:
```c
type ClassName_FieldName(FieldArgs...)
```

## Function implementation
To obtain access to the `this` class reference, you must add `func_init(CLASSNAME)` at the beginning of the function.
```c
type ClassName_FieldName(FieldArgs...) {
  func_init(ClassName);
  this->...
}
```

## Constructors and destructors
**Destructors are not available for stack-allocated classes.**
To deconstruct a class, one can use the `delete(instance)` macro.
```c
#define constructor(CLASSNAME, ...) [...]
#define def_func(CLASSNAME, func) this_ ## CLASSNAME->func = CLASSNAME ## _ ## func
#define def_prop(CLASSNAME, prop) this_ ## CLASSNAME->prop
#define def_destruct(CLASSNAME) this_ ## CLASSNAME->destruct = CLASSNAME ## __dest
#define return_class(CLASSNAME) return this_ ## CLASSNAME

#define destructor(CLASSNAME, ...) void CLASSNAME ## __dest (__VA_ARGS__)
#define destructor_free free(this); this = 0

#define delete(INSTANCE) $(INSTANCE)->destruct();
```
```c
constructor(ClassName) {
    create(ClassName);
    def_func(ClassName,ClassFunction);              // this_ClassName->ClassFunction = ClassName_ClassFunction;
#ifndef _OBJECTC_NOMALLOC
    def_destruct(ClassName);                        // this_ClassName->destruct = ClassName__dest;
#endif
    def_prop(ClassName,ClassParameter) = 0;         // this_ClassName->ClassParameter = 0;
    return_class(ClassName);                        // return this_ClassName;
}
#ifndef _OBJECTC_NOMALLOC
destructor(ClassName) {
    destructor_init(ClassName);
    this->ClassParameter = 0;
    destructor_free;
}
#endif
```

# Example
One implementation example with support for both MALLOCcated objects and stack-allocated objects can be found in ./examples/chrono.
