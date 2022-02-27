
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include "VectorTemplates.h"

using namespace std;
int rnd();

int main()
{
    setlocale(LC_ALL, "ru");
    vector<int> myVec;

    int num;
    cin >> num;
    while (num != 0)
    {
        myVec.push_back(num);
        cout << "size = " << myVec.size() << "cap = " << myVec.capacity() << endl;
        cin >> num;
    }
    cout << endl;
    cout << "Source array: " << endl;
    PrintVector(myVec);
    cout << "Free space for numbers - " << myVec.capacity() - myVec.size() << endl;
    reverse(myVec.begin(), myVec.end());
    cout << "Reverse array: " << endl;
    PrintVector(myVec);
    return 0;
}

int rnd() {
    return rand() % 6 + 1;
}