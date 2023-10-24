#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <cmath>
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
    int N, S;
    cin >> N >> S;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));
    dp[0][0] = true;

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 0; j < S + 1; j++)
        {
            // cout << "j=" << j << ",  i=" << i << endl;
            if (j - A[i - 1] >= 0)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << (dp[N][S] ? "Yes" : "No") << endl;

    return 0;
}
