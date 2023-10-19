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
    FILE *stream = fopen("log.txt", "w");
    printlist(list, stream);
    fputc('\n', stream);
    fprintf(stream, "Length: %d\n", list->length);
    insert(list, -3, createstr("monkey d luffy", 14));
    printlist(list, stream);
    fputc('\n', stream);
    fprintf(stream, "Length: %d\n", list->length);
    pop(list, 3);
    printlist(list, stream);
    fputc('\n', stream);
    fprintf(stream, "Length: %d\n", list->length);
    fclose(stream);
    // for (int i = 1; i <= list->length; ++i) {
    //     printf("Value: %s\n", getnode(list, -i)->value->content);
    // }
    deletelist(list);
    return 0;
}
