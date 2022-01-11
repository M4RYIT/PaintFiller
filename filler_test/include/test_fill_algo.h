#pragma once
#include "clove.h"
#include "filler.h"

CLOVE_TEST(FillAlgo_Rec_OnePixel)
{
    uint8_t data[] = {255, 0, 0}; // red image
    vec2 dim = {1, 1};
    vec2 pos = {0, 0};
    int channels = 3;
    color new_col = {0, 255, 0}; // green

    fill_rec_algo(data, &dim, channels, pos, &new_col);

    CLOVE_INT_EQ(0, data[0]);
    CLOVE_INT_EQ(255, data[1]);
    CLOVE_INT_EQ(0, data[2]);
}

CLOVE_TEST(FillAlgo_Dyn_Rec_OnePixel)
{
    uint8_t data[] = {255, 0, 0}; // red image
    vec2 dim = {1, 1};
    vec2 pos = {0, 0};
    int channels = 3;
    color new_col = {0, 255, 0}; // green

    fill_dyn_rec_algo(data, &dim, channels, pos, &new_col);

    CLOVE_INT_EQ(0, data[0]);
    CLOVE_INT_EQ(255, data[1]);
    CLOVE_INT_EQ(0, data[2]);
}

CLOVE_TEST(FillAlgo_Iter_OnePixel)
{
    uint8_t data[] = {255, 0, 0}; // red image
    vec2 dim = {1, 1};
    vec2 pos = {0, 0};
    int channels = 3;
    color new_col = {0, 255, 0}; // green

    fill_iter_algo(data, &dim, channels, pos, &new_col);

    CLOVE_INT_EQ(0, data[0]);
    CLOVE_INT_EQ(255, data[1]);
    CLOVE_INT_EQ(0, data[2]);    
}

CLOVE_TEST(FillAlgo_Rec_OnePixelOffRange)
{
    uint8_t data[] = {255, 0, 0}; // red image
    vec2 dim = {1, 1};
    vec2 pos = {10, 10};
    int channels = 3;
    color new_col = {0, 255, 0}; // green

    fill_rec_algo(data, &dim, channels, pos, &new_col);

    CLOVE_INT_EQ(255, data[0]);
    CLOVE_INT_EQ(0, data[1]);
    CLOVE_INT_EQ(0, data[2]);
}

CLOVE_TEST(FillAlgo_Dyn_Rec_OnePixelOffRange)
{
    uint8_t data[] = {255, 0, 0}; // red image
    vec2 dim = {1, 1};
    vec2 pos = {10, 10};
    int channels = 3;
    color new_col = {0, 255, 0}; // green

    fill_dyn_rec_algo(data, &dim, channels, pos, &new_col);

    CLOVE_INT_EQ(255, data[0]);
    CLOVE_INT_EQ(0, data[1]);
    CLOVE_INT_EQ(0, data[2]);
}

CLOVE_TEST(FillAlgo_Iter_OnePixelOffRange)
{
    uint8_t data[] = {255, 0, 0}; // red image
    vec2 dim = {1, 1};
    vec2 pos = {10, 10};
    int channels = 3;
    color new_col = {0, 255, 0}; // green

    fill_iter_algo(data, &dim, channels, pos, &new_col);

    CLOVE_INT_EQ(255, data[0]);
    CLOVE_INT_EQ(0, data[1]);
    CLOVE_INT_EQ(0, data[2]);
}

CLOVE_TEST(FillAlgo_Rec_1x3First2PixelsUpdated)
{
    uint8_t data[] = {255, 0, 0, 255, 0, 0, 0, 0, 255};
    vec2 dim = {3, 1};
    vec2 pos = {0, 0};
    int channels = 3;
    color new_col = {0, 255, 0}; // green

    fill_rec_algo(data, &dim, channels, pos, &new_col);

    CLOVE_INT_EQ(0, data[0]);
    CLOVE_INT_EQ(255, data[1]);
    CLOVE_INT_EQ(0, data[2]);

    CLOVE_INT_EQ(0, data[3]);
    CLOVE_INT_EQ(255, data[4]);
    CLOVE_INT_EQ(0, data[5]);

    CLOVE_INT_EQ(0, data[6]);
    CLOVE_INT_EQ(0, data[7]);
    CLOVE_INT_EQ(255, data[8]);
}

CLOVE_TEST(FillAlgo_Dyn_Rec_1x3First2PixelsUpdated)
{
    uint8_t data[] = {255, 0, 0, 255, 0, 0, 0, 0, 255};
    vec2 dim = {3, 1};
    vec2 pos = {0, 0};
    int channels = 3;
    color new_col = {0, 255, 0}; // green

    fill_dyn_rec_algo(data, &dim, channels, pos, &new_col);

    CLOVE_INT_EQ(0, data[0]);
    CLOVE_INT_EQ(255, data[1]);
    CLOVE_INT_EQ(0, data[2]);

    CLOVE_INT_EQ(0, data[3]);
    CLOVE_INT_EQ(255, data[4]);
    CLOVE_INT_EQ(0, data[5]);

    CLOVE_INT_EQ(0, data[6]);
    CLOVE_INT_EQ(0, data[7]);
    CLOVE_INT_EQ(255, data[8]);
}

CLOVE_TEST(FillAlgo_Iter_1x3First2PixelsUpdated)
{
    uint8_t data[] = {255, 0, 0, 255, 0, 0, 0, 0, 255};
    vec2 dim = {3, 1};
    vec2 pos = {0, 0};
    int channels = 3;
    color new_col = {0, 255, 0}; // green

    fill_iter_algo(data, &dim, channels, pos, &new_col);

    CLOVE_INT_EQ(0, data[0]);
    CLOVE_INT_EQ(255, data[1]);
    CLOVE_INT_EQ(0, data[2]);

    CLOVE_INT_EQ(0, data[3]);
    CLOVE_INT_EQ(255, data[4]);
    CLOVE_INT_EQ(0, data[5]);

    CLOVE_INT_EQ(0, data[6]);
    CLOVE_INT_EQ(0, data[7]);
    CLOVE_INT_EQ(255, data[8]);
}