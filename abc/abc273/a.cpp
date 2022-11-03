// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int f(int k)
{
    if (k == 0)
        return 1;
    return k * f(k - 1);
}

int main()
{
    int N;
    cin >> N;

    int res = f(N);

    cout << res << endl;

    return 0;
}
