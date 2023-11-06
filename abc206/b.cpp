#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;
// using P = pair<int, int>;
// using Graph = vector<vector<int>>;
// using mint = modint1000000007;

int main()
{
    int n;
    cin >> n;

    int saving = 0;
    int i = 1;
    while (saving < n)
    {
        saving += i;
        i++;
    }

    cout << i - 1 << endl;

    return 0;
}
