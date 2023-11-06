#include <iostream>
#include <iomanip>
#include <sstream>
#include <list>
#include <utility>
#include <string>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstring>
// #include <cstdlib>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    vector<vector<int>> A(9, vector<int>(9));

    rep(i, 9)
    {
        rep(j, 9)
        {
            cin >> A[i][j];
        }
    }

    set<int> s;

    rep(i, 9)
    {
        s.clear();
        rep(j, 9)
        {
            s.insert(A[i][j]);
        }

        if (s.size() != 9)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    rep(j, 9)
    {
        s.clear();
        rep(i, 9)
        {
            s.insert(A[i][j]);
        }
        if (s.size() != 9)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    if (s.size() != 9)
    {
        cout << "No" << endl;
        return 0;
    }

    int dx[] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
    int dy[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};

    rep(i, 3) rep(j, 3)
    {
        s.clear();
        rep(k, 9)
        {
            s.insert(A[i * 3 + dx[k]][j * 3 + dy[k]]);
        }

        if (s.size() != 9)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
