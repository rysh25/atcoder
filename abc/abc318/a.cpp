#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N, M, P;
    cin >> N >> M >> P;

    int ans = 0;

    if (N < M)
    {
        cout << 0 << endl;
        return ans;
    }
    ans = 1;
    N -= M;

    // cout << N << endl;
    // cout << N / P << endl;

    ans += N / P;

    cout << ans << endl;

    return 0;
}
