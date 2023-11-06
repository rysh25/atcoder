// #include <bits/stdc++.h>
#include <iostream>
#include <string>
// #include <set>
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

    string S;
    cin >> S;

    // set<char> found;

    int ans = 0;
    for (int i = 1; i < N; i++)
    {
        // int num = 0;
        // found.clear();
        string X = S.substr(0, i);
        string Y = S.substr(i, N - i);

        vector<bool> found(26, false);

        // cout << "X=" << X << ", Y=" << Y << endl;
        for (auto &c : X)
        {
            // cout << "c=" << c << "Y.find(c)=" << Y.find(c) << endl;

            if ( // found.find(c) == found.end() &&
                Y.find(c) != string::npos)
            {
                // cout << "Found" << endl;
                // found.insert(c);
                found[c - 'a'] = true;
                // num++;
            }
        }
        int sum = 0;
        for (bool i : found)
            sum += i;
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
