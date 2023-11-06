#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, T, M;
    cin >> N >> T >> M;

    vector<vector<int>> A(M, vector<int>(2));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> dp(1 << N, vector<int>(T + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < (1 << N); i++)
    {
        for (int j = 0; j < T; j++)
        {
            if (dp[i][j] == 0)
            {
                continue;
            }

            for (int k = 0; k < M; k++)
            {
                if ((i & (1 << A[k][0])) && (i & (1 << A[k][1])))
                {
                    continue;
                }

                dp[i | (1 << A[k][0])][j + 1] += dp[i][j];
                dp[i | (1 << A[k][1])][j + 1] += dp[i][j];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < T; i++)
    {
        ans += dp[(1 << N) - 1][i];
    }

    cout << ans << endl;

    return 0;
}
