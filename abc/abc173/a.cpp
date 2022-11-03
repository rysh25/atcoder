// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int N;

    cin >> N;

    int res = 1000 * ((N / 1000) + (N % 1000 == 0 ? 0 : 1)) - N;

    cout << res << endl;

    return 0;
}
