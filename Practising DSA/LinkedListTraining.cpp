#include <bits/stdc++.h>
using namespace std;
#include "LinkedList.h"

int main()
{
    LinkedList<int> list1;
    int n, element;

    cout << "Size of linked list: ";
    cin >> n;
    cout << "Elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        list1.insert(element);
    }

    cout << "List looks like this: \n";
    list1.print(" -> ");
    cout << "\n";

    cout << "The number in index 1 is: " << list1.getValue(1) << endl;

    list1.changeValue(7, 1);

    cout << "\nNow the number in index 1 is: " << list1.getValue(1) << endl;

    cout << "List looks like this: \n";
    list1.print(" -> ");
    cout << "\n";

    list1.swap(1, 3);
    cout << "\nSwapped index 1 and 3.\nList looks like this: \n";
    list1.print(" -> ");
    cout << "\n";

    list1.insert(9, 3);

    cout << "\nInserted number 9 at index 3!\nList looks like this: \n";
    list1.print(" -> ");
    cout << "\n";

    list1.sort();

    cout << "\nList looks like this: \n";
    list1.print(" -> ");
    cout << "\n";

    LinkedList<int> list2;
    int n2, element2;

    cout << "\nSize of another linked list: ";
    cin >> n2;
    cout << "Elements: \n";
    for (int i = 0; i < n2; i++)
    {
        cin >> element2;
        list2.insert(element2);
    }

    cout << "\nList looks like this: \n";
    list2.print(" -> ");
    cout << "\n";

    if (list1 == list2)
        cout << "Lists are the same!\n";
    else
        cout << "Lists are different!\n";
    return 0;
}