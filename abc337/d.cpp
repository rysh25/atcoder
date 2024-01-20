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
    int H, W, K;
    cin >> H >> W >> K;

    vector<string> S(H);

    rep(h, H) cin >> S[h];

    vector<int> r_o_streak(W, 0);
    vector<int> r_d_streak(W, 0);
    vector<queue<int>> r_o_index(W, queue<int>());

    int c_ans = 1e9 + 1;
    int r_ans = 1e9 + 1;

    rep(h, H)
    {
        int c_o_streak = 0;
        int c_d_streak = 0;
        queue<int> c_o_index;
        rep(w, W)
        {
            // cout << S[h][w]; // debug

            if (!c_o_index.empty() && c_o_index.front() + K <= w)
            {
                // cout << "!!c_o_index.front()=" << c_o_index.front() << ", w=" << w << "!!" << endl; // debug
                c_o_streak--;
                c_o_index.pop();
            }

            if (!r_o_index[w].empty() && r_o_index[w].front() + K <= h)
            {
                // cout << "!!r_o_index[" << w << "].front()=" << r_o_index[w].front() << ", h=" << h << ", w=" << w << "!!" << endl; // debug
                r_o_streak[w]--;
                r_o_index[w].pop();
            }

            if (S[h][w] == 'o')
            {
                c_o_index.push(w);
                // cout << "!!c_o_index.push(" << w << ")!!" << endl; // debug
                r_o_index[w].push(h);
                // cout << "!!r_o_index[" << w << "].push(" << h << ")!!" << endl; // debug
                c_o_streak++;
                r_o_streak[w]++;
            }
            else if (S[h][w] == 'x')
            {
                c_o_streak = 0;
                c_d_streak = 0;
                c_o_index = queue<int>();

                r_o_streak[w] = 0;
                r_d_streak[w] = 0;
                r_o_index[w] = queue<int>();
            }
            else
            {
                c_d_streak++;
                r_d_streak[w]++;
            }

            if (c_o_streak + c_d_streak >= K)
            {
                // cout << "!!cK("
                //      << "h=" << h << ", w=" << w << ")!!, c_d_streak=" << c_d_streak << endl; // debug
                c_ans = min(c_ans, max(0, K - c_o_streak));
            }
        }

        rep(w, W)
        {
            if (r_o_streak[w] + r_d_streak[w] >= K)
            {
                // cout << "!!rK("
                //      << "h=" << h << ", w=" << w << ")!!, r_d_streak[w]=" << r_d_streak[w] << ", K - r_o_streak[w]=" << K - r_o_streak[w] << endl; // debug
                r_ans = min(r_ans, max(0, K - r_o_streak[w]));
            }
        }
    }

    // cout << "c_ans=" << c_ans << ", r_ans=" << r_ans << endl; // debug

    int ans = min(c_ans, r_ans);

    std::cout << (ans >= 1e9 + 1 ? -1 : ans) << endl;

    return 0;
}
