//csvexample
//Drew Gotshalk
//2020-10-29
#include <iostream>
#include <string>
#include "csvHandler.h"
#include <vector>
#include <utility>

int main(){
	csvHandler newcsv;
	std::string date{"1600766348"}; 
	std::vector<std::string> data{"i literally just want this to work"};
	newcsv.writeOut(date, data);
	std::vector<std::pair<std::string,bool>> invec{ newcsv.readIn("1600766348") };
	for (auto line : invec){
		std::cout << line.first << " " << line.second << std::endl;
	}
	return 0;
}
