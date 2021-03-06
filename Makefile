main: func.o
	c++ main.cpp func.o -o ats

funkcijos:
	c++ -c func.cpp

clean:
	del *.o *.exe Rezultatai.txt