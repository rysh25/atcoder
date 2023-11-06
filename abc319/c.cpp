#include <iostream>
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

double disapoint(int a, int b, int c)
{
    if (a == b && a != c)
        return 2.0 / 3.0;
    if (a == c && a != b)
        return 2.0 / 3.0;
    if (b == c && b != a)
        return 2.0 / 3.0;
    return 1;
}

int main()
{
    int N = 3;
    int c[N][N];

    rep(i, N)
    {
        rep(j, N)
        {
            cin >> c[i][j];
        }
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << c[i][0] << c[i][1] << c[i][2] << endl;
    // }

    double prob = 1;

    for (int i = 0; i < N; i++)
    {
        prob *= disapoint(c[i][0], c[i][1], c[i][2]);
        // cout << prob << endl;
        prob *= disapoint(c[0][i], c[1][i], c[2][i]);
        // cout << prob << endl;
    }
    prob *= disapoint(c[0][0], c[1][1], c[2][2]);
    // cout << prob << endl;
    prob *= disapoint(c[0][2], c[1][1], c[2][0]);
    // cout << prob << endl;

    cout.precision(20);
    cout << prob << endl;

    return 0;
}
