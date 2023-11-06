#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main()
{
    int H, W;

    cin >> H >> W;

    vector<string> C(H);

    // cout << "H=" << H << ", W=" << W << endl;

    int Sh, Sw;
    for (int h = 0; h < H; h++)
    {
        string c;
        cin >> c;
        cout << c << endl;
        C[h] = c;
        for (int w = 0; w < W; w++)
        {
            if (c[w] == 'S')
            {
                Sh = h;
                Sw = w;
            }
        }
    }

    cout << "Sh=" << Sh << ", Sw=" << Sw << endl;

    int dh[] = {-1, 0, 1, 0};
    int dw[] = {0, 1, 0, -1};

    vector<vector<int>> dist(H, vector<int>(W, -1));

    dist[Sh][Sw] = 0;
    queue<pair<int, int>> que;
    que.emplace(Sh, Sw);

    while (!que.empty())
    {
        auto curr = que.front();
        que.pop();

        int ch = curr.first;
        int cw = curr.second;

        for (int i = 0; i < 4; i++)
        {
            int wh = ch + dh[i];
            int ww = cw + dw[i];

            // cout << "wh=" << wh << ", ww=" << ww << endl;

            if (wh < 0 || wh >= H)
                continue;
            if (ww < 0 || ww >= W)
                continue;

            // cout << "C[wh][ww]=" << C[wh][ww] << endl;

            if (C[wh][ww] == '#')
                continue;

            if (dist[wh][ww] >= 0)
                continue;

            dist[wh][ww] = dist[ch][cw] + 1;
            que.emplace(wh, ww);
        }
    }

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            cout << dist[h][w];
        }
        cout << endl;
    }

    return 0;
}
