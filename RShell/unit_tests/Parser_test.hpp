#ifndef PARSER_TEST_H
#define PARSER_TEST_H

#include "gtest/gtest.h"
#include "../header/Parser.hpp"

TEST(echohello, single) {
    Parser* p = new Parser("echo hello");
    EXPECT_EQ(p->commands.at(0), "echo hello\0");
}

TEST(echobye_echoss, twocommands){
    Parser* p = new Parser("echo bye && echo ss");
    EXPECT_EQ(p->commands.at(0), "echo bye &&");
    EXPECT_EQ(p->commands.at(1), "echo ss\0");
}

TEST(echobye_echoss_quote, onecommands_quote){
    Parser* p = new Parser("echo \"bye && echo ss\"");
    EXPECT_EQ(p->commands.at(0), "echo \"bye && echo ss\"\0");
}

TEST(derptest, randomstring) {
    Parser* p = new Parser("derp nerp");
    EXPECT_EQ(p->commands.at(0), "derp nerp\0");
}

TEST(comment, Single) {
    Parser* p = new Parser("echo he##llo");
    EXPECT_EQ(p->commands.at(0), "echo he;");
}

TEST(brackets_test, single) {
    Parser* p = new Parser("[echo hello]");
    EXPECT_EQ(p->commands.at(0), "[echo hello]\0");
}

#endif //PARSER_TEST_H
