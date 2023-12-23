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
    ll A, M, L, R;
    cin >> A >> M >> L >> R;

    L -= A;
    R -= A;
    ll ans = 0;

    // cout << "L=" << L << ", R=" << R << endl;

    ll l_count = abs(L / M);
    ll r_count = abs(R / M);

    // cout << "l_count=" << l_count << ", r_count=" << r_count << endl;

    if (L == 0 && R == 0)
    {
        ans = 1;
    }
    else if (L <= 0 && R >= 0)
    {
        ans = l_count + r_count + 1;
    }
    else if (L <= 0 && R <= 0)
    {
        ans = l_count - r_count;
        if (R % M == 0)
        {
            ans += 1;
        }
    }
    else if (L >= 0 && R >= 0)
    {
        ans = r_count - l_count;
        if (L % M == 0)
        {
            ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
}
