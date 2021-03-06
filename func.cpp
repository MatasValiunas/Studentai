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

bool IvedimasIsFailo(vector<Stud>& A, double Laik[]){
    auto start = high_resolution_clock::now();

    int failas;
    cout << "Failo skaicius, is kurio bus atliktas skaitymas [Studentai ... .txt]: ";
    while (!(cin >> failas) || failas < 1){
        cout << "Neteisinga ivestis!" << endl;
        cin.clear();
		cin.ignore(128, '\n');
    }

    try {
        ifstream in("Studentai" + to_string(failas) + ".txt");
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

    auto end  = high_resolution_clock::now();
    duration<double> diff = end - start;
    Laik[1] = diff.count();

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

void Isvedimas(vector<Stud> A, double Laik[]){
    auto start = high_resolution_clock::now();

    ofstream out("Rezultatai.txt");
    char VidMed;
    cout << "Rodyti vidurki ar mediana? [V/M]: ";
    cin >> VidMed;
    sort(A.begin(), A.end());

    while (toupper(VidMed) != 'V' && toupper(VidMed) != 'M'){
        cout << "Neteisinga ivestis!" << endl << "Rodyti vidurki ar mediana? [V/M]: ";
        cin >> VidMed;
    }
    ofstream outK("RezultataiKieti.txt");
    ofstream outM("RezultataiMinksti.txt");
    if (toupper(VidMed) == 'V'){
        outK << "Pavarde                  Vardas             Galutinis (Vid.)" << endl;
        outK << "------------------------------------------------------------" << endl;
        outM << "Pavarde                  Vardas             Galutinis (Vid.)" << endl;
        outM << "------------------------------------------------------------" << endl;
        for (int i=0; i<A.size(); i++){
            if (round(0.4 * Vidurkis(A[i].nd) + 0.6 * A[i].egz) >= 5)
                outK <<fixed<<left<<setw(25)<< A[i].vard <<setw(25)<< A[i].pav <<setprecision(0)<< round(0.4 * Vidurkis(A[i].nd) + 0.6 * A[i].egz) << endl;
            else
                outM <<fixed<<left<<setw(25)<< A[i].vard <<setw(25)<< A[i].pav <<setprecision(0)<< round(0.4 * Vidurkis(A[i].nd) + 0.6 * A[i].egz) << endl;
        }
    }
    else {
        outK << "Pavarde                  Vardas             Galutinis (Med.)" << endl;
        outK << "------------------------------------------------------------" << endl;
        outM << "Pavarde                  Vardas             Galutinis (Med.)" << endl;
        outM << "------------------------------------------------------------" << endl;
        for (int i=0; i<A.size(); i++){
            if (round(0.4 * Mediana(A[i].nd) + 0.6 * A[i].egz) >= 5)
                outK <<fixed<<left<<setw(25)<< A[i].vard <<setw(25)<< A[i].pav <<setprecision(0)<< round(0.4 * Mediana(A[i].nd) + 0.6 * A[i].egz) << endl;
            else
                outM <<fixed<<left<<setw(25)<< A[i].vard <<setw(25)<< A[i].pav <<setprecision(0)<< round(0.4 * Mediana(A[i].nd) + 0.6 * A[i].egz) << endl;
        }
    }
    out.close();

    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    Laik[2] = diff.count();

    cout << endl << "Duomenu kurimo laikas: " << Laik[0] << " s" << endl;
    cout << "Duomenu skaitymo laikas: " << Laik[1] << " s" << endl;
    cout << "Studentu rusiavimo ir isvedimo laikas: " << Laik[2] << " s" << endl;
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

void Generavimas(double Laik[]){
    int stud, nd;
    cout << "Studentu skaicius: ";
    cin >> stud;
    cout << "Namu darbu skaicius: ";
    cin >> nd;

    auto start = high_resolution_clock::now();

    ofstream out("Studentai" + to_string(stud) + ".txt");
    out <<fixed<<setw(25)<<left<< "Vardas" <<setw(25)<< "Pavarde";
    for (int i=1; i<=nd; i++)
        out <<fixed<<setw(10)<<left<< "ND" + to_string(i);
    out << "Egz." << endl;

    for (int i=1; i<=stud; i++){
        out <<fixed<<setw(25)<<left<< "Vardas" + to_string(i) <<setw(25)<< "Pavarde" + to_string(i);
        for (int i=0; i<nd; i++)
            out <<fixed<<setw(10)<<left<< dist(mt);
        out << dist(mt);
        if (i != stud)
            out << endl;
    }
    out.close();

    auto end = high_resolution_clock::now();
    duration<double> diff = end - start;
    Laik[0] = diff.count();

    if (!IvestisYN("toliau testi programa"))
        exit(1);
}