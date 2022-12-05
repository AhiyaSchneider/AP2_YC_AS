//
// Created by oem on 12/2/22.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "KnnCalc.h"
#include "DistanceCalc.h"

using namespace std;
//class DistanceCalc;
/**
 * class KnnCalc will use DistaceCalc to calculate a distance from one vector of data to
 * its K neighbors and conclude its kind accordingly
 */
    // constructor
    KnnCalc::KnnCalc(int j, string file, string type)
    {    
        //calc already initialized
        k = j;
        inputFile = file;
        distanceType = type;
    }


    void KnnCalc::findK_NearestNeighbors()
    {
        vectorList = list<vector<double>>();
        distanceList = list<double>();
        ifstream inFile;
        inFile.open(inputFile);
        if (!inFile.is_open())
        { // error openning file
            cout << "error openning file";
            exit(1);
        }
        // set cin to get input from file
        /*ifstream in(inputFile);
        streambuf *cinbuf = cin.rdbuf(); // save old buf
        cin.rdbuf(in.rdbuf());*/                // redirect std::cin to in.txt!
        int v1Length = calc.getV1().size();
        vector<double> v;
        string s;
        while (getline(inFile, s, ','))
        {
            try{
            double x = stod(s);
            v.push_back(x);
            }
            // todo - a function for adding new vector to the list - mabye generalize setV2 func - for extracting a vector from a file regardless to its destination after.
            //getting the vectros already categories according to type (red/white wine etc.)
            catch(exception) {
                if (!v.size() == v1Length) {
                    exit(1);
                }
                calc.setV2(v);
                // TODO - switch case and validation check
                vectorList.push_back(v); // need to add name of each vector and link the two lists
                distanceList.push_back(calc.manhattan_Distance());
            }
        }
        // todo - private partition function for the whole list of vectors extracted from the file
        // todo - return k first neighbors in the list after partition
        inFile.close();
    }
