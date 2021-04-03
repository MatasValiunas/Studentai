#include "header.hpp"

int main(){
    double Laik[4]{};

    char tip;
    cout << "Su kuo vykdyti programa? [V/L/D]:" << endl;
    cout << "Vektorius [V] / Listas [L] / Vektorius [D]: ";
    cin >> tip;

    while (toupper(tip) != 'V' && toupper(tip) != 'L' && toupper(tip) != 'D'){
        cout << "Neteisinga ivestis! [V/L/D]: ";
        cin >> tip;
    }

    fromMain(Laik, toupper(tip));
}