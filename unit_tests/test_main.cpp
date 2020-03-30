#include "gtest/gtest.h"
#include "../unit_tests/Parser_test.hpp"
#include "../unit_tests/Tokenizer_test.hpp"
#include "../unit_tests/Connector_test.hpp"
#include "../unit_tests/Shunting_test.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
