#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    long long X, Y, Z;
    cin >> X >> Y >> Z;
    string S;
    cin >> S;

    int n = S.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 1e18));

    dp[0][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        if (S[i] == 'A')
        {
            dp[i + 1][0] = min(dp[i][0] + Y, dp[i][1] + Z + min(X, Y));
            dp[i + 1][1] = min(dp[i][0] + Z + min(X, Y), dp[i][1] + X);
        }
        else
        {
            dp[i + 1][0] = min(dp[i][0] + X, dp[i][1] + Z + min(X, Y));
            dp[i + 1][1] = min(dp[i][0] + Z + min(X, Y), dp[i][1] + Y);
        }

        // cout << "dp[" << i + 1 << "][0]=" << dp[i + 1][0] << ", dp[" << i + 1 << "][1]=" << dp[i + 1][1] << endl;
    }

    cout << min(dp[n][0], dp[n][1]) << endl;

    return 0;
}
