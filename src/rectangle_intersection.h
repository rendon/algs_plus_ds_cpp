#ifndef RECTANGLE_INTERSECTION_H_
#define RECTANGLE_INSTERSECTION_H
struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};

struct Rectangle {
    Point ul, lr;
    Rectangle() {}
    Rectangle(Point ul, Point lr) : ul(ul), lr(lr) {}
};

bool doSegmentIntersect(int a, int b, int c, int d)
{
    if (a <= c) {
        return b > c;
    } else {
        return a < d;
    }
}

bool doRectanglesIntersect(Rectangle A, Rectangle B)
{
    return doSegmentIntersect(A.ul.x, A.lr.x, B.ul.x, B.lr.x) &&
           doSegmentIntersect(A.lr.y, A.ul.y, B.lr.y, B.ul.y);
}

#endif
