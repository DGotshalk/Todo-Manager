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
#include <QString>
#include <QTextStream>
// File inclusion
#include "csvHandler.h"

using namespace std;

inline QString const BooltoString(bool b){
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
/* ALL STRING BECOME QSTRING
 * ALL FILE READING MUST BE CHANGED TO QFILE READING
 */
std::vector<std::pair<QString ,bool>> csvHandler::readIn(QString date){
		QFile infile(csv_name);
		std::vector<std::pair<QString,bool>> db_vector;
		if (!infile.open(QIODevice::ReadOnly | QIODevice::Text)){
			return db_vector;
		}
		QTextStream in(&infile);
        while (true){
			QStringList current_line_data = {""};
			current_line_data = in.readLine().split(',');  //1st comma seperated statement should be the date,
			if (date == current_line_data[0]){

				/* After current_line_data[0], it should be data,bool,data,bool
				 * want to put everything after current_line_data[0] into a stream
				 * then go through the stream, pausing on every "," getting the data, and bool
				 * put the data into a Qstring, the bool into a bool, put that into a vector
				 * done
				 */

				QStringstream data_strm(data); //data_strm is a row in the csv file

				while(data_strm.good()){
					QString task;
					std::getline(data_strm,task,',');	
					std::replace(task.begin(),task.end(),'\\', ',');	
					QString checked_as_string;
					std::getline(data_strm, checked_as_string, ',');
					std::istringstream check_stream(checked_as_string);	
					bool checked;
					check_stream >> checked;	
					std::pair<QString, bool> newpair(task,checked);
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

*/
/* ALL STRING BECOME QSTRING
 * ALL FILE READING MUST BE CHANGED TO QFILE READING
 */


void csvHandler::writeOut(QString date, std::vector<std::pair<QString,bool>> content){
	//Processing input data		
	//still need to handle semicolons and commas in my data 

	QString row;
	row += date;
	for (auto line: content){
		std::replace(line.first.begin(),line.first.end(),',','\\');	
		row+= ","+ line.first +","+ BooltoString(line.second);
	}
	row += "\n";


	fstream infile(csv_name.c_str(), ios_base::in | ios_base::out);
	QString newfile = "new_" + csv_name;
	fstream outfile(newfile.c_str(), ios_base::out | ios_base::in);


	bool written = false;
	QString current_line_date = "";
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
				QString rest_of_line;
				std::getline(infile, rest_of_line);
				written = true;
			}
			else if (std::stoi(date) > std::stoi(current_line_date) && written == false){
				outfile << row;
				QString rest_of_line;
				std::getline(infile, rest_of_line);
				outfile << current_line_date + "," + rest_of_line + "\n"; 
				written = true;
			}
			else {
				QString rest_of_line;
				std::getline(infile, rest_of_line);
				outfile << current_line_date + "," + rest_of_line + "\n"; 
			}
			QString current_line_date = "";
			std::getline(infile, current_line_date, ',');
		}
	}
	infile.close();
	outfile.close();
	std::rename(newfile.c_str(), csv_name.c_str());

};

