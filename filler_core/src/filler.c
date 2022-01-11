#include <stdio.h>
#include "filler.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void fill_rec(const char *dst_path, const char *src_path, vec2 pos, color new_col)
{
    int channels;
    vec2 dim;
    uint8_t *data = stbi_load(src_path, &dim.x, &dim.y, &channels, 0);

    fill_rec_algo(data, &dim, channels, pos, &new_col);

    stbi_write_png(dst_path, dim.x, dim.y, channels, data, 0);

    stbi_image_free(data);
}

void fill_dyn_rec(const char *dst_path, const char *src_path, vec2 pos, color new_col)
{
    int channels;
    vec2 dim;
    uint8_t *data = stbi_load(src_path, &dim.x, &dim.y, &channels, 0);

    fill_dyn_rec_algo(data, &dim, channels, pos, &new_col);

    stbi_write_png(dst_path, dim.x, dim.y, channels, data, 0);

    stbi_image_free(data);
}

void fill_iter(const char *dst_path, const char *src_path, vec2 pos, color new_col)
{
    int channels;
    vec2 dim;
    uint8_t *data = stbi_load(src_path, &dim.x, &dim.y, &channels, 0);

    fill_iter_algo(data, &dim, channels, pos, &new_col);

    stbi_write_png(dst_path, dim.x, dim.y, channels, data, 0);

    stbi_image_free(data);
}

void fill_rec_algo(uint8_t *data, const vec2 *dim, const int channels, vec2 pos, color *new_col)
{
    if (off_bounds(&pos, dim)) return;

    color sample_col = *get_col(data, pixel_index(&pos, dim->x, channels));

    rec_algo(data, dim, channels, pos, new_col, &sample_col);
}

void fill_dyn_rec_algo(uint8_t *data, const vec2 *dim, const int channels, vec2 pos, color *new_col)
{
    if (off_bounds(&pos, dim)) return;

    color sample_col = *get_col(data, pixel_index(&pos, dim->x, channels));

    array cache;
    array_init(&cache, dim->x * dim->y, sizeof(int));

    dyn_rec_algo(data, dim, channels, pos, new_col, &sample_col, &cache);
}

void fill_iter_algo(uint8_t *data, const vec2 *dim, const int channels, vec2 pos, color *new_col)
{
    if (off_bounds(&pos, dim)) return;

    color sample_col = *get_col(data, pixel_index(&pos, dim->x, channels));

    array visited;
    array_init(&visited, dim->x * dim->y, sizeof(int));

    list target;
    list_init(&target, sizeof(vec2));
    list_append(&target, &pos);

    iter_algo_1(data, dim, channels, new_col, &sample_col, &visited, &target);
    // iter_algo_2(data, dim, channels, new_col, &sample_col, &visited, &target);
}

void iter_algo_1(uint8_t *data, const vec2 *dim, const int channels, color *new_col, color *old_col, array *visited, list *target)
{
    vec2 pos;
    int index;

    while(!list_empty(target))
    {
        list_pop(target, &pos);

        if (off_bounds(&pos, dim)) continue;

        index = pixel_index(&pos, dim->x, channels);

        if (array_contains(visited, &index)) continue;

        array_add(visited, &index);

        if (!compare_colors(old_col, get_col(data, index)))
        {
            set_color(data, index, new_col);
        }

        list_append(target, &(vec2){pos.x+1, pos.y});
        list_append(target, &(vec2){pos.x-1, pos.y});
        list_append(target, &(vec2){pos.x, pos.y+1});
        list_append(target, &(vec2){pos.x, pos.y-1});
    }
}

void iter_algo_2(uint8_t *data, const vec2 *dim, const int channels, color *new_col, color *old_col, array *visited, list *target)
{
    vec2 pos;
    int index;

    index = pixel_index(&pos, dim->x, channels);
    array_add(visited, &index);

    while(!list_empty(target))
    {
        list_pop(target, &pos);

        index = pixel_index(&pos, dim->x, channels);

        set_color(data, index, new_col);

        if (validate(data, dim, channels, &(vec2){pos.x+1, pos.y}, old_col, visited, &index))
        {
            list_append(target, &(vec2){pos.x+1, pos.y});
            array_add(visited, &index);
        }

        if (validate(data, dim, channels, &(vec2){pos.x-1, pos.y}, old_col, visited, &index))
        {
            list_append(target, &(vec2){pos.x-1, pos.y});
            array_add(visited, &index);
        }

        if (validate(data, dim, channels, &(vec2){pos.x, pos.y+1}, old_col, visited, &index))
        {
            list_append(target, &(vec2){pos.x, pos.y+1});
            array_add(visited, &index);
        }

        if (validate(data, dim, channels, &(vec2){pos.x, pos.y-1}, old_col, visited, &index))
        {
            list_append(target, &(vec2){pos.x, pos.y-1});
            array_add(visited, &index);
        }
    }
}

int validate(uint8_t *data, const vec2 *dim, const int channels, vec2 *pos, color *old_col, array *visited, int *out_index)
{
   if (off_bounds(pos, dim)) return 0;

   *out_index = pixel_index(pos, dim->x, channels);

   if (array_contains(visited, out_index)) return 0;
   
   if (compare_colors(old_col, get_col(data, *out_index))) return 0;

   return -1;
}

void dyn_rec_algo(uint8_t *data, const vec2 *dim, const int channels, vec2 pos, color *new_col, color *old_col, array *cache)
{
    if (off_bounds(&pos, dim)) return;

    int index = pixel_index(&pos, dim->x, channels);

    if (array_contains(cache, &index)) return;

    array_add(cache, &index);

    color *current_col = get_col(data, index);

    if (compare_colors(current_col, old_col)) return;

    set_color(data, index, new_col);

    dyn_rec_algo(data, dim, channels, (vec2){pos.x+1, pos.y}, new_col, old_col, cache);
    dyn_rec_algo(data, dim, channels, (vec2){pos.x-1, pos.y}, new_col, old_col, cache);
    dyn_rec_algo(data, dim, channels, (vec2){pos.x, pos.y+1}, new_col, old_col, cache);
    dyn_rec_algo(data, dim, channels, (vec2){pos.x, pos.y-1}, new_col, old_col, cache);
}

void rec_algo(uint8_t *data, const vec2 *dim, const int channels, vec2 pos, color *new_col, color *old_col)
{
    if (off_bounds(&pos, dim)) return;

    int index = pixel_index(&pos, dim->x, channels);

    color *current_col = get_col(data, index);

    if (compare_colors(current_col, old_col)) return;

    set_color(data, index, new_col);

    rec_algo(data, dim, channels, (vec2){pos.x+1, pos.y}, new_col, old_col);
    rec_algo(data, dim, channels, (vec2){pos.x-1, pos.y}, new_col, old_col);
    rec_algo(data, dim, channels, (vec2){pos.x, pos.y+1}, new_col, old_col);
    rec_algo(data, dim, channels, (vec2){pos.x, pos.y-1}, new_col, old_col);
}

int off_bounds(const vec2 *pos, const vec2 *dim)
{
    if (pos->x>=dim->x || pos->x<0) return -1;
    if (pos->y>=dim->y || pos->y<0) return -1;
    return 0;
}

color *get_col(uint8_t *data, const int index)
{
    return (color*)&data[index];
}

int pixel_index(const vec2 *pos, const int w, const int channels)
{
    return (pos->x + pos->y * w) * channels;
}

void set_color(uint8_t *data, const int index, color *new_col)
{
    //*((color*)&data[index]) = *new_col;

    data[index + 0] = new_col->r;
    data[index + 1] = new_col->g;
    data[index + 2] = new_col->b;
}

int compare_colors(const color *col_1, const color *col_2)
{
    if (col_1->r != col_2->r) return -1;
    if (col_1->g != col_2->g) return -1;
    if (col_1->b != col_2->b) return -1;

    return 0;
}