#include <string.h>
#include "array.h"

void array_init(array *arr, const size_t size, const size_t type)
{
    arr->data = calloc(size, type);

    arr->count = 0;
    arr->size = size;
    arr->type = type;
}

void array_add(array *arr, void *value)
{
    if (arr->count>=arr->size) return;

    size_t offset = arr->count * arr->type;
    memcpy(arr->data + offset, value, arr->type);
    arr->count++;
}

int array_contains(array *arr, void *value)
{
    size_t offset;
    for (size_t i=0; i<arr->count; i++)
    {
        offset = i * arr->type;
        if (!memcmp(arr->data+offset, value, arr->type))
        {
            return -1;
        }
    }

    return 0;
}

int array_empty(array *arr)
{
    if (arr->count<=0) return -1;
    return 0;
}