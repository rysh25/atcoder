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
#include <cstdlib>
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

    map<string, int> counter;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());

        counter[s]++;
    }

    ll ans = 0;

    for (auto p : counter)
    {
        ll n = p.second;
        ans += n * (n - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
