main: func.o
	c++ main.cpp func.o -o ats -O2

funkcijos:
	c++ -c func.cpp

clean:
	del *.o *.exe Rezultatai*.txt