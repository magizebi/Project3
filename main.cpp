#include <iostream>
#include "SimpleVector.h"

using namespace std;

int main()
{
    SimpleVector<int> a;
    a.push_back(33);
    a.push_back(11);
    a.push_back(22);
    a.pop_back();
    a.push_back(5);
    a.sortData();
    SimpleVector<int> b(a);
    SimpleVector<char> c;
    c.push_back('o');
    c.push_back('w');
    c.push_back('o');
    try {
        for (int i = 0; i < b.capacity(); i++) {
            cout << b[i] << endl;
        }
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    
    for (int i = 0; i < c.size(); i++) {
        cout << c[i];
    }

}