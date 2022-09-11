// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;

    if (T.find(S, 0) == 0)
    {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}
