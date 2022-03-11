#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int steps;
string path;

int countingValleys (int steps, string path){
    int valley=0, level=0, mount=0;
    for (int i=0; i<steps; i++){
        if (path[i]=='U'){
            level++;
        }
        else if (path[i]=='D'){
            level--;
            if (level==-1){
                valley++;
            }
        }
    }
    return (valley);
}

int main (){
    cin >> steps >> path;
    cout << countingValleys (steps, path);
    return 0;
}