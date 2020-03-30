#ifndef RSHELL_SHUNTING_TEST_HPP
#define RSHELL_SHUNTING_TEST_HPP

#include "gtest/gtest.h"
#include "../header/Parser.hpp"
#include "../header/Tokenizer.hpp"
#include "../header/ShuntingYard.hpp"


TEST(ShuntingYard, Single_command){
    Parser* p = new Parser("echo bye");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    ShuntingYard* Shunt = new ShuntingYard();
    Shunt->ShuntingYardRun(t->tokenized());
    vector<Token*> x = Shunt->Yarded();
    EXPECT_EQ(x.at(0)->getToken(), "echo");
}

TEST(ShuntingYard, two_commands_AND){
    Parser* p = new Parser("echo bye && echo ss");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    ShuntingYard* Shunt = new ShuntingYard();
    Shunt->ShuntingYardRun(t->tokenized());
    vector<Token*> x = Shunt->Yarded();
    EXPECT_EQ(x.at(0)->getToken(), "echo");
    EXPECT_EQ(x.at(1)->getToken(), "echo");
    EXPECT_EQ(x.at(2)->getToken(), "&&");
}

TEST(ShuntingYard, two_commands_OR){
    Parser* p = new Parser("echo bye || echo ss");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    ShuntingYard* Shunt = new ShuntingYard();
    Shunt->ShuntingYardRun(t->tokenized());
    vector<Token*> x = Shunt->Yarded();
    EXPECT_EQ(x.at(0)->getToken(), "echo");
    EXPECT_EQ(x.at(1)->getToken(), "echo");
    EXPECT_EQ(x.at(2)->getToken(), "||");
}

TEST(ShuntingYard, three_commands){
    Parser* p = new Parser("echo bye && echo ss && ls -a");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    ShuntingYard* Shunt = new ShuntingYard();
    Shunt->ShuntingYardRun(t->tokenized());
    vector<Token*> x = Shunt->Yarded();
    EXPECT_EQ(x.at(0)->getToken(), "echo");
    EXPECT_EQ(x.at(1)->getToken(), "echo");
    EXPECT_EQ(x.at(2)->getToken(), "&&");
    EXPECT_EQ(x.at(3)->getToken(), "ls");
    EXPECT_EQ(x.at(4)->getToken(), "&&");
}

TEST(ShuntingYard, two_commands_parenthesis){
    Parser* p = new Parser("(echo bye && echo ss)");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    ShuntingYard* Shunt = new ShuntingYard();
    Shunt->ShuntingYardRun(t->tokenized());
    vector<Token*> x = Shunt->Yarded();
    EXPECT_EQ(x.at(0)->getToken(), "echo");
    EXPECT_EQ(x.at(1)->getToken(), "echo");
    EXPECT_EQ(x.at(2)->getToken(), "&&");
}


TEST(ShuntingYard, three_commands_parenthesis){
    Parser* p = new Parser("(echo bye && echo ss) || ls -la");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    ShuntingYard* Shunt = new ShuntingYard();
    Shunt->ShuntingYardRun(t->tokenized());
    vector<Token*> x = Shunt->Yarded();
    EXPECT_EQ(x.at(0)->getToken(), "echo");
    EXPECT_EQ(x.at(1)->getToken(), "echo");
    EXPECT_EQ(x.at(2)->getToken(), "&&");
    EXPECT_EQ(x.at(3)->getToken(), "ls");
    EXPECT_EQ(x.at(4)->getToken(), "||");
}


TEST(ShuntingYard, four_commands_two_parenthesis){
    Parser* p = new Parser("(echo a && echo b) || (echo c && echo d)");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    ShuntingYard* Shunt = new ShuntingYard();
    Shunt->ShuntingYardRun(t->tokenized());
    vector<Token*> x = Shunt->Yarded();
    EXPECT_EQ(x.at(0)->getToken(), "echo");
    EXPECT_EQ(x.at(1)->getToken(), "echo");
    EXPECT_EQ(x.at(2)->getToken(), "&&");
    EXPECT_EQ(x.at(3)->getToken(), "echo");
    EXPECT_EQ(x.at(4)->getToken(), "echo");
    EXPECT_EQ(x.at(5)->getToken(), "&&");
    EXPECT_EQ(x.at(6)->getToken(), "||");
}


TEST(ShuntingYard, test){
    Parser* p = new Parser("test header");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    ShuntingYard* Shunt = new ShuntingYard();
    Shunt->ShuntingYardRun(t->tokenized());
    vector<Token*> x = Shunt->Yarded();
    EXPECT_EQ(x.at(0)->getToken(), "test");
}


TEST(ShuntingYard, test_with_flag){
    Parser* p = new Parser("test -e header");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    ShuntingYard* Shunt = new ShuntingYard();
    Shunt->ShuntingYardRun(t->tokenized());
    vector<Token*> x = Shunt->Yarded();
    EXPECT_EQ(x.at(0)->getToken(), "test");
}


TEST(ShuntingYard, test_brackets){
    Parser* p = new Parser("[header]");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    ShuntingYard* Shunt = new ShuntingYard();
    Shunt->ShuntingYardRun(t->tokenized());
    vector<Token*> x = Shunt->Yarded();
    EXPECT_EQ(x.at(0)->getToken(), "test");
}


TEST(ShuntingYard, test_brackets_with_space){
    Parser* p = new Parser("[ -e header ]");
    Tokenizer* t = new Tokenizer();
    t->Tokenize(p->commands);
    ShuntingYard* Shunt = new ShuntingYard();
    Shunt->ShuntingYardRun(t->tokenized());
    vector<Token*> x = Shunt->Yarded();
    EXPECT_EQ(x.at(0)->getToken(), "test");
}


#endif //RSHELL_SHUNTING_TEST_HPP
