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
    ll N;
    cin >> N;

    ll ans = 0;
    ll base = 1;
    ll k = N - 1;
    while (k > 0)
    {
        ll digit = k % 5;

        // cout << "digit=" << digit << ", base=" << base << endl;
        ans += base * (digit * 2);

        k /= 5;
        base *= 10;
        // cout << "k=" << k << endl;
    }

    cout << ans << endl;

    return 0;
}
