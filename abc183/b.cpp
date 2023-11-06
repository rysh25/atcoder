// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    double Sx, Sy;
    double Gx, Gy;

    cin >> Sx >> Sy >> Gx >> Gy;

    // 0 - Sy = (-Gy - Sy / Gx - Sx) * (x - Sx)

    double ans = (Sy / (Sy + Gy)) * (Gx - Sx) + Sx;

    cout << setprecision(9) << ans << endl;

    return 0;
}
