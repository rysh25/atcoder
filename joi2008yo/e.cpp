#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int R, C;
    cin >> R >> C;

    int a[10][10000] = {0};

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int tmp;
            cin >> tmp;
            // cout << "i=" << i << ", j=" << j << ", temp=" << tmp << endl;
            // tmp <<= j;
            a[i][j] = tmp;
        }
    }

    int res = 0;
    for (int b = 0; b < 1 << R; b++)
    {
        long long s = 0;
        int tmp[10][10000];

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                tmp[i][j] = a[i][j];
                if (b >> i & 1)
                {
                    tmp[i][j] = !a[i][j];
                }
            }
        }

        int count = 0;
        for (int j = 0; j < C; j++)
        {
            int count_0 = 0;
            int count_1 = 0;
            for (int k = 0; k < R; k++)
            {
                if (tmp[k][j])
                {
                    count_1++;
                }
                else
                {
                    count_0++;
                }
            }
            count += max(count_0, count_1);

            // cout << "j=" << j << ", count=" << count << ", count_0=" << count_0 << ", count_1=" << count_1 << endl;
        }

        res = max(res, count);
    }

    cout << res << endl;

    return 0;
}
