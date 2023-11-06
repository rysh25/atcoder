// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    int R, C, sy, sx, gy, gx;

    cin >> R >> C >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;

    vector<vector<char>> c(R, vector<char>(C));

    for (int y = 0; y < R; y++)
    {
        for (int x = 0; x < C; x++)
        {
            cin >> c[y][x];
        }
    }

    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    deque<pair<int, int>> que;

    vector<vector<int>> dist(R, vector<int>(C, -1));
    dist[sy][sx] = 0;
    que.push_front(pair<int, int>(sy, sx));

    while (!que.empty())
    {
        auto [y, x] = que.back();
        que.pop_back();

        for (int i = 0; i < 4; i++)
        {
            if (c[y + dy[i]][x + dx[i]] == '#')
            {
                continue;
            }

            if (dist[y + dy[i]][x + dx[i]] != -1)
            {
                continue;
            }

            dist[y + dy[i]][x + dx[i]] = dist[y][x] + 1;

            que.push_front(pair<int, int>(y + dy[i], x + dx[i]));
        }
    }

    cout << dist[gy][gx] << endl;

    return 0;
}
