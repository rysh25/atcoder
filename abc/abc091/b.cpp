// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;

    // vector<string> S;
    string S[N];

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
        // string s;
        // cin >> s;
        // S.push_back(s);
    }

    int M;
    cin >> M;

    // vector<string> T;
    string T[M];

    for (int i = 0; i < M; i++)
    {
        cin >> T[i];
        // string t;
        // cin >> t;
        // T.push_back(t);
    }

    int ans = 0;

    for (int i = 0; i < N - 1; i++)
    {
        int amount = 0;
        for (int j = i; j < N; j++)
        {
            // cout << "S[" << j << "]=" << S[j] << endl;
            if (S[i] == S[j])
                amount++;
        }
        for (int j = 0; j < M; j++)
        {
            if (S[i] == T[j])
                amount--;
        }
        ans = max(ans, amount);
    }

    cout << ans << endl;

    return 0;
}
