//
// Created by oem on 12/2/22.
//

#ifndef AP2_YC_AS_KNNCALC_H
#define AP2_YC_AS_KNNCALC_H
#include "DistanceCalc.h"
#include <string>
#include <utility>

using namespace std;
class KnnCalc { //TODO - declare functions and globals
private:
    DistanceCalc calc;
    int k;               // for holding amuont of neighbors chosen by the user (args[0])
    string inputFile;    // args[1] - file to read neighbors from
    string distanceType; // args[2] - chosen metric
    vector<vector<double>> vectorList;
    vector<pair<string, double>> distanceList;
    
public:
    KnnCalc(int j, std::string file, std::string DistanceType);
    void findK_NearestNeighbors();

};


#endif //AP2_YC_AS_KNNCALC_H
