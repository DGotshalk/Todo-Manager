// Included Libraries 
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <sstream>
#include <utility>
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

std::vector<std::pair<std::string,bool>> csvHandler::readIn(std::string date){
		ifstream infile(csv_name, ios_base::in);
		std::vector<std::pair<std::string,bool>> db_vector;	
		while (true){
			std::string current_line_date = "";
			std::getline(infile, current_line_date, ',');
			if (date == current_line_date){
				std::string data;		
				std::getline(infile,data);	
				std::stringstream data_strm(data); //data_strm is a row in the csv file
				while(data_strm.good()){
					std::string single_line;
					std::getline(data_strm,single_line,',');
					std::istringstream single_stream(single_line); //single_stream should be task;checked 
					std::string task;
					std::getline(single_stream,task,';');
					bool checked;	
					single_stream >> checked;
					std::pair<std::string, bool> newpair(task,checked);
					db_vector.push_back(newpair);
				}
				break;
			}
		}
		return db_vector;
}

void csvHandler::writeOut(std::string& date, std::vector<std::string>& content)
{	
	//Processing input data		
	//still need to handle semicolons and commas in my data 
	std::string row;
	row += date;
	for (auto line: content){
		row+= ","+ line;
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
			std::string rest_of_line;
			std::getline(infile, rest_of_line);
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
