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
#include <algorithm>
#include <QFile>

// File inclusion
#include "csvHandler.h"

using namespace std;

inline std::string const BooltoString(bool b){
	return b ? "1": "0";
}

// C++ file containing class function definitions 

// Constructor, read file into vectors 
csvHandler::csvHandler(){
	csv_name = "sample.csv";
}

csvHandler::csvHandler(QString filename){
	csv_name = filename;
}

/* Find the date that was just selected
 * read in the data from that line
 * send it back to the app in the form of a vector
*/
std::vector<std::pair<std::string,bool>> csvHandler::readIn(std::string date){

		QFile infile(csv_name);
		std::vector<std::pair<std::string,bool>> db_vector;
		if (!infile.open(QIODevice::ReadOnly | QIODevice::Text)){
			return db_vector;
        }
        while (true){
			std::string current_line_date = "";
            std::getline(infile, current_line_date, ',');
            if (date == current_line_date){
				std::string data;		
				std::getline(infile,data);	
				std::stringstream data_strm(data); //data_strm is a row in the csv file
				while(data_strm.good()){		
					std::string task;	
					std::getline(data_strm,task,',');	
					std::replace(task.begin(),task.end(),'\\', ',');	
					std::string checked_as_string;
					std::getline(data_strm, checked_as_string, ',');
					std::istringstream check_stream(checked_as_string);	
					bool checked;
					check_stream >> checked;	
					std::pair<std::string, bool> newpair(task,checked);
					db_vector.push_back(newpair);	
                }
				infile.close();
				break;
			}
			else if (infile.eof()){

				infile.close();
				break;
			}
			std::getline(infile,current_line_date);
		}
		return db_vector;
};

/* Gets data from the app, turn it into a single string
 * Open a new file, read data from the old file into the new file
 * then pick a time to write the new data into the file
 * write the rest of the file out, rename the new file to the name of the old file
*/
void csvHandler::writeOut(std::string date, std::vector<std::pair<std::string,bool>> content){
	//Processing input data		
	//still need to handle semicolons and commas in my data 

	std::string row;
	row += date;
	for (auto line: content){
		std::replace(line.first.begin(),line.first.end(),',','\\');	
		row+= ","+ line.first +","+ BooltoString(line.second);
	}
	row += "\n";


	fstream infile(csv_name.c_str(), ios_base::in | ios_base::out);
	std::string newfile = "new_" + csv_name;
	fstream outfile(newfile.c_str(), ios_base::out | ios_base::in);


	bool written = false;
	std::string current_line_date = "";
	std::getline(infile, current_line_date, ',');	
		
	if (infile.eof()){
		outfile << row;
	}
	else if (current_line_date ==""){
		outfile << row;
	}
	else{
        while (true){
			if (infile.eof()){
				break;
			}
			std::cout << infile.eof() <<std::endl;
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
			std::string current_line_date = "";
			std::getline(infile, current_line_date, ',');
		}
	}
	infile.close();
	outfile.close();
	std::rename(newfile.c_str(), csv_name.c_str());

};

