// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <bitset>

using namespace std;

int main()
{

    long long N;
    cin >> N;

    stringstream ss;
    ss << std::bitset<60>(N);

    string b = ss.str();
    // cout << b << endl;

    // int c = count(b.cbegin(), b.cend(), '1');

    string res(60, '0');

    int c = 0;
    vector<int> digit;
    for (int i = b.length() - 1; i >= 0; i--)
    {
        if (b[i] == '1')
        {
            digit.push_back(i);
            c++;
        }
    }

    // cout << c << endl;
    // cout << res << endl;

    for (int bit = 0; bit < (1 << c); bit++)
    {
        for (int i = 0; i < c; i++)
        {
            if (bit & (1 << i))
            {
                res[digit[i]] = '1';
            }
            else
            {
                res[digit[i]] = '0';
            }
        }
        // cout << res << endl;
        cout << stoll(res, nullptr, 2) << endl;
    }

    return 0;
}
