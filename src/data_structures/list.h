#ifndef data_structures_h
#define data_structures_h

#include <stddef.h>
#include <stdlib.h>

// Dynamic array/list
typedef struct {
    void* items;     // pointer to elements
    size_t count;     // number of elements in list
    size_t capacity;  // max list capacity
    size_t item_size; // size of each element
} List;

// alloc/init dynamic list
void list_init(List* list, size_t item_size);

// append an item to the end of the list
void list_append(List* list, const void* item);

// free mem
void list_free(List* list);

#endif
