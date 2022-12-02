#include <vector>
#include <cmath>
#include "DistanceCalc.h"
#include "KnnCalc.h"
#include <iostream>
#include <float.h>


using namespace std;

/**
 * class DistanceCalc - set 2 vectors from cin than calculate 5 types of distances on the vectors.
*/
class DistanceCalc
{
private:
    const double maxDigits = log10(DBL_MAX);
    vector<double> v1;
    vector<double> v2;

    /**
     * validVectors - validate if the vectors are the same sizes.
    */
    bool validVectors()
    {
        // validate by vectors length.
        if (v1.size() != v2.size())
        {
            return false;
        }
        return true;
    }

    /**
     * printDouble - print double as shown in the example.
    */
    void printDouble(double d)
    {
        //check if d is an integer
        if (d == ceil(d) && d == floor(d))
        { 
            fixed(cout);
            cout.precision(1);
            cout << d;
        }
        //d is a real number
        else 
        {
            fixed(cout);
            cout.precision(16);
            cout << d;
        }
        cout << "\n";
    }

public:

    /**
     * DistanceCalc - constructor to this class
    */
    DistanceCalc()
    {
        //get 2 vectors from user.
        v1 = createInputVector();
        v2 = createInputVector();
        //check if we can ccalculate distances
        if (!validVectors())
        {
            cout << "vector are not valid for distance calculation not same size!\n";
            //cout << v1.size() << "\n" << v2.size();
            exit(1);
        }
    }

    /**
     * ~DistanceCalc - distructor to this class.
    */
    ~DistanceCalc()
    {
    }

    /**
     * getV1 - getter for v1.
     * return v1.
    */
    vector<double> getV1()
    {
        return v1;
    }

    /**
     * getV2 - getter for v2.
     * return v2.
    */
    vector<double> getV2()
    {
        return v2;
    }

    void setV1(vector<double> update)
    {
        v1 = update;
    }
    void setV2(vector<double> update)
    {
        v2 = update;
    }

    /**
     * createInputVector - creating vector from buffer.
     * return vector of double values.
    */
    vector<double> createInputVector()
    {
        vector<double> v;
        string input, temp = "";
        //set boolean varabales for negative numbers and decimal points.
        bool dotFlag = false, minusFlag = false;
        //read buffer to input
        getline(cin, input);
        //check if there is no input
        if (input.size() == 0)
        {
            cout << "no input entered\n";
            exit(1);
        }
        //run on input string and generate double varabales.
        for (int i = 0; i < input.size(); i++)
        {
            //check if the char at i is digit if it is add to temp string.
            if (isdigit(input.at(i)))
            {
                temp += input.at(i);
            }
            //check pussabilitty for negative value.
            else if (!minusFlag && temp.size() == 0 && input.at(i) == '-')
            {
                //set minus flag as true.
                temp += input.at(i);
                minusFlag = true;
            }
            //check pussabilitty for dacimal value.
            else if (input.at(i) == '.' && temp.size() != 0)
            { 
                // valid dot location
                if (!dotFlag && !(temp.size() == 1 && minusFlag))
                {
                //check if the first char in '-'
                    temp += input.at(i);
                    dotFlag = true;
                }
                // input is no valid
                else
                {
                    cout << "real number can not have more than one decimal point!\n";
                    exit(1);
                }
            }
            //check if the input is not a ' ' or '\n' so it a - Z or other sign that not connected to double numbers.
            else if (input.at(i) != ' ' && input.at(i) != '\n')
            {
                cout << "real number can not contain these characters!\n";
                exit(1);
            }
            // space key and check if temp.size is greater than 0 and smaller than double range (~308)
            else if (temp.size() != 0)
            { 
                if(temp.size() > maxDigits) { //too many digit for double range
                    cout << "too many digit for double range - invalid input\n";
                    exit(1);

                }
                // if we got here we have valid number
                double valid = stod(temp);
                v.push_back(valid);
                //re set for the next double var from user
                temp = "";
                minusFlag = false;
                dotFlag = false;
            }
        }
        // check if temp is valid number within double range
        if (temp != "") {
            if(temp.size() > maxDigits) { //too many digit for double range
                    cout << "too many digit for double range - invalid input\n";
                    exit(1);

                }
            // if we got here we have valid number
            double valid = stod(temp); 
            v.push_back(valid);
        }
        return v;
    }

    /**
     * euclidean_Distance - calculae the distance in euclidean method.
     * return distance.
    */
    double euclidean_Distance()
    {
        double sum = 0;
        int i;
        for (i = 0; i < v1.size(); i++)
        {               
            // calculate all dimentions                        
            sum += pow(v1.at(i) - v2.at(i), 2); 
        }
        return sqrt(sum);
    }

    /**
     * manhattan_Distance - calculae the distance in manhattan method.
     * return distance.
    */
    double manhattan_Distance()
    {
        double sum = 0;
        int i;
        for (i = 0; i < v1.size(); i++)
        {                               
            // calculate all dimentions
            sum += abs(v1.at(i) - v2.at(i)); 
        }
        return sum;
    }

    /**
     * chebyshev_Distance - calculae the distance in chebyshev method.
     * return distance.
    */
    double chebyshev_Distance()
    {
        double sum = 0, max = 0;
        int i;
        for (i = 0; i < v1.size(); i++)
        {                    
            // calculate all dimentions
            sum = abs(v1.at(i) - v2.at(i)); 
            if (sum > max)
            {
                max = sum;
            }
        }
        return max;
    }

    /**
     * canberra_Distance - calculae the distance in canberra method.
     * return distance.
    */
    double canberra_Distance()
    {
        double sum = 0, mone, machne;
        int i;
        for (i = 0; i < v1.size(); i++)
        {
            // calculate all dimentions
            mone = abs(v1.at(i) - v2.at(i));
            machne = (abs(v1.at(i)) + abs(v2.at(i)));
            if (!machne)
            {
                continue;
            }  
            sum += mone / machne;                     
        }
        return sum;
    }

    /**
     * minkowski_Distance - calculae the distance in minkowski method.
     * return distance.
    */
    double minkowski_Distance()
    {
        double sum = 0;
        int i;
        for (i = 0; i < v1.size(); i++)
        {
            // calculate all dimentions
            sum += pow(v1.at(i) - v2.at(i), 2); 
        }
        return sqrt(sum);
    }

    /**
    * printDistances - printing all of the distances.
    */
    void printDistances()
    {
        printDouble(euclidean_Distance());
        printDouble(manhattan_Distance());
        printDouble(chebyshev_Distance());
        printDouble(canberra_Distance());
        printDouble(minkowski_Distance());
    }  
};

/**
 * main - run this class and print the distances.
*/
int main()
{
    DistanceCalc d;
    d.printDistances();
    return 0;
}
