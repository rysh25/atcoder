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

vector<string> rotate(const vector<string> &p)
{
    vector<string> res(4, string(4, '.'));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            res[j][3 - i] = p[i][j];
        }
    }
    return res;
}

int main()
{
    vector<vector<string>> P(3, vector<string>(4));
    rep(i, 3) rep(j, 4) cin >> P[i][j];

    // cout << "P: " << endl;
    // rep(i, 3)
    // {
    //     cout << "i=" << i << endl;
    //     rep(j, 4)
    //     {
    //         cout << P[i][j] << endl;
    //     }
    //     cout << endl;
    // }

    vector<string> board(4, "....");

    auto can_place = [&](int x, int y, const vector<string> &p) -> bool
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (p[i][j] == '#' &&
                    (x + i < 0 ||
                     y + j < 0 ||
                     x + i >= 4 ||
                     y + j >= 4 ||
                     board[x + i][y + j] == '#'))
                {
                    return false;
                }
            }
        }
        return true;
    };

    auto place = [&](int x, int y, const vector<string> p, char c)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (p[i][j] == '#')
                {
                    board[x + i][y + j] = c;
                }
            }
        }
    };

    auto dfs = [&](auto dfs, int i) -> bool
    {
        if (i == 3)
        {
            // cout << "board: " << endl;
            // rep(i, 4) cout << board[i] << endl;

            bool res = true;
            rep(i, 4) rep(j, 4) if (board[i][j] == '.') res = false;
            return res;
        }

        for (int x = -3; x < 4; x++)
        {
            for (int y = -3; y < 4; y++)
            {
                // cout << "i=" << i << ", x=" << x << ", y=" << y << endl;
                auto p = P[i];

                for (int r = 0; r < 4; r++)
                {
                    // cout << "p: " << endl;
                    // rep(i, 4) cout << p[i] << endl;

                    if (can_place(x, y, p))
                    {
                        place(x, y, p, '#');

                        if (dfs(dfs, i + 1))
                            return true;
                        place(x, y, p, '.');
                    }
                    else
                    {
                        // cout << "cannot place" << endl;
                        // cout << "p: " << endl;
                        // rep(i, 4) cout << p[i] << endl;
                    }
                    p = rotate(p);
                }
            }
        }
        return false;
    };

    if (dfs(dfs, 0))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
