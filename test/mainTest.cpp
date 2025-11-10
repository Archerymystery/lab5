#include "gtest/gtest.h"
#include "../src/main.hpp"
#include <cmath>
using namespace std;

const double EPSILON = 1e-6;
namespace UnitTest
{

    TEST(CalculateTests, x7_n4_Returned)
    {
        int n = 4;
        int x = 7;

        double expected = 0.006;

        double actual = calculate(n, x);

        EXPECT_NE(expected, actual);
    }

    TEST(CalculateTests, x3_n2_Returned)
    {

        int n = 2;
        int x = 3;

        double expected = 0.111111;

        double actual = calculate(n, x);

        EXPECT_NEAR(expected, actual, EPSILON);
    }

    TEST(CalculateTests, x3_n3_Returned_NOT_PASS)
    {

        int n = 3;
        int x = 3;

        double expected = 1;

        double actual = calculate(n, x);
        EXPECT_NEAR(expected, actual, EPSILON);
    }

    TEST(CalculateTests, x0_n3_Returned_INFINITY)
    {

        int n = 3;
        int x = 0;

        double expected = INFINITY;

        double actual = calculate(n, x);

        EXPECT_NEAR(expected, actual, EPSILON);
    }

    TEST(CheckParamsTests, CheckValidParams_InvalidN_ThrowsError)
    {
        int n = 0;
        EXPECT_ANY_THROW(checkValidParams(n));
    }
    TEST(CheckParamsTests, CheckValidParams_InvalidN_ThrowsError_NOT_PASS)
    {
        int n = 3;
        EXPECT_ANY_THROW(checkValidParams(n));
    }

    TEST(CheckParamsTests, CheckValidParams_ValidN_NoThrow)
    {
        int n = 5;
        EXPECT_NO_THROW(checkValidParams(n));
    }

}