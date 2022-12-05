//
// Created by oem on 12/2/22.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include "KnnCalc.h"
#include "DistanceCalc.h"

using namespace std;

/**
 * class KnnCalc will use DistaceCalc to calculate a distance from one vector of data to
 * its K neighbors and conclude its kind accordingly
 */
    // constructor
    KnnCalc::KnnCalc(int j, string file, string type)
    {                        
        calc = DistanceCalc(); // done! need to check - modify DistanceCalc constructor accordingly - no specific v2
        k = j;
        inputFile = file;
        distanceType = type;

    }

    /**
     * ~KnnCalc - distructor to this class.
    */
    KnnCalc::~KnnCalc()
    {
    }


    KnnCalc::void findK_NearestNeighbors()
    {
        distanceList = list<vector<double>>();
        ifstream inFile;
        inFile.open(inputFile);
        if (!inFile.is_open())
        { // error openning file
            cout << "error openning file";
            exit(1);
        }
        // set cin to get input from file
        ifstream in(inputFile);
        streambuf *cinbuf = cin.rdbuf(); // save old buf
        cin.rdbuf(in.rdbuf());                // redirect std::cin to in.txt!

        while (!inFile.eof())
        {
            calc.setV2FromFile();
            distanceList.push_back(calc.getV2());
            // todo - a function for adding new vector to the list - mabye generalize setV2 func - for extracting a vector from a file regardless to its destination after.
            //getting the vectros already categories according to type (red/white wine etc.)
        }
        // todo - private partition function for the whole list of vectors extracted from the file
        // todo - return k first neighbors in the list after partition
        inFile.close();
    }
