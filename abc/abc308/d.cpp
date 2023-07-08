#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dist[500][500][5];
string snuke = "snuke";

int main()
{
    int H, W;
    cin >> H >> W;

    vector<string> S(H);

    for (int i = 0; i < H; i++)
    {
        cin >> S[i];
    }

    if (S[0][0] != snuke[0])
    {
        cout << "No" << endl;
        return 0;
    }

    memset(dist, -1, sizeof(dist));
    queue<pair<pair<int, int>, int>> que;
    que.push({{0, 0}, 0});
    dist[0][0][0] = 0;

    while (!que.empty())
    {
        auto [cur, idx] = que.front();
        que.pop();
        auto [x, y] = cur;

        cout << "x=" << x << ", y=" << y << ", idx=" << idx << endl;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            cout << "nx=" << nx << ", ny=" << ny << endl;

            if (0 <= nx && nx < H && 0 <= ny && ny < W)
            {
                cout << "dist[nx][ny][idx + 1]=" << dist[nx][ny][idx + 1] << endl;
                cout << "S[nx][ny]=" << S[nx][ny] << endl;
                if (dist[nx][ny][idx + 1] == -1 && S[x][y] == snuke[idx])
                {
                    dist[nx][ny][idx + 1] = dist[x][y][idx] + 1;
                    que.push({{nx, ny}, idx + 1 % 5});
                }
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (dist[H - 1][W - 1][i] != -1)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
