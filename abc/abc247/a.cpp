// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    string S;
    cin >> S;

    for (int i = 0; i < S.length(); i++)
    {
        if (i == 0)
            cout << '0';
        else
            cout << S[i - 1];
    }
    cout << endl;

    return 0;
}
