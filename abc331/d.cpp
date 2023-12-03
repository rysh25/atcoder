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
    int N, Q;
    cin >> N >> Q;

    vector<string> P(N);
    rep(i, N) cin >> P[i];

    vector<vector<int>> sum(N, vector<int>(N + 1, 0));

    rep(i, N)
    {
        rep(j, N)
        {
            if (P[i][j] == 'B')
            {
                sum[i][j + 1] = sum[i][j] + 1;
            }
            else
            {
                sum[i][j + 1] = sum[i][j];
            }
        }
    }

    // cout << "sum: " << endl;
    // rep(i, N)
    // {
    //     rep(j, N + 1)
    //     {
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    rep(q, Q)
    {
        ll ans = 0;
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        // cout << "q=" << q << ", A=" << A << ", B=" << B << ", C=" << C << ", D=" << D << endl;

        int a = A % N;
        int c = C % N;
        // cout << "a=" << a << ", c=" << c << endl;

        int count = C / N - (A + N - 1) / N;
        cout << "count=" << count << endl;

        for (int aa = 0; aa < N; aa++)
        {
            cout << "N=" << N << ", aa=" << aa << ", B=" << B << ", C=" << C << ", D=" << D << endl;
            int b = B % N + 1;
            int d = D % N + 1;
            // cout << "b=" << b << ", d=" << d << endl;
            int x = 0;
            if (d > b)
            {
                x = ((ll)sum[aa][d] - (ll)sum[aa][b - 1]);
            }
            else
            {
                x = ((ll)sum[aa][N] - (ll)sum[aa][b - 1] + (ll)sum[aa][d]);
            }

            ll wk = count;
            if (aa <= a)
            {
                wk++;
            }

            if (aa <= c)
            {
                wk++;
            }

            x *= wk;
            cout << "wk=" << wk << endl;

            ans += x;

            cout << "ans=" << ans << endl;
        }

        cout << ans << endl;
    }

    return 0;
}
