// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string S;
    cin >> S;

    int columns[7]{0};

    if (S[0] == '1')
    {
        cout << "No" << endl;
        return 0;
    }

    if (S[6] == '1')
    {
        columns[0] = 1;
    }
    if (S[3] == '1')
    {
        columns[1] = 1;
    }
    if (S[1] == '1' or S[7] == '1')
    {
        columns[2] = 1;
    }
    if (S[0] == '1' or S[4] == '1')
    {
        columns[3] = 1;
    }
    if (S[2] == '1' or S[8] == '1')
    {
        columns[4] = 1;
    }
    if (S[5] == '1')
    {
        columns[5] = 1;
    }
    if (S[9] == '1')
    {
        columns[6] = 1;
    }

    int l = -1;
    for (int i = 0; i < 6; i++)
    {
        if (columns[i] == 1)
        {
            l = i;
        }
        else if (columns[i] == 0 && l > -1)
        {
            for (int j = i + 1; j < 7; j++)
            {
                if (columns[j] == 1)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
