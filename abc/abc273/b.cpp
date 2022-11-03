// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    long long X;
    int K;

    // freopen("abc/abc273/b.in", "r", stdin);

    cin >> X >> K;

    long long a = 1;
    long long res = X;
    for (int i = 0; i < K; i++)
    {
        res += 5 * a;
        a *= 10;

        res = res / a * a;
    }

    cout << res << endl;
    return 0;
}
