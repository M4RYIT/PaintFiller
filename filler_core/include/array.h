#pragma once

#include <stdlib.h>
#include <stdint.h>

typedef struct
{
    size_t count;
    size_t size;
    size_t type;
    uint8_t *data;
}
array;

void array_init(array *arr, const size_t size, const size_t type);

void array_add(array *arr, void *value);

int array_contains(array *arr, void *value);

int array_empty(array *arr);