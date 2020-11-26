// fltk.h
// Kelby Hubbard
// Started: 2020-10-15
// Updated: 2020-11-25

// For CS 301 Fall 2020
// FLTK header for Assembly Language Programming Project
// Binary to hexadecimal tester

#ifndef FILE_FLTK_H_INCLUDED
#define FILE_FLTK_H_INCLUDED

// **************************************************************
// I N C L U D E S
// **************************************************************

#include <iostream>
#include <random>   // For std::random_device, std::mt19937, std::uniform_int_distribution
#include <string>   
using std::string;
#include <iomanip>  // For std::hex
#include <sstream>  // For std::stringstream

// ***** FLTK Includes *****
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Spinner.H>

// **************************************************************
// P R O T O T Y P E S
// **************************************************************

// ***** Assembly Language Functions *****
// Info on these functions can be found in bar.asm

extern "C" const char* resultOutputStartup(void);
extern "C" const char* generateButtonClick(void);
extern "C" const char* correctString(void);
extern "C" const char* wrongString(void);
extern "C" long generate(long difficulty);

// help
// Function for menu dropdown bar
// Opens help window
void help(Fl_Widget* w, void* data);

// quit
// Function for menu dropdown bar
// Opens quit window
void quit(Fl_Widget* w, void* data);

// quitProgram
// Exits program -- for use in quit()
void quitProgram(Fl_Widget* w, void* data);

// generateButtonCallback
// Callback function for generateButton
// Generates random binary number and displays to binaryOutput
void generateButtonCallback(Fl_Widget* w, void* data);

// submitButtonCallback
// Callback function for submitButton
// Compares user answer (in hexInput) to binryOut. Prints 
// result to resultOutput
void submitButtonCallback(Fl_Widget* w, void* data);

// concedeButtonCallback
// Callback function for concedeButton
// Converts binaryOutput to hex and prints result to resultOutput
void concedeButtonCallback(Fl_Widget* w, void* data);

// diffValue
// Difficulty Value is returned as a long
// Function used to pass difficulty value to assembly function generate
long diffValue(Fl_Widget* w, void* data);

// decToBinary
// Converts decimal long (taken from generate function) to
// its binary counter-part. Binary output is returned as a string
// for use in generateButtonCallback
string decToBinary(long n);

// binaryToDecimal
// Converts binary string (taken from binaryOutput) to
// its decimal counter-part. Decimal output is returned as an
// int for use in submitButtonCallback
int binaryToDecimal(string n);

#endif // FILE_FLTK_H_INCLUDED