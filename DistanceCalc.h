#ifndef DISTANCECALC_H
#define DISTANCECALC_H
#include <vector>
class KnnCalc; //notify DistanceCalc that this class exists

double euclidean_Distance();
double manhattan_Distance();
double chebyshev_Distance();
double canberra_Distance();
double minkowski_Distance();
//bool validVectors(vector<double> v1, vector<double> v2);
//vector<double> createInputVector();

#endif