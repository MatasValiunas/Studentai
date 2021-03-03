#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <fstream>

using namespace std;

struct Stud{
    string vard, pav;
    vector<int> nd;
    int egz;

    bool operator<(Stud a){
        return vard < a.vard;
    }
};

void IvedimasRanka(vector<Stud>& A);
bool IvedimasIsFailo(vector<Stud>& A);
double Vidurkis(int n, vector<int>& paz);
double Mediana(int n, vector<int>& paz);
void Isvedimas(vector<Stud> A);
bool IvestisYN(string tip);
int IvestisSk(string tekstas, bool check0to10 = true);
void RandomPridejimas(vector<int>& nd);