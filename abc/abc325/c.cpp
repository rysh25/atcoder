#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <tuple>
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
    rep(i, H)
    {
        cin >> S[i];
    }

    int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

    queue<pair<int, int>> q;
    map<pair<int, int>, bool> seen;

    int ans = 0;

    rep(i, H)
    {
        rep(j, W)
        {
            if (S[i][j] == '#')
            {

                if (seen.count({j, i}))
                {
                    // cout << "seen: " << j << ", " << i << endl;
                    continue;
                }
                // cout << "!!!!!!!not seen: " << j << ", " << i << endl;
                ans++;
                q.emplace(j, i);

                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    if (seen.count({x, y}))
                    {
                        // cout << "seen: " << x << ", " << y << endl;
                        continue;
                    }

                    seen[{x, y}] = true;

                    // cout << "x, y: " << x << ", " << y << endl;

                    rep(i, 8)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];

                        if (nx < 0 || nx >= W || ny < 0 || ny >= H)
                        {
                            continue;
                        }

                        if (S[ny][nx] != '#')
                        {
                            continue;
                        }

                        // cout << "nx, ny: " << nx << ", " << ny << endl;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
