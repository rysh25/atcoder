// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long N;
    cin >> N;

    long long res = 0;

    int c = 0;
    vector<int> digit;
    for (int i = 0; i < 60; i++)
    {
        if (((N >> i) & 1) == 1)
        {
            // cout << "i=" << i << endl;
            digit.push_back(i);
            c++;
        }
    }

    // cout << c << endl;
    // cout << res << endl;

    for (int bit = 0; bit < (1 << c); bit++)
    {
        res = 0;
        for (int i = 0; i < c; i++)
        {
            if (bit & (1 << i))
            {
                res |= (1LL << digit[i]);
            }
        }
        // cout << res << endl;
        cout << res << endl;
    }

    return 0;
}
