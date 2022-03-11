#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // 1. Mean
    int n, brr = 1;
    cin >> n;
    double a[n];
    double sum;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    printf("%.1lf\n", sum / n);
    if (n % 2 == 0) printf("%.1lf", (a[(n / 2) - 1] + a[n / 2]) / 2);
    else cout << a[n/2] << endl;
    // 2. Median
    vector<int> br;
    vector<unsigned long long> bra;
    for (int i=1; i<n; i++){
        if (a[i] == a[i-1]) brr++;
        else {
            br.push_back(brr);
            bra.push_back(a[i - 1]);
            brr = 1;
        }
    }
    cout << endl;
    // 3. Mode
    br.push_back(brr);
    bra.push_back(a[n - 1]);
    int brSize = br.size(), braSize = bra.size();
    int c = 0;
    unsigned long long max = br[0];
    for (int i = 1; i < brSize; i++){
        if (max < br[i]){
            max = br[i];
            c = i;
        }
    }
    cout << bra[c];
    return 0;
}
