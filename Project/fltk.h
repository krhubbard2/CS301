// fltk.h
// Kelby Hubbard
// Started: 2020-10-15
// Updated: 2020-10-24

// For CS 301 Fall 2020
// FLTK header for Assembly Language Programming Project
// Binary to hexadecimal tester


#ifndef FILE_FLTK_H_INCLUDED
#define FILE_FLTK_H_INCLUDED

#include <iostream>

// For std::random_device, std::mt19937, std::uniform_int_distribution
#include <random>
#include <string>
using std::string;

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Spinner.H>

// Help function for menu dropdown bar
void help(Fl_Widget* w, void* data);

// Quit function for menu dropdown bar
void quit(Fl_Widget* w, void* data);

// Exits program
void quitProgram(Fl_Widget* w, void* data);

// Callback function for generateButton
void generateButtonCallback(Fl_Widget* w, void* data);

// Callback function for submitButton
void submitButtonCallback(Fl_Widget* w, void* data);

// Difficulty Value is returned as a long
long diffValue(Fl_Widget* w, void* data);


string decToBinary(long n);

#endif // FILE_FLTK_H_INCLUDED