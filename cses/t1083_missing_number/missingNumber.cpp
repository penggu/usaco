#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _numsCount = 0;
int _res = 0;
vector<int> _numsList;

void ParseIn() {

    // ifstream fin("template.in");

    int solo = 0;
    cin >> _numsCount;

    for (int i = 0; i < _numsCount - 1; i++) {
        cin >> solo;
        // cout << solo << endl;
        _numsList.push_back(solo);
    }

}


void Core() {
    int tmp = 0;
    int solo = 0;

    for (int i = 0; i < _numsCount - 1; i++) {
        tmp ^= i + 1;
        tmp ^= _numsList[i];
        // cout << tmp << ',';

    }

    tmp ^= _numsCount;

    _res = tmp;
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
