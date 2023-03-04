#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }

    vector<int> dp(N + 1, 0);
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < N + 1; i++)
    {
        if (A[i - 2] != A[i - 1] && A[i - 2] != B[i - 1])
        {
            dp[i] = (dp[i - 1] + 2) % MOD;
        }

        if (A[i - 2] != B[i - 1] && B[i - 2] != B[i - 1])
        {
            dp[i] = (dp[i - 1] + 2) % MOD;
        }

        if (dp[i] == 0)
        {
            dp[i] = dp[i - 1];
        }
    }

    for (int i = 0; i < N + 1; i++)
    {
        cout << dp[i] << ", ";
    }

    cout << dp[N] << endl;

    return 0;
}
