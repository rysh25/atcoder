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
    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<pair<int, int>> win(N, make_pair(0, 0));
    rep(i, N) win[i].second = i + 1;

    rep(i, N) rep(j, N)
    {
        if (S[i][j] == 'o')
        {
            win[i].first--;
        }
    }

    // cout << "win: " << endl;
    // rep(i, N)
    // {
    //     cout << win[i].first << " ";
    // }
    // cout << endl;
    sort(win.begin(), win.end());

    rep(i, N)
    {
        cout << win[i].second << " ";
    }
    cout << endl;

    return 0;
}
