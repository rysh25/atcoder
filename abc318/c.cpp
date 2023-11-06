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
    int N, D, P;
    cin >> N >> D >> P;

    vector<int> F(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> F[i];
    }

    sort(F.rbegin(), F.rend());

    ll ans = 0;
    ll cost = 0;
    int days = 0;
    for (int i = 0; i < N; ++i)
    {
        days++;
        cost += F[i];
        // cout << "F[i]: " << F[i] << endl;
        // cout << "cost: " << cost << endl;
        if (days == D)
        {
            // cout << "days: " << days << endl;
            if (cost >= P)
            {
                // cout << "cost >= P" << endl;
                ans += P;
                // cout << "ans: " << ans << endl;
            }
            else
            {
                // cout << "cost < P" << endl;
                ans += cost;
                // cout << "ans: " << ans << endl;
            }
            cost = 0;
            days = 0;
        }
    }
    if (cost >= P)
    {
        // cout << "cost >= P" << endl;
        ans += P;
        // cout << "ans: " << ans << endl;
    }
    else
    {
        // cout << "cost < P" << endl;
        ans += cost;
        // cout << "ans: " << ans << endl;
    }

    cout << ans << endl;

    return 0;
}
