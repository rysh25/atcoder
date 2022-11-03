// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string S;
    cin >> S;

    int count = 4;

    string akihabara("AKIHABARA");

    bool yes = false;

    for (int bit = 0; bit < (1 << count); bit++)
    {
        vector<bool> use(count, false);
        for (int i = 0; i < count; i++)
        {
            if (bit & (1 << i))
            {
                use[i] = true;
            }
        }

        int c;
        string tmp;
        for (int i = 0; i < akihabara.length(); i++)
        {
            char c = akihabara[i];
            if (c == 'A')
            {
                if (use[i])
                    tmp += c;
                c++;
            }
            else
            {
                tmp += c;
            }
        }

        if (tmp == S)
        {
            yes = true;
            break;
        }
    }

    cout << (yes ? "YES" : "NO") << endl;

    return 0;
}
