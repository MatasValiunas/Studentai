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

class Stud{
    private:
        string vard, pav;
        int galut;
        vector<int> nd;

    public: 
        void setVard(string _vard, string _pav){
            vard = _vard;
            pav = _pav;
        }

        void setGalut(int _galut){
            galut = _galut;
        }

        string getVard() const { return vard; }

        string getVard() { return vard; }

        string getPav() const { return pav; }

        int getGalut() const { return galut; }

        bool operator<(Stud a){
            return vard < a.vard;
        }

        bool operator>(Stud a){
            return vard > a.vard;
        }

        ~Stud(){}
};

template <typename T>
void Startas(T&, T&, T&, double []);

template <typename T>
void Rusiavimas(T&, T&, T& , double []);

template <typename T>
void Rusiavimas2(T&, T&, double []);

template <typename T>
void Isvedimas(T&, T&, T&, double []);

template <typename T>
bool IvedimasIsFailo(T&, double []);

void fromMain(double [], char tip);
double Vidurkis(vector<int>&);
bool IvestisYN(string);
int IvestisSk(string, bool check0to10 = true);
void Generavimas(double []);
bool DaugiauNei4(int);