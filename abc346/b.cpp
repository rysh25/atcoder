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
    int W, B;
    cin >> W >> B;

    string piano = "wbwbwwbwbwbw";

    int init_w = 7;
    int init_b = 5;

    // W %= init_w;
    // B %= init_b;

    int l = 0;

    int len = piano.size() * 15;

    rep(i, len)
    {
        int w_size = 0;
        int b_size = 0;
        for (int j = i; j < len; j++)
        {
            if (piano[j % piano.size()] == 'w')
            {
                w_size++;
            }
            else
            {
                b_size++;
            }

            if (w_size == W && b_size == B)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
