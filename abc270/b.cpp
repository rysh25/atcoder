// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int res = 0;

    if (0 < X && (Y < 0 || X < Y))
    {
        res = X;
    }
    else if (X < 0 && (0 < Y || Y < X))
    {
        res = -X;
    }
    else if (0 < X && 0 < Y && Y < X && Z < Y)
    {
        if (Z < 0)
        {
            res = -Z * 2 + X;
        }
        else
        {
            res = X;
        }
    }
    else if (X < 0 && Y < 0 && X < Y && Y < Z)
    {
        if (0 < Z)
        {
            res = Z * 2 + -X;
        }
        else
        {
            res = -X;
        }
    }
    else
    {
        res = -1;
    }

    cout << res << endl;

    return 0;
}
