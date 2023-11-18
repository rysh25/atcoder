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
    int N, M;
    cin >> N >> M;

    vector<int> A(M);

    priority_queue<tuple<int, int>> pq;

    rep(i, M)
    {
        cin >> A[i];
    }

    vector<int> votes(N, 0);
    int maxVotes = 0, winner = 1;

    for (int i = 0; i < M; ++i)
    {
        // cout << "i: " << i << ", A[i]=" << A[i] << endl;
        votes[A[i] - 1]++;

        if (votes[A[i] - 1] > maxVotes || (votes[A[i] - 1] == maxVotes && winner > A[i]))
        {
            // cout << "maxVotes=" << maxVotes << ", votes[A[i] - 1]: " << votes[A[i] - 1] << endl;
            maxVotes = votes[A[i] - 1];
            winner = A[i];
        }

        cout << winner << endl;
    }

    return 0;
}
