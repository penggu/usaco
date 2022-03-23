#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string _myStr;
int _res = 0;

void DisplayList(vector<int> theList) {
    for (auto element: theList) {
        cout << element << ", ";
    }
    
    cout << endl;
}


void ParseIn() {
    cin >> _myStr;
}


void Core() {
    char prevChar = '&';
    char currChar = '#';
    int count = 0;
    int maxCount = 0;

    for (size_t i = 0; i < _myStr.length(); i++) {
        currChar = _myStr[i];
        if (currChar == prevChar) {
            count++;
        } else {
            prevChar = currChar;
            count = 1;
        }
        if (count > maxCount) {
            maxCount = count;
        }
    }

    _res = maxCount;
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

PROGRAM=repetitions && /usr/bin/g++ -std=c++11 -O2 -Wall -fdiagnostics-color=always ./$PROGRAM.cpp -o ./a.out && ./a.out && cat $PROGRAM.out && rm ./a.out $PROGRAM.out

*/
