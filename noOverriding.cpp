#include <iostream>
using namespace std;

class baseClass {
    public:
    virtual void perkenalan() final
    {
        cout << "halo saya function dari base class" << endl;
    }
};
