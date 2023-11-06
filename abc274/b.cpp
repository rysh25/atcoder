// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    string C;
    vector<int> res(W, 0);

    for (int i = 0; i < H; i++)
    {
        cin >> C;

        for (int j = 0; j < W; j++)
        {
            if (C[j] == '#')
            {
                res[j]++;
            }
        }
    }

    for (auto &r : res)
    {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
