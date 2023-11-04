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

    vector<int> P(N);
    rep(i, N)
    {
        cin >> P[i];
    }

    sort(P.rbegin(), P.rend());

    double ans = -1e18;

    double top = 0;
    double bottom = 0;
    rep(i, N)
    {
        cout << P[i] << endl;
        top += pow(0.9, i) * P[i];
        bottom += pow(0.9, i);

        // cout << "top=" << top << ", botton=" << bottom << ", 1200 / sqrt(i)=" << 1200 / sqrt(i + 1) << endl;

        // cout << fixed << setprecision(10) << (top / bottom) - (1200 / sqrt(i + 1)) << endl;

        ans = max(ans, (top / bottom) - (1200 / sqrt(i + 1)));
        // cout << "ans=" << ans << endl;
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
