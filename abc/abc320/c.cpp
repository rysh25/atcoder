#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int M;
    cin >> M;

    string S1, S2, S3;
    cin >> S1 >> S2 >> S3;

    int ans = -1;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < M; k++)
            {
                // cout << "i: " << i << ", j: " << j << ", k: " << k << endl;
                if (S1[i] == S2[j] && S2[j] == S3[k])
                {
                    int i2 = i;
                    int j2 = j;
                    int k2 = k;
                    if (i2 == j2 && j2 == k2)
                    {
                        j2 += M;
                        k2 += M * 2;
                    }
                    if (i2 == j2)
                    {
                        j2 += M;
                    }
                    if (j2 == k2)
                    {
                        k2 += M;
                    }
                    if (i2 == k2)
                    {
                        k2 += M;
                    }
                    auto max_num = max({i2, j2, k2});
                    if (ans == -1 || max_num < ans)
                    {
                        ans = max_num;
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
