

#include <iostream>

using namespace std;

int _myInt = 0;

void ParseIn() {
    cin >> _myInt;
}

void Core() {

    if (_myInt < 4 && _myInt != 1) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    // output even
    for (int i = 2; i <= _myInt; i += 2) {
        cout << i << " ";
    }

    // output odd
    for (int i = 1; i <= _myInt; i += 2) {
        cout << i << " ";
    }

    cout << endl;

}

void Core2() {
    int a = 0;
    int b = 0;

    if (_myInt < 4 && _myInt != 1) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    if (_myInt % 2 == 0) {
        a = _myInt - 1;
        b = _myInt;
    } else {
        a = _myInt;
        b = _myInt - 1;
    }

    // output odd
    for (int i = a; i > 0; i -= 2) {
        cout << i << " ";
    }

    // output even
    for (int i = b; i > 0; i -= 2) {
        cout << i << " ";
    }

    cout << endl;

}

void CWriteOut() {
    // output is in Core
}

int main() {
    ParseIn();
    Core2();
    CWriteOut();

    return 0;
}

/*

PROGRAM=permutations && /usr/bin/g++ -std=c++11 -O2 -Wall -fdiagnostics-color=always ./$PROGRAM.cpp -o ./a.out && ./a.out && cat $PROGRAM.out && rm ./a.out $PROGRAM.out

*/