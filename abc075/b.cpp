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

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            for (int i = 0; i < 8; i++)
            {
                int nh = h + dy[i];
                int nw = w + dx[i];

                if (nh < 0 || H <= nh || nw < 0 || W <= nw)
                    continue;

                if (S[nh][nw] == '#')
                    ans[h][w]++;
            }
        }
    }

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            if (S[h][w] == '#')
                cout << '#';
            else
                cout << ans[h][w];
        }

        cout << endl;
    }

    return 0;
}
