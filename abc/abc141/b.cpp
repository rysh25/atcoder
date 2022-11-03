// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    string S;

    cin >> S;

    bool res = true;
    for (int i = 0; i < S.length(); i++)
    {
        if (i % 2 == 0 && S[i] != 'R' && S[i] != 'U' && S[i] != 'D')
        {
            res = false;
        }
        else if (i % 2 == 1 && S[i] != 'L' && S[i] != 'U' && S[i] != 'D')
        {
            res = false;
        }
    }

    cout << (res ? "Yes" : "No") << endl;

    return 0;
}
