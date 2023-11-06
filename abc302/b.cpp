#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> S(H);

    string snuke = "snuke";

    for (int i = 0; i < H; i++)
    {
        cin >> S[i];
    }

    auto dfs = [&](auto dfs, int i, int ci, int cj, pair<int, int> next, vector<pair<int, int>> &path) -> bool
    {
        if (i == 5)
        {
            return true;
        }

        int ni = ci + next.first;
        int nj = cj + next.second;

        if (ni < 0 || ni >= H || nj < 0 || nj >= W)
        {
            return false;
        }

        if (S[ni][nj] != snuke[i])
        {
            return false;
        }

        path.emplace_back(ni, nj);
        // cout << "ni=" << ni << ", nj=" << nj << endl;

        if (dfs(dfs, i + 1, ni, nj, next, path))
        {
            return true;
        }

        path.pop_back();
        return false;
    };

    pair<int, int> d[8] = {{1, 0},
                           {0, 1},
                           {-1, 0},
                           {0, -1},
                           {1, 1},
                           {1, -1},
                           {-1, 1},
                           {-1, -1}};

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            // cout << "S[" << i << "][" << j << "]=" << S[i][j] << endl;
            if (S[i][j] != snuke[0])
            {
                continue;
            }

            vector<pair<int, int>> path;
            path.emplace_back(i, j);
            // cout << "i=" << i << ", j=" << j << endl;

            int ci = i;
            int cj = j;
            for (int k = 0; k < 8; k++)
            {
                int ni = ci + d[k].first;
                int nj = cj + d[k].second;

                if (ni < 0 || ni >= H || nj < 0 || nj >= W)
                {
                    continue;
                }

                if (S[ni][nj] != snuke[1])
                {
                    continue;
                }
                path.emplace_back(ni, nj);
                // cout << "ni=" << ni << ", nj=" << nj << ", k=" << k << endl;

                if (dfs(dfs, 2, ni, nj, d[k], path))
                {
                    for (auto p : path)
                    {
                        cout << p.first + 1 << " " << p.second + 1 << endl;
                    }

                    cout << endl;
                    return 0;
                }
                path.pop_back();
            }
        }
    }

    return 0;
}
