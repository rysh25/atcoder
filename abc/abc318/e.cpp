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

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    unordered_map<int, int> count;
    unordered_map<int, int> prefix_count;
    ll ans = 0;

    for (int j = 0; j < N; ++j)
    {
        ++count[A[j]];
    }

    for (int j = 1; j < N - 1; ++j)
    {
        --count[A[j]];            // A[j]は中央の値なので、countから減算
        ++prefix_count[A[j - 1]]; // A[j - 1]はprefixに追加されるので、prefix_countに加算

        // A[i] = A[k] かつ A[i] != A[j] を満たす (i, j, k) の数を計算
        ans += count[A[j - 1]] - (A[j] == A[j - 1]);
    }

    cout << ans << endl;

    return 0;
}
