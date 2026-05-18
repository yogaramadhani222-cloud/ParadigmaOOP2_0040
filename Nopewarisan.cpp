#include <iostream>
using namespace std;

class baseClass final{
    public:
    virtual void perkenalan()
    {
        cout << "halo saya dari base class" << endl;
    }
};

class baseClass1{
    public:
    virtual void perkenalan()
    {
        cout << "halo saya function dari base class" << endl;
    }
};