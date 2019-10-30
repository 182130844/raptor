#include <stdlib.h>
#include <string.h>
#include "alloc.h"

static void* zero_mem_with_calloc(size_t size) {
    return calloc(size, 1);
}

static void* zero_mem_with_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr != nullptr) {
        memset(ptr, 0, size);
    }
    return ptr;
}

static raptor_allocator g_allocator = {
    malloc,
    zero_mem_with_calloc,
    realloc,
    free
};

void* raptor_malloc(size_t size) {
    return g_allocator.fn_malloc(size);
}

void* raptor_zalloc(size_t size) {
    return g_allocator.fn_zalloc(size);
}

void* raptor_realloc(void* ptr, size_t size) {
    return g_allocator.fn_realloc(ptr, size);
}

void raptor_free(void* ptr) {
    g_allocator.fn_free(ptr);
}

void raptor_set_allocator(raptor_allocator allocator) {
    if (allocator.fn_zalloc == nullptr) {
        allocator.fn_zalloc = zero_mem_with_malloc;
    }
    g_allocator = allocator;
}

raptor_allocator raptor_get_allocator() {
    return g_allocator;
}
