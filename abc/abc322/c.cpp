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
    int N, M;
    cin >> N >> M;

    vector<int> A(M);
    rep(i, M) cin >> A[i], A[i]--;

    vector<int> fire(N, 0);

    int fire_idx = N - 1, a_idx = M - 1;

    int days = 0;
    while (fire_idx >= 0)
    {
        if (a_idx >= 0 && fire_idx == A[a_idx])
        {
            // cout << "!!!fire_idx == A[a_idx]" << endl;
            days = 0;
            fire[fire_idx] = days;
            fire_idx--;
            a_idx--;
        }
        else
        {
            days++;
            fire[fire_idx] = days;
            fire_idx--;
        }
    }

    rep(i, N) cout << fire[i] << '\n';

    return 0;
}
