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

    deque<char> q;

    stack<int> streaks;
    string ABC = "ABC";
    for (int i = 0; i < S.size(); i++)
    {
        // cout << "i=" << i << ", S[i]=" << S[i] << endl;
        q.push_back(S[i]);
        if (q.back() == ABC[0])
        {
            // cout << "push 1" << endl;
            streaks.push(1);
        }
        else if (!streaks.empty() && q.back() == ABC[streaks.top()])
        {
            streaks.top()++;
            // cout << "++" << endl;
            while (!streaks.empty() && streaks.top() == 3)
            {
                q.pop_back();
                q.pop_back();
                q.pop_back();

                // cout << "pop " << streaks.top() << endl;
                streaks.pop();
            }
        }
        else
        {
            // cout << "push 0" << endl;
            streaks.push(0);
        }
    }

    for (int i = 0; i < q.size(); i++)
    {
        cout << q[i];
    }
    cout << endl;

    return 0;
}
