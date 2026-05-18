#include <iostream>
using namespace std;

class orang{
    public:
    int umur;
    orang(int umur) :
        umur(umur)
        {
            cout << "orang dibuat dengan umur: " << umur << endl;
        }
};