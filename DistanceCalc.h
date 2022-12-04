#ifndef AP2_YC_AS_DISTANCECALC_H
#define AP2_YC_AS_DISTANCECALC_H
#include <vector>
// notify DistanceCalc that this class exists
class KnnCalc;
using namespace std;
class DistanceCalc
{
   public:
    vector <double> getV1();
    vector <double> getV2();
    void setV1(vector <double> update);
    void setV2(vector <double> update);
    void setV2FromFile();
    double euclidean_Distance();
    double manhattan_Distance();
    double chebyshev_Distance();
    double canberra_Distance();
    double minkowski_Distance();
    void printDistances();
    //bool validVectors(vector<double> v1, vector<double> v2);
    //vector<double> createInputVector();
};

#endif