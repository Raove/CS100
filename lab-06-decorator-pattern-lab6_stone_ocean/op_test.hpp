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

#endif //__OP_TEST_HPP__
