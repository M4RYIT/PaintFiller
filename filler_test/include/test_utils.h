#pragma once
#include <string.h>
#include <stdlib.h>

char *concat_path(const char *base, const char *name)
{
    size_t size = strlen(base) + strlen(name);
    char *new_path = (char*)calloc(size, sizeof(char));
    strcat_s(new_path, size, base);
    strcat_s(new_path, size, name);

    return new_path;
}