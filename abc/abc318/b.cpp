#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N;
    cin >> N;

    vector<vector<bool>> G(100, vector<bool>(100, false));

    for (int i = 0; i < N; i++)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        for (int r = A; r < B; r++)
        {
            for (int c = C; c < D; c++)
            {
                G[r][c] = true;
            }
        }
    }

    int ans = 0;
    for (int r = 0; r < 100; r++)
    {
        for (int c = 0; c < 100; c++)
        {
            if (G[r][c])
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
