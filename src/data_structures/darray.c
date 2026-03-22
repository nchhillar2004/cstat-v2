#include "darray.h"

#include <stdlib.h>
#include <string.h>

DynamicArray _darray_init(size_t item_size) {
    return (DynamicArray) {
        .count = 0,
        .capacity = 0,
        .item_size = item_size,
        .data = NULL
    };
}

void darray_append(DynamicArray *array, const void *item) {
    if (array->count >= array->capacity) {
        if (array->capacity == 0) {
            array->capacity = 8;
            array->data = malloc(array->capacity * array->item_size);
        }
        else {
            array->capacity *= 2;
            array->data = realloc(array->data, array->capacity * array->item_size);
        }
    }
    memcpy((char*)array->data + (array->count * array->item_size), item, array->item_size);
    array->count++;
}

void darray_free(DynamicArray *array) {
    free(array->data);
    array->data = NULL;
    array->count = 0;
    array->capacity = 0;
}
