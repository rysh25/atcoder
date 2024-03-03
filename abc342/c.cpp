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
    string S;
    cin >> S;

    int Q;
    cin >> Q;

    vector<int> mp(26, -1);

    while (Q--)
    {
        char c, d;
        cin >> c >> d;

        int ci = c - 'a';
        int di = d - 'a';

        // cout << "c=" << c << " d=" << d << " ci=" << ci << " di=" << di << endl;

        if (mp[ci] == -1)
        {
            mp[ci] = di;
        }

        rep(i, 26)
        {
            if (mp[i] == ci)
            {
                mp[i] = di;
            }
        }
    }

    // rep(i, 26)
    // {
    //     cout << "i=" << (char)(i + 'a') << " mp[i]=" << (char)mp[i] + 'a' << endl;
    // }

    rep(i, N)
    {
        int ci = S[i] - 'a';

        if (mp[ci] != -1)
        {
            S[i] = mp[ci] + 'a';
        }
    }

    cout << S << endl;

    return 0;
}
