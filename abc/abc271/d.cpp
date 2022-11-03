// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, S;

    cin >> N >> S;
    vector<int> a(N), b(N);

    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(S + 1, false));

    dp[0][0] = true;
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < S + 1; j++)
        {
            if (a[i] < j && a[j] < j)
            {
                dp[i][j] = a[i - 1][j];
            }
        }
    }

    if (yes)
    {
        cout << "Yes" << endl;

        for (int i = 0; i < N; i++)
        {
            if (res & (1 << i))
            {
                cout << "H";
            }
            else
            {
                cout << "T";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
