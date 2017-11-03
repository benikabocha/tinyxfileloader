#include <gtest/gtest.h>

#define TINYXLOADER_IMPLEMENTATION
#include "../tinyxfileloader.h"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    const int result = RUN_ALL_TESTS();
    return result;
}
