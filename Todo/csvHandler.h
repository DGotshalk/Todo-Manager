#ifndef csvHandler_h
#define csvHandler_h
// Header file for csvHandler class

// Included Libraries 
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <QFile>
#include <QString>
#include <vector>
#include <utility>


// This class is the main class for the backend

class csvHandler {	
	private:
		QString csv_name;
	public:
		std::vector<std::pair<QString, bool>> readIn(QString date);
		void writeOut(QString date, std::vector<std::pair<QString, bool>> content);
		csvHandler();
		csvHandler(QString filename);
};
#endif
