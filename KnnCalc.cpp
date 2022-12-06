//
// Created by oem on 12/2/22.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "KnnCalc.h"
#include "DistanceCalc.h"
#include <utility>

using namespace std;
// class DistanceCalc;
/**
 * class KnnCalc will use DistaceCalc to calculate a distance from one vector of data to
 * its K neighbors and conclude its kind accordingly
 */
// constructor
KnnCalc::KnnCalc(int j, string file, string type)
{
    // calc already initialized
    k = j;
    inputFile = file;
    distanceType = type;
}

void KnnCalc::findK_NearestNeighbors()
{
    ifstream inFile;
    inFile.open(inputFile);
    if (!inFile.is_open())
    { // error openning file
        cout << "error openning file";
        exit(1);
    }
    int v1Length = calc.getV1().size();
    vector<double> v;
    string s;
    while (getline(inFile, s))
    {
        istringstream ss(s);
        string temp;
        for (int i = 0; i < v1Length; i++)
        {
            double x;
            ss >> x;
            v.push_back(x);

            ss.get();
        }
        //works for unclassified file also?
        ss >> temp;
        calc.setV2(v);
        // TODO - switch case and validation check
        vectorList.push_back(v);
        pair <string, double> p;
        p.first = temp;
        p.second = calc.manhattan_Distance();
        distanceList.push_back(p);
        v.clear();
        temp = "";
    }
    // todo - private partition function for the whole list of vectors extracted from the file
    // todo - return k first neighbors in the list after partition
    inFile.close();
}
