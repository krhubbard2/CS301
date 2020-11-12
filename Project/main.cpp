// main.cpp
// Kelby Hubbard
// Started: 2020-10-15
// Updated: 2020-11-11

// For CS 301 Fall 2020
// Main source code for Assembly Language Programming Project
// Binary to hexadecimal tester

// Please note this program is not a very clean way to make this
// program. This program implements assembly lanaguage (x86-64 via nasm).
// This program can be made simpler, cleaner and more efficiently without
// implementation of assembly -- which is not the point of writing this.

#include "fltk.h"

// Main program
// Runs FLTK main window
int main(int argc, char** argv)
{
	  
	// Main Window
	Fl_Double_Window* mainWindow = new Fl_Double_Window(765, 520, 
	 												"Binary to Hexadecimal");


	// Drop Down Menu Bar Child 0
	{ Fl_Menu_Bar* menuBar
			= new Fl_Menu_Bar(0, 0, 85, 25);
	  	menuBar->box(FL_PLASTIC_UP_BOX);
		// When selected runs "generateButtonCallback()" in fltk.cpp
    menuBar->add("File/Generate", FL_CTRL + 'g',generateButtonCallback);
    // When selected runs "submitButtonCallback()" in fltk.cpp
    menuBar->add("File/Submit", FL_CTRL + 's',submitButtonCallback);
    // When selected runs "concedeButtonCallback()" in fltk.cpp
    menuBar->add("File/Concede", FL_CTRL + 'c', concedeButtonCallback);
		// When selected runs "quit()" in fltk.cpp
		menuBar->add("File/Quit", FL_CTRL + 'q',quit);
		// When selected runs "help()" in fltk.cpp
		menuBar->add("Help/Help", FL_CTRL + 'h',help);
	}

	// Generate Button Child 1
	{ Fl_Button* generateButton = new Fl_Button(118, 255, 185, 100, "Generate");
      generateButton->box(FL_PLASTIC_UP_BOX);

      // On button press
      generateButton->callback(generateButtonCallback);
    }

    // Submit Button Child 2
    { Fl_Button* submitButton = new Fl_Button(413, 255, 185, 100, "Submit");
      submitButton->box(FL_PLASTIC_UP_BOX);

      // On button press
      submitButton->callback(submitButtonCallback);
    } 

    // Binary Output Box Child 3
    { Fl_Output* binaryOutput = new Fl_Output(105, 80, 215, 50, "Binary");
      binaryOutput->box(FL_PLASTIC_UP_BOX);
      binaryOutput->align(Fl_Align(FL_ALIGN_BOTTOM));
    }

    // Hex Input Box Child 4
    { Fl_Input* hexInput = new Fl_Input(390, 80, 215, 50, "Hex input");
      hexInput->box(FL_PLASTIC_UP_BOX);
      hexInput->align(Fl_Align(FL_ALIGN_BOTTOM));
    }

    // Result Output Box Child 5
    { Fl_Output* resultOutput = new Fl_Output(245, 175, 215, 50, "Result");
      resultOutput->box(FL_PLASTIC_UP_BOX);
      resultOutput->align(Fl_Align(FL_ALIGN_BOTTOM));

      // Starting output
      string start = "First click \"Generate\"!";
      resultOutput->value(resultOutputStartup());
    }

    // Difficulty Counter Child 6
    { Fl_Spinner* difficultyCounter = new Fl_Spinner(303, 450, 110, 25, "Difficulty");
      difficultyCounter->align(Fl_Align(FL_ALIGN_BOTTOM));
      difficultyCounter->box(FL_PLASTIC_UP_BOX);
      difficultyCounter->range(1,4);
    }

    // Concede Button Child 7
    { Fl_Button* concedeButton = new Fl_Button(265, 380, 185, 50, "Concede");
      concedeButton->box(FL_PLASTIC_UP_BOX);

      // On button press
      concedeButton->callback(concedeButtonCallback);
    }

	//Show main FLTK window
	mainWindow->end();
	mainWindow->resizable();
	mainWindow->show(argc, argv);
	return (Fl::run());
}


