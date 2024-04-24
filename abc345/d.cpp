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
#include <stack>
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
    int N, H, W;
    cin >> N >> H >> W;

    vector<int> A(N), B(N);

    rep(i, N)
    {
        cin >> A[i] >> B[i];
    }

    vector<vector<bool>> grid(H, vector<bool>(W, false));
    vector<bool> used(N, false);

    auto dfs = [&](auto dfs, vector<vector<bool>> &grid) -> bool
    {
        int count = 0;
        int si = -1, sj = -1;

        bool finished = false;
        rep(i, H)
        {
            rep(j, W)
            {
                if (grid[i][j])
                {
                    count++;
                }
                else
                {
                    si = i, sj = j;
                    finished = true;
                    break;
                }
            }

            if (finished)
                break;
        }

        if (count == H * W)
        {
            return true;
        }

        // cerr << "si=" << si << " sj=" << sj << endl;

        rep(k, N)
        {
            if (used[k])
                continue;

            auto a = A[k], b = B[k];

            rep(x, 2)
            {
                vector<vector<bool>> tmp = grid;
                bool ok = true;
                rep(i, a) rep(j, b)
                {
                    if (si + i >= H || sj + j >= W || tmp[si + i][sj + j])
                    {
                        ok = false;
                        break;
                    }

                    tmp[si + i][sj + j] = true;
                }

                if (ok)
                {
                    // cerr << "k=" << k << " a=" << a << " b=" << b << endl;
                    // cerr << "grid:" << endl;
                    // rep(i, H)
                    // {
                    //     rep(j, W)
                    //     {
                    //         cerr << (tmp[i][j] ? "1" : "0") << " ";
                    //     }
                    //     cerr << endl;
                    // }

                    used[k] = true;
                    if (dfs(dfs, tmp))
                        return true;
                    used[k] = false;
                }

                swap(a, b);
            }
        }

        return false;
    };

    if (dfs(dfs, grid))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
