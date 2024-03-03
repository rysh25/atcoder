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
    ll N;
    cin >> N;

    map<ll, ll> mp;

    auto f = [&](auto &&f, ll n) -> ll
    {
        // cout << "n=" << n << ", depth=" << depth << endl;
        if (mp.count(n) > 0)
        {
            // cout << "n=" << n << ", ret=" << mp[n] << endl;
            return mp[n];
        }

        if (n == 1)
        {
            mp[n] = 0;
            return 0;
        }
        else if (n == 2)
        {
            mp[n] = 2;
            return 2;
        }

        ll ret = 0;
        ll r1 = f(f, (n + 1) / 2);
        // cout << "f(" << (n + 1) / 2 << ")"
        //      << "r1=" << r1 << endl;
        ll r2 = f(f, n / 2);
        // cout << "f(" << n / 2 << ")"
        //      << "r2=" << r1 << endl;
        ret = r1 + r2;

        mp[n] = n + ret;
        // cout << "n=" << n << ", ret=" << ret << ", depth=" << depth << endl;
        return mp[n];
    };

    cout << f(f, N) << endl;

    return 0;
}
