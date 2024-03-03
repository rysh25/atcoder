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

ll gcd(ll a, ll b)
{
    if (a < b)
        return gcd(b, a);

    if (b == 0)
        return a;

    ll r;
    while ((r = a % b))
    {
        a = b;
        b = r;
    }
    return b;
}

int main()
{
    ll N, M, K;
    cin >> N >> M >> K;

    ll G = gcd(N, M);
    ll L = (N / gcd(N, M)) * M;

    cout << "G=" << G << " L=" << L << endl;

    // for (ll i = 1; i <= K; i++)
    // {
    //     cout << N * i << " " << M * i << endl;
    // }

    // cout << N * K << " " << M * K << endl;

    // cout << L / N - 1 << " " << L / M - 1 << endl;

    ll x = (L / N) - 1 + (L / M) - 1;

    // cout << x << endl;

    ll y = (K / (x + 1)) * L;

    // cout << y << endl;

    ll ans = (K / (x + 1)) * x;
    // cout << "ans=" << ans << endl;

    for (ll i = y;; i += G)
    {
        if (i % N == 0 && i % M == 0)
        {
            continue;
        }
        else if (i % N == 0)
        {
            ans++;
        }
        else if (i % M == 0)
        {
            ans++;
        }

        if (ans == K)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
