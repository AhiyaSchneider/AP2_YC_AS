a.out: main.o KnnCalc.o DistanceCalc.o
	g++ main.o KnnCalc.o DistanceCalc.o -o a.out

main.o: main.cpp
	g++ -c main.cpp

KnnCalc.o: KnnCalc.cpp
	g++ -c KnnCalc.cpp

	
DistanceCalc.o: DistanceCalc.cpp
	g++ -c DistanceCalc.cpp

clean:
	rm *.o a.out

	

