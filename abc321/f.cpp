#include <iostream>
#include <string>
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

long long solve(long long N, long long X, long long K)
{
    if (K == 0)
    {
        return 1;
    }
    vector<ll> ancestors;
    while (X > 0)
    {
        ancestors.push_back(X);
        X /= 2;
    }

    long long start = ancestors[K];
    long long end = start + (1LL << K) - 1;

    cout << "start=" << start << ", end=" << end << endl;

    if (end > N)
    {
        return N - start + 1;
    }
    else
    {
        return (1LL << K);
    }
}
int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        ll N, X, K;
        cin >> N >> X >> K;
        cout << solve(N, X, K) << endl;
    }

    return 0;
}
