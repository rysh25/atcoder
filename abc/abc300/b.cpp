#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<string> A(H);
    vector<string> B(H);

    for (int i = 0; i < H; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < H; i++)
    {
        cin >> B[i];
    }

    vector<string> C(H, string(W, ' '));

    auto f = [&](auto f) -> bool
    {
        bool ret = true;
        for (int i = 0; i < H; i++)
        {
            if (C[i] != B[i])
            {
                // cout << "C[i]=" << C[i] << ", B[i]=" << B[i] << endl;
                ret = false;
                break;
            }
        }

        return ret;
    };

    int di = 0, dj = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {

            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    // cout << "i=" << i << ", j=" << j << endl;
                    // cout << "di=" << di << ", dj=" << dj << endl;
                    // cout << "i + di % H=" << i + di % H << ", j + dj % W=" << j + dj % W << endl;
                    // cout << "A[i][j]" << A[i][j] << endl;
                    C[(i + di) % H][(j + dj) % W] = A[i][j];
                    // cout << "C[(i + di) % H][(j + dj) % W]" << C[(i + di) % H][(j + dj) % W] << endl;
                }
                // cout << "A[i]=" << A[i] << ", B[i]=" << B[i] << ", C[i]=" << C[i] << endl;
            }

            // for (int i = 0; i < H; i++)
            // {
            //     cout << "C[i]=" << C[i] << endl;
            // }

            if (f(f))
            {
                cout << "Yes" << endl;
                return 0;
            }

            dj++;
        }
        di++;
    }

    cout << "No" << endl;
    return 0;
}
