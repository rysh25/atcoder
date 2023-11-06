// #include <bits/stdc++.h>
#include <iostream>
#include <cfloat>
#include <cmath>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main()
{
    int N, D;

    cin >> N >> D;

    // vector<int, int> XY(N);

    // for (auto &xy : XY)
    // {
    //     cin >> xy;
    // }

    int X, Y;
    int ans = 0;
    rep(i, N)
    {
        cin >> X >> Y;

        // 不動小数点の誤差に気をつける
        // double d = sqrt(pow(X, 2) + pow(Y, 2));
        // if (d - FLT_EPSILON <= D)

        // ルートを計算しなければ不動小数点誤差を気にしなくても良い
        // ルート計算のしなくて良いので軽くなる
        if (pow(X, 2) + pow(Y, 2) <= pow(D, 2))
        {
            // cout << "X=" << X << ", Y=" << Y << endl;
            // cout << "d=" << d << ", D=" << D << endl;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
