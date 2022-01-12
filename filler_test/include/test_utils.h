#pragma once
#include <string.h>
#include <stdlib.h>

typedef enum
{
    Rec,
    Dyn_Rec,
    Iter
}
algo_type;

static algo_type algo = Rec;

char *concat_path(const char *base, const char *name)
{
    size_t size = strlen(base) + strlen(name) + 1;
    char *new_path = (char*)calloc(size, sizeof(char));
    strcat_s(new_path, size, base);
    strcat_s(new_path, size, name);

    return new_path;
}