#include <cstream>
#include <iostream>

#include "csvHandler.cpp"

// A Sample drive program for testing the csvHandler class 

// A simple menu function
void menu(char option)
{
	// Add event to file
	// Remove event from file
}

int main(){
	// Char value
	char inputOption;

	// Instantiate class
	
	// Run Menu function
	while (inputOption != 'q')
	{
		// User inputs values 
		cin >> inputOption;

		// Run menu function
		menu(inputOption);
	}
	return 0;
}
