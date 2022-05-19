#include <iostream>
#include <cstdio>
#include <utility>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int _nTickets = 0;
int _mCustomers = 0;
vector<int> _ticketPrices;
vector<int> _offerPrices;
vector<int> _resList;

void DisplayList(vector<int> theList)
{
    for (auto solo : theList)
    {
        cout << solo << endl;
    }
}

void ParseIn() {
    int solo;
    cin >> _nTickets;
    cin >> _mCustomers;

    for (int i = 0; i < _nTickets; i++) {
        cin >> solo;
        _ticketPrices.push_back(solo);
    }
        
    for (int i = 0; i < _mCustomers; i++) {
        cin >> solo;
        _offerPrices.push_back(solo);
    }
}

void Core()
{
    vector<int>::iterator it;
    sort(_ticketPrices.begin(), _ticketPrices.end());

    for (auto offer: _offerPrices) {
        if (_ticketPrices.size() == 0) {
            _resList.push_back(-1);
            continue;
        }

        it = lower_bound (_ticketPrices.begin(),
                      _ticketPrices.end(),
                      offer
                      );

        if ((*it) == offer) {
            _resList.push_back(offer);
            _ticketPrices.erase(it);
            continue;
        }

        if (it != _ticketPrices.begin()) {
            _resList.push_back(*(it - 1));
            _ticketPrices.erase(it - 1);
            continue;
        }

        _resList.push_back(-1);
    }

}

void CWriteOut()
{
    DisplayList(_resList);
}

int main()
{
    // freopen("concertTickets.in", "r", stdin);
    // freopen("concertTickets.out", "w", stdout);

    ParseIn();
    Core();
    CWriteOut();

    return 0;
}
