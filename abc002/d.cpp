#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int conn[12][12] = {0};

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        conn[x][y] = conn[y][x] = 1;
    }

    int res = 0;
    for (int i = 0; i < (1 << N); i++)
    {
        bool ok = true;
        // cout << "i=" << bitset<32>(i) << endl;
        int count = bitset<32>(i).count();
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (i >> j & i >> k & 1 && conn[j][k])
                {
                    // cout << "j=" << j << ", k=" << k << endl;
                }

                if (j != k && i >> j & i >> k & 1 && !conn[j][k])
                {
                    // cout << "NG: j=" << j << ", k=" << k << endl;
                    ok = false;
                }
            }
        }

        if (ok)
        {
            // cout << "OK" << endl;
            res = max(res, count);
        }
    }

    cout << res << endl;
}
