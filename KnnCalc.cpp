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
            //check if there are no numbers in the line
            if(!ss){
                cout<<"the file's vectors arent the same length as the given one: shorter\n";
                exit(1);
            }
        }
        //works for unclassified file also?
        /**
         * check if in ss remained numbers if so exit.
         * check if the next char of stream is part of number or part of the name.
         * problem if it is ok but the string start with number?????????????????????!!!!!!!!!!!1
         */
        if(ss.peek() >= '0' && ss.peek() <= '9'){                              
            cout<<"the file's vectors arent the same length as the given one: longer\n";
            exit(1);
        }
        ss >> temp;
        calc.setV2(v);
        // TODO - switch case and validation check
        vectorList.push_back(v);
        pair <double ,string> p1;
        p1.second = temp;
        p1.first = wantedDist();
        distanceList1.push_back(p1);
        v.clear();
        temp = "";
    }
    // todo - private partition function for the whole list of vectors extracted from the file
    // todo - return k first neighbors in the list after partition
    inFile.close();
    sort(distanceList1.begin(), distanceList1.end());
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
    multimap <string, double> distanceMap1;
    //make sure that k is the smaller between given k and given vectors amount
    int localK = min(distanceList1.size(), k);
    for (int i = 0; i < localK; i++)
    {
        distanceMap1.insert(pair<string,double > (distanceList1.at(i).second, distanceList1.at(i).first));
    }
    pair <int, string> max1;
    max1.first = 0;
    map<string, double> :: iterator it1;
    for (it1 = distanceMap1.begin(); it1 != distanceMap1.end(); it1++)
    {
        if(max1.first < distanceMap1.count(it1 -> first)) {
            max1.first = distanceMap1.count(it1 -> first);
            max1.second = it1 -> first;
        }
    }
    return max1.second;  
}

/**
 * launchCheckVectors - ask for vector and return the type endless time.
*/
void KnnCalc::launchCheckVectors(){
    while(true){
        //reset everything to beggining.
        vectorList.clear();
        distanceList1.clear();
        //launch the sequence.
        calc.setV1(calc.createInputVector());
        setDistanceList();
        cout<<"the type is: " + TheMostReturnType() + '\n';
    }
}
