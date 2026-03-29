/******************************************************************************
This program demonstrates the functionality of the MY_STRING object.
It creates MY_STRING objects and tests operations that include appending
characters, trimming characters, printing the string, and freeing memory.

Author: Deena Qannan
Date: 3/12/2026

*******************************************************************************/
#include "my_string.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

int main(void) {

	// Demonstrates append
	printf("MY_STRING demo 1: Numbers (append)\n");
	MY_STRING *str = CreateString("123");
	if (str == NULL) {
		printf("String create failed.");
		return -1;
	}
	PrintString(str);
	AppendChar(str, '4');
	PrintString(str);
	AppendChar(str, '5');
	PrintString(str);
	DeleteString(str);
	

	// Demonstrates append
	printf("\n\nMY_STRING demo 2: Alphabet (empty string, append)\n");
	str = CreateString("");
	if (str == NULL) {
	  printf("String create failed.");
	  return -1;
	}
	PrintString(str);
	for (char c = 'A'; c <= 'Z'; c++) {
	  AppendChar(str, c);
	}
	PrintString(str);
	DeleteString(str);

	// Demonstrates trim
	printf("\n\nMY_STRING demo 3: Trim state (trim)\n");
	str = CreateString("Bothell, Washington");
	if (str == NULL) {
	  printf("String create failed.");
	  return -1;
	}
	PrintString(str);
	int result = TrimAt(str, 7);
	assert(result == 0); // checking error code was success
	PrintString(str);
	DeleteString(str);

	// Demonstrates append, trim
	printf("\n\nMY_STRING demo 4: Hello world (append and trim)\n");
	str = CreateString("Hello world");
	if (str == NULL) {
	  printf("String create failed.");
	  return -1;
	}
	PrintString(str);
	AppendChar(str, '!');
	PrintString(str);
	TrimAt(str, 6);
	PrintString(str);
	AppendChar(str, ':');
	AppendChar(str, ')');
	PrintString(str);
	DeleteString(str);

	// Demonstrates trim error with invalid index
	printf("\n\nMY_STRING demo 5: Invalid index (trim)\n");
	str = CreateString("James Bond");
	if (str == NULL) {
	  printf("String create failed.");
	  return -1;
	}
	PrintString(str);
	result = TrimAt(str, 50);
	assert(result != 0); // checking error code was failure
	PrintString(str);
	DeleteString(str);


	// Demonstrates trim all
	printf("\n\nMY_STRING demo 6: Disappear (trim all)\n");
	str = CreateString("Disappear!");
	if (str == NULL) {
	  printf("String create failed.");
	  return -1;
	}
	PrintString(str);
	result = TrimAt(str, 0);
	assert(result == 0); // checking error code was success
	DeleteString(str);

	// Demonstrates trim all and then append
	printf("\n\nMY_STRING demo 7: Re-appear (trim all and append)\n");
	str = CreateString("Disappear!");
	if (str == NULL) {
	  printf("String create failed.");
	  return -1;
	}
	PrintString(str);
	result = TrimAt(str, 0);
	assert(result == 0); // checking error code was success
	PrintString(str);
	char reappear[] = "...re-appear!";
	for (int i = 0; i < strlen(reappear); i++){
	  AppendChar(str, reappear[i]);
	}
	PrintString(str);
	DeleteString(str);
	

	return 0;
}