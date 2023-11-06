// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (auto &a : A)
    {
        cin >> a;
    }
    for (auto &b : B)
    {
        cin >> b;
    }

    int res = 0;
    for (int i = 0; i < N; i++)
    {
        res += A[i] * B[i];
    }

    // cout << res << endl;
    cout << (res == 0 ? "Yes" : "No") << endl;

    return 0;
}
