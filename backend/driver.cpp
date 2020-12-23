//csvexample
//Drew Gotshalk
//2020-10-29
#include <iostream>
#include <string>
#include "csvHandler.h"
#include <vector>
#include <utility>

int main(){
	csvHandler newcsv("created.csv");
	std::string date{"1600766348"}; 	
	std::vector<std::pair<std::string,bool>> data{{"i literally just want this to work",true},{ "oh my god, my jello is QUIVERING",false}};
	std::cout << "writing out data"	<< std:: endl;
	newcsv.writeOut(date, data);
	std::vector<std::pair<std::string,bool>> invec{ newcsv.readIn(date) };
	for (auto line : invec){
		std::cout << line.first << " " << line.second << std::endl;
	}
	return 0;
}
