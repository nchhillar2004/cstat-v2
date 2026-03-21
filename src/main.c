#include "list.h"
#include <stdio.h>

int main(int argc, char** argv) {
    if (argc == 0) {
        puts("No elements to append");
        return 0;
    }

    List list;
    list_init(&list, sizeof(char*));
    for (int i = 0; i < argc; i++) 
        list_append(&list, &argv[i]);

    for (size_t i = 0; i < list.count; i++) {
        char* val = ((char**)list.items)[i];
        printf("%s\n", val);
    }

    list_free(&list);

    return 0;
}
