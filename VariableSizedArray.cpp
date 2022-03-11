#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, queries, sizeRow, cell, x, y;
    vector<vector<int>> c;
    cin >> n >> queries;
    for (int _ = 0; _ < n; _++){
        cin >> sizeRow;
        vector<int> row;
        for (int __ = 0; __ < sizeRow; __++){
            cin >> cell;
            row.push_back(cell);
        }
        c.push_back(row);
    }
    for (int _ = 0; _ < queries; _++){
        cin >> x >> y;
        cout << c[x][y] << endl;
    }
    return 0;
}
