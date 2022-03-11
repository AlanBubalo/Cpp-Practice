#include <iostream>
using namespace std;

int n, out = 0, d = 1, e, ar[100], b;

void sockMerchant(int n, int *ar)
{
    int out = 0, d = 1, e, b;
    for (int i = 1; i < n; i++){
        e = i;
        while (ar[e] < ar[e - 1]){
            b = ar[e - 1];
            ar[e - 1] = ar[e];
            ar[e] = b;
            e--;
            if (e == 0) break;
        }
    }
    b = ar[0];
    for (int i = 1; i < n; i++){
        if (b == ar[i]){
            d++;
            b = ar[i];
            continue;
        }
        out += d / 2;
        d = 1;
        b = ar[i];
    }
    out += d/2;
    cout << out;
}

int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++) cin >> ar[i];
    sockMerchant(n, ar);
    return 0;
}
