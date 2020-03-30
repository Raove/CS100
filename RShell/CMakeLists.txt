CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(rshell)

ADD_SUBDIRECTORY(googletest)

set(SOURCES src/main.cpp)

set(TESTS unit_tests/Parser_test.hpp unit_tests/test_main.cpp unit_tests/Tokenizer_test.hpp  unit_tests/Shunting_test.hpp)

set(HEADERS header/Parser.hpp header/Executable.hpp header/Paren.hpp
        header/Argument.hpp header/Command.hpp header/Paren.hpp
        header/ShuntingYard.hpp header/Token.hpp header/Tokenizer.hpp
        header/And.hpp header/Or.hpp header/Semicolon.hpp header/Tree.hpp)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rshell
        ${SOURCES}
)

ADD_EXECUTABLE(test
        ${HEADERS} ${TESTS}
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
