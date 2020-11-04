// fltk.cpp
// Kelby Hubbard
// Started: 2020-10-15
// Updated: 2020-10-24

// For CS 301 Fall 2020
// FLTK source code for Assembly Language Programming Project
// Binary to hexadecimal tester

#include "fltk.h"

// ***** Assembly Language Functions *****
// Info on these functions can be found in bar.asm

extern "C" int foo(void);
extern "C" long generate(long difficulty);

// ***** Dropdown Menu Functions *****

//Help function
void help(Fl_Widget* w, void* data){
  Fl_Window* window = new Fl_Window(380, 150, "Help");
    window->box(FL_PLASTIC_UP_BOX);
    Fl_Box* box = new Fl_Box(35, 60, 300, 35,
      "Help instructions will be here.\n"
      "I promise.\n"
      "");
  window->show();
  box->show();
}

//Quit function 
void quit(Fl_Widget* w, void* data){
  Fl_Window* window = new Fl_Window(340, 150, "Quit");
  	Fl_Box* box = new Fl_Box(20, 40, 300, 35, "Are you sure you want to quit?");
  	Fl_Button* yesButton = new Fl_Button(120, 100, 100, 25, "Yes I\'m sure.");
    yesButton->box(FL_PLASTIC_UP_BOX);
  	yesButton->callback(quitProgram);

  	box->show();
  	window->show();
}

//Exits program
void quitProgram(Fl_Widget* w, void* data)
{
	exit(0);
}

// ***** Callback Functions *****

void generateButtonCallback(Fl_Widget* w, void* data)
{
  //std::cout << generate(diffValue(w,data)) << std::endl;
  //std::cout << decToBinary(generate(diffValue(w,data))) << std::endl;
  Fl_Button* b = (Fl_Button*) w;
  Fl_Output * o = (Fl_Output*)b->parent()->child(3);
  o->value(decToBinary(generate(diffValue(w,data))).c_str());
}

void submitButtonCallback(Fl_Widget* w, void* data)
{
  foo();
}

long diffValue(Fl_Widget* w, void* data)
{
  double temp = 0;
  Fl_Button* b = (Fl_Button*) w;
  Fl_Spinner * s = (Fl_Spinner*)b->parent()->child(6);
  temp = s->value();
  long final = temp;
  return final;
}

// Function that convert Decimal to binary 
string decToBinary(long n) 
{ 
  string result = "";
    // Size of an integer is assumed to be 8 bits 
    for (long i = 7; i >= 0; i--) { 
        long k = n >> i; 
        if (k & 1) 
          result.append("1");
        else
          result.append("0");
    } 
    return result;
} 