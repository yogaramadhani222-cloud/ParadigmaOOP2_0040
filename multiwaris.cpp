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

 class pekerja: virtual public orang{
    public:
    pekerja(int umur) :
    orang(umur)
    {
        cout << "pekerja dibuat\n: " << endl;
    }
};
