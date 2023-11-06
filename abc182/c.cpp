// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long N;

    cin >> N;

    string ns = to_string(N);

    int digit = ns.length();

    int mind = 20;
    for (int bit = 0; bit < (1 << digit); bit++)
    {
        string s;
        for (int i = 0; i < digit; i++)
        {
            if (!(bit & 1 << i))
            {
                s += ns[i];
            }
        }

        if (s == "")
            continue;

        if (stoll(s) % 3 == 0)
        {
            mind = min(mind, (int)(digit - s.length()));
        }
    }

    if (mind == 20)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << mind << endl;
    }
    return 0;
}
