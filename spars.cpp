#include <iostream>
using namespace std;
#include "polinomATP.h"

//Napišite funkciju bool sparse(polinom p) koja uzima polinom p
// i vraća true ako je 50% ili više koeficijenata polinoma p jednako 0.

bool sparse(polinom djiga){
double brojac=0;
double brojacnula=0;
for(int i=0; i<Degree(djiga); i++){
    if(Coef(djiga, i)==0){
        brojacnula++;
        }
    brojac+=0.5;
    }
if(brojacnula>=brojac){ return true;
    }else return false;
}

int main(){
polinom a;
Zero(&a);
Attach(&a, 0, 5);
Attach(&a, 3, 1);
Attach(&a, 2, 0);
Attach(&a, 1, 0);
cout<<sparse(a);
return 0;
}