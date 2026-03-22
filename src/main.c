#include <stdio.h>
#include "darray.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        puts("No elements to append");
        return 0;
    }

    DynamicArray flags = darray_init(char*);

    for (int i = 1; i < argc; i++) 
        darray_append(&flags, &argv[i]);

    for (size_t i = 0; i < flags.count; i++)
        printf("%s\n", darray_get(char*, flags, i));

    darray_free(&flags);

    return 0;
}
