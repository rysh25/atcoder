// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main()
{
    int X;
    cin >> X;

    int ans = 1;
    for (int b = 2; b * b < X; b++)
    {
        for (int p = 2;; p++)
        {
            int power = pow(b, p);
            // cout << pn << endl;
            if (power > X)
            {
                break;
            }
            ans = max(ans, power);
        }
    }

    cout << ans << endl;

    return 0;
}
