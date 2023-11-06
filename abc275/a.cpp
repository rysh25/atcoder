// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int m = 0;
    int res = 0;
    for (int i = 1; i <= N; i++)
    {
        int H;
        cin >> H;
        if (m < H)
        {
            m = H;
            res = i;
        }
    }

    cout << res << endl;

    return 0;
}
