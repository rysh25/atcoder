// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int X, Y, N;
    cin >> X >> Y >> N;

    int result;

    if (X * 3 < Y)
    {
        result = N * X;
    }
    else
    {
        int count_y = N / 3;
        int count_x = N % 3;

        result = count_y * Y + count_x * X;
    }

    cout << result << endl;

    return 0;
}
