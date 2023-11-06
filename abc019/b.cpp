// #include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    cin >> S;

    string result;

    // cout << "S=" << S << endl;
    for (int l = 0; l < S.size();)
    {
        int r = l + 1;
        for (; S[l] == S[r]; r++)
        {
        }

        result.push_back(S[l]);
        result.append(to_string(r - l));
        l = r;
    }

    cout << result << endl;

    return 0;
}
