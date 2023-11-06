#include <iostream>
#include <vector>
#include <set>
#include <map>
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

    const int INF = 1e9;
    vector<vector<int>> dist(H, vector<int>(W, INF));
    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};
    const char eye[] = {'v', '>', '^', '<'};

    pair<int, int> start, goal;

    auto is_valid = [&](int x, int y) -> bool
    {
        return 0 <= x && x < H && 0 <= y && y < W;
    };

    for (int i = 0; i < H; i++)
    {
        cin >> S[i];

        for (int j = 0; j < W; j++)
        {
            if (S[i][j] == 'S')
                start = {i, j};
            if (S[i][j] == 'G')
                goal = {i, j};

            for (int d = 0; d < 4; d++)
            {
                if (S[i][j] == eye[d])
                {
                    int x = i, y = j;
                    while (is_valid(x, y) &&
                           S[x][y] != '#' &&
                           S[x][y] != eye[(d + 2) % 4])
                    {
                        S[x][y] = '#';
                        x += dx[d];
                        y += dy[d];
                    }
                }
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;

    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (is_valid(nx, ny) &&
                S[nx][ny] != '#' &&
                dist[nx][ny] == INF)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    if (dist[goal.first][goal.second] == INF)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << dist[goal.first][goal.second] << endl;
    }

    return 0;
}
