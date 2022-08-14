// #include <bits/stdc++.h>
#include <iostream>

using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i < 10; i++)
    {
        for (int j = i; j < 10; j++)
        {
            if (i * j == N)
            {
                // cout << "i=" << i << ", j=" << j << endl;
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
