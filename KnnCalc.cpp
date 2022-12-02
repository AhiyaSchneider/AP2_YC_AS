//
// Created by oem on 12/2/22.
//
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include "KnnCalc.h"
#include "DistanceCalc.h"

using namespace std;

/**
 * class KnnCalc will use DistaceCalc to calculate a distance from one vector of data to
 * its K neighbors and conclude its kind accordingly
*/
class KnnCalc
{
private:
    DistanceCalc calc;
    int k; // for holding amuont of neighbors chosen by the user (args[0])
    string inputFile; // args[1] - file to read neighbors from
    string distanceType; // args[2] - chosen metric
    List<vector> distanceList;

public:
    KnnCalc(int k, string file, string type) { // constructor
        calc = new DistanceCalc; // todo - modify DistanceCalc constructor accordingly - no specific v2
        this.k = k;
        this.inputFile = file;
        this.distanceType = type;
    }

    void findK_NearestNeighbors() {
        distanceList = new List<vector>;
        ifstream inFile;
        inFile.open(this.inputFile);
        if(!inFile.is_open()) { //error openning file
            cout >> "error openning file"
            exit(1);
        }
        while (!inFile.eof()) {
            // todo - a function for adding new vector to the list - mabye generalize setV2 func - for extracting a vector from a file regardless to its destination after.
        }
        //todo - private partition function for the whole list of vectors extracted from the file
        //todo - return k first neighbors in the list after partition
        inFile.close();

    }

};
