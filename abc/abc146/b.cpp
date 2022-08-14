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

    for (auto &c : S)
    {
        c = (c + N - 'A') % 26 + 'A';
        cout << c;
    }
    cout << endl;

    return 0;
}
