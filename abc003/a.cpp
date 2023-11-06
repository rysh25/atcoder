// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    double N;

    cin >> N;

    double res = ((1.0 + N) * N / 2.0) / N;

    cout << res * 10000 << endl;

    return 0;
}
