// Included Libraries 
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// File inclusion
#include "csvHandler.h"

using namespace std;

// C++ file containing class function definitions 

// Constructor, read file into vectors 
csvHandler::csvHandler()
{
	csv_name = "backend.csv";
	// Read csv file and write to vectors 
	// Open file stream
	// Close file stream
}
// Check the date  against dates in the database
std::string csvHandler::readIn(std::string date){
	// open the csv file
	// read the csv file and match the first column with the date parameter
	// return the line on the csv file
}
// Write vectors to csv file \\Content is the combined "date, details,
// plan is to have "Date, content; checked;; contentl checked;;" etc etc etc
void csvHandler::writeOut(std::string date, std::string content)
{
	// either format the data here, or before input, im thinking you do it here
	// put it in the format in the comment above the function name
	// insert it in to the file
	// if we can match the dates then replace the line there,
	// if not make a new line (do we sort here or later? probably on insertion) 
	


	/* Test writing to the sample csv
	ifstream input( "sample.csv", ios::binary );
	char buffer;
	string outfile = "sample.csv";
	ofstream appendFile(outfile, ios_base::out);
	for(int i=0; i<0; i++) 
	{
		input.read( &buffer, sizeof(buffer) ); 
		appendFile.write(&buffer,1);
	}
	appendFile.close(); 
	//
	
	// Open file stream
	// For loop to create string from vectors and write string to file
	// Close file stream
	cout << "Writing" << endl;
	*/
}

void csvHandler::outputVec()
{
	// For loop to output vectors 
	cout << "Outputting" << endl;
}
