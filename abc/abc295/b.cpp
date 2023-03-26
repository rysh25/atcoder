#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int R, C;
    cin >> R >> C;

    vector<string> B(R);

    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        B[i] = s;
    }

    auto bomb = [&](int i, int j, int b)
    {
        // cout << "i=" << i << ", j=" << j << ", b=" << b << endl;
        B[i][j] = '.';
        for (int ci = i - b; ci <= i + b; ci++)
        {
            for (int cj = j - b; cj <= j + b; cj++)
            {
                if (ci < 0 || cj < 0 || ci >= R || cj >= C)
                    continue;

                // cout << "ci=" << ci << ", cj=" << cj << endl;
                // cout << "abs(i - ci)=" << abs(i - ci) << ",  abs(j - cj)=" << abs(j - cj) << endl;
                if (abs(i - ci) + abs(j - cj) > b)
                    continue;

                if (B[ci][cj] == '#')
                {
                    B[ci][cj] = '.';
                }
            }
        }
    };

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (B[i][j] >= '1' && B[i][j] <= '9')
            {
                // cout << "i=" << i << ", j=" << j << endl;
                bomb(i, j, B[i][j] - '0');
            }
        }
    }

    for (int i = 0; i < R; i++)
    {
        cout << B[i] << endl;
    }

    return 0;
}
