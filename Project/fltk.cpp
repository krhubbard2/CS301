// fltk.cpp
// Kelby Hubbard
// Started: 2020-10-15
// Updated: 2020-11-11

// For CS 301 Fall 2020
// FLTK source code for Assembly Language Programming Project
// Binary to hexadecimal tester

#include "fltk.h"


// ***** Dropdown Menu Functions *****

// help
// Refer to header for documentation
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

// quit
// Refer to header for documentation
void quit(Fl_Widget* w, void* data){
  Fl_Window* window = new Fl_Window(340, 150, "Quit");
  	Fl_Box* box = new Fl_Box(20, 40, 300, 35, "Are you sure you want to quit?");
  	Fl_Button* yesButton = new Fl_Button(120, 100, 100, 25, "Yes I\'m sure.");
    yesButton->box(FL_PLASTIC_UP_BOX);
  	yesButton->callback(quitProgram);

  	box->show();
  	window->show();
}

// quitProgram
// Refer to header for documentation
void quitProgram(Fl_Widget* w, void* data)
{
	exit(0);
}

// ***** Callback Functions *****

// generateButtonCallback
// Refer to header for documentation
void generateButtonCallback(Fl_Widget* w, void* data)
{
  Fl_Button* b = (Fl_Button*) w;
  Fl_Output * o = (Fl_Output*)b->parent()->child(3);

  // Generate random number and convert to binary. Display output.
  o->value(decToBinary(generate(diffValue(w,data))).c_str());

  Fl_Output * o1 = (Fl_Output*)b->parent()->child(5);
  o1->value(generateButtonClick());

}

// submitButtonCallback
// Refer to header for documentation
void submitButtonCallback(Fl_Widget* w, void* data)
{
  // Grab user input
  Fl_Button* b = (Fl_Button*) w;
  Fl_Output * o = (Fl_Output*)b->parent()->child(4);
  string input = o->value();

  // Grab generated binary and convert to decimal
  Fl_Output * o1 = (Fl_Output*)b->parent()->child(3);
  string binaryOut = o1->value();
  int decimalOut = binaryToDecimal(binaryOut);


  // 
  int decIn;
  std::stringstream stream;
  stream << input;
  stream >> std::hex >> decIn;

  // If user input was correct
  Fl_Output * op = (Fl_Output*)b->parent()->child(5);
  if (decIn == decimalOut)
  {
    op->value(correctString());
  }
  else
  {
    op->value(wrongString());
  }

}

// concedeButtonCallback
// Refer to header for documentation
void concedeButtonCallback(Fl_Widget* w, void* data)
{
  Fl_Button* b = (Fl_Button*) w;
  Fl_Output * o = (Fl_Output*)b->parent()->child(3);
  string binaryOut = o->value(); 
  int decimalOut = binaryToDecimal(binaryOut);

  std::stringstream stream;
  stream << std::hex << decimalOut;
  string answer = (stream.str());

  Fl_Output * o1 = (Fl_Output*)b->parent()->child(5);
  string out = "The correct answer was " + answer;
  o1->value(out.c_str());


}

// diffValue
// Refer to header for documentation
long diffValue(Fl_Widget* w, void* data)
{
  double temp = 0;
  Fl_Button* b = (Fl_Button*) w;
  Fl_Spinner * s = (Fl_Spinner*)b->parent()->child(6);
  temp = s->value();
  long final = temp;
  return final;
}

// decToBinary
// Refer to header for documentation
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

// binaryToDecimal
// Refer to header for documentation
int binaryToDecimal(string n)
{

    int num = std::stoi(n);
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}