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
	// Read csv file and write to vectors 
	// Open file stream
	// Close file stream
}

// Write vectors to csv file 
void csvHandler::writeOut()
{
	// Truncate file 
	///* Replace csv with correct filename
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
	//*/
	
	// Open file stream
	// For loop to create string from vectors and write string to file
	// Close file stream
	cout << "Writing" << endl;
}

void csvHandler::outputVec()
{
	// For loop to output vectors 
	cout << "Outputting" << endl;
}
