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
    string S;
    cin >> S;

    sort(S.begin(), S.end());

    ll max_value = pow(10, N);
    ll ans = 0;
    // cout << "max_value=" << max_value << endl;
    for (ll i = 0; i * i < max_value; i++)
    {
        string T = to_string(i * i);
        // cout << "T=" << T << endl;
        T.resize(N, '0');
        sort(T.begin(), T.end());
        // cout << "T=" << T << endl;
        if (S == T)
        {
            ans++;
        }
        // cout << "i=" << i << ", i*i=" << i * i << endl;
    }

    cout << ans << endl;

    return 0;
}
