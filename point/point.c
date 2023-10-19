#include "point.h"
#include <stdlib.h>
#include <stdio.h>

Point *blankpoint() {
    Point *point = (Point *)malloc(sizeof(Point));
    point->x = point->y = 0;
    return point;
}

void deletepoint(Point *point) {
    free(point);
}

Point *createpoint(point_type x, point_type y) {
    Point *point = (Point *)malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    return point;
}
