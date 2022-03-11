#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int fact(int n){
    if (n <= 1)
        return 1;
    return (n * fact(n - 1));
}

float b(int x, int n, float p){
    return (fact(n) / (fact(x) * fact(n - x)) * pow(p, x) * pow(1 - p, n - x));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    float m, f;
    scanf("%f %f", &m, &f);
    float p = m / (m + f), result = 0;
    for (int x = 3; x <= 6; x++){
        result += b(x, 6, p);
    }
    printf("%.3f", result);
    return 0;
}
