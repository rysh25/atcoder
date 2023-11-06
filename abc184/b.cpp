// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int N, X;

    cin >> N >> X;

    string S;

    cin >> S;

    for (auto &s : S)
    {
        if (s == 'o')
        {
            X += 1;
        }
        else if (X > 0)
        {
            X -= 1;
        }
    }

    cout << X << endl;

    return 0;
}
