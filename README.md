welcome to our distance caculator machine learning!

the program will get as arguments a K, path to a obj_classified.csv file, a type of distance.
K- run on the k nearest vectors from the file and return the type of the most return type.
path to a obj_classified.csv file - path (relative or direct) to a file of classified vectors to check a vector with.
type of distance - a type of distance between 2 vectors.

user is required to enter input of a vector of numbers: after writing a number - press the space key to move on. 
after insserting the vector the program will run on the given file and return from the k nearest the most return type. 
then wait to another vector and do the same endlessly.

 for any ilegal input - the program will show you a message and finish immediately!

instructions for running the program from terminal:

clone the project files to your local path on your computer you need the files: 
DistanceCalc.cpp DicstanceCalc.h KnnCalc.cpp KnnCalc.h main.cpp and a file of classified vectors.

open the terminal in the path you put the files in.
write the order: "make" than press enter
after that enter "./a.out ..." -  the ...is for the K path and distance method that need to be added as arguments with
only one space seperating between them.

/?g++ *.cpp -std=c++11

////a few words about our implementation: we hold an object of distance calculator that has two members - two vectors of real numbers. we use the vector object given by the library for holding conveniently a dynamic size series of numbers, put in by the user.

we execute several validation tests for the user's input before safely storing his chosen numbers in the vector.
these validations are made to ensure a future legal calculation for each of the calculator 5 distance types.

finally, we hold a .h file holding all of functions and libraries signatures.
