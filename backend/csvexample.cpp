//csvexample
//Drew Gotshalk
//2020-10-29
#include <iostream>
#include <string>
#include "csvHandler.h"
#include <vector>

int main(){
	csvHandler newcsv;
	std::string date{"1600766348"}; 
	std::vector<std::string> data{"i literally just want this to work"};
	newcsv.writeOut(date, data);
	return 0;
}
