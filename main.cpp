#include "DistanceCalc.h"
#include "KnnCalc.h"
#include <iostream>
#include <unistd.h>
using namespace std;

/**
 * main - try to run the program with given args.
 * argc - the length of argv
 *  excepcted:
 * argv[1] - k as int num.
 * argv[2] - the path to the directory.
 * argv[3] - the distance type.
*/
int main(int argc, char *argv[]) {
    //char cwd[2048] = "/home/oem/Desktop/AP1/YC-AS2/datasets/iris/iris_classified.csv";
    //getcwd(cwd, sizeof(cwd));
    //try to get int from the first arg if not succeed so catch the exception.
    try
    {
        string j = argv[1];
        int kNum = stoi(j);//try to set the first argument as int. take prefix need to change!!!!!!!!
        KnnCalc k(kNum, argv[2], argv[3]);
        k.launchCheckVectors();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " invalid k\n"; //if the stoi failed exception trowned.
    }
    return 0;
}