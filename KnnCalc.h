//
// Created by oem on 12/2/22.
//

#ifndef AP2_YC_AS_KNNCALC_H
#define AP2_YC_AS_KNNCALC_H
#include "DistanceCalc.h"
#include <string>
#include <utility>

using namespace std;
class KnnCalc {
private:
    DistanceCalc calc;
    int k;               // argv[1] for holding amuont of neighbors chosen by the user (args[0])
    string inputFile;    // argv[2] - file to read neighbors from
    string distanceType; // argv[3] - chosen metric
    vector<vector<double>> vectorList;
    vector<pair<double, string>> distanceList1;

    //private methods:
    void setDistanceList();
    double wantedDist();
    string TheMostReturnType();
    

    
public:
    KnnCalc(int j, std::string file, std::string DistanceType);
    void launchCheckVectors();
};


#endif
