#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N;
    cin >> N;

    map<ll, ll> slimes;

    rep(i, N)
    {
        ll S, C;
        cin >> S >> C;
        slimes[S] += C;
    }

    map<int, ll> bit;
    for (auto &[size, count] : slimes)
    {
        for (int i = 0; i < 60; i++)
        {
            int s = size;
            if (s & (1LL << i))
            {
                s -= (1LL << i);
                bit[i] += count;
            }
        }
    }

    cout << "bit: " << endl;
    for (auto &[i, count] : bit)
    {
        cout << (1 << i) << " " << count << endl;
    }
    cout << endl;

    for (int i = 0; i < 59; i++)
    {
        if (bit[i] >= 2)
        {
            bit[i + 1] += bit[i] / 2;
            bit[i] %= 2;
        }
    }

    cout << "bit: " << endl;
    for (auto &[i, count] : bit)
    {
        cout << (1 << i) << " " << count << endl;
    }
    cout << endl;

    long long ans = 0;
    for (auto &[bit, count] : bit)
    {
        ans += count;
    }

    cout << ans << endl;

    return 0;
}
