#include "header.hpp"

int main(){
    vector<Stud> A;
    double Laik[3]{};

    if (IvestisYN("generuotis duomenu faila"))
        Generavimas(Laik);
        
    if (IvestisYN("skaityti duomenis is tekstinio failo")){
        if (IvedimasIsFailo(A, Laik))
            Isvedimas(A, Laik);
    }
    else {
        IvedimasRanka(A);
        Isvedimas(A, Laik);
    }
}