#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string S;
    cin >> S;

    int n = S.size();

    vector<vector<int>> sum(10, vector<int>(n + 1, 0));

    for (int i = 0; i < n; i++)
    {
        // cout << "S[i]=" << S[i] << endl;
        for (int j = i; j < n; j++)
            sum[S[i] - '0'][j + 1]++;
    }

    int res = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << sum[i][j];
    //     }
    //     cout << endl;
    // }

    for (int left = 0; left < n; left++)
    {
        for (int right = left + 1; right < n; right++)
        {
            int len = (right - left) + 1;
            if (len % 2 != 0)
            {
                continue;
            }

            bool eq = true;
            // cout << "** left=" << left << ", right=" << right << ", len=" << len << endl;

            for (int j = 0; j < 10; j++)
            {
                // cout << "j=" << j << ":" << endl;
                int freq = sum[j][right + 1] - sum[j][left];

                if (freq % 2 != 0)
                {
                    eq = false;
                }
            }

            if (eq)
            {
                // cout << "!!!!!!left=" << left + 1 << ", right=" << right + 1 << ", len=" << len << endl;
                res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}
