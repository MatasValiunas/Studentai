#include "header.hpp"

random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(0, 10);

void fromMain(double Laik[], char tip){
    if (tip == 'V'){
        vector<Stud> A;
        vector<Stud> Minkst;
        vector<Stud> Kiet;
        Startas(A, Minkst, Kiet, Laik);
    }
    else if (tip == 'L'){
        list<Stud> A;
        list<Stud> Minkst;
        list<Stud> Kiet;
        Startas(A, Minkst, Kiet, Laik);
    }
    else {
        deque<Stud> A;
        deque<Stud> Minkst;
        deque<Stud> Kiet;
        Startas(A, Minkst, Kiet, Laik);
    }
}

template <typename T>
void Startas(T& A, T& Minkst, T& Kiet, double Laik[]){
    if (IvestisYN("generuotis duomenu faila"))
        Generavimas(Laik);
        
    if (IvestisYN("skaityti duomenis is tekstinio failo")){
        if (IvedimasIsFailo(A, Laik))
            Isvedimas(A, Minkst, Kiet, Laik);
    }
    else {
        IvedimasRanka(A);
        Isvedimas(A, Minkst, Kiet, Laik);
    }
}

template <typename T>
void IvedimasRanka(T& A){
    bool atsit = IvestisYN("generuoti balus atsitiktinai");
    int nd = 0;
    if (IvestisYN("zinomas namu darbu skaicius"))
        nd = (IvestisSk("Namu darbu skaicius: ", false));
    
    do {
        Stud laikinas;
        cout << A.size() << " studento pavarde: ";
        cin >> A.back().pav;
        cout << A.size() << " studento vardas: ";
        cin >> A.back().vard;
        if (!atsit){
            if (A.front().nd.size() == 0 && nd == 0){
                do {
                    A.back().nd.push_back(IvestisSk("Namu darbo ivertinimas"));
                } while (IvestisYN("prideti dar 1 namu darba"));
            }
            else {
                for (int i=0; i<(nd ? nd : A.front().nd.size()); i++)
                    A.back().nd.push_back(IvestisSk("Namu darbo ivertinimas"));
            }        
            A.back().egz = IvestisSk("Egzamino ivertinimas");
        }
        else {
            if (A.front().nd.size() == 0 && nd == 0){
                do {
                    A.back().nd.push_back(dist(mt));
                } while (IvestisYN("prideti dar 1 namu darba"));
            }
            else {
                for (int i=0; i<(nd? nd : A.front().nd.size()); i++)
                    A.back().nd.push_back(dist(mt));
            }
            A.back().egz = dist(mt);
        }
    } while (IvestisYN("prideti dar 1 studenta"));
}

template <typename T>
bool IvedimasIsFailo(T& A, double Laik[]){
    int failas;
    cout << "Failo skaicius, is kurio bus atliktas skaitymas [Studentai ... .txt]: ";
    while (!(cin >> failas) || failas < 1){
        cout << "Neteisinga ivestis!" << endl;
        cin.clear();
		cin.ignore(128, '\n');
    }

    auto start = system_clock::now();

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
            in >> A.back().vard >> A.back().pav;
            for (int i=0; i<nd; i++){
                in >> sk;
                A.back().nd.push_back(sk);
            }
            in >> A.back().egz;
            A.back().galut = round(0.4 * Vidurkis(A.back().nd) + 0.6 * A.back().egz);
        }
        in.close();
    }
    catch (exception ex){
        cout << "Ivyko klaida su failo skaitymu arba failas neegzistuoja!" << endl;
        return false;
    }

    auto end  = system_clock::now();
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

template <typename T>
void Isvedimas(T& A, T& Minkst, T& Kiet, double Laik[]){
    bool skirstymas2 = IvestisYN("skirstyti studentus i 2 atskirus konteinerius");
    if (skirstymas2)
        Rusiavimas(A, Kiet, Minkst, Laik);
    else
        Rusiavimas2(A, Minkst, Laik);

    auto start = system_clock::now();                   // Isvedimas

    ofstream outK("RezultataiKieti.txt");
    ofstream outM("RezultataiMinksti.txt");

    outK << "Pavarde                  Vardas             Galutinis (Vid.)" << endl;
    outM << "Pavarde                  Vardas             Galutinis (Vid.)" << endl;
    outK << "------------------------------------------------------------" << endl;
    outM << "------------------------------------------------------------" << endl;

    if (skirstymas2){
        for (auto elem : Kiet)
            outK <<fixed<<left<<setw(25)<< elem.vard <<setw(25)<< elem.pav << elem.galut << endl;
    }
    else {
        for (auto elem : A)
            outK <<fixed<<left<<setw(25)<< elem.vard <<setw(25)<< elem.pav << elem.galut << endl;
    }
    for (auto elem : Minkst)
        outM <<fixed<<left<<setw(25)<< elem.vard <<setw(25)<< elem.pav << elem.galut << endl;
    outK.close();
    outM.close();

    auto end = system_clock::now();
    duration<double> diff = end - start;
    Laik[3] = diff.count();

    cout << endl;
    if (Laik[0] != 0)
        cout << endl << "Duomenu generavimo ir irasymo i faila laikas: " << Laik[0] << " s" << endl;
    if (Laik[1] != 0)
        cout << "Duomenu skaitymo laikas: " << Laik[1] << " s" << endl;
    if (Laik[2] != 0)
        cout << "Studentu rusiavimo laikas: " << Laik[2] << " s" << endl;
    if (Laik[3] != 0)
        cout << "Isvedimo i failus laikas: " << Laik[3] << " s" << endl;
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

void Generavimas(double Laik[]){
    int stud, nd;
    stud = IvestisSk("Studentu skaicius: ", false);
    nd = IvestisSk("Namu darbu skaicius: ", false);

    auto start = system_clock::now();

    ofstream out("Studentai" + to_string(stud) + ".txt");
    out <<fixed<<setw(25)<<left<< "Vardas" <<setw(25)<< "Pavarde";
    for (int i=1; i<=nd; i++)
        out <<fixed<<setw(10)<<left<< "ND" + to_string(i);
    out << "Egz." << endl;

    for (int i=1; i<stud; i++){
        out <<fixed<<setw(25)<<left<< "Vardas" + to_string(i) <<setw(25)<< "Pavarde" + to_string(i);
        for (int i=0; i<nd; i++)
            out <<fixed<<setw(10)<<left<< dist(mt);
        out << dist(mt) << endl;
    }
    out <<fixed<<setw(25)<<left<< "Vardas" + to_string(stud) <<setw(25)<< "Pavarde" + to_string(stud);
    for (int i=0; i<nd; i++)
        out <<fixed<<setw(10)<<left<< dist(mt);
    out << dist(mt);
    out.close();

    auto end = system_clock::now();
    duration<double> diff = end - start;
    Laik[0] = diff.count();

    if (!IvestisYN("toliau testi programa"))
        exit(1);
}

template <typename T>
void Rusiavimas(T& A, T& Kiet, T& Minkst, double Laik[]){
    auto start = system_clock::now();     

    for (auto elem : A){
        //elem.galut = round(0.4 * Vidurkis(elem.nd) + 0.6 * elem.egz);
        if (elem.galut < 5)
            Minkst.push_back(elem);
        else
            Kiet.push_back(elem);
    }

    auto end = system_clock::now();
    duration<double> diff = end - start;
    Laik[2] = diff.count();       
}

bool MaziauUz5(Stud A){
    return (A.galut < 5);
}

template <typename T>
void Rusiavimas2(T& A, T& Minkst, double Laik[]){
    auto start = system_clock::now();     

    copy_if(A.begin(), A.end(), back_inserter(Minkst), MaziauUz5);
    remove_if(A.begin(), A.end(), MaziauUz5);

    auto end = system_clock::now();
    duration<double> diff = end - start;
    Laik[2] = diff.count();       
}