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
#include <cstdlib>
#include <limits>
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
    int N;
    cin >> N;

    deque<pair<ll, ll>> events;
    ll max_t = 0;
    for (int i = 0; i < N; ++i)
    {
        ll T, D;
        cin >> T >> D;
        events.emplace_back(T, T + D);
        max_t = max(max_t, T + D);
    }

    sort(events.begin(), events.end());

    priority_queue<ll, vector<ll>, greater<ll>> printing;

    // cout << "max_t=" << max_t << endl;
    ll t = 0;
    ll ans = 0;
    while (true)
    {
        // cout << "t=" << t << ", ans=" << ans << endl;
        while (!events.empty() && events.front().first <= t)
        {
            // cout << "push " << events.front().second << endl;
            printing.push(events.front().second);
            events.pop_front();
        }

        while (!printing.empty() && printing.top() < t)
        {
            // cout << "pop " << printing.top() << endl;
            printing.pop();
        }

        if (printing.empty())
        {
            if (events.empty())
                break;
            else
                t = events.front().first;
        }
        else if (printing.top() >= t)
        {
            // cout << "print: " << printing.top() << endl;
            printing.pop();
            ans++;
            t++;
        }
    }

    cout << ans << endl;
    return 0;
}
