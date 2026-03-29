/*
This file implements the functions for the MY_STRING library. The MY_STRING
object stores text using heap-allocated memory and keeps track of the number
of characters in the string. The functions allow creating a string, printing
it, appending characters, trimming characters, and safely freeing memory.
*/
#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

MY_STRING *CreateString(char *inputStr) {
	MY_STRING *obj = (MY_STRING *)malloc(sizeof(MY_STRING));
	if (obj == NULL) {
		return NULL;
	}
	obj->size = strlen(inputStr);
	if (obj->size == 0) {
		obj->strData = NULL;
	} else {
		obj->strData = (char *)malloc(strlen(inputStr));
		if (obj->strData == NULL) {
			free(obj);
			return NULL;
		}
		memcpy(obj->strData, inputStr, obj->size);
	}
	return obj;
}


void PrintString(MY_STRING *str) {
	printf("MyString (size %d): ", str->size);
	for (int i = 0; i < str->size; i++) {
		printf("%c", str->strData[i]);
	}
	printf("\n");
}


//DeleteString() frees all heap memory used by the MY_STRING object. Including
//the character data and the MY_STRING structure.
void DeleteString(MY_STRING *str) {
	if (str == NULL) {
		return;
	}

	if (str->strData != NULL) {
		free(str->strData);
	}

	free(str);
}


//AppendChar() adds a character to the end of the MY_STRING data. realloc() is
//used to increase the memory size of the character array. Returns 0 if the
//append succeeds and -1 if memory allocation fails.
int AppendChar(MY_STRING *str, char c) {
	char *newData = (char *)realloc(str->strData, str->size + 1);

	if (newData == NULL) {
		return -1;
	}

	str->strData = newData;
	str->strData[str->size] = c;
	str->size++;

	return 0;
}


//TrimAt() removes characters from the given index to the end of the string.
//If index is 0, the entire string is removed and its memory is freed.
//Returns 0 on success and -1 if the index is invalid or memory allocation fails.
int TrimAt(MY_STRING *str, int index) {
	if (index < 0 || index > str->size) {
		return -1;
	}

	if (index == 0) {
		free(str->strData);
		str->strData = NULL;
		str->size = 0;
		return 0;
	}

	char *newData = (char *)realloc(str->strData, index);

	if (newData == NULL) {
		return -1;
	}

	str->strData = newData;
	str->size = index;


	return 0;
}