#include "gtest/gtest.h"
#include "rectangle_intersection.h"

TEST(RectangleIntersection, AllCases)
{
    Point a(0, 5), b(5, 0);
    Point c(0, 2), d(5, 0);
    ASSERT_TRUE(doRectanglesIntersect(Rectangle(a, b), Rectangle(c, d)));

    a = Point(0, 10);
    b = Point(10, 0);
    c = Point(3, 8);
    d = Point(7, 2);

    ASSERT_TRUE(doRectanglesIntersect(Rectangle(a, b), Rectangle(c, d)));

    a = Point(0, 5);
    b = Point(5, 0);
    c = Point(10, 5);
    d = Point(50, 0);
    ASSERT_FALSE(doRectanglesIntersect(Rectangle(a, b), Rectangle(c, d)));

    a = Point(0, 0);
    b = Point(5,  -5);
    c = Point(-1, -1);
    d = Point(4, -4);
    ASSERT_TRUE(doRectanglesIntersect(Rectangle(a, b), Rectangle(c, d)));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

