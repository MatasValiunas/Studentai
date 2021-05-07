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

class Zmogus{
    protected:
        string vard, pav;
        int galut;

    public: 
        virtual ~Zmogus() = 0;

        string getVard() const { return vard; }
        string getPav() const { return pav; }

        void setVard(string _vard, string _pav){
            vard = _vard;
            pav = _pav;
        }
        void setGalut(int _galut){ galut = _galut; }
};

inline Zmogus::~Zmogus(){}

class Stud : public Zmogus{
    private:
        int galut;

    public: 
        void setVard(string _vard, string _pav){
            vard = _vard;
            pav = _pav;
        }

        void setGalut(int _galut){ galut = _galut; }

        string getVard() const { return vard; }
        string getPav() const { return pav; }
        int getGalut() const { return galut; }


        Stud(){}
        Stud (string _vard, string _pav, int _galut) : galut(_galut){
            vard = _vard;
            pav = _pav; 
        }

        Stud (const Stud& a) : galut(a.getGalut()){        // Kopijavimo konstruktorius
            vard = a.getVard();
            pav = a.getPav();
        }

        Stud& operator=(const Stud& a){     // Priskyrimo operatorius
            if(&a == this) 
                return *this;
            vard = a.getVard();
            pav = a.getPav();
            galut = a.getGalut();   
            return *this;
        }

        ~Stud(){}       // Destruktorius

        bool operator<(Stud a){
            return vard < a.vard;
        }

        bool operator>(Stud a){
            return vard > a.vard;
        }
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
