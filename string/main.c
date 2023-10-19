#include <stdio.h>
#include "string.h"

int main() {
    String *a = blankstr();
    String *b = blankstr();
    fputs("String A: ", stream);
    getstr(a, 20);
    fputs("String B: ", stream);
    getstr(b, 20);
    if (comparestr(a, b->content)) puts("They are the same.");
    else puts("They are different.");
    return 0;
}
