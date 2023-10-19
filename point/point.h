#ifndef POINT_H
#define POINT_H

#include "../string/string.h"

// type  | you want the x and y values to be
//       v   should be a numeric type like int or double
typedef int point_type;

// how long the string form of the Point can possibly be
#define MAX_POINT_STRING_LENGTH 64

typedef struct Point {
    point_type x, y;
} Point;

Point *blankpoint();
Point *createpoint(point_type x, point_type y);
void deletepoint(Point *point);

#endif
