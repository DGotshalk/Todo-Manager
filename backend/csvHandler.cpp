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
	csv_name = "null.csv";
}
csvHandler::csvHandler(std::string filename){
	csv_name = filename;
}
// Check the date  against dates in the database
std::string csvHandler::readIn(std::string date){
	// open the csv file
	// read the csv file and match the first column with the date parameter
	// return the line on the csv file
}
// Write vectors to csv file \\Content is the combined "date, details,
// plan is to have "Date, content; checked, content; checked," etc etc etc
void csvHandler::writeOut(std::string& date, std::vector<std::string>& content)
{	
	//Processing input data		
	std::string row;
	row += date + ",";
	for (auto line: content){
		row+= line + ",";
	}
	row += "\n";
	//Now this data should be in date;content;checked;;content;checked;;
		
	//open old file and a new file
	//either search for the exact date, or find where the date should be
	//everytime we process a line, we write that to the new file
	//after we do our updating or whatever, then we need to replace the old file with the new file an change name
	ifstream infile(csv_name, ios_base::in);
	std::string newfile = "new_" + csv_name;
	ofstream outfile(newfile, ios_base::out);







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
