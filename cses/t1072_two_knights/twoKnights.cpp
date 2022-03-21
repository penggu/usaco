#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _sideLength = 0;
vector<long long int> _resList;

void DisplayList(vector<long long int> myList) {
    for (auto solo: myList) {
        cout << solo << endl;
    }
}


void ParseIn() {
    cin >> _sideLength;
}


void Core() {
    long long int n = 0;
    long long int ans = 0;
    for (int i = 0; i < _sideLength; i++) {
        n = i + 1;
        ans = (n * n) * (n * n - 1) / 2 - (n - 1) * (n - 2) * 4;
        _resList.push_back(ans);
    }
}


void CWriteOut() {
    DisplayList(_resList);
}


int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}

/*
To run it in command line:
PROGRAM=two_knights && /usr/bin/g++ -fdiagnostics-color=always --std=c++17 ./$PROGRAM.cpp -o ./a.out && ./a.out && rm ./a.out
*/
