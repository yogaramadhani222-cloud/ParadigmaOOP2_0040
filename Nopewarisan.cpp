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

class derivedClass : public baseClass1{
    public:
    void perkenalan()
    {
        cout << "halo saya function dari derived class" << endl;
    }
};

int main(){
    derivedClass a;
    a.perkenalan();

    return 0;
}