// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>

using namespace std;

double calcRadan(int *p1, int *p2, int *p3)
{
    double a[2];
    double b[2];
    a[0] = p1[0] - p2[0];
    a[1] = p1[1] - p2[1];
    b[0] = p3[0] - p2[0];
    b[1] = p3[1] - p2[1];
    // cout << "a=(" << a[0] << ", " << a[1] << ")" << endl;
    // cout << "b=(" << b[0] << ", " << b[1] << ")" << endl;

    // cout << sqrt(a[0] * a[0] + a[1] * a[1]) << endl;
    // cout << sqrt(b[0] * b[0] + b[1] * b[1]) << endl;
    // cout << a[0] * b[0] + a[1] * b[1] << endl;
    // cout << sqrt(a[0] * a[0] + a[1] * a[1]) * sqrt(b[0] * b[0] + b[1] * b[1]) << endl;
    // cout << (a[0] * b[0] + a[1] * b[1]) / (sqrt(a[0] * a[0] + a[1] * a[1]) * sqrt(b[0] * b[0] + b[1] * b[1])) << endl;
    // cout << acos((a[0] * b[0] + a[1] * b[1]) / (sqrt(a[0] * a[0] + a[1] * a[1]) * sqrt(b[0] * b[0] + b[1] * b[1]))) << endl;

    return acos((a[0] * b[0] + a[1] * b[1]) / (sqrt(a[0] * a[0] + a[1] * a[1]) * sqrt(b[0] * b[0] + b[1] * b[1])));
}

double calcCross(int *p1, int *p2, int *p3)
{
    double a[2];
    double b[2];
    a[0] = p1[0] - p2[0];
    a[1] = p1[1] - p2[1];
    b[0] = p3[0] - p2[0];
    b[1] = p3[1] - p2[1];
    // cout << "a=(" << a[0] << ", " << a[1] << ")" << endl;
    // cout << "b=(" << b[0] << ", " << b[1] << ")" << endl;

    // cout << a[0] * b[1] - b[0] * a[1] << endl;
    return a[0] * b[1] - b[0] * a[1];
}

int main()
{
    int A[2], B[2], C[2], D[2];

    cin >> A[0] >> A[1];
    cin >> B[0] >> B[1];
    cin >> C[0] >> C[1];
    cin >> D[0] >> D[1];

    if (calcCross(D, A, B) > 0)
    {
        cout << "No" << endl;
        return 0;
    }
    else if (calcCross(A, B, C) > 0)
    {
        cout << "No" << endl;
        return 0;
    }
    else if (calcCross(B, C, D) > 0)
    {
        cout << "No" << endl;
        return 0;
    }
    else if (calcCross(C, D, A) > 0)
    {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    return 0;
}
