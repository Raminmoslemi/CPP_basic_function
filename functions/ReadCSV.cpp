

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;

std::vector<std::vector<double> > ReadCSV(string file_name,
  int start_x, int end_x, int start_y, int end_y){
  std::vector<std::vector<double> > result;
 std::ifstream  data(file_name.c_str());
 if(data.is_open()){
   std:: string line;
   int line_counter=0;
   while (std::getline(data,line) ) {
     if (line_counter<=end_x &&  line_counter>=start_x ){
       std::stringstream line_stream(line);
       std::string cell_temp;
       std::vector<double> line_container;
       int column_counter=0;
       while (std::getline(line_stream, cell_temp, ',')) {
         if (line_counter<=end_y &&  line_counter>=start_y) {
           line_container.push_back(atof(cell_temp.c_str()));
         }
         column_counter++;
       }
       result.push_back(line_container);
     }
     line_counter++;
   }
 }else{ std::cout<< "The file can not be opend"<< std::endl;  }
  return result;
}
