// #include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;

    string S;
    cin >> S;

    int ans = 0;

    char c;
    for (int i = 0; i < N - 1; i++)
    {
        if (S[i] != S[i + 1])
            ans++;
    }
    ans++;

    cout << ans << endl;

    return 0;
}
