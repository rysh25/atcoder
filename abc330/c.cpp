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
    ll D;
    cin >> D;

    ll ans = D;

    for (ll x = 0; x * x <= 2 * 1e12; x++)
    {
        ll y_squared = D - x * x;
        if (y_squared < 0)
            break;

        ll y = sqrt(y_squared);

        // cout << "x=" << x << ", y_squared=" << y_squared << ", y=" << y << endl;

        long long diff = abs(x * x + y * y - D);

        // cout << "x=" << x << ", y_squared=" << y_squared << ", y=" << y << ", diff=" << diff << endl;

        ans = min(ans, diff);
        diff = abs(x * x + (y + 1) * (y + 1) - D);
        ans = min(ans, diff);
    }

    cout << ans << endl;

    return 0;
}
