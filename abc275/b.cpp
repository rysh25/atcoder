// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    long long A, B, C, D, E, F;
    long long P = 998244353;
    cin >> A >> B >> C >> D >> E >> F;
    A %= P;
    B %= P;
    C %= P;
    D %= P;
    E %= P;
    F %= P;

    long long abc = (((A * B) % P) * C) % P;
    long long def = (((D * E) % P) * F) % P;
    long long res = (abc - def + P) % P;

    cout << res << endl;

    return 0;
}
