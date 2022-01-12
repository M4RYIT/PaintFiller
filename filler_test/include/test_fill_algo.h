#pragma once
#include "clove.h"
#include "filler.h"
#include "test_utils.h"

CLOVE_TEST(FillAlgo_OnePixel)
{
    uint8_t data[] = {255, 0, 0}; // red image
    vec2 dim = {1, 1};
    vec2 pos = {0, 0};
    int channels = 3;
    color new_col = {0, 255, 0}; // green

    switch(algo)
    {
        case Rec:
        fill_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Dyn_Rec:
        fill_dyn_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Iter:
        fill_iter_algo(data, &dim, channels, pos, &new_col);
        break;
    }

    CLOVE_INT_EQ(0, data[0]);
    CLOVE_INT_EQ(255, data[1]);
    CLOVE_INT_EQ(0, data[2]);
}

CLOVE_TEST(FillAlgo_OnePixelOffRange)
{
    uint8_t data[] = {255, 0, 0}; // red image
    vec2 dim = {1, 1};
    vec2 pos = {10, 10};
    int channels = 3;
    color new_col = {0, 255, 0}; // green

    switch(algo)
    {
        case Rec:
        fill_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Dyn_Rec:
        fill_dyn_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Iter:
        fill_iter_algo(data, &dim, channels, pos, &new_col);
        break;
    }

    CLOVE_INT_EQ(255, data[0]);
    CLOVE_INT_EQ(0, data[1]);
    CLOVE_INT_EQ(0, data[2]);
}

CLOVE_TEST(FillAlgo_1x3First2PixelsUpdated)
{
    uint8_t data[] = {255, 0, 0, 255, 0, 0, 0, 0, 255};
    vec2 dim = {3, 1};
    vec2 pos = {0, 0};
    int channels = 3;
    color new_col = {0, 255, 0}; // green

    switch(algo)
    {
        case Rec:
        fill_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Dyn_Rec:
        fill_dyn_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Iter:
        fill_iter_algo(data, &dim, channels, pos, &new_col);
        break;
    }

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

CLOVE_TEST(FillAlgo_4ChannelsImage)
{
    uint8_t data[] = {255, 0, 0, 255};
    vec2 dim = {1, 1};
    vec2 pos = {0, 0};
    int channels = 4;
    color new_col = {0, 255, 0, 255};

    switch(algo)
    {
        case Rec:
        fill_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Dyn_Rec:
        fill_dyn_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Iter:
        fill_iter_algo(data, &dim, channels, pos, &new_col);
        break;
    }

    CLOVE_INT_EQ(0, data[0]);
    CLOVE_INT_EQ(255, data[1]);
    CLOVE_INT_EQ(0, data[2]);
    CLOVE_INT_EQ(255, data[3]);    
}

CLOVE_TEST(FillAlgo_2ChannelsImage)
{
    uint8_t data[] = {255, 0};
    vec2 dim = {1, 1};
    vec2 pos = {0, 0};
    int channels = 2;
    color new_col = {0, 255};

    switch(algo)
    {
        case Rec:
        fill_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Dyn_Rec:
        fill_dyn_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Iter:
        fill_iter_algo(data, &dim, channels, pos, &new_col);
        break;
    }

    CLOVE_INT_EQ(0, data[0]);
    CLOVE_INT_EQ(255, data[1]);
}

CLOVE_TEST(FillAlgo_1ChannelImage)
{
    uint8_t data[] = {255};
    vec2 dim = {1, 1};
    vec2 pos = {0, 0};
    int channels = 1;
    color new_col = {0};

    switch(algo)
    {
        case Rec:
        fill_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Dyn_Rec:
        fill_dyn_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Iter:
        fill_iter_algo(data, &dim, channels, pos, &new_col);
        break;
    }

    CLOVE_INT_EQ(0, data[0]);
}

CLOVE_TEST(FillAlgo_1x3First2PixelsStartCenter)
{
    uint8_t data[] = {255, 0, 0, 255, 0, 0, 0, 0, 255};
    vec2 dim = {3, 1};
    vec2 pos = {1, 0};
    int channels = 3;
    color new_col = {0, 255, 0}; // green

    switch(algo)
    {
        case Rec:
        fill_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Dyn_Rec:
        fill_dyn_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Iter:
        fill_iter_algo(data, &dim, channels, pos, &new_col);
        break;
    }

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

CLOVE_TEST(FillAlgo_1x3First2PixelsStartLast)
{
    uint8_t data[] = {255, 0, 0, 255, 0, 0, 0, 0, 255};
    vec2 dim = {3, 1};
    vec2 pos = {2, 0};
    int channels = 3;
    color new_col = {0, 255, 0}; // green

    switch(algo)
    {
        case Rec:
        fill_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Dyn_Rec:
        fill_dyn_rec_algo(data, &dim, channels, pos, &new_col);
        break;

        case Iter:
        fill_iter_algo(data, &dim, channels, pos, &new_col);
        break;
    }

    CLOVE_INT_EQ(255, data[0]);
    CLOVE_INT_EQ(0, data[1]);
    CLOVE_INT_EQ(0, data[2]);

    CLOVE_INT_EQ(255, data[3]);
    CLOVE_INT_EQ(0, data[4]);
    CLOVE_INT_EQ(0, data[5]);

    CLOVE_INT_EQ(0, data[6]);
    CLOVE_INT_EQ(255, data[7]);
    CLOVE_INT_EQ(0, data[8]);
}