#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];

    int dp[N + 1][X + 1];

    for (int i = 0; i <= N; i++)
        dp[0][i] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int x = 0; x <= X; x++)
        {
            if (x == A[i])
                dp[i + 1][x] =
        }
    }
    return 0;
}
