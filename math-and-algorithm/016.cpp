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

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);

    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main()
{
    int N;
    cin >> N;

    vector<ll> A(N);

    rep(i, N)
    {
        cin >> A[i];
    }

    ll ans = A[0];

    for (int i = 1; i < N; i++)
    {
        ans = gcd(ans, A[i]);
    }

    cout << ans << endl;

    return 0;
}
