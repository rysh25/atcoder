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
    rep(h, H)
        rep(w, W)
    {
        cin >>
            A[h][w];
    }
    rep(h, H)
        rep(w, W)
    {
        cin >>
            B[h][w];
    }

    auto is_same = [&](vector<vector<int>> &A, vector<vector<int>> &B)
    {
        rep(h, H)
            rep(w, W)
        {
            if (A[h][w] != B[h][w])
                return false;
        }
        return true;
    };

    auto swap_next_row = [&](vector<vector<int>> &A, int h)
    {
        rep(w, W)
        {
            swap(A[h][w], A[h + 1][w]);
        }
    };

    auto swap_next_col = [&](vector<vector<int>> &A, int w)
    {
        rep(h, H)
        {
            swap(A[h][w], A[h][w + 1]);
        }
    };



    return 0;
}
