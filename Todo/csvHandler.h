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
	// Functions
	public:
		// Read csv file into vectors
		std::vector<std::pair<std::string,bool>> readIn(std::string date);
		//Testing reading in as part of constructor
		
		// Add event to object (in dev)
		
		// Remove event from object (in dev)

		// Write object to csv file
		void writeOut(std::string date, std::vector<std::pair<std::string,bool>> content);
		
		// Sort object (in dev)

		// Output objects 
		void outputVec();
		
		// Constructor
		csvHandler();
		csvHandler(std::string filename);

	// Variables 
	private:
		// Vector for date
		std::vector<int> dateVec;
	    std::string csv_name;
		// Vector for event data
		std::vector<std::string> eventVec;
};
#endif
