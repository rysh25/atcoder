#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N, K, P;
    cin >> N >> K >> P;
    vector<int> C(N);
    vector<vector<int>> A(N, vector<int>(K, 0));

    rep(i, N)
    {
        cin >> C[i];
        rep(j, K)
        {
            cin >> A[i][j];
        }
    }

    return 0;
}
