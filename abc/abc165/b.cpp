#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main()
{
    long long x;
    cin >> x;

    long long saving = 100;
    int i = 0;
    while (saving < x)
    {
        // 不動小数点の誤差がある
        // saving += (long long)(saving * 0.1);

        // 少数を使わなければ不動小数点の誤差を気にしなくても良い
        // int の割り算は小数点以下切り捨て
        saving += saving / 100;
        i++;
    }

    cout << i << endl;

    return 0;
}
