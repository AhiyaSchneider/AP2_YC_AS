#include "DistanceCalc.h"
#include "KnnCalc.h"
#include <iostream>
using namespace std;

int main() {
    KnnCalc k(3, "/home/oem/Desktop/AP1/YC-AS2/datasets/iris/iris_classified.csv", "MAN");
    //DistanceCalc d;
    //d.printDistances();
    k.findK_NearestNeighbors();
    return 0;
}