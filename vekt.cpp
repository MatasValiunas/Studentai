#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <random>

using namespace std;

struct Stud{
    string vard, pav;
    vector<int> nd;
};

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(0, 10);

void Ivedimas(int& stud, Stud A[]);
double Vidurkis(int n, vector<int>& paz);
double Mediana(int n, vector<int>& paz);
void Isvedimas(int stud, Stud A[]);
bool IvestisYN(string tip);
void IvestisSk(int stud, vector<int>& nd);
void RandomPridejimas(vector<int>& nd);


int main(){
    int stud = 0;
    Stud A[100];

    Ivedimas(stud, A);
    Isvedimas(stud, A);
}

void Ivedimas(int& stud, Stud A[]){
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
    
    do {
        cout << stud+1 << " studento pavarde: ";
        cin >> A[stud].pav;
        cout << stud+1 << " studento vardas: ";
        cin >> A[stud].vard;
        if (!atsit){
            if (A[0].nd.size() == 0){
                IvestisSk(stud, A[stud].nd);
                while (IvestisYN("namu darba"))
                    IvestisSk(stud, A[stud].nd);
            }
            else {
                for (int i=0; i<A[0].nd.size(); i++)
                    IvestisSk(stud, A[stud].nd);
            }
        }
        else {
            if (A[0].nd.size() == 0){
                RandomPridejimas(A[stud].nd); 
                while (IvestisYN("namu darba"))
                    RandomPridejimas(A[stud].nd);
            }
            else {
                for (int i=0; i<A[0].nd.size(); i++)
                    RandomPridejimas(A[stud].nd);
            }
        }
        stud++;
    } while (IvestisYN("studenta"));
}

double Vidurkis(int n, vector<int>& paz){
    int sum = 0;
    for (int i=0; i<n; i++)
        sum += paz[i];
    return (double)sum / n;
}

double Mediana(int n, vector<int>& paz){
    sort(paz.begin(), paz.end());
    if (n % 2 != 0)
        return paz[n/2];
    else
        return ((double)paz[n/2 - 1] + paz[n/2]) / 2;
}

void Isvedimas(int stud, Stud A[]){
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
            cout <<fixed<<left<<setw(12)<< A[i].pav <<setw(12)<< A[i].vard <<setprecision(2)<< Vidurkis(A[i].nd.size(), A[i].nd) << endl;
    }
    else {
        cout << "Pavarde     Vardas      Galutinis (Med.)" << endl;
        cout << "---------------------------------------" << endl;
        for (int i=0; i<stud; i++)
            cout <<fixed<<left<<setw(12)<< A[i].pav <<setw(12)<< A[i].vard <<setprecision(2)<< Mediana(A[i].nd.size(), A[i].nd) << endl;
    }
}

bool IvestisYN(string tip){
    char naujas;
    cout << "Ar prideti dar 1 " << tip << "? [Y/N]: ";
    cin >> naujas;
    while (toupper(naujas) != 'Y' && toupper(naujas) != 'N'){
        cout << "Neteisinga ivestis!" << endl << "Ar prideti dar 1 " << tip << "? [Y/N]: ";
        cin >> naujas;
    }
    if (toupper(naujas) == 'Y')
        return true;
    else
        return false;
}

void IvestisSk(int stud, vector<int>& nd){
    string laik;
    cout << stud+1 << " studento " << nd.size() + 1 << " namu darbo ivertinimas [0-10]: ";
    cin >> laik;
    while (laik.length() != 1 || (laik.length() == 1 && (laik[0] - '0' < 0 || laik[0] - '0' > 10))){
        cout << "Neteisinga ivestis!" << endl << stud+1 << " studento " << nd.size() + 1 << " namu darbo ivertinimas [0-10]: ";
        cin >> laik;
    }
    nd.push_back(laik[0] - '0');
}

void RandomPridejimas(vector<int>& nd){
    nd.push_back(dist(mt));
    cout << "Pridetas " << nd.back() << endl;
}