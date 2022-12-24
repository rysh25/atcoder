#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    vector<int> A(N);

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));

    // dp[0][0] = -1;

    for (int i = 0; i < N + 1; i++)
    {
        int sum = 0;
        for (int j = 0; j < K + 1; j++)
        {
            sum += A[j];
            if (sum % 2 == 0)
            {
                dp[i + 1][j] = max(dp[i][j - A[j]] + 1, dp[i][j]);
            }
            else
            {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    return 0;
}
