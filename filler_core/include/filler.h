#pragma once

#include <stdint.h>
#include "array.h"
#include "list.h"

typedef struct
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
}
color;

typedef struct
{
    int x;
    int y;
}
vec2;

void fill_rec(const char *dst_path, const char *src_path, vec2 pos, color new_col);

void fill_dyn_rec(const char *dst_path, const char *src_path, vec2 pos, color new_col);

void fill_iter(const char *dst_path, const char *src_path, vec2 pos, color new_col);

void fill_rec_algo(uint8_t *data, const vec2 *dim, const int channels, vec2 pos, color *new_col);

void fill_dyn_rec_algo(uint8_t *data, const vec2 *dim, const int channels, vec2 pos, color *new_col);

void fill_iter_algo(uint8_t *data, const vec2 *dim, const int channels, vec2 pos, color *new_col);

void rec_algo(uint8_t *data, const vec2 *dim, const int channels, vec2 pos, color *new_col, color *old_col);

void dyn_rec_algo(uint8_t *data, const vec2 *dim, const int channels, vec2 pos, color *new_col, color *old_col, array *cache);

void iter_algo_1(uint8_t *data, const vec2 *dim, const int channels, color *new_col, color *old_col, array *visited, list *target);

void iter_algo_2(uint8_t *data, const vec2 *dim, const int channels, color *new_col, color *old_col, array *visited, list *target);

int validate(uint8_t *data, const vec2 *dim, const int channels, vec2 *pos, color *old_col, array *visited, int *out_index);

int off_bounds(const vec2 *pos, const vec2 *dim);

color *get_col(uint8_t *data, const int index);

int pixel_index(const vec2 *pos, const int w, const int channels);

void set_color(uint8_t *data, const int index, color *new_col);

int compare_colors(const color *col_1, const color *col_2, const size_t channels);