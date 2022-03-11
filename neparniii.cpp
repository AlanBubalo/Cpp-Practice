#include <iostream>
using namespace std;

int neparni(int a){
    if (a == 0)
        return 0;
    return a * (a % 2) + neparni(a - 1);
}

int main(){
    int a;
    cin >> a;
    cout << neparni(a);
    return 0;
}