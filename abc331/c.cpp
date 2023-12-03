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

    vector<int> a(N);
    rep(i, N) cin >> a[i];

    vector<int> b;
    b = a;

    sort(b.begin(), b.end());

    // cout << "b: ";
    // rep(i, N) cout << b[i] << " ";
    // cout << endl;

    vector<ll> prefix_sum(N + 1, 0);
    rep(i, N) prefix_sum[i + 1] = prefix_sum[i] + b[i];

    // cout << "prefix_sum: ";
    // rep(i, N + 1) cout << prefix_sum[i] << " ";
    // cout << endl;

    rep(i, N)
    {
        int idx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();

        // cout << "idx: " << idx << endl;

        if (idx == N)
        {
            cout << 0 << " ";
            continue;
        }

        cout << prefix_sum[N] - prefix_sum[idx] << " ";
    }

    cout << endl;

    return 0;
}
