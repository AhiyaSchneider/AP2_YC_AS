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
#include<bits/stdc++.h>
#include <map>

using namespace std;

/**
 * class KnnCalc will use DistaceCalc to calculate a distance from one vector of data to
 * its K neighbors and conclude its kind accordingly
 */

/**
 * constructor
 * param - j the int that serve as k for k nearest.
 * file - the path to the file.
 * type - type of wanted distances.
 */ 
KnnCalc::KnnCalc(int j, string file, string type)
{
    /**
     * DistanceCalc calc;
     * int k                // argv[1] for holding amuont of neighbors chosen by the user (args[0])
     * string inputFile     // argv[2] - file to read neighbors from
     * string distanceType  // argv[3] - chosen metric
     * vector<vector<double>> vectorList      initialized in launch
     * vector<pair<string, double>> distanceList;   initialized in launch
     *calc already initialized
     */ 
    k = j;
    inputFile = file;
    distanceType = type;
}

 //change to method only for extract from file and add method that sort and find the k's
void KnnCalc::setDistanceList()
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
    //maybe to try do the setv2 as another func
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
        p.second = wantedDist();
        distanceList.push_back(p);
        v.clear();
        temp = "";
    }
    // todo - private partition function for the whole list of vectors extracted from the file
    // todo - return k first neighbors in the list after partition
    inFile.close();
    sort(distanceList.begin(), distanceList.end());
}

/**
 * wantedDist - search for the wanted type of distance and return the double value.
 * return the wanted dist.
*/
double KnnCalc::wantedDist(){
    if(!distanceType.compare("AUC")){
        return calc.euclidean_Distance();
    } else if(!distanceType.compare("MAN")){
        return calc.manhattan_Distance();
    } else if(!distanceType.compare("CHB")){
        return calc.chebyshev_Distance();
    } else if(!distanceType.compare("CAN")) {
        return calc.canberra_Distance();
    } else if(!distanceType.compare("MIN")) {
        return calc.minkowski_Distance();
    }
    cout<< "not valid distance";
    exit(1);
    return 0;
}

/**
 * TheMostReturnType - search from the first k which return the most times.
*/
string KnnCalc::TheMostReturnType(){
    multimap <string, double> distanceMap;
    for (int i = 0; i < k; i++)
    {
        distanceMap.insert(pair<string, double> (distanceList.at(i).first, distanceList.at(i).second));
    }
    pair <int, string> max;
    max.first = 0;
    map<string, double> :: iterator it;
    for (it = distanceMap.begin(); it != distanceMap.end(); it++)
    {
        if(max.first < distanceMap.count(it -> first)) {
            max.first = distanceMap.count(it -> first);
            max.second = it -> first;
        }
    }
    return max.second;  
}

/**
 * launchCheckVectors - ask for vector and return the type endless time.
*/
void KnnCalc::launchCheckVectors(){
    while(true){
        //reset everything to beggining.
        vectorList.clear();
        distanceList.clear();
        //launch the sequence.
        calc.setV1(calc.createInputVector());
        setDistanceList();
        cout<<"the type is: " + TheMostReturnType() + '\n';
    }
}
