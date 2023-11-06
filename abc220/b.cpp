#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    ll K, A, B;
    cin >> K >> A >> B;

    ll m = 1;
    ll a = 0;
    ll b = 0;
    rep(i, 19)
    {
        a += A % 10L * m;
        b += B % 10L * m;
        A /= 10L;
        B /= 10L;
        m *= K;
    }

    cout << a * b << endl;

    return 0;
}
