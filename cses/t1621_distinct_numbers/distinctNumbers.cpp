#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <map>

using namespace std;

int _numsCount = 0;
int _res = 0;
vector<int> _numsList;

void ParseIn() {

    // ifstream fin("template.in");

    int solo = 0;
    cin >> _numsCount;

    for (int i = 0; i < _numsCount; i++) {
        cin >> solo;
        _numsList.push_back(solo);
    }

}


void Core() {
    unordered_set<int> numSet;

    for (auto element: _numsList) {
        numSet.insert(element);
    }

    _res = numSet.size();
}


void CWriteOut() {
    // ofstream fout("template.out");
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
PROGRAM=distinct && /usr/bin/g++ -fdiagnostics-color=always --std=c++17 ./$PROGRAM.cpp -o ./a.out && ./a.out && rm ./a.out
*/