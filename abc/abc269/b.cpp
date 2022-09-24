// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> S(10);
    int a = 0, b = 0, c = 0, d = 0;
    bool in_rect = false;
    for (int i = 0; i < 10; i++)
    {
        cin >> S[i];

        string::size_type pos = S[i].find("#");

        if (!in_rect)
        {
            if (pos != string::npos)
            {
                in_rect = true;
                if (a == 0)
                {
                    a = i + 1;
                }
                if (c == 0)
                {
                    c = pos + 1;
                    d = S[i].find_last_of("#") + 1;
                }
            }
        }
        else
        {
            if (pos == string::npos)
            {
                if (b == 0)
                {
                    b = i;
                }
            }
        }
    }

    if (a != 0 && b == 0)
    {
        b = 10;
    }

    cout << a << " " << b << endl;
    cout << c << " " << d << endl;

    return 0;
}
