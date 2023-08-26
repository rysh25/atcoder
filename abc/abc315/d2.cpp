#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    vector<string> c(H);

    for (int i = 0; i < H; i++)
    {
        cin >> c[i];
    }

    vector<int> deletedRows, deletedCols;

    int ans = H * W;
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (int i = 0; i < H; i++)
        {
            if (find(deletedRows.begin(), deletedRows.end(), i) != deletedRows.end())
                continue;

            char firstColor = 0;
            bool allSame = true;
            int count_color = 0;
            for (int j = 0; j < W && allSame; j++)
            {
                if (find(deletedCols.begin(), deletedCols.end(), j) != deletedCols.end())
                    continue;

                count_color++;
                if (firstColor == 0)
                {
                    firstColor = c[i][j];
                }
                else if (firstColor != c[i][j])
                {
                    allSame = false;
                }
            }
            if (allSame && firstColor != 0 && count_color > 1)
            {
                deletedRows.push_back(i);
                changed = true;
            }
        }

        for (int j = 0; j < W; j++)
        {
            if (find(deletedCols.begin(), deletedCols.end(), j) != deletedCols.end())
                continue;

            char firstColor = 0;
            bool allSame = true;
            int count_color = 0;
            for (int i = 0; i < H && allSame; i++)
            {
                if (find(deletedRows.begin(), deletedRows.end(), i) != deletedRows.end())
                    continue;

                count_color++;
                if (firstColor == 0)
                {
                    firstColor = c[i][j];
                }
                else if (firstColor != c[i][j])
                {
                    allSame = false;
                }
            }

            if (allSame && firstColor != 0 && count_color > 1)
            {
                deletedCols.push_back(j);
                changed = true;
            }
        }
    }

    ans -= (deletedRows.size() * W) + (deletedCols.size() * H) - (deletedRows.size() * deletedCols.size());
    cout << ans << endl;

    return 0;
}
