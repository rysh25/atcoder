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
    int N;
    cin >> N;
    string S;
    cin >> S;

    map<char, int> mp;

    int l = 0;
    for (int r = 0; r < N; r++)
    {
        while (S[r] != S[l])
        {
            l++;
        }
        // cout << "S[r]: " << S[r];
        // cout << ", r-l+1=" << r - l + 1 << endl;
        mp[S[r]] = max(mp[S[r]], r - l + 1);
    }

    int ans = 0;
    for (auto p : mp)
    {
        ans += p.second;
    }

    cout << ans << endl;

    return 0;
}
