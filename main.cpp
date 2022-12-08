#include "DistanceCalc.h"
#include "KnnCalc.h"
#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]) {
    //char cwd[2048] = "/home/oem/Desktop/AP1/YC-AS2/datasets/iris/iris_classified.csv";
    //getcwd(cwd, sizeof(cwd));
    
    try
    {
        string j = argv[1];
        int kNum = stoi(j);//try to set the first argument as int. take prefix need to change!!!!!!!!
        KnnCalc k(kNum, argv[2], argv[3]);
        k.launchCheckVectors();
        //k.setDistanceList();
        //cout<<"the type is: " + k.TheMostReturnType() + '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " invalid k\n"; //if the stoi failed exception trowned.
    }
    //DistanceCalc d;
    //d.printDistances();
    return 0;
}