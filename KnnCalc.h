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
public:
    KnnCalc(int j, std::string file, std::string type);
    void findK_NearestNeighbors();

};


#endif //AP2_YC_AS_KNNCALC_H
