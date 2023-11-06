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
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a : A)
    {
        cin >> a;
    }
    int ans = 0;

    while (true)
    {
        for (auto &a : A)
        {
            if (a % 2 != 0)
            {
                cout << ans << endl;

                return 0;
            }
            a /= 2;
        }
        ans++;
    }

    cout << ans << endl;

    return 0;
}
