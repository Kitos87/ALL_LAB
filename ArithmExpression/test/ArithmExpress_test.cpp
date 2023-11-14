#include<gtest.h>
#include "MyArithmExpress.h"

TEST(TArithmeticExpression, basic_arithmetic) {
    TArithmeticExpression expr1("3+2");
    EXPECT_EQ(expr1.Calculate(), 5);

    TArithmeticExpression expr2("4-2");
    EXPECT_EQ(expr2.Calculate(), 2);

    TArithmeticExpression expr3("5*3");
    EXPECT_EQ(expr3.Calculate(), 15);

    TArithmeticExpression expr4("8/2");
    EXPECT_EQ(expr4.Calculate(), 4);
}

TEST(TArithmeticExpression, complex_arithmetic) {
    TArithmeticExpression expr1("3+2*5");
    EXPECT_EQ(expr1.Calculate(), 13);

    TArithmeticExpression expr2("(1+2)*4");
    EXPECT_EQ(expr2.Calculate(), 12);

    TArithmeticExpression expr3("10/(2+3)");
    EXPECT_EQ(expr3.Calculate(), 2);
}

TEST(TArithmeticExpression, sin_cos) {
    TArithmeticExpression expr1("sin(90)");
    EXPECT_NEAR(expr1.Calculate(), 1, 1e-6);

    TArithmeticExpression expr2("cos(0)");
    EXPECT_NEAR(expr2.Calculate(), 1, 1e-6);
}

TEST(TArithmeticExpression, division_by_zero) {
    TArithmeticExpression expr1("1/0");
    EXPECT_THROW(expr1.Calculate(), runtime_error);
}

TEST(TArithmeticExpression, zero_operations) {
    TArithmeticExpression expr1("0");
    EXPECT_EQ(expr1.Calculate(), 0);

    TArithmeticExpression expr2("0+0");
    EXPECT_EQ(expr2.Calculate(), 0);

    TArithmeticExpression expr3("0-0");
    EXPECT_EQ(expr3.Calculate(), 0);
}

TEST(TArithmeticExpression, parentheses) {
    TArithmeticExpression expr1("(3+2)*2");
    EXPECT_EQ(expr1.Calculate(), 10);

    TArithmeticExpression expr2("2*(3+2)");
    EXPECT_EQ(expr2.Calculate(), 10);

    TArithmeticExpression expr3("(2+3)*(4+5)");
    EXPECT_EQ(expr3.Calculate(), 45);
}

TEST(TArithmeticExpression, nested_parentheses) {
    TArithmeticExpression expr1("((3+2)*2)");
    EXPECT_EQ(expr1.Calculate(), 10);

    TArithmeticExpression expr2("(2*(3+(2*2)))");
    EXPECT_EQ(expr2.Calculate(), 14);

    TArithmeticExpression expr3("(((2+3)*(4+5)))");
    EXPECT_EQ(expr3.Calculate(), 45);
}

TEST(TArithmeticExpression, functions_and_arithmetic) {
    TArithmeticExpression expr1("sin(45)+1");
    EXPECT_NEAR(expr1.Calculate(), sin(M_PI / 4) + 1, 1e-6);

    TArithmeticExpression expr2("2*cos(45)");
    EXPECT_NEAR(expr2.Calculate(), 2 * cos(M_PI / 4), 1e-6);
}


TEST(TArithmeticExpression, edge_cases) {
    TArithmeticExpression expr1("999*999");
    EXPECT_EQ(expr1.Calculate(), 999 * 999);

    TArithmeticExpression expr2("0.1+0.2");
    EXPECT_NEAR(expr2.Calculate(), 0.3, 1e-6);

    TArithmeticExpression expr3("0.00001/0.0001");
    EXPECT_NEAR(expr3.Calculate(), 0.1, 1e-6);
}

TEST(TArithmeticExpression, simple_addition) {
    TArithmeticExpression expr("1+1");
    EXPECT_EQ(expr.Calculate(), 2);
}
