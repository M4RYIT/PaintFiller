#include "clove.h"
#include "test_fill_algo.h"
#include "test_fill.h"
#include "test_utils.h"

// Recursive - Dynamic Recursive - Iterative Algo
CLOVE_RUNNER(FillAlgo_OnePixel, FillAlgo_OnePixelOffRange, FillAlgo_1x3First2PixelsUpdated,
             FillAlgo_4ChannelsImage, FillAlgo_2ChannelsImage, FillAlgo_1ChannelImage,
             FillAlgo_1x3First2PixelsStartCenter, FillAlgo_1x3First2PixelsStartLast, Fill_Imag16x16);