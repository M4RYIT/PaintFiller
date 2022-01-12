#pragma once
#include <string.h>
#include "clove.h"
#include "filler.h"
#include "stb_image.h"
#include "test_utils.h"

CLOVE_TEST(Fill_Imag16x16)
{
    char *dst = "assets\\update16x16.png";
    char *src = "assets\\img16x16.png";
    char *test = "assets\\result16x16.png";

    color new_col = {0, 255, 0};
    vec2 pos = {0, 0};

    switch(algo)
    {
        case Rec:
        fill_rec(dst, src, pos, new_col);
        break;

        case Dyn_Rec:
        fill_dyn_rec(dst, src, pos, new_col);
        break;

        case Iter:
        fill_iter(dst, src, pos, new_col);
        break;
    }

    vec2 dim;
    int channels;
    uint8_t *res = stbi_load(dst, &dim.x, &dim.y, &channels, 0);
    uint8_t *t = stbi_load(test, &dim.x, &dim.y, &channels, 0);
    size_t sz = dim.x * dim.y * channels;

    CLOVE_INT_EQ(0, memcmp(res, t, sz));

    stbi_image_free(res);
    stbi_image_free(t);
}