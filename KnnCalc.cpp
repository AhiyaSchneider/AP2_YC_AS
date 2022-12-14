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
#include <bits/stdc++.h>
#include <map>

using namespace std;

/**
 * class KnnCalc will use DistaceCalc to calculate a distance from one vector of data to
 * its K neighbors and conclude its kind accordingly
 */

/**
 * constructor
 * param:
 * j the int that serve as k for k nearest.
 * file - the path to the file.
 * type - type of wanted distances.
 * 
 * other fields:
 * vector<vector<double>> vectorList      initialized in launch
   vector<pair<string, double>> distanceList;   initialized in launch
   calc already initialized
 * 
 */
KnnCalc::KnnCalc(int j, string file, string type)
{
    k = j;
    inputFile = file;
    distanceType = type;
}

/**
 * setDistanceList - safly collects the right distances from the input vector (according to chosen metrica)
 * to a list of pairs - <distance, type of specific vector according to file>
 * eventually sort the list - prep for finding first k neighbors
 */


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
    while (getline(inFile, s))
    {
        if(!validString(s)){
            cout << "one of the vector wasnt ok from file";
            exit(1);
        }
        istringstream ss(s);
        string temp;
        for (int i = 0; i < v1Length; i++)
        {
            double x;
            ss >> x;
            v.push_back(x);
            ss.get();
            // check if there are no numbers in the line
            if (!ss)
            {
                cout << "the file's vectors arent the same length as the given one: shorter\n";
                exit(1);
            }
        }
        /*
         * check if in ss remained numbers if so exit.
         * check if the next char of stream is part of number or part of the name.
         * is it okay to string - a type, to start with a number
         */
        if (ss.peek() >= '0' && ss.peek() <= '9')
        {
            cout << "the file's vectors arent the same length as the given one: longer\n";
            exit(1);
        }
        ss >> temp;
        calc.setV2(v);
        vectorList.push_back(v);
        pair<double, string> p1;
        p1.second = temp;
        p1.first = wantedDist();
        distanceList1.push_back(p1);
        v.clear();
        temp = "";
    }
    inFile.close();
    sort(distanceList1.begin(), distanceList1.end());
}

/**
 * wantedDist - search for the wanted type of distance and return the double value.
 * return the wanted dist.
 */
double KnnCalc::wantedDist()
{
    if (!distanceType.compare("AUC"))
    {
        return calc.euclidean_Distance();
    }
    else if (!distanceType.compare("MAN"))
    {
        return calc.manhattan_Distance();
    }
    else if (!distanceType.compare("CHB"))
    {
        return calc.chebyshev_Distance();
    }
    else if (!distanceType.compare("CAN"))
    {
        return calc.canberra_Distance();
    }
    else if (!distanceType.compare("MIN"))
    {
        return calc.minkowski_Distance();
    }
    cout << "not valid distance";
    exit(1);
    return 0;
}

/**
 * TheMostReturnType - search maximal frequency of type within the first k neighbors in the list and returns it.
 */
string KnnCalc::TheMostReturnType()
{
    multimap<string, double> distanceMap1;
    // make sure that k is the smaller between given k and given vectors amount
    int listSize = distanceList1.size();
    int localK = std::min(listSize, k);
    for (int i = 0; i < localK; i++)
    {
        distanceMap1.insert(pair<string, double>(distanceList1.at(i).second, distanceList1.at(i).first));
    }
    pair<int, string> max1;
    max1.first = 0;
    map<string, double>::iterator it1;
    for (it1 = distanceMap1.begin(); it1 != distanceMap1.end(); it1++)
    {
        if (max1.first < distanceMap1.count(it1->first))
        {
            max1.first = distanceMap1.count(it1->first);
            max1.second = it1->first;
        }
    }
    return max1.second;
}

/**
 * launchCheckVectors - ask for vector and return the type according to knn.
 * the method will run as long as the user wishes.
 */
void KnnCalc::launchCheckVectors()
{
    while (true)
    {
        // reset everything to beggining - for new input.
        vectorList.clear();
        distanceList1.clear();
        // for convinience - make sure the file to open is valid before taking input from user
        ifstream inFile;
        inFile.open(inputFile);
        if (!inFile.is_open())
        { // error openning file
            cout << "error openning file";
            exit(1);
        }
        inFile.close();
        // launch the sequence.
        calc.setV1(calc.createInputVector());
        setDistanceList();
        cout << "the type is: " + TheMostReturnType() + '\n';
    }
}

bool KnnCalc::validString(string s)
{
    int i = 0, sLen = s.length();
    int v1Size = calc.getV1().size(), v2Size = 0;
    bool minusF = false, dotF = false, letterEF = false, numF = false;
    for(i = 0; i < sLen; i++) {
        if(v2Size > v1Size){
            cout << "the vector from the file is longer";
            exit(1);
        }else if(s[i] == ',' && numF){
            v2Size++;
            minusF = false;
            dotF = false;
            letterEF = false;
            numF = false;
        }else if(s[i] == '-'){
            if(numF || minusF){
                cout<<"there is '-' in wrong place";
                exit(1);
            }
            minusF = true;
        }else if(s[i] == '.'){
            if(!numF || dotF){
                cout<<"there is '.' in wrong place";
                exit(1);
            }
            dotF = true;
        }else if((s[i] < '0' || s[i] > '9') && v1Size > v2Size){
            if(s[i] == 'e'){
                //if(letterEF){
                //    cout<<"?????????? not sureee"; /////////////////////////////////////////////////////////
                //}
                //letterEF = true;
            }
            else {
                cout<< "there is letter where it shoudnt be in the file";
                exit(1);
            }
        } else if(s[i] >= '0' && s[i] <= '9') {
            numF = true;
        }
    }
    return true;
}
