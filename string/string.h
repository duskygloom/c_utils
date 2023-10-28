#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>

#define STRING_DEFAULT_SIZE 8

typedef struct String {
	int size, length;
	char *content;
} String;

String *blankstr(void);
String *createstr(const char *content, int length);
String *createchar(char ch);
void deletestr(String *string);

String *concatchar(String *string, char ch);
String *precatchar(String *string, char ch);
String *concatstr(String *string, const char *content, int length);
String *precatstr(String *string, const char *content, int length);

String *itos(int n);

/*
	Function comparestr:
		compares str object str1 to char * object str2
		when comparing two str objects, use comparestr(str1, str2->content)
		returns 0 if not equal
		returns 1 if equal
*/
int comparestr(const String *str1, char *str2);

/*
	Function assignstr:
		assigns new content to string
		if content is NULL, does not change the string
			just returns string
		returns the content added into the string
			string->content
*/
char *assignstr(String *string, const char *content, int length);

int getstr(String *string, int length);
static inline char *tostring(String *string) { return string->content; }
void printstr(String *string, FILE *stream);
void printstr_wquotes(String *string, FILE *stream);

#endif

