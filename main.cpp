#include "header.hpp"

int main(){
    vector<Stud> A;

    if (IvestisYN("skaityti duomenis is tekstinio failo"))
        IvedimasIsFailo(A);
    else
        IvedimasRanka(A);
    Isvedimas(A);
}