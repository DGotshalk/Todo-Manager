// Included Libraries 
#include <cstdlib>
#include <iostream>

// Included Files 
#include "csvHandler.cpp"

using namespace std;

// A Sample drive program for testing the csvHandler class 

// A simple menu function
void menu()
{
	// Char value
	char inputOption;

	// Output menu as visual queue
	cout << "Options:" << endl;
	cout << "a, add event to csv file" << endl;
	cout << "o, output data from csv file" << endl;
	cout << "r, remove event from csv file" << endl;
	cout << "w, save data to csv file" << endl;
	cout << "q, quit program" << endl;
	cout << "Enter an option: ";
	// User inputs values 
	cin >> inputOption;

	// Instantiate class
	csvHandler csvData;

	// Run Menu function
	while (inputOption != 'q')
	{
		// Add event to object
		if (inputOption == 'a')
		{
			cout << "Adding event to object" << endl;
			cout << "In development, try again later" << endl;
		}

		// Output items in CSV file
		else if (inputOption == 'o') 
		{
			cout << "Outputting events in calendar" << endl;
			csvData.outputVec();
		}

		// Remove event from csv file 
		else if (inputOption == 'r')
		{
			cout << "Removing event from object" << endl;
			cout << "In development, try again later" << endl;
		}

		// Write object to csv file 
		else if (inputOption == 'w')
		{
			cout << "Writing events to csv file" << endl;
			csvData.writeOut();
		}

		// Else if input invalid
		else
		{
			cout << "Invalid option entered" << endl;
		}
		cout << "Options:" << endl;
		cout << "a, add event to csv file" << endl;
		cout << "o, output data from csv file" << endl;
		cout << "r, remove event from csv file" << endl;
		cout << "w, save data to csv file" << endl;
		cout << "q, quit program" << endl;
		cout << "Enter an option: ";
		cin >> inputOption;
	}
	cout << "Exiting" << endl;
}

int main(){
	menu();
	return 0;
}
