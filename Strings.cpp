#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, size;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++){
        size = s[i].size();
        for (int j = 0; j < size; j++){
            if (!(j % 2)) cout << s[i][j];
        }
        cout << " ";
        for (int j = 0; j < size; j++){
            if (j % 2) cout << s[i][j];
        }
        cout << endl;
    }
    return 0;
}
