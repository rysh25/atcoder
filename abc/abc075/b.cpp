#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    vector<vector<int>> ans(H, vector<int>(W, 0));

    for (auto &s : S)
    {
        cin >> s;
    }

    int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (0 <= x && x < H &&
                    0 <= y && y < W && S[x][y] == '#')
                {
                    ans[i][j]++;
                }
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (S[i][j] == '#')
                cout << '#';
            else
                cout << ans[i][j];
        }

        cout << endl;
    }

    return 0;
}
