#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

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

    vector<bool> validRows(H, true), validCols(W, true);

    int ans = H * W;
    // cout << "ans: " << ans << endl;
    bool changed = true;
    int deletedRows = 0;
    int deletedCols = 0;
    while (changed)
    {
        set<int> rowsToDelete, colsToDelete;

        changed = false;
        for (int i = 0; i < H; i++)
        {
            if (!validRows[i])
                continue;

            char firstColor = 0;
            bool allSame = true;
            int count_color = 0;
            for (int j = 0; j < W; j++)
            {
                // cout << "row: i = " << i << ", j = " << j << endl;
                // cout << "c[" << i << "][" << j << "] = " << c[i][j] << endl;
                if (validCols[j])
                {
                    count_color++;
                    if (firstColor == 0)
                    {
                        firstColor = c[i][j];
                    }
                    else if (firstColor != c[i][j])
                    {
                        allSame = false;
                        break;
                    }
                }
            }
            if (allSame && firstColor != 0 && count_color > 1)
            {
                rowsToDelete.insert(i);
                changed = true;
            }
        }

        for (int j = 0; j < W; j++)
        {
            if (!validCols[j])
                continue;
            char firstColor = 0;
            bool allSame = true;
            int count_color = 0;
            for (int i = 0; i < H; i++)
            {
                // cout << "col: i = " << i << ", j = " << j << endl;
                // cout << "c[" << i << "][" << j << "] = " << c[i][j] << endl;
                if (validRows[i])
                {
                    count_color++;
                    if (firstColor == 0)
                    {
                        firstColor = c[i][j];
                    }
                    else if (firstColor != c[i][j])
                    {
                        allSame = false;
                        break;
                    }
                }
            }

            if (allSame && firstColor != 0 && count_color > 1)
            {
                colsToDelete.insert(j);
                changed = true;
            }
        }

        for (int row : rowsToDelete)
        {
            // cout << "rowsToDelete: " << row << endl;
            validRows[row] = false;
            ans -= (W - deletedCols);
            // cout << "ans: " << ans << endl;
            deletedRows++;
        }
        for (int col : colsToDelete)
        {
            // cout << "colsToDelete: " << col << endl;
            validCols[col] = false;
            ans -= (H - deletedRows);
            // cout << "ans: " << ans << endl;
            deletedCols++;
        }
        // cout << "ans: " << ans << endl;
    }

    std::cout << ans << endl;

    return 0;
}
