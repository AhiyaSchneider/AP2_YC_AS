#include "DistanceCalc.h"
#include "KnnCalc.h"
#include <iostream>
using namespace std;

int main() {
    KnnCalc k(2, "file", "type");
    DistanceCalc d;
    d.printDistances();
    return 0;
}