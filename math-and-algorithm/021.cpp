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
    ll n, r;
    cin >> n >> r;

    ll ans = 1;
    ll s = r;
    for (int i = 0; i < r; i++)
    {
        ans *= n;
        // cout << "ans=" << ans << ", n=" << n << endl;
        n--;
    }
    for (int i = 0; i < s; i++)
    {
        ans /= r;
        // cout << "ans=" << ans << ", r=" << r << endl;
        r--;
    }

    cout << ans << endl;

    return 0;
}
