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
#include <stack>
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
    int N;
    cin >> N;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<int> row_count(N, 0), col_count(N, 0);

    rep(r, N) rep(c, N)
    {
        if (S[r][c] == 'o')
            row_count[r]++;
    }

    rep(c, N) rep(r, N)
    {
        if (S[r][c] == 'o')
            col_count[c]++;
    }

    // cout << "row_count: ";
    // rep(i, N) cout << row_count[i] << " ";
    // cout << endl;

    // cout << "col_count: ";
    // rep(i, N) cout << col_count[i] << " ";
    // cout << endl;

    ll ans = 0;
    rep(r, N)
    {
        if (row_count[r] < 2)
            continue;
        rep(c, N)
        {
            if (S[r][c] != 'o')
                continue;

            if (col_count[c] < 2)
                continue;

            ans += ((ll)row_count[r] - 1) * ((ll)col_count[c] - 1);
        }
    }

    cout << ans << endl;

    return 0;
}
