//
// Created by Francesco on 1/13/19.
//

#include "CSVReader.h"
#include <math.h>
#include "PointND.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>

void CSVReader::getData(std::vector<PointND>* punti)
{
    std::ifstream file(fileName);

    std::string line = "";

    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        std::vector<std::string> vec;
        std::vector<float> vecFloat;
        boost::algorithm::split(vec, line, boost::is_any_of(delimeter)); //funzione che fa lo split del vettore ad ogni riga
        for(int i=0; i<vec.size();i++){
            float coord = std::stof(vec.at(i));
            vecFloat.push_back(coord);
        }

        PointND pointND = PointND(&vecFloat);
        punti->push_back(pointND);

    }
    // Close the File
    file.close();

}

void CSVReader::getData(std::vector<PointND>* punti, int dimDataset)
{
    std::ifstream file(fileName);

    std::string line = "";
    int i=0;
    // Iterate through each line and split the content using delimeter
    while (getline(file, line) && i<dimDataset)
    {
        std::vector<std::string> vec;
        std::vector<float> vecFloat;
        boost::algorithm::split(vec, line, boost::is_any_of(delimeter)); //funzione che fa lo split del vettore ad ogni riga
        for(int i=0; i<vec.size();i++){
            float coord = std::stof(vec.at(i));
            vecFloat.push_back(coord);
        }

        PointND pointND = PointND(&vecFloat);
        punti->push_back(pointND);
        i++;
    }
    // Close the File
    file.close();

}
