#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the toys function below.
int toys(vector<int> w) {
    int n = w.size(), m = 0, temp = 0, cont = 0;
    sort(w.begin(), w.end());
    m = 0;
    for (int i = 1; i < n; i++){
        if ((w[i] - w[m]) > 4){
            m = i;
            cont++;
        }
    }
    return cont;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string w_temp_temp;
    getline(cin, w_temp_temp);

    vector<string> w_temp = split_string(w_temp_temp);

    vector<int> w(n);

    for (int i = 0; i < n; i++) {
        int w_item = stoi(w_temp[i]);

        w[i] = w_item;
    }

    //int result = toys(w);
    int /*n=w.size(), */m=0, temp=0, dif=4;
    int cont=1;
    int smallest=w[0], biggest=w[1];
    for (int i=1; i<=cont; i++){
        for (int j=0; j<n; j++){
            smallest=(w[j]<smallest)?w[j]:smallest;
            biggest=(w[j]>biggest)?w[j]:biggest;
            dif=biggest-smallest;
            if (dif>=5){
                cont=i+1;
            }
        }
    }
    cout << cont << endl;
    //return cont;
    //fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}