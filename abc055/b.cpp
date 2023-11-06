// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;

    cin >> N;

    long long res = 1;

    long long P = 1000000007;

    for (int i = 0; i < N; i++)
    {
        res = (res * (i + 1)) % P;
    }

    cout << res << endl;

    return 0;
}
