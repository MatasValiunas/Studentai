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

template <typename T>
void Startas(T&, T&, T&, double []);

template <typename T>
void IvedimasRanka(T&);

template <typename T>
void Rusiavimas(T&, T&, T& , double []);

template <typename T>
void Isvedimas(T&, T&, T&, double []);

template <typename T>
bool IvedimasIsFailo(T&, double []);

void fromMain(double [], char tip);
double Vidurkis(int n, vector<int>&);
bool IvestisYN(string);
int IvestisSk(string, bool check0to10 = true);
void Generavimas(double []);