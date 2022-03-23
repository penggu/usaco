/*
https://cses.fi/problemset/task/1084

Time limit: 1.00 s Memory limit: 512 MB
There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.

Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.

Input

The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum allowed difference.

The next line contains n integers a1,a2,…,an: the desired apartment size of each applicant. If the desired size of an applicant is x, he or she will accept any apartment whose size is between x−k and x+k.

The last line contains m integers b1,b2,…,bm: the size of each apartment.

Output

Print one integer: the number of applicants who will get an apartment.

Constraints
1≤n,m≤2⋅10^5
0≤k≤10^9
1≤ai,bi≤10^9
Example

Input:
4 3 5
60 45 80 60
30 60 75

Output:
2
*/

// #define __USACO__

#ifdef __USACO__
#define __USE_FSTREAM__
#endif


#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int _tenantCount = 0;
int _housesCount = 0;
int _tolerance = 0;
vector<int> _tenantsList;
vector<int> _housesList;

int _res = 0;

void DisplayList(vector<int> theList) {
    for (auto element: theList) {
        cout << element << ", ";
    }
    
    cout << endl;
}


void ParseIn() {
#ifdef __USE_FSTREAM__
    ifstream cin("apartments.in");
#endif

    int solo = 0;

    cin >> _tenantCount >> _housesCount >> _tolerance;
    // cout << "_tenantCoutn->" << _tenantCount << ", "
    //     << "_housesCount->" << _housesCount << ", "
    //     << "_tolerance->" << _tolerance 
    //     << endl;

    for (int i = 0; i < _tenantCount; i++) {
        cin >> solo;
        _tenantsList.push_back(solo);
    }

    for (int i = 0; i < _housesCount; i++) {
        cin >> solo;
        _housesList.push_back(solo);
    }

#ifdef __USE_FSTREAM__
    cin.close();
#endif
    
    // DisplayList(_tenantsList);
    // DisplayList(_housesList);

}


void Core() {
    multiset<int> tenantsSet;
    multiset<int> housesSet;
    int error = _tolerance;
    int ans = 0;

    for (auto element: _tenantsList) {
        tenantsSet.insert(element);
    }

    for (auto element: _housesList) {
        housesSet.insert(element);
    }

    auto tIt = tenantsSet.begin();
    auto hIt = housesSet.begin();

    while (tIt != tenantsSet.end() and hIt != housesSet.end()) {
        if (*tIt - error <= *hIt && *hIt <= *tIt + error) {
            ans++;
            tIt++;
            hIt++;
        } else if (*tIt < *hIt) {
            tIt++;
        } else {
            hIt++;
        }
    }

    _res = ans;
}


void CWriteOut() {
#ifdef __USE_FSTREAM__
    ofstream outFile("apartments.out");
    outFile << _res << endl;
    outFile.close();
#else
    cout << _res << endl;
#endif
}


int main() {
    ParseIn();
    Core();
    CWriteOut();

    return 0;
}

/*
To run it in command line:
PROGRAM=apartments && /usr/bin/g++ -fdiagnostics-color=always --std=c++17 ./$PROGRAM.cpp -o ./a.out && ./a.out && rm ./a.out $PROGRAM.out
*/
