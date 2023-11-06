// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

long long rec(long long X)
{
    if (X == 1)
    {
        return 1;
    }
    else
    {
        return rec(X / 2) * 2 + 1;
    }
}

int main()
{
    long long H;
    cin >> H;

    cout << rec(H) << endl;

    return 0;
}
