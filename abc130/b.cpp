#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main()
{
    int N, X;
    cin >> N >> X;

    int count = 1;

    int D = 0;
    rep(i, N)
    {
        int L;
        cin >> L;
        // cout << "L=" << L << ", ";
        D += L;
        // cout << "D=" << D << ", ";
        // cout << "X=" << X << endl;
        if (D > X)
        {
            break;
        }
        count++;
    }

    cout << count << endl;

    return 0;
}
