#include <bits/stdc++.h>
using namespace std;

unsigned long long result(string s, unsigned long long n){
    unsigned long long a;
    string str = "";
    int polje[100] = {}, e = 0;
    unsigned long long amount = 0, fullSize = 0;
    for (int i=0; i < s.size(); i++){
        if (s[i] == 'a'){
            polje[e] = i + 1;
            e++;
        }
    }
    if (n % s.size() == 0)
        amount = n / s.size();
    else
        amount = n / s.size() + 1;
    fullSize = amount * s.size();
    a = e * (amount - 1);
    fullSize -= n;
    fullSize = s.size() - fullSize;
    for (int i = 0; i < e; i++) if (fullSize >= polje[i]) a++;
    return a;
}

int main(){
    unsigned long long n;
    string s;
    cin >> s;
    cin >> n;
    cout << result(s, n);
    return 0;
}