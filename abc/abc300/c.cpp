#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    int N = min(H, W);

    vector<string> C;

    for (int i = 0; i < H; i++)
    {
        string s;
        cin >> s;
        C.push_back(s);
    }

    vector<int> S(N + 1, 0);

    for (int a = 0; a < H; a++)
    {
        for (int b = 0; b < W; b++)
        {
            if (C[a][b] == '#')
            {
                int d = 0;
                for (d = 0; d <= N; d++)
                {
                    vector<pair<int, int>> dd = {{a + d, b + d}, {a + d, b - d}, {a - d, b + d}, {a - d, b - d}};
                    bool x = true;
                    for (auto [i, j] : dd)
                    {
                        if (0 > i || i >= H || 0 > j || j >= W)
                        {
                            x = false;
                            break;
                        }
                        else if (C[i][j] != '#')
                        {
                            x = false;
                            break;
                        }
                        // cout << "C[" << i << "][" << j << "]" << C[i][j] << endl;
                    }

                    if (!x)
                        break;
                }

                if (d - 1 > 0)
                {
                    // cout << "d=" << d << endl;
                    S[d - 1]++;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << S[i] << " ";
    }

    cout << endl;

    return 0;
}
