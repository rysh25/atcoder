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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, K) cin >> A[i];

    int socks = 2 * N - K;
    vector<int> colors(socks, 0);

    // cout << "socks=" << socks << endl;

    int color = 1;
    int i = 0;
    int j = 0;
    while (i < socks)
    {
        colors[i] = color;
        i++;

        if (A[j] == color)
        {
            j++;
        }
        else
        {
            colors[i] = color;
            i++;
        }
        color++;
    }

    // cout << "colors: ";
    // rep(i, socks)
    // {
    //     cout << colors[i] << " ";
    // }
    // cout << endl;

    int pairs = socks / 2;

    vector<int> diffs(socks - 1, 0);
    rep(i, socks - 1)
    {
        diffs[i] = colors[i + 1] - colors[i];
    }

    // cout << "diffs: ";
    // rep(i, socks - 1)
    // {
    //     cout << diffs[i] << " ";
    // }
    // cout << endl;
    int max_diff_index = 0;
    int max_diff = 0;
    rep(i, socks - 1)
    {
        if (diffs[i] > max_diff)
        {
            max_diff = diffs[i];
            max_diff_index = i;
        }
    }

    // cout << "socks=" << socks << ", pairs=" << pairs << ", max_diff_index=" << max_diff_index << endl;

    int ans = 0;
    if (socks % 2 == 0)
    {
        // cout << "even" << endl;
        for (int i = 0; i < N; i += 2)
        {
            ans += diffs[i];
        }
    }
    else
    {
        // cout << "odd" << endl;
        bool skipped = false;
        for (int i = 0; i < N; i += 2)
        {
            if (!skipped && diffs[i] == max_diff)
            {
                skipped = true;
                i++;
            }
            // cout << "i=" << i << endl;
            ans += diffs[i];
        }
    }

    cout << ans << endl;

    return 0;
}
