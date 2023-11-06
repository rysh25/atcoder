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

    vector<string> S(N);
    vector<int> T(N);

    vector<bool> originals(N, false);

    rep(i, N)
    {
        cin >> S[i] >> T[i];
    }

    set<string> st;

    rep(i, N)
    {
        if (st.count(S[i]) == 0)
        {
            originals[i] = true;
        }
        st.insert(S[i]);
    }

    int max_score = 0;
    int best_index = 0;
    rep(i, N)
    {
        if (originals[i])
        {
            // cout << "original=" << i << endl;
            if (max_score < T[i])
            {
                max_score = T[i];
                best_index = i;
            }
        }
    }

    cout << best_index + 1 << endl;

    return 0;
}
