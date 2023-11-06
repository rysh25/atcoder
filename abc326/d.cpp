#include <iostream>
#include <iomanip>
#include <sstream>
#include <list>
#include <utility>
#include <string>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <cstring>
// #include <cstdlib>
#include <limits>
#include <algorithm>
#include <functional>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N;
    string R, C;
    cin >> N >> R >> C;

    vector<string> grid(N, string(N, '.'));
    // for (int i = 0; i < N; i++)
    // {
    //     grid[i][0] = R[i];
    //     grid[0][i] = C[i];
    // }

    const auto check = [&](const vector<string> &grid) -> bool
    {
        string r, c;

        rep(i, N) rep(j, N)
        {
            if (grid[i][j] != '.')
            {
                r += grid[i][j];
                break;
            }
        }

        rep(j, N) rep(i, N)
        {
            if (grid[i][j] != '.')
            {
                c += grid[i][j];
                break;
            }
        }

        if (r != R || c != C)
            return false;

        return true;
    };

    const auto solve = [&](auto &&solve, char c, vector<string> grid) -> bool
    {
        // cout << "c=" << c << endl;

        if (c == 'D')
        {
            if (check(grid))
            {
                cout << "Yes" << endl;
                for (const auto &row : grid)
                    cout << row << endl;
                return true;
            }
            else
            {
                return false;
            }
        }

        vector<int> p(N);
        rep(i, N) p[i] = i;

        do
        {
            auto tmp = grid;

            bool ok = true;
            rep(i, N)
            {
                if (tmp[i][p[i]] != '.')
                {
                    ok = false;
                    break;
                }
                tmp[i][p[i]] = c;
            }

            // cout << "tmp:" << endl;
            // for (const auto &row : tmp)
            //     cout << row << endl;
            // cout << endl;

            if (!ok)
                continue;

            if (solve(solve, c + 1, tmp))
                return true;

        } while (next_permutation(p.begin(), p.end()));

        return false;
    };

    if (!solve(solve, 'A', grid))
    {
        cout << "No" << endl;
    }
    return 0;
}
