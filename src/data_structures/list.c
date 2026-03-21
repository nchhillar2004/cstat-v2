#include "list.h"
#include <stdlib.h>
#include <string.h>

void list_init(List* list, size_t item_size) {
    list->count = 0;
    list->capacity = 8;
    list->item_size = item_size;
    list->items = malloc(list->capacity * item_size);
}

void list_append(List* list, const void* item) {
    if (list->count >= list->capacity) {
        if (list->capacity == 0) list->capacity = 8;
        else list->capacity *= 2;
        list->items = realloc(list->items, list->capacity * list->item_size);
    }
    void* dest = (char*)list->items + (list->count * list->item_size);
    memcpy(dest, item, list->item_size);
    list->count++;
}

void list_free(List* list) {
    free(list->items);
    list->items = NULL;
    list->count = 0;
    list->capacity = 0;
}
