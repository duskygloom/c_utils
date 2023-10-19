#include "list.h"
#include <stdio.h>

int main() {
    List * list = createlist();
    // String *str1 = ;
    // String *str2 = ;
    // String *str3 = ;
    append(list, createstr("hello", 5));
    append(list, createstr("melusine", 8));
    append(list, createstr("real", 4));
    append(list, createstr("aloha", 5));
    append(list, createstr("teri teri", 9));
    append(list, createstr("real hai", 8));
    append(list, createstr("truest", 6));
    append(list, createstr("meow pussy", 10));
    printlist(list);
    putchar('\n');
    printf("Length: %d\n", list->length);
    insert(list, -1, createstr("monkey d luffy", 14));
    printlist(list);
    putchar('\n');
    printf("Length: %d\n", list->length);
    // for (int i = 1; i <= list->length; ++i) {
    //     printf("Value: %s\n", getnode(list, -i)->value->content);
    // }
    deletelist(list);
    return 0;
}
