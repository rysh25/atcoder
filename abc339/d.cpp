#include <iostream>
#include <iomanip>
#include <sstream>
#include <list>
#include <utility>
#include <string>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstring>
// #include <cstdlib>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <tuple>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N;
    cin >> N;

    vector<string> S(N);

    rep(i, N)
    {
        cin >> S[i];
    }

    const int INF = 1e9 + 1;

    pair<int, int> players[2];
    int p = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (S[i][j] == 'P')
            {
                players[p++] = {i, j};
            }
        }
    }

    cout << "player1: " << players[0].first << " " << players[0].second << "\n";
    cout << "player2: " << players[1].first << " " << players[1].second << "\n";

    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    auto bfs = [&](int x, int y) -> vector<vector<int>>
    {
        vector<vector<int>> dist(N, vector<int>(N, INF));

        queue<pair<int, int>> q;
        q.push({x, y});
        dist[x][y] = 0;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d)
            {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && S[nx][ny] != '#' && dist[nx][ny] == INF)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dist;
    };

    auto dist1 = bfs(players[0].first, players[0].second);

    cout << "dist1:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << dist1[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    auto dist2 = bfs(players[1].first, players[1].second);

    cout << "dist2:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << dist2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int ans = INF;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (dist1[i][j] != INF && dist2[i][j] != INF)
            {
                if (i == 0 || j == 0 || i == N - 1 || j == N - 1)
                {
                    int wk = max(dist1[i][j], dist2[i][j]);
                    cout << "1: i=" << i << " j=" << j << " wk=" << wk << endl;
                    ans = min(ans, wk);
                }
                else if (i > 0 && S[i - 1][j] == '#')
                {
                    int wk = max(dist1[i][j], dist2[i][j]);
                    cout << "1: i=" << i << " j=" << j << " wk=" << wk << endl;
                    ans = min(ans, wk);
                }
                else if (i < N - 1 && S[i + 1][j] == '#')
                {
                    int wk = max(dist1[i][j], dist2[i][j]);
                    cout << "1: i=" << i << " j=" << j << " wk=" << wk << endl;
                    ans = min(ans, wk);
                }
                else if (j > 0 && S[i][j - 1] == '#')
                {
                    int wk = max(dist1[i][j], dist2[i][j]);
                    cout << "1: i=" << i << " j=" << j << " wk=" << wk << endl;
                    ans = min(ans, wk);
                }
                else if (j < N - 1 && S[i][j + 1] == '#')
                {
                    int wk = max(dist1[i][j], dist2[i][j]);
                    cout << "1: i=" << i << " j=" << j << " wk=" << wk << endl;
                    ans = min(ans, wk);
                }
            }
        }
    }

    if (ans == INF)
        cout << "-1\n";
    else
        cout << ans << "\n";

    return 0;
}
