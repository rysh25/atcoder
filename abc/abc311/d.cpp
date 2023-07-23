#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int N, M;
string S[205];
int visited[205][205][4];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> S[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < 4; k++)
                visited[i][j][k] = -1;
    visited[1][1][0] = visited[1][1][1] = visited[1][1][2] = visited[1][1][3] = 0;

    queue<tuple<int, int, int>> q;
    q.push(make_tuple(1, 1, 0));
    q.push(make_tuple(1, 1, 1));
    q.push(make_tuple(1, 1, 2));
    q.push(make_tuple(1, 1, 3));

    while (!q.empty())
    {
        auto [x, y, dir] = q.front();
        q.pop();
        int nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M || S[nx][ny] == '#')
            continue;
        if (visited[nx][ny][dir] != -1)
            continue;
        visited[nx][ny][dir] = visited[x][y][dir] + 1;
        q.push(make_tuple(nx, ny, dir));
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < 4; k++)
                if (visited[i][j][k] != -1)
                    ans++;

    cout << ans << endl;

    return 0;
}
