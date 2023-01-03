welcome to our machine learning - distance calculator !

the program will get as arguments : K, path to a obj_classified.csv file, a type of a distance (metrica).
K- run on the k nearest vectors from the file and return the type of the most return type.
path to a obj_classified.csv file - path (relative or direct) to a file of classified vectors to check a vector with.
type of distance - a type of distance between 2 vectors.

user is required to enter input of a vector of numbers: after writing a number - press the space key to move on. 
after inserting the vector the program will run on the given file and return from the k nearest the most return type. 
then wait to another vector and do the same endlessly.

 for any ilegal input - the program will show you a message and finish immediately!
 (including inaccurate representation of numbers. for example = ".3" will not be accetped! i don't know if your intention is indeed 0.3 or some other idea)

instructions for running the program from terminal:

clone the project files to your local path on your computer you need the files: 
DistanceCalc.cpp DicstanceCalc.h KnnCalc.cpp KnnCalc.h main.cpp and a file of classified vectors.

open the terminal in the path you put the files in.
notice - if you choose to use relative file path - make sure you open your terminal from the relevant folder for both the data file and the code files!

write the order: "make" than press enter
after that enter "./a.out ..." -  the ...is for the K path and distance method that need to be added as arguments with
only one space seperating between them.

a few words about our implementation: we had the distanceCalc class from the previous assignmant.
the distanceCalc class have 2 vectors and 5 methods of distances so we wraped this method with KnnCalc class.
the class has as variable an object of distanceCalc class.
send k, path, distance type to KnnCalc constructor than launch the program to read one vector from user to v1 from distanceCalc.
than run on the given file and set every line as v2 of distanceCalc. the string at the end of line - is the given distance type (in a valid case).
return the most return type and wait for new vector to repeat the program endlessly.

we execute several validation tests for the user's input before safely storing his chosen numbers in the vector, and a vector type.
these validations are made to ensure a future legal calculation for each of the calculator 5 distance types.

finally, we hold a .h file holding all of functions and libraries signatures.
our code could be easily modified for adding more distance options or change k and data file while running.
