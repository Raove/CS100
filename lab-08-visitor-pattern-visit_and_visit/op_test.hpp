#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "base.hpp"
#include "ceil.hpp"
#include "floor.hpp"
#include "abs.hpp"
#include "trunc.hpp"
#include "paren.hpp"
#include "iterator.hpp"
#include "countvisitor.hpp"


Base* num1 = new Op(10);
Base* num2 = new Op(2);

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}
TEST(OpStringTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->stringify(), "8.000000");
}
TEST(RandTest, OpEvaluateNonZero) {
    Rand* test = new Rand();
    EXPECT_LT(test->evaluate(), 101);
}
TEST(MultTest, OpEvaluateNonZero) {
    Mult* test = new Mult(num1, num2);
    EXPECT_EQ(test->evaluate(), 20);
}
TEST(MultStringTest, OpEvaluateNonZero) {
    Mult* test = new Mult(num1, num2);
    EXPECT_EQ(test->stringify(), "10.000000*2.000000");
}
TEST(DivTest, OpEvaluateNonZero) {
    Div* test = new Div(num1, num2);
    EXPECT_EQ(test->evaluate(), 5);
}
TEST(DivStringTest, OpEvaluateNonZero) {
    Div* test = new Div(num1, num2);
    EXPECT_EQ(test->stringify(), "10.000000/2.000000");
}
TEST(AddTest, OpEvaluateNonZero) {
    Add* test = new Add(num1, num2);
    EXPECT_EQ(test->evaluate(), 12);
}
TEST(AddStringTest, OpEvaluateNonZero) {
    Add* test = new Add(num1, num2);
    EXPECT_EQ(test->stringify(), "10.000000+2.000000");
}
TEST(SubTest, OpEvaluateNonZero) {
    Sub* test = new Sub(num1, num2);
    EXPECT_EQ(test->evaluate(), 8);
}
TEST(SubStringTest, OpEvaluateNonZero) {
    Sub* test = new Sub(num1, num2);
    EXPECT_EQ(test->stringify(), "10.000000-2.000000");
}
TEST(PowTest, OpEvaluateNonZero) {
    Pow* test = new Pow(num1, num2);
    EXPECT_EQ(test->evaluate(), 100);
}
TEST(PowStringTest, OpEvaluateNonZero) {
Pow* test = new Pow(num1, num2);
EXPECT_EQ(test->stringify(), "10.000000**2.000000");
}
TEST(CeilStringTest, Base10) {
Base* three = new Op(3);
Base* seven = new Op(7);
Base* four = new Op(4);
Base* two = new Op(2);
Base* mult = new Mult(seven, four);
Base* add = new Add(three, mult);
Base* minus = new Sub(add, two);
Ceil* test = new Ceil(minus);
EXPECT_EQ(test->stringify(), "3.000000+28.000000-2.000000");
}
TEST(FloorStringTest, Base10) {
Base* three = new Op(3);
Base* seven = new Op(7);
Base* four = new Op(4);
Base* two = new Op(2);
Base* mult = new Mult(seven, four);
Base* add = new Add(three, mult);
Base* minus = new Sub(add, two);
Floor* test = new Floor(minus);
EXPECT_EQ(test->stringify(), "3.000000+28.000000-2.000000");
}
TEST(AbsStringTest, Base10) {
Base* three = new Op(3);
Base* seven = new Op(7);
Base* four = new Op(4);
Base* two = new Op(2);
Base* mult = new Mult(seven, four);
Base* add = new Add(three, mult);
Base* minus = new Sub(add, two);
Abs* test = new Abs(minus);
EXPECT_EQ(test->stringify(), "3.000000+28.000000-2.000000");
}
TEST(ParenStringTest, Base10) {
Base* three = new Op(3);
Base* seven = new Op(7);
Base* four = new Op(4);
Base* two = new Op(2);
Base* mult = new Mult(seven, four);
Base* add = new Add(three, mult);
Base* minus = new Sub(add, two);
Paren* test = new Paren(minus);
EXPECT_EQ(test->stringify(), "(3.000000+28.000000-2.000000)");
}
TEST(TruncStringTest, Base10) {
Base* three = new Op(3);
Base* seven = new Op(7);
Base* four = new Op(4);
Base* two = new Op(2);
Base* mult = new Mult(seven, four);
Base* add = new Add(three, mult);
Base* minus = new Sub(add, two);
Trunc* test = new Trunc(minus);
EXPECT_EQ(test->stringify(), "29.000000");
}

TEST(NullIterator, one){
    Op* one = new Op(1);
    Iterator* test = new NullIterator(one);
    EXPECT_EQ(test->current(), nullptr);
}

TEST(UnaryIterator, ABSone){
    Base* one = new Op(1);
    Base* abs1 = new Abs(one);
    Iterator* test= new UnaryIterator(abs1);
    test->first();

    EXPECT_EQ(test->current()->evaluate(), 1);
}

TEST(BinaryIterator, Add){
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* add = new Add(one, two);
    Iterator* test= new BinaryIterator(add);
    test->first();
    test->next();

    EXPECT_EQ(test->current()->evaluate(), 2);
    EXPECT_EQ(test->is_done(), false);
}

TEST(PreorderIterator, one){
    Op* one = new Op(1);
    Op* two = new Op(2);
    Op* three = new Op(3);
    Op* four = new Op(4);
    Op* six = new Op(6);

    Add* add = new Add(one, two);
    Mult* mul1 = new Mult(add, three);
    Mult* mul2 = new Mult(mul1, four);
    Div* div1 = new Div(mul2, six);

    PreorderIterator* tester = new PreorderIterator(div1);
    tester->first();
    tester->next();

    //EXPECT_EQ("1", tester->first()->stringify());
    EXPECT_EQ(tester->current()->evaluate(), 9);
}

TEST(VisitorTest, One) {
    Op *one = new Op(1);
    Op *two = new Op(2);
    Op *three = new Op(3);
    Op *four = new Op(4);
    Op *six = new Op(6);

    Add *add = new Add(one, two);
    Mult *mul1 = new Mult(add, three);
    Mult *mul2 = new Mult(mul1, four);
    Div *div1 = new Div(mul2, six);
    Base *Dummy = new Abs(div1);

    PreorderIterator *it = new PreorderIterator(Dummy);
    CountVisitor *v = new CountVisitor;
    for (it->first(); !it->is_done(); it->next()) {
        it->current()->accept(v);
    }

    EXPECT_EQ(v->op_count(), 5);
    EXPECT_EQ(v->add_count(), 1);
    EXPECT_EQ(v->div_count(), 1);
    EXPECT_EQ(v->mult_count(), 2);
}

#endif //__OP_TEST_HPP__
