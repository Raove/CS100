#include "c-echo.h"

#include "gtest/gtest.h"

TEST(EchoTest, HelloWorld) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world";
    EXPECT_EQ("hello world", echo(3,test_val));
}
TEST(EchoTest, EmptyString) {
    char* test_val[1]; test_val[0] = "./c-echo";
    EXPECT_EQ("", echo(1,test_val));
}
TEST(EchoTest, HappyFace) {
    char* test_val[1]; test_val[0] = "./c-echo"; test_val[1] = ":)";
    EXPECT_EQ("", echo(1,test_val));
}
TEST(EchoTest, HelloWorldWithNewLine) {
    char* test_val[3]; test_val[0] = "./c-echo"; test_val[1] = "hello"; test_val[2] = "world\n";
    EXPECT_EQ("hello world\n", echo(3,test_val));
}
TEST(EchoTest, MyName) {
    char* test_val[5]; test_val[0] = "./c-echo"; test_val[1] = "Raoul"; test_val[2] = "Steve"; test_val[3] = "Larios"; test_val[4] = "Lopez";
    EXPECT_EQ("Raoul Steve Larios Lopez", echo(5,test_val));
}
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
