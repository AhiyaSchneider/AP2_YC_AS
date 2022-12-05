//
// Created by oem on 12/2/22.
//

#ifndef AP2_YC_AS_KNNCALC_H
#define AP2_YC_AS_KNNCALC_H
#include <string>

//notify Knn that this class exists
class DistanceCalc;
using namespace std;
class KnnCalc { //TODO - declare functions and globals
private:
    DistanceCalc calc;
    int k;               // for holding amuont of neighbors chosen by the user (args[0])
    string inputFile;    // args[1] - file to read neighbors from
    string distanceType; // args[2] - chosen metric
    list<vector<double>> distanceList;

public:
    KnnCalc(int j, std::string file, std::string type);
    void findK_NearestNeighbors();

};


#endif //AP2_YC_AS_KNNCALC_H
