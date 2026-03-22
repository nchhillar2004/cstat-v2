#ifndef cstat_config_h
#define cstat_config_h

#include "darray.h"
#include <stdbool.h>
#include <stdint.h>

#define NAME              "cstat"
#define VERSION           "v1.0.0"
// File size in MB
#define FILE_SIZE(value)  ((size_t)(value * (1024 * 1024))

static const char* DEFAULT_EXCLUDED_DIRS[] = {
    "node_modules", ".git", ".venv", "venv",
    "build", "Build", "env", ".cargo", ".vs",
    ".vscode", ".idea", ".cache", ".gradle"
};

static const char* DEFAULT_EXCLUDED_EXT[] = {};

typedef struct {
    char* scan_path;
    bool json_output;
    bool csv_output;
    uint8_t max_file_size;
    uint8_t min_file_size;

    DynamicArray user_excluded_dirs;
    DynamicArray user_excluded_ext;
} Config;

#endif
