#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

struct Stud{
    string vard, pav;
    int nd[100];
};

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(0, 10);

void Ivedimas(int& stud, int& n, Stud A[]);
double Vidurkis(int n, int paz[]);
double Mediana(int n, int paz[]);
void Isvedimas(int stud, int n, Stud A[]);
void IvestisYN(char& naujas, string tip);
void IvestisSk(int stud, int n, Stud A[]);
void RandomPridejimas(int& n, int nd[]);

int main(){
    int stud = 0;
    int n = 0;
    Stud A[100];

    Ivedimas(stud, n, A);
    Isvedimas(stud, n, A);
}

void Ivedimas(int& stud, int& n, Stud A[]){
    char naujasStud = 'Y';
    char naujasND = 'Y';
    bool atsit = false;
    char laik;

    cout << "Ar balus generuoti atsitiktinai? [Y/N]: ";
    cin >> laik;
    while (toupper(laik) != 'Y' && toupper(laik) != 'N'){
        cout << "Neteisinga ivestis!" << endl << "Ar balus generuoti atsitiktinai? [Y/N]: ";
        cin >> laik;
    }
    if (toupper(laik) == 'Y')
        atsit = true;
    
    while (toupper(naujasStud) == 'Y'){
        cout << stud+1 << " studento pavarde: ";
        cin >> A[stud].pav;
        cout << stud+1 << " studento vardas: ";
        cin >> A[stud].vard;
        if (!atsit){
            if (n == 0){
                IvestisSk(stud, n, A);
                n++;
                IvestisYN(naujasND, "namu darba");
                while (toupper(naujasND) == 'Y'){
                    IvestisSk(stud, n, A);
                    n++;
                    IvestisYN(naujasND, "namu darba");
                }
            }
            else {
                for (int i=0; i<n; i++)
                    IvestisSk(stud, i, A);
            }
        }
        else {
            if (n == 0){
                RandomPridejimas(n, A[stud].nd); 
                IvestisYN(naujasND, "namu darba");
                while (toupper(naujasND) == 'Y'){
                    RandomPridejimas(n, A[stud].nd);
                    IvestisYN(naujasND, "namu darba");
                }
            }
            else {
                for (int i=0; i<n; i++)
                    RandomPridejimas(i, A[stud].nd);
            }
        }
        stud++;
        IvestisYN(naujasStud, "studenta");
    }  
}

double Vidurkis(int n, int paz[]){
    int sum = 0;
    for (int i=0; i<n; i++)
        sum += paz[i];
    return (double)sum / n;
}

double Mediana(int n, int paz[]){
    sort(paz, paz + n); 
    if (n % 2 != 0)
        return paz[n/2];
    else
        return ((double)paz[n/2 - 1] + paz[n/2]) / 2;
}

void Isvedimas(int stud, int n, Stud A[]){
    char VidMed;
    cout << "Rodyti vidurki ar mediana? [V/M]: ";
    cin >> VidMed;

    while (toupper(VidMed) != 'V' && toupper(VidMed) != 'M'){
        cout << "Neteisinga ivestis!" << endl << "Rodyti vidurki ar mediana? [V/M]: ";
        cin >> VidMed;
    }

    if (toupper(VidMed) == 'V'){
        cout << "Pavarde     Vardas      Galutinis (Vid.)" << endl;
        cout << "---------------------------------------" << endl;
        for (int i=0; i<stud; i++)
            cout <<fixed<<left<<setw(12)<< A[i].pav <<setw(12)<< A[i].vard <<setprecision(2)<< Vidurkis(n, A[i].nd) << endl;
    }
    else {
        cout << "Pavarde     Vardas      Galutinis (Med.)" << endl;
        cout << "---------------------------------------" << endl;
        for (int i=0; i<stud; i++)
            cout <<fixed<<left<<setw(12)<< A[i].pav <<setw(12)<< A[i].vard <<setprecision(2)<< Mediana(n, A[i].nd) << endl;
    }
}

void IvestisYN(char& naujas, string tip){
    cout << "Ar prideti dar 1 " << tip << "? [Y/N]: ";
    cin >> naujas;
    while (toupper(naujas) != 'Y' && toupper(naujas) != 'N'){
        cout << "Neteisinga ivestis!" << endl << "Ar prideti dar 1 " << tip << "? [Y/N]: ";
        cin >> naujas;
    }
}

void IvestisSk(int stud, int n, Stud A[]){
    string laik;
    cout << stud+1 << " studento " << n+1 << " namu darbo ivertinimas [0-10]: ";
    cin >> laik;
    while (laik.length() != 1 || (laik.length() == 1 && (laik[0] - '0' < 0 || laik[0] - '0' > 10))){
        cout << "Neteisinga ivestis!" << endl << stud+1 << " studento " << n+1 << " namu darbo ivertinimas [0-10]: ";
        cin >> laik;
    }
    A[stud].nd[n] = laik[0] - '0';
}

void RandomPridejimas(int& n, int nd[]){
    nd[n] = (dist(mt));
    cout << "Pridetas " << nd[n] << endl;
    n++;
}