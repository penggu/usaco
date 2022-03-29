

#include <iostream>
#include <vector>

using namespace std;

int _myInt = 0;
int _res = 0;


void ParseIn() {
    cin >> _myInt;
}

int Power(int n) {
    int MOD = 1000000000 + 7;

    int index = 0;
    int power = 1;
    long long int powpow = 2;
    vector<int> powerList;
    vector<long long int> powpowList;

    powerList.push_back(power);
    powpowList.push_back(powpow);

    int n_ = n;
    while (n_ > 1) {
        n_ /= 2;
        index ++;
        power *= 2;
        powpow = (powpow * powpow) % MOD;
        powerList.push_back(power);
        powpowList.push_back(powpow);
    }

    long long int ans = 1;
    while (index >= 0) {
        if (n >= powerList[index]) {
            n -= powerList[index];
            ans = (ans * powpowList[index]) % MOD;
        }
        index --;
    }

    return ans;
}

void Core() {
    _res = Power(_myInt);
}

void CWriteOut() {
    cout << _res << endl;
}

int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}