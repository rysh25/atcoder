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
    int N, P;
    cin >> N >> P;

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;

        if (a < P)
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
