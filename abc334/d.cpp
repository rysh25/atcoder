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
    int N, Q;
    cin >> N >> Q;
    vector<int> R(N);
    rep(i, N) cin >> R[i];
    vector<ll> prefix_sum(N + 1);
    sort(R.begin(), R.end());
    rep(i, N) prefix_sum[i + 1] = prefix_sum[i] + (ll)R[i];

    // cout << "prefix_sum: ";
    // rep(i, N + 1) cout << prefix_sum[i] << " ";
    // cout << endl;

    while (Q--)
    {
        ll x;
        cin >> x;

        // cout << "x: " << x << endl;
        int ans = upper_bound(prefix_sum.begin(), prefix_sum.end(), x) - prefix_sum.begin() - 1;

        cout << ans << endl;
    }

    return 0;
}
