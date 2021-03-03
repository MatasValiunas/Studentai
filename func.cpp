#include "header.hpp"

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(0, 10);

void IvedimasRanka(vector<Stud>& A){
    bool atsit = IvestisYN("generuoti balus atsitiktinai");
    int nd = 0;
    if (IvestisYN("zinomas namu darbu skaicius"))
        nd = (IvestisSk("Namu darbu skaicius: ", false));
    
    do {
        A.resize(A.size()+1);
        cout << A.size() << " studento pavarde: ";
        cin >> A[A.size()-1].pav;
        cout << A.size() << " studento vardas: ";
        cin >> A[A.size()-1].vard;
        if (!atsit){
            if (A[0].nd.size() == 0 && nd == 0){
                do {
                    A[A.size()-1].nd.push_back(IvestisSk("Namu darbo ivertinimas"));
                } while (IvestisYN("prideti dar 1 namu darba"));
            }
            else {
                for (int i=0; i<(nd? nd : A[0].nd.size()); i++)
                    A[A.size()-1].nd.push_back(IvestisSk("Namu darbo ivertinimas"));
            }        
            A[A.size()-1].egz = IvestisSk("Egzamino ivertinimas");
        }
        else {
            if (A[0].nd.size() == 0 && nd == 0){
                do {
                    RandomPridejimas(A[A.size()-1].nd);
                } while (IvestisYN("prideti dar 1 namu darba"));
            }
            else {
                for (int i=0; i<(nd? nd : A[0].nd.size()); i++)
                    RandomPridejimas(A[A.size()-1].nd);
            }
            A[A.size()-1].egz = dist(mt);
        }

    } while (IvestisYN("prideti dar 1 studenta"));
}

bool IvedimasIsFailo(vector<Stud>& A){
    int failas;
    cout << "Failas is kurio bus atliktas skaitymas [1-3]: ";
    while (!(cin >> failas) || failas < 1 || failas > 3){
        cout << "Neteisinga ivestis!" << endl << "Failas is kurio bus atliktas skaitymas [1-3]: ";
        cin.clear();
		cin.ignore(128, '\n');
    }
    string failoPav;
    if (failas == 1)
        failoPav = "Studentai10000.txt";  
    else if (failas == 2)
        failoPav = "Studentai100000.txt"; 
    else
        failoPav = "Studentai1000000.txt";

    try {
        ifstream in(failoPav);
        in.exceptions(ifstream::failbit | ifstream::badbit);
        int nd = -3;
        string tekst;
        while (tekst != "Egz."){
            in >> tekst;
            nd++;
        }
        int sk;
        while (!in.eof()){
            A.resize(A.size()+1);
            in >> A[A.size()-1].vard >> A[A.size()-1].pav;
            for (int i=0; i<nd; i++){
                in >> sk;
                A[A.size()-1].nd.push_back(sk);
            }
            in >> A[A.size()-1].egz;
        }
        in.close();
    }
    catch (exception ex){
        cout << "Ivyko klaida su failo skaitymu arba failas neegzistuoja!" << endl;
        return false;
    }
    return true;
}

double Vidurkis(vector<int>& paz){
    int sum = 0;
    for (int i=0; i<paz.size(); i++)
        sum += paz[i];
    return (double)sum / paz.size();
}

double Mediana(vector<int>& paz){
    int n = paz.size();
    sort(paz.begin(), paz.end());
    if (n % 2 != 0)
        return paz[n/2];
    else
        return ((double)paz[n/2 - 1] + paz[n/2]) / 2;
}

void Isvedimas(vector<Stud> A){
    ofstream out("Rezultatai.txt");
    char VidMed;
    cout << "Rodyti vidurki ar mediana? [V/M]: ";
    cin >> VidMed;
    sort(A.begin(), A.end());

    while (toupper(VidMed) != 'V' && toupper(VidMed) != 'M'){
        cout << "Neteisinga ivestis!" << endl << "Rodyti vidurki ar mediana? [V/M]: ";
        cin >> VidMed;
    }
    if (toupper(VidMed) == 'V'){
        out << "Pavarde        Vardas         Galutinis (Vid.)" << endl;
        out << "----------------------------------------------" << endl;
        for (int i=0; i<A.size(); i++)
            out <<fixed<<left<<setw(15)<< A[i].vard <<setw(15)<< A[i].pav <<setprecision(0)<< round(0.4 * Vidurkis(A[i].nd) + 0.6 * A[i].egz) << endl;
    }
    else {
        out << "Pavarde        Vardas         Galutinis (Med.)" << endl;
        out << "----------------------------------------------" << endl;
        for (int i=0; i<A.size(); i++)
            out <<fixed<<left<<setw(15)<< A[i].vard <<setw(15)<< A[i].pav <<setprecision(0)<< round(0.4 * Mediana(A[i].nd) + 0.6 * A[i].egz) << endl;
    }
    out.close();
}

bool IvestisYN(string tekstas){
    char naujas;
    cout << "Ar " << tekstas << "? [Y/N]: ";
    cin >> naujas;
    while (toupper(naujas) != 'Y' && toupper(naujas) != 'N'){
        cout << "Neteisinga ivestis! [Y/N]: ";
        cin >> naujas;
    }
    if (toupper(naujas) == 'Y')
        return true;
    else
        return false;
}

int IvestisSk(string tekstas, bool check0to10){
    int sk;
    cout<<  tekstas << (check0to10? " [0-10]: " : "");
    while (!(cin >> sk) || (check0to10? (sk < 0 || sk > 10) : false)){
        cout << "Neteisinga ivestis!" << endl << tekstas <<  (check0to10? " [0-10]: " : "");
        cin.clear();
		cin.ignore(128, '\n');
    }
    return sk;
}

void RandomPridejimas(vector<int>& nd){
    nd.push_back(dist(mt));
    cout << "Pridetas " << nd.back() << endl;
}