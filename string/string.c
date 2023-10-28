#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

String *blankstr(void) {
	String *string = malloc(sizeof(String));
	string->content = malloc(STRING_DEFAULT_SIZE * sizeof(char));
	string->size = STRING_DEFAULT_SIZE;
	string->length = 0;
	string->content[0] = '\0';
	return string;
}

String *createstr(const char *content, int length) {
	int nblocks = length / STRING_DEFAULT_SIZE + 1;
	String *string = malloc(sizeof(String));
	string->content = malloc(nblocks * STRING_DEFAULT_SIZE * sizeof(char));
	string->size = nblocks * STRING_DEFAULT_SIZE;
	string->length = length;
	string->content = memcpy(string->content, content, length);
	string->content[length] = '\0';
	return string;
}

String *createchar(char ch) {
    String *string = (String *)malloc(sizeof(String));
	string->size = STRING_DEFAULT_SIZE;
	string->length = 1;
	string->content = (char *)malloc(STRING_DEFAULT_SIZE * sizeof(char));
    string->content[0] = ch;
	string->content[1] = '\0';
    return string;
}

void deletestr(String *string) {
	free(string->content);
	free(string);
}

String *concatchar(String *string, char ch) {
    if (string->size - string->length <= 1) {
        string->size += STRING_DEFAULT_SIZE;
        string->content = realloc(string->content, string->size);
    }
    char *stringptr = string->content;
    for (; *stringptr; ++stringptr);
    *stringptr = ch;
    ++stringptr;
    *stringptr = '\0';
    ++string->length;
    return string;
}

String *precatchar(String *string, char ch) {
	char *oldcontent = string->content;
	if (string->size - string->length <= 1)
        string->size += STRING_DEFAULT_SIZE;
    string->content = malloc(sizeof(char) * string->size);
	char *stringptr = string->content;
	*stringptr = ch;
	++stringptr;
	memcpy(stringptr, oldcontent, string->length);
	*(stringptr + string->length) = '\0';
	free(oldcontent);
	++string->length;
    return string;
}

/*
	Function concatstr:
		value of length is very crucial
		because it directly adds length to the existing length
		so use carefully
		returns the same string after concatenation
*/
String *concatstr(String *string, const char *content, int length) {
	int needed = string->length + length;
	if (needed >= string->size) {
		int nblocks = needed / STRING_DEFAULT_SIZE + 1;
		string->size = nblocks * STRING_DEFAULT_SIZE;
		string->content = realloc(string->content, sizeof(char) * string->size);
	}
	char *stringptr = string->content;
	for (; *stringptr; ++stringptr);
	memcpy(stringptr, content, length);
	*(stringptr + length) = '\0';
	string->length += length;
	return string;
}

String *precatstr(String *string, const char *content, int length) {
	char *oldcontent = string->content;
	int needed = string->length + length;
	if (needed >= string->size) {
		int nblocks = needed / STRING_DEFAULT_SIZE + 1;
		string->size = nblocks * STRING_DEFAULT_SIZE;
	}
	string->content = malloc(sizeof(char) * string->size);
	char *stringptr = string->content;
	memcpy(stringptr, content, length);
	stringptr += length;
	memcpy(stringptr, oldcontent, string->length);
	*(stringptr + string->length) = '\0';
	string->length += length;
    return string;
}

String *itos(int n) {
	String *string = blankstr();
	for (; n > 0; n/=10) precatchar(string, '0' + n%10);
    return string;
}

/*
	Function comparestr:
		returns -1 if str1 < str2
		returns 0 if str1 == str2
		returns 1 if str1 > str2
*/
int comparestr(const String *str1, char *str2) {
	char *strptr1 = str1->content;
	char *strptr2 = str2;
	// running the loop till the strings are the same
	for (; *strptr1 && *strptr2 && *strptr1 == *strptr2; ++strptr1, ++strptr2);
	if (*strptr1 < *strptr2) return -1;
	else if (*strptr1 == *strptr2) return 0;
	else return 1;
}

char *assignstr(String *string, const char *content, int length) {
	if (!content) return NULL;

	if (length >= string->size) {
		int nblocks = length / STRING_DEFAULT_SIZE + 1;
		string->size = nblocks * STRING_DEFAULT_SIZE;
		string->content = realloc(string->content, string->size);
	}

	memcpy(string->content, content, length);
	*(string->content + length) = '\0';
	string->length = length;
	return string->content;
}

int getstr(String *string, int length)
{
    int counter = 0, ch;
	for (ch = getchar(); counter < length && ch != '\n'; ch = getchar(), ++counter)
		concatchar(string, ch);
	return counter;
}

void printstr(String *string, FILE *stream) {
	char *stringptr = string->content;
	for (; *stringptr; ++stringptr) fputc(*stringptr, stream);
}

void printstr_wquotes(String *string, FILE *stream) {
	fputc('\'', stream);
	printstr(string, stream);
	fputc('\'', stream);
}
