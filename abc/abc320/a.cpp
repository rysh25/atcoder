#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

long long pow(long long a, long long n)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res *= a; // 最下位ビットが 1 ならば (2で割り切れなければ) a^(2^i) を掛ける
        a *= a;
        n >>= 1; // n を1bit 左にずらす
    }
    return res;
}

int main()
{
    int A, B;
    cin >> A >> B;

    ll ans = pow(A, B) + pow(B, A);

    cout << ans << endl;

    return 0;
}
