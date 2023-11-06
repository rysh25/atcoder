// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string S;
    cin >> S;

    vector<bool> res(9);

    for (auto &c : S)
    {
        res[c - '0'] = true;
    }

    for (int i = 0; i < 10; i++)
    {
        if (!res[i])
        {
            cout << i << endl;
        }
    }

    return 0;
}
