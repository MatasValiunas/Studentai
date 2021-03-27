main: vector.o
	c++ main.cpp vector.o -o ats

funkcijos:
	c++ -c vector.cpp

clean:
	del *.o *.exe Rezultatai.txt