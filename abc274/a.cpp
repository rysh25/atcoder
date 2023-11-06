// #include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double A, B;
    cin >> A >> B;

    double res = B / A;
    res *= pow(10, 3);
    res = round(res);
    res /= pow(10, 3);

    cout << fixed;
    cout << setprecision(3) << res << endl;

    return 0;
}
