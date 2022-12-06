#include "DistanceCalc.h"
#include "KnnCalc.h"
#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    //char cwd[2048] = "/home/oem/Desktop/AP1/YC-AS2/datasets/iris/iris_classified.csv";
    //getcwd(cwd, sizeof(cwd));
    KnnCalc k(10, "/home/oem/Desktop/AP1/YC-AS2/datasets/iris/iris_classified.csv", "MAN");
    //DistanceCalc d;
    //d.printDistances();
    k.findK_NearestNeighbors();
    return 0;
}