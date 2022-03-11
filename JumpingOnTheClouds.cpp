#include <iostream>

using namespace std;

int n, c[100];

int jumpingOnClouds(int n, int *c){
    int moves = 0;
    for (int i = 1; i < n; i++){
        if (c[i] == 1){
            moves++;
            continue;
        }
        if (c[i - 1] == 1) moves++;
    }
    return moves;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }
    int moves = 0;
    int step = 0;
    for (int i = 1; i < n; i++){
        if (c[i] == 0){
            step++;
            if (step == 1){
                moves++;
                continue;
            }
            if (step == 2){
                step = 0;
            }
            continue;
        }
        moves++;
        step = 0;
        i++;
    }
    cout << moves;
    //cout << jumpingOnClouds(n, c);
    return 0;
}