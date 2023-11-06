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
    int N;

    cin >> N;

    vector<vector<int>> D(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            cin >> D[i][j];
            D[j][i] = D[i][j];
        }
    }

    vector<vector<int>> dp(1 << N, vector<int>(N, 0));

    for (int S = 0; S < (1 << N); ++S)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                if (!(S & (1 << i)) && !(S & (1 << j)))
                {
                    dp[S | (1 << i) | (1 << j)] = max(dp[S | (1 << i) | (1 << j)], dp[S] + D[i][j]);
                }
            }
        }
    }

    cout << dp[(1 << N) - 1] << endl;

    return 0;
}
