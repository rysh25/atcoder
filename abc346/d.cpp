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

    vector<int> C(N);

    rep(i, N)
    {
        cin >> C[i];
    }

    vector<ll> l(N + 1, 0);
    vector<ll> r(N + 1, 0);

    ll ans = 1e18 + 1;
    rep(i, 2)
    {
        // cerr << "S: " << S << endl;

        char curr = '0';
        for (int i = 0; i < N; i++)
        {
            if (S[i] == curr)
                l[i + 1] = l[i];
            else
                l[i + 1] = l[i] + C[i];

            curr ^= '0' ^ '1';
        }

        // cerr << "l: ";
        // for (int i = 0; i <= N; i++)
        // {
        //     cerr << l[i] << " ";
        // }
        // cerr << endl;

        if (N % 2 == 0)
            curr = '0';
        else
            curr = '1';

        for (int i = N - 1; i >= 0; i--)
        {
            if (S[i] == curr)
                r[i] = r[i + 1];
            else
                r[i] = r[i + 1] + C[i];

            curr ^= '0' ^ '1';
        }

        // cerr << "r: ";
        // for (int i = 0; i <= N; i++)
        // {
        //     cerr << r[i] << " ";
        // }
        // cerr << endl;

        rep(i, N - 1)
        {
            ans = min(ans, l[i + 1] + r[i + 1]);
        }

        rep(i, N) S[i] ^= '0' ^ '1';
    }

    cout << ans << endl;

    return 0;
}
