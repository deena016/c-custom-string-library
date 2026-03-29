#ifndef MY_STRING_H
#define MY_STRING_H

/*
Interface for the MY_STRING object.

Allows for additional string manipulations, such as appending characters
and erasing characters.
*/

struct MyString {
	// Pointer to a heap-allocated char[].  Data includes only the visible
	// letters (no terminating character)
	char *strData;

	// Number of characters in the string
	int size;
} typedef MY_STRING;

/*
Takes as input a regular c string and returns a pointer to a MY_STRING object.  Uses the text from the input string as the data text.  Returns NULL if creation unsuccessful.
*/
MY_STRING* CreateString(char* inputStr);

/*
Prints the size and text of a MY_STRING object
*/
void PrintString(MY_STRING* str);

/*
Deletes all resources for a MY_STRING object.
*/
void DeleteString(MY_STRING* str);

/*
Appends the given character to the end of the MY_STRING data.  Returns 0 if the append is successful and -1 otherwise.
*/
int AppendChar(MY_STRING* str, char c);

/*
Removes the text data from the given index to the end of the MY_STRING data.  Returns 0 if the trim is successful and -1 otherwise.
*/
int TrimAt(MY_STRING* str, int index);

#endif