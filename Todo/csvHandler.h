#ifndef csvHandler_h
#define csvHandler_h
// Header file for csvHandler class

// Included Libraries 
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
// This class is the main class for the backend

class csvHandler {	
    private:
        std::string csv_name;
    public:
		std::vector<std::pair<std::string,bool>> readIn(std::string date);
		void writeOut(std::string date, std::vector<std::pair<std::string,bool>> content);	
		csvHandler();
		csvHandler(std::string filename);
};
#endif
