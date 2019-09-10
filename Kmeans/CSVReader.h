//
// Created by Francesco on 1/13/19.
//

#ifndef KMEANS_SERIALE_CSVREADER_H
#define KMEANS_SERIALE_CSVREADER_H

#include <string>
#include <vector>
#include "PointND.h"


class CSVReader
{
    std::string fileName;
    std::string delimeter;

public:
    CSVReader(std::string filename, std::string delm = ",") :
            fileName(filename), delimeter(delm)
    { }

    // Function to fetch data from a CSV File
    void getData(std::vector<PointND>* punti);
    void getData(std::vector<PointND>* punti, int dimDataset);
};
//It accepts the filename as constructor argument and provides a member function
// that reads the content of CSV file and returns the data in a vector of vector<std::string> i.e.
#endif //KMEANS_SERIALE_CSVREADER_H