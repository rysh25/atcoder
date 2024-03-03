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
    int N, T;
    cin >> N >> T;

    vector<int> A(T);
    vector<int> B(T);

    vector<ll> P(N, 0);

    map<ll, int> mp;
    set<ll> st;

    mp[0] = N;
    st.insert(0);

    rep(i, T)
    {
        cin >> A[i] >> B[i];
        A[i]--;
    }

    rep(i, T)
    {
        if (mp[P[A[i]]] == 0)
        {
            // cout << "error: i=" << i << endl;
        }
        mp[P[A[i]]]--;
        if (mp[P[A[i]]] == 0)
        {
            st.erase(P[A[i]]);
        }

        P[A[i]] += B[i];

        mp[P[A[i]]]++;
        st.insert(P[A[i]]);

        cout << st.size() << endl;
    }

    return 0;
}
