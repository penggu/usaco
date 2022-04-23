#include <iostream>
#include <cstdio>
#include <utility>
#include <set>
#include <vector>

using namespace std;

int N_ROWS = 8;      // number of rows on the board
int N_COLS = N_ROWS; // number of columns on the board
char BLOCKER = '*';
set<pair<int, int> > _blockerSet;
vector<vector<int> > _ansList;
int _res = -1;

void DisplayList(vector<int> theList)
{
    for (auto solo : theList)
    {
        cout << solo << " ";
    }

    cout << endl;
}

void DisplayBlockers(set<pair<int, int> > blockers)
{
    for (auto b : blockers)
    {
        cout << b.first << "," << b.second << endl;
    }
}

void ParseIn()
{
    char piece = '&';
    for (int i = 0; i < N_ROWS; i++)
    {
        for (int j = 0; j < N_COLS; j++)
        {
            cin >> piece;
            // cout << piece; // DBG only

            if (BLOCKER == piece)
            {
                _blockerSet.insert(make_pair(i, j));
            }
        }
        // cout << endl;  // DBG only
    }
    // DisplayBlockers(_blockerSet); // DBG only
}

bool IsValidBoard(vector<int> board)
{
    // Empty board is always valid
    if (board.size() == 0) {
        return true;
    }

    // The lastly placed piece shall not attack existing pieces.
    int last_row = board.size() - 1;
    int last_col = board[last_row];
    int j = -1;
    for (int i = 0; i < last_row; i++)
    {
        /* make sure attacking does not happen on column and both diagnal lines.
            For example: if last piece * is placed on (3, 2)
            .o.o....
            ooo.....
            o*oooooo
            ooo.....
            .o.o....
            .o..o...
            .o...o..
            .o....o.
         */
        j = board[i];
        if (j == last_col ||                // same column attack
            i + j == last_row + last_col || // same slash attack
            i - j == last_row - last_col)   // same backslash attack
        {
            return false;
        }
    }

    // Make sure all places are not blocked
    for (auto piece : _blockerSet)
    {
        if (piece.first < int(board.size()) && board[piece.first] == piece.second)
        {
            return false;
        }
    }

    return true;
}

void NQueens0(int N, vector<int> ans)
{
    // DisplayList(ans); // DBG only
    if (!IsValidBoard(ans))
    {
        return;
    }

    if (N == int(ans.size()))
    {
        // DisplayList(ans); // DBG only
        _ansList.push_back(ans);
        return;
    }

    for (int col = 0; col < N_COLS; col++)
    {
        ans.push_back(col);
        NQueens0(N, ans);
        ans.pop_back();
    }
}

void Core()
{
    vector<int> ans;
    NQueens0(N_ROWS, ans);
    // _res = _ansList.size()
}

void CWriteOut()
{
    cout << _ansList.size() << endl;
}

int main()
{
    // freopen("nQueens.in", "r", stdin);
    // freopen("nQueens.out", "w", stdout);

    ParseIn();
    Core();
    CWriteOut();

    return 0;
}
