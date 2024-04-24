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
    string S;
    cin >> S;
    int N = S.size();

    unordered_map<char, int> freq;

    rep(i, N)
    {
        freq[S[i]]++;
    }

    ll sum = 0;
    for (auto [key, count] : freq)
    {
        if (count > 1)
            sum += (ll)count * (count - 1) / 2;
    }

    ll ans = (ll)N * (N - 1) / 2 - sum;

    if (sum > 0)
    {
        // 重複する文字がある場合、重複分は元の文字列と同じになる
        ans++;
    }

    cout << ans << endl;

    return 0;
}
