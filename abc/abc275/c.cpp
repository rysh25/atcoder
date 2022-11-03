// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> S(9);
    for (auto &s : S)
    {
        cin >> s;
    }

    int res = 0;
    for (int r = 0; r < 8; r++)
    {
        cout << "r=" << r << endl;
        for (int c = 0; c < 8; c++)
        {
            cout << "c=" << c << endl;
            if (S[r][c] == '#')
            {
                for (int i = r; i >= 0; i--)
                {
                    cout << "i=" << i << endl;
                    for (int j = c + 1; j < 9; j++)
                    {
                        cout << "j=" << j << endl;
                        if (S[i][j] == '#' &&
                            S[i + (j - c)][j + (i - r)] == '#' &&
                            S[r + (j - c)][c + (i - r)] == '#')
                        {
                            cout << "(r, c)=(" << r << ", " << c << ")";
                            res++;
                        }
                    }
                }
            }
        }
    }

    cout << res << endl;

    return 0;
}
