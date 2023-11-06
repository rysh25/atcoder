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
    int N;

    cin >> N;

    vector<int> P(N);

    rep(i, N - 1)
    {
        cin >> P[i];
    }

    int ans = 0;
    int i = N - 2;
    while (i >= 0)
    {
        i = P[i] - 2;
        ans++;
        // cout << "i=" << i << ", ans=" << ans << endl;
    }

    cout << ans << endl;

    return 0;
}
