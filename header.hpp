#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>
#include <chrono>
#include <deque>
#include <list>

using namespace std;
using namespace chrono;

struct Stud{
    string vard, pav;
    vector<int> nd;
    int egz;
    int galut;

    bool operator<(Stud a){
        return vard < a.vard;
    }
};

void IvedimasRanka(vector<Stud>& A);
bool IvedimasIsFailo(vector<Stud>& A, double Laik[]);
double Vidurkis(int n, vector<int>& paz);
double Mediana(int n, vector<int>& paz);
void Isvedimas(vector<Stud>& A, double Laik[]);
bool IvestisYN(string tip);
int IvestisSk(string tekstas, bool check0to10 = true);
void Generavimas(double Laik[]);
void Rusiavimas(vector<Stud>& A, vector<Stud>& Kiet, vector<Stud>& Minkst, double Laik[]);