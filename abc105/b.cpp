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

    for (int i = 0; i * 4 <= N; i++)
    {
        for (int j = 0; j * 7 <= N; j++)
        {
            if (4 * i + 7 * j == N)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
