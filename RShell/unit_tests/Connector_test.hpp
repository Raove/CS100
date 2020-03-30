#ifndef CONNECTOR_TEST_H
#define CONNECTOR_TEST_H

#include "../header/Or.hpp"
#include "../header/Semicolon.hpp"
#include "../header/And.hpp"
#include <string>

TEST(isOrString, Orconnector) {
    Or* o = new Or();
    std::string bars = o->getToken();
    EXPECT_EQ(bars, "||");
    EXPECT_EQ(o->getType(), "CNT");
}

TEST(isAndString, andconnector) {
    And* a = new And();
    std::string ands = a->getToken();
    EXPECT_EQ(ands, "&&");
    EXPECT_EQ(a->getType(), "CNT");
}

TEST(isSemicolon, semiconnector) {
    Semicolon* s = new Semicolon();
    std::string colon = s->getToken();
    EXPECT_EQ(colon, ";");
    EXPECT_EQ(s->getType(), "CNT");
}

TEST(isCommand, command) {
    Command* s = new Command("echo");
    std::string colon = s->getToken();
    EXPECT_EQ(colon, "echo");
    EXPECT_EQ(s->getType(), "CMD");
}

TEST(isArgument, argument_without_spaces) {
    Argument* s = new Argument("hello");
    std::string colon = s->getToken();
    EXPECT_EQ(colon, "hello");
    EXPECT_EQ(s->getType(), "ARG");
}

TEST(isArgument, argument_with_spaces) {
    Argument* s = new Argument("hello world!");
    std::string colon = s->getToken();
    EXPECT_EQ(colon, "hello world!");
    EXPECT_EQ(s->getType(), "ARG");
}

#endif //CONNECTOR_TEST_H