#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <tuple>
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
    vector<int> T(24);

    rep(i, N)
    {
        int W, X;
        cin >> W >> X;

        for (int t = 9 + X; t < 18 + X; t++)
        {
            T[t % 24] += W;
        }
    }

    sort(T.rbegin(), T.rend());

    cout << T[0] << endl;

    return 0;
}
