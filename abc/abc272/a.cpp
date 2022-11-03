// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int res = 0;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        res += a;
    }

    cout << res << endl;

    return 0;
}
