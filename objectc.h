
#define _OBJECTC_NOMALLOC
// remove comment above to enable NOMALLOC mode (static-allocated objects)


#ifdef _OBJECTC_NOMALLOC
#include "objectc_nomalloc.h"
#else
#include "objectc_malloc.h"
#endif