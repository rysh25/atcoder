// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    long long A, B, K;
    cin >> A >> B >> K;

    if (A > K)
    {
        cout << A - K << " " << B << endl;
    }
    else if (A + B < K)
    {
        cout << 0 << " " << 0 << endl;
    }
    else
    {
        cout << 0 << " " << B - (K - A) << endl;
    }

    return 0;
}
