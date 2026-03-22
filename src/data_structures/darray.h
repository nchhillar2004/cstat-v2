#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>

/*
 * Implementing Dynamic Array
 * */
typedef struct {
    void*  data;      // pointer to elements
    size_t count;     // number of elements in the array
    size_t capacity;  // max list capacity
    size_t item_size; // size of each element
} DynamicArray;

// alloc/init dynamic array
DynamicArray _darray_init(size_t item_size);

// append an element to the end of the list
void darray_append(DynamicArray* array, const void* item);

// free memory
void darray_free(DynamicArray* array);

#define darray_init(type) _darray_init(sizeof(type))
#define darray_get(type, arr, index) (*(type*)((char*)(arr).data + (index) * (arr).item_size))

#endif
