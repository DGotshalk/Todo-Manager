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
std::vector<std::pair<QString ,bool>> csvHandler::readIn(QString date){
		QFile infile(QCoreApplication::applicationDirPath() + "/"+csv_name);
		std::vector<std::pair<QString,bool>> db_vector;
		if (!infile.open(QIODevice::ReadWrite | QIODevice::Text)){
			std::cout << csv_name.toStdString()<<"Reading in file that does not open" << std::endl;
			return db_vector;
		}
		QTextStream in(&infile);
        while (true){
			QStringList current_line_data = {""};
			current_line_data = in.readLine().split(',');  //1st comma seperated statement should be the date,
			if (date == current_line_data[0]){
				for (int i =1; i < current_line_data.size(); i+=2){
					QString task = current_line_data[i];
					task.replace(QString("\\"), QString(","));
					QString checked_s = current_line_data[i+1];
					bool checked = checked_s.toInt();
					std::pair<QString, bool> newpair(task,checked);
					db_vector.push_back(newpair);
				}

				infile.close();
				break;
			}
			else if (in.atEnd()){
				infile.close();
				break;
			}	
		}

		return db_vector;
};

/* Gets data from the app, turn it into a single string
 * Open a new file, read data from the old file into the new file
 * then pick a time to write the new data into the file
 * write the rest of the file out, rename the new file to the name of the old file
*/
void csvHandler::writeOut(QString date, std::vector<std::pair<QString,bool>> content){	
	QString row;
	row += date;
	for (auto line: content){	
		line.first.replace(QString(","),QString("\\"));
		row+= ","+ line.first +","+ BooltoString(line.second);
	}
	row += "\n";
	QFile infile(QCoreApplication::applicationDirPath() + "/"+csv_name);
	QString newfile = QCoreApplication::applicationDirPath() + "/new_" + csv_name;
	QFile out(newfile);
	if (!infile.open(QIODevice::ReadWrite | QIODevice::Text)){
		std::cout <<csv_name.toStdString()<< "failed to open infile" << std::endl;
		return;
	}
	if (!out.open(QIODevice::WriteOnly | QIODevice::Text)){
		std::cout <<newfile.toStdString()<< "failed to open outfile" << std::endl;
		return;
	}
	/*
	 * NOT WRITING OUT CORRECTLY DAYS CORRECTLY
	 */
	QTextStream in(&infile);
	QTextStream outfile(&out);
	bool written = false;
	QStringList current_line_data = {""};
	current_line_data = in.readLine().split(',');
	QString current_line_date = current_line_data[0];
	if (in.atEnd()){
		if (date.toFloat() > current_line_date.toFloat()){
			outfile << row;
			QString rest_of_line = current_line_data.join(",");
			outfile << rest_of_line + "\n";
		}
		else{
			QString rest_of_line = current_line_data.join(",");
			outfile << rest_of_line + "\n";
			outfile << row;
		}
	}
	else if (current_line_date ==""){
		outfile << row;
	}
	else{
		while (true){			
			if (in.atEnd() || current_line_date == ""){
				if (written == true){
					QString rest_of_line = current_line_data.join(",");
					outfile << rest_of_line + "\n";
				}

				else if (date.toFloat() > current_line_date.toFloat() && written == false){
					outfile << row;
					QString rest_of_line = current_line_data.join(",");
					outfile << rest_of_line + "\n";
				}
				else {
					QString rest_of_line = current_line_data.join(",");
					outfile << rest_of_line + "\n";
					outfile << row;
				}
				break;
			}	
			else if (date == current_line_date){
				outfile << row;
				written = true;
			}
			else if (date.toFloat() > current_line_date.toFloat() && written == false){
				outfile << row;
				QString rest_of_line = current_line_data.join(",");
				outfile << rest_of_line + "\n";
				written = true;
			}
			else {
				QString rest_of_line = current_line_data.join(",");
				outfile << rest_of_line + "\n";
			}
			current_line_date = "";
			current_line_data = in.readLine().split(',');
			current_line_date = current_line_data[0];
		}
	}
	infile.close();
	infile.remove();
	out.close();
	out.rename(QCoreApplication::applicationDirPath() + "/"+csv_name);

};

