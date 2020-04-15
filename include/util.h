/*	CS125 Group Project
	File: util.h
	Description: Header file to include util.c functions
	Authors: Forrest Mobley
	References: N/A
*/

#ifndef UTIL
#define UTIL

// Global variables
extern int DELAYMODIFIER;

// Function prototypes
void delay(int);
void clear();
void readPrint(int, char [], char []);
int pokemonChoiceToInt(char []);
int debugLauncher();
void pokemonStatReadout();
void npcStatReadout();

#endif
