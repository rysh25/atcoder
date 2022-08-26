// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int H, W;

    cin >> H >> W;

    vector<vector<char>> G(H, vector<char>(W));

    for (int i = 0; i < H; i++)
    {
        string S;
        cin >> S;

        for (int j = 0; j < W; j++)
        {
            G[i][j] = S[j];
        }
    }

    map<string, bool> visited;

    int i = 0, j = 0;
    while (true)
    {
        string p = to_string(i) + "," + to_string(j);
        if (visited.count(p))
        {
            cout << -1 << endl;
            return 0;
        }
        visited[p] = true;
        if (G[i][j] == 'U' && i > 0)
        {
            i--;
        }
        else if (G[i][j] == 'D' && i < H - 1)
        {
            i++;
        }
        else if (G[i][j] == 'L' && j > 0)
        {
            j--;
        }
        else if (G[i][j] == 'R' && j < W - 1)
        {
            j++;
        }
        else
        {
            break;
        }
    }

    cout << i + 1 << " " << j + 1 << endl;

    return 0;
}
