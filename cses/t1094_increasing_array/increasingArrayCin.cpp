#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> _numList;
long long int _res = 0;

void DisplayList(vector<int> theList) {
    for (auto element: theList) {
        cout << element << ", ";
    }

    cout << endl;
}


void ParseIn() {

    int maxi = 0;
    int solo = 0;


    cin >> maxi;

    for (int i = 0; i < maxi; i++) {
        cin >> solo;
        _numList.push_back(solo);
    }
}


void Core() {
    long long int ans = 0;
    int curr = _numList[0];

    for (size_t i = 1; i < _numList.size(); i++) {
        if (curr > _numList[i]) {
            ans += curr - _numList[i];
        } else {
            curr = _numList[i];
        }
    }

    _res = ans;
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

/*
To run it in command line:

PROGRAM=increasingArray && /usr/bin/g++ -std=c++11 -O2 -Wall -fdiagnostics-color=always ./$PROGRAM.cpp -o ./a.out && ./a.out && cat $PROGRAM.out && rm ./a.out $PROGRAM.out

*/
