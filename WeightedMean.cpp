#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    float sum = 0, sumW = 0;
    cin >> n;
    int x[n], w[n];
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++){
        sum += x[i]*w[i];
        sumW += w[i];
    }
    printf("%.1f", sum/sumW);
    return 0;
}
