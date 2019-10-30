#ifndef __RAPTOR_UTIL_ALLOC__
#define __RAPTOR_UTIL_ALLOC__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct raptor_allocator {
    void* (*fn_malloc)(size_t size);
    void* (*fn_zalloc)(size_t size);  // malloc & zero
    void* (*fn_realloc)(void* ptr, size_t size);
    void  (*fn_free)(void* ptr);
} raptor_allocator;


void* raptor_malloc(size_t size);

// zero all bytes before return
void* raptor_zalloc(size_t size);

void* raptor_realloc(void* ptr, size_t size);

void  raptor_free(void* ptr);

void raptor_set_allocator(raptor_allocator allocator);

raptor_allocator raptor_get_allocator();

#ifdef __cplusplus
}
#endif

#endif  // __RAPTOR_UTIL_ALLOC__
