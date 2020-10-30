// Included Libraries 
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>


// File inclusion
#include "csvHandler.h"

using namespace std;

// C++ file containing class function definitions 

// Constructor, read file into vectors 
csvHandler::csvHandler()
{
	csv_name = "sample.csv";
}
csvHandler::csvHandler(std::string filename){
	csv_name = filename;
}
// Check the date  against dates in the database
//std::string csvHandler::readIn(std::string date){
	// open the csv file
	// read the csv file and match the first column with the date parameter
	// return the line on the csv file
//}
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
	//Now this data should be in date;content;checked,content;checked,...
	

	//open old file and a new file
	//either search for the exact date, or find where the date should be
	//everytime we process a line, we write that to the new file
	//after we do our updating or whatever, then we need to replace the old file with the new file an change name
	ifstream infile(csv_name, ios_base::in);
	std::string newfile = "new_" + csv_name;
	ofstream outfile(newfile, ios_base::out);
	bool written = false;
	while (true){
		std::string current_line_date = "";
		std::getline(infile, current_line_date, ',');
		if (infile.eof()){
			break;
		}
		if (date == current_line_date){
			outfile << row;
			written = true;
		}
		else if (std::stoi(date) > std::stoi(current_line_date) && written == false){
			outfile << row;
			std::string rest_of_line;
			std::getline(infile, rest_of_line);
			outfile << current_line_date + "," + rest_of_line + "\n"; 
			written = true;
		}
		else {
			std::string rest_of_line;
			std::getline(infile, rest_of_line);
			outfile << current_line_date + "," + rest_of_line + "\n"; 
		}
	}
	infile.close();
	outfile.close();
	std::rename(newfile.c_str(), csv_name.c_str());
}

void csvHandler::outputVec()
{
	// For loop to output vectors 
	cout << "Outputting" << endl;
}
