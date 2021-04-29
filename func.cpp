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

    if (IvedimasIsFailo(A, Laik))
        Isvedimas(A, Minkst, Kiet, Laik);
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
        string vard, pav;
        while (!in.eof()){
            vector<int> ndV;
            A.resize(A.size()+1);
            in >> vard >> pav;
            A.back().setVard(vard, pav);
            for (int i=0; i<nd; i++){
                in >> sk;
                ndV.push_back(sk);
            }
            in >> sk;
            A.back().setGalut(round(0.4 * Vidurkis(ndV) + 0.6 * sk));
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
    int sk;
    cout <<  "Ar skirstyti studentus i 2 naujus konteinerius [1], ar sukurti tik 1 nauja konteineri minkstiems studentams [2]?: ";
    while (!(cin >> sk) || sk < 1 || sk > 2){
        cout << "Neteisinga ivestis!" << endl << "Ar skirstyti studentus i 2 naujus konteinerius [1], ar sukurti tik 1 nauja konteineri minkstiems studentams [2]?: ";
        cin.clear();
		cin.ignore(128, '\n');
    }
    if (sk == 1)
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

    if (sk == 1){
        for (auto elem : Kiet)
            outK <<fixed<<left<<setw(25)<< elem.getVard() <<setw(25)<< elem.getPav() << elem.getGalut() << endl;
    }
    else {
        for (auto elem : A)
            outK <<fixed<<left<<setw(25)<< elem.getVard() <<setw(25)<< elem.getPav() << elem.getGalut() << endl;
    }
    for (auto elem : Minkst)
        outM <<fixed<<left<<setw(25)<< elem.getVard() <<setw(25)<< elem.getPav() << elem.getGalut() << endl;
    outK.close();
    outM.close();

    auto end = system_clock::now();
    duration<double> diff = end - start;
    Laik[3] = diff.count();

    double laikas = 0;
    cout << endl;
    if (Laik[0] != 0){
        laikas += Laik[0];
        cout << endl << "Duomenu generavimo ir irasymo i faila laikas: " << Laik[0] << " s" << endl;
    }
    if (Laik[1] != 0){
        laikas += Laik[1];
        cout << "Duomenu skaitymo laikas: " << Laik[1] << " s" << endl;
    }
    if (Laik[2] != 0){
        laikas += Laik[2];
        cout << "Studentu rusiavimo laikas: " << Laik[2] << " s" << endl;
    }
    if (Laik[3] != 0){
        laikas += Laik[3];
        cout << "Isvedimo i failus laikas: " << Laik[3] << " s" << endl;
    }
    cout << "Bendras laikas: " << laikas << " s" <<  endl;
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
        if (elem.getGalut() < 5)
            Minkst.push_back(elem);
        else
            Kiet.push_back(elem);
    }

    auto end = system_clock::now();
    duration<double> diff = end - start;
    Laik[2] = diff.count();       
}

bool MaziauUz5(Stud A){
    return (A.getGalut() < 5);
}

template <typename T>
void Rusiavimas2(T& A, T& Minkst, double Laik[]){
    auto start = system_clock::now();     

    copy_if(A.begin(), A.end(), back_inserter(Minkst), MaziauUz5);
    A.erase(remove_if(A.begin(), A.end(), MaziauUz5), A.end());

    auto end = system_clock::now();
    duration<double> diff = end - start;
    Laik[2] = diff.count();       
}