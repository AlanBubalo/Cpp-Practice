#include <iostream>
using namespace std;

int suma(int f, int* g){
    *g = 8;
    int a = 1;
    return f + *g + a;
}

int main(){
    int a = 7;
    cout << suma(5, &a) << " ";
    cout << a;
    return 0;
}