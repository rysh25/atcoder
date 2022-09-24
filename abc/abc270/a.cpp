// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    int res = 0;

    if ((A & 1) == 1 || (B & 1) == 1)
    {
        res |= 1;
    }
    if ((A & 2) == 2 || (B & 2) == 2)
    {
        res |= 2;
    }
    if ((A & 4) == 4 || (B & 4) == 4)
    {
        res |= 4;
    }

    cout << res << endl;

    return 0;
}
