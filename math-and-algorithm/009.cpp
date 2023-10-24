#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include <cmath>
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
    int N, S;
    cin >> N >> S;

    vector<int> A(N);
    rep(i, N) cin >> A[i];

    for (ll bit = 0; bit < (1LL << N); bit++)
    {
        // bitset<60> bs(bit);
        // cout << bs << endl;

        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (bit & (1LL << i))
            {
                sum += A[i];
            }
        }

        if (sum == S)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
