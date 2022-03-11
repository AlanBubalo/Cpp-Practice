#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    int n = w.length();
    char charArray[n + 1];
    strcpy(charArray, w.c_str());
    int endIndex = 0;
    for (endIndex = n - 1; endIndex > 0; endIndex--)
        if (charArray[endIndex] > charArray[endIndex - 1]) break;
    if (endIndex == 0)
        return "no answer";
    char fsChar = charArray[endIndex - 1];
    int nsChar = endIndex;
    for (int startIndex = endIndex+1; startIndex < n; startIndex++)
        if (charArray[startIndex] > fsChar && charArray[startIndex] < charArray[nsChar])
            nsChar = startIndex;
    char temp = charArray[endIndex - 1];
    charArray[endIndex - 1] = charArray[nsChar];
    charArray[nsChar] = temp;
    // ----- Sorting
    for (int i = endIndex; i < n - 1; i++){
        int e = i;
        while (charArray[e] > charArray[e + 1]){
            temp = charArray[e];
            charArray[e] = charArray[e + 1];
            charArray[e + 1] = temp;
            e--;
            if (e == endIndex - 1) break;
        }
    }
    return string (charArray);
}

int main()
{
    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string y[T]={};
    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);
        string result = biggerIsGreater(w);
        y[T_itr]+=result;
    }
    for (int T_itr = 0; T_itr < T; T_itr++) {
        cout << y[T_itr] << "\n";
    }
    return 0;
}