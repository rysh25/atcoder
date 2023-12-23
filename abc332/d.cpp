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
    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> B(H, vector<int>(W));
    rep(h, H) rep(w, W)
    {
        cin >> A[h][w];
    }
    rep(h, H) rep(w, W)
    {
        cin >> B[h][w];
    }

    cout << "A:" << endl;
    rep(h, H)
    {
        rep(w, W)
        {
            cout << A[h][w] << " ";
        }
        cout << endl;
    }
    cout << "B:" << endl;
    rep(h, H)
    {
        rep(w, W)
        {
            cout << B[h][w] << " ";
        }
        cout << endl;
    }

    vector<int> dist(10, 0);
    vector<int> dist_h(5, 0);
    vector<int> dist_w(5, 0);

    rep(ah, H) rep(aw, W)
    {
        bool match = false;
        rep(bh, H) rep(bw, W)
        {
            if (A[ah][aw] == B[bh][bw])
            {
                dist[abs(ah - bh) + abs(aw - bw)]++;
                dist_h[abs(ah - bh)]++;
                dist_w[abs(aw - bw)]++;
                match = true;
            }
        }
        if (!match)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    // rep(i, 10)
    // {
    //     cout << "dist[" << i << "]=" << dist[i] << endl;
    // }

    int h_count = 0;
    int h_times = 0;
    int w_count = 0;
    int w_times = 0;
    cout << "H=" << H << ", W=" << W << endl;
    rep(i, 5)
    {
        cout << "dist_h[" << i << "]=" << dist_h[i] << endl;
        h_count += dist_h[i];
        h_times += (dist_h[i] / (W * 2)) * i;
    }
    rep(i, 5)
    {
        cout << "dist_w[" << i << "]=" << dist_w[i] << endl;
        w_count += dist_w[i];
        w_times += (dist_w[i] / (H * 2)) * i;
    }

    cout << "h_count=" << h_count << ", w_count=" << w_count << endl;
    cout << "h_times=" << h_times << ", w_times=" << w_times << endl;

    return 0;
}
