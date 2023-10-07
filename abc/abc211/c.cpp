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

int main()
{
    const int mod = 1000000007;

    string S;
    cin >> S;

    int N = S.size();

    string chokudai = "chokudai";
    vector<vector<int>> dp(chokudai.size() + 1, vector<int>(N + 1, 0));

    for (int i = 0; i < N + 1; i++)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i < chokudai.size() + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            if (chokudai[i - 1] == S[j - 1])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i][j - 1]) % mod;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    // cout << "dp: " << endl;
    // for (int i = 0; i < chokudai.size() + 1; i++)
    // {
    //     for (int j = 0; j < N + 1; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[chokudai.size()][N] << endl;

    return 0;
}
