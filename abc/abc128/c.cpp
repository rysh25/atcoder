#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> lights(M, vector<bool>(N, false));

    vector<int> p(M);

    for (int i = 0; i < M; i++)
    {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            int s;
            cin >> s;
            s--;
            lights[i][s] = true;
        }
    }

    // cout << "lights:" << endl;
    // for (int i = 0; i < M; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << lights[i][j];
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < M; i++)
    {
        cin >> p[i];
    }

    int res = 0;
    for (int i = 0; i < 1 << N; i++)
    {
        // cout << "*i=" << bitset<10>(i) << endl;
        // cout << "*i=" << i << ":" << endl;

        int light = 0;
        for (int k = 0; k < M; k++)
        {
            // cout << "k=" << k << ":" << endl;
            int on = 0;
            for (int j = 0; j < N; j++)
            {
                // cout << "j=" << j << ":" << endl;
                if (((i >> j) & 1) == 1)
                {
                    if (lights[k][j])
                    {
                        // cout << "lights: k=" << k << ", i=" << i << endl;
                        on++;
                    }
                }
            }

            if (on % 2 == p[k])
            {
                light++;
                // cout << "light=" << light << ", on=" << on << endl;
            }
        }

        if (light == M)
        {
            res++;
            // cout << "!res=" << res << endl;
        }
    }

    cout << res << endl;

    return 0;
}
