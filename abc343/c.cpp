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
    ll N;

    cin >> N;

    ll ans = 0;

    auto palindrome = [&](ll n) -> bool
    {
        string s = to_string(n);
        for (ll i = 0; i < s.size() / 2; i++)
        {
            if (s[i] != s[s.size() - 1 - i])
            {
                return false;
            }
        }
        return true;
    };

    for (ll i = 1; i * i * i <= N; i++)
    {
        if (palindrome(i * i * i))
        {
            ans = i * i * i;
        }
    }

    cout << ans << endl;

    return 0;
}
