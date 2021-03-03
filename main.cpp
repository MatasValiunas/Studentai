#include "header.hpp"

int main(){
    vector<Stud> A;

    if (IvestisYN("skaityti duomenis is tekstinio failo")){
        if (IvedimasIsFailo(A))
            Isvedimas(A);
    }
    else{
        IvedimasRanka(A);
        Isvedimas(A);
    }
}