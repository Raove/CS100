#ifndef TOKENIZER_TEST_H
#define TOKENIZER_TEST_H

#include "gtest/gtest.h"
#include "../header/Parser.hpp"
#include "../header/Tokenizer.hpp"

TEST(echohello, oneObject){
    Parser* p = new Parser("echo hello");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    EXPECT_EQ(t->Token_vector.at(0)->getToken(), "echo");
    EXPECT_EQ(t->Token_vector.at(1)->getToken(), "hello");
}

TEST(echobye_echoss, Connector){
Parser* p = new Parser("echo bye && echo ss");
Tokenizer* t = new Tokenizer();
t->Tokenize(p->commands);
EXPECT_EQ(t->Token_vector.at(0)->getToken(), "echo");
EXPECT_EQ(t->Token_vector.at(3)->getToken(), "echo");
EXPECT_EQ(t->Token_vector.at(1)->getToken(), "bye");
EXPECT_EQ(t->Token_vector.at(4)->getToken(), "ss");
EXPECT_EQ(t->Token_vector.at(2)->getToken(), "&&");
}

TEST(echo, noarg) {
    Parser* p = new Parser("echo");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    EXPECT_EQ(t->Token_vector.at(0)->getToken(), "echo");
    EXPECT_EQ(t->Token_vector.at(1)->getToken(), "");
}

TEST(test, no_brackets){
    Parser* p = new Parser("test -e header");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    EXPECT_EQ(t->Token_vector.at(0)->getToken(), "test");
    EXPECT_EQ(t->Token_vector.at(1)->getToken(), "-e header");
}

TEST(test, with_brackets){
    Parser* p = new Parser("[-e header]");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    EXPECT_EQ(t->Token_vector.at(0)->getToken(), "test");
    EXPECT_EQ(t->Token_vector.at(1)->getToken(), "-e header");
}

TEST(test, with_brackets_with_space){
    Parser* p = new Parser("[ -e header ]");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    EXPECT_EQ(t->Token_vector.at(0)->getToken(), "test");
    EXPECT_EQ(t->Token_vector.at(1)->getToken(), " -e header");
}

TEST(test, no_flag){
    Parser* p = new Parser("test header");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    EXPECT_EQ(t->Token_vector.at(0)->getToken(), "test");
    EXPECT_EQ(t->Token_vector.at(1)->getToken(), "header");
}

#endif //TOKENIZER_TEST_H