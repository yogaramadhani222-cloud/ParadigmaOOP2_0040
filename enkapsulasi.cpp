#include <iostream>
using namespace std;

class remoteLampu{
private:
    string saklarNo[10];
public:
    void setSaklarNo(int i, string value){
        saklarNo[i] = value;
    }
    string getSaklarNo(int i){
        return saklarNo[i];
    }
};

int main()
{
    remoteLampu lampuRumah;
    lampuRumah.setSaklarNo(0, "Saklar 1");
    lampuRumah.setSaklarNo(1, "Saklar 2");
    lampuRumah.setSaklarNo(2, "Saklar 3");

    cout << lampuRumah.getSaklarNo(0) << endl;
    cout << lampuRumah.getSaklarNo(1) << endl;
    cout << lampuRumah.getSaklarNo(2) << endl;

    return 0;
}