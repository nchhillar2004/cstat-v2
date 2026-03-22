#include "darray.h"
#include <stdio.h>

typedef struct {
    char* filename;
    size_t size;
} FileEntry;

int main() {
    DynamicArray user_excluded_ext = darray_init(char*);
    DynamicArray files = darray_init(FileEntry);
    
    char* extensions[] = {"c", "h", "c", "cpp"};
    FileEntry f[] = {
        {"main.c", 100},
        {"config.h", 80},
        {"config.c", 200},
        {"test.cpp", 250}
    };

    printf("%zu\n", files.capacity*files.item_size);

    for (int i = 0; i < 4; i++) { 
        darray_append(&user_excluded_ext, &extensions[i]);
        darray_append(&files, &f[i]);
    }

    printf("%zu\n", files.capacity*files.item_size);
    
    for (int i = 0; i < files.count; i++) 
        printf("%s (size: %zu) -> %s\n", 
               darray_get(FileEntry, files, i).filename,
               darray_get(FileEntry, files, i).size,
               darray_get(char*, user_excluded_ext, i));

    darray_free(&user_excluded_ext);
    darray_free(&files);
    printf("%zu\n", files.capacity*files.item_size);

    return 0;
}
