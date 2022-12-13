a.out: main.o KnnCalc.o DistanceCalc.o
	g++ -std=c++11 -o a.out main.o KnnCalc.o DistanceCalc.o

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

KnnCalc.o: KnnCalc.cpp
	g++ -std=c++11 -c KnnCalc.cpp


DistanceCalc.o: DistanceCalc.cpp
	g++ -std=c++11 -c DistanceCalc.cpp

clean:
	rm *.o a.out