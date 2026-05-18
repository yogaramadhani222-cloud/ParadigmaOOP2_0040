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

class pelajar: virtual public orang{
    public:
    pelajar(int umur) :
    orang(umur)
    {
        cout << "pelajar dibuat\n: " << endl;
    }
};

class budi: public pekerja, public pelajar{
    public:
    budi(int pUmur) :
    pekerja(pUmur),
    pelajar(pUmur),
    orang(pUmur) //hal ini dapat dilakukan jika dengan menggunakan virtual
    {
        cout << "budi dibuat\n: " << endl;
    }
};