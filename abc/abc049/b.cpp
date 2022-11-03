// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string S;

    cin >> S;

    vector<int> a(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < S.length(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[j] == i)
            {
                cout << '"';
            }
        }
        cout << S[i];
    }

    if (a[3] == S.length())
    {
        cout << '"';
    }

    cout << endl;

    return 0;
}
