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
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int ans = 0;

    for (int a = 0; a <= A; a++)
    {
        for (int b = 0; b <= B; b++)
        {
            int c = X - 500 * a - 100 * b;
            if (0 <= c && c % 50 == 0 && c / 50 <= C)
            {
                // cout << "a=" << a << ", b=" << b << ", c=" << c / 50 << endl;
                ans++;
            }

            // for (int c = 0; c <= C; c++)
            // {
            //     if (500 * a + 100 * b + 50 * c == X)
            //     {
            //         ans++;
            //     }
            // }
        }
    }

    cout << ans << endl;

    return 0;
}
