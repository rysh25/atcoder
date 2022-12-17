#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, K, D;

    cin >> N >> K >> D;

    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K + 1; j++)
        {
            // cout << "i=" << i << ", j=" << j << endl;
            if ((dp[i][j] + A[i]) % D == 0)
            {
                dp[i + 1][j] = max(dp[i][j] + A[i], dp[i][j]);
            }
            else
            {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    cout << (dp[N][K] == 0 ? -1 : dp[N][K]) << endl;

    return 0;
}
