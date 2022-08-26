// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N, M;
    long long T;
    cin >> N >> M >> T;

    vector<long long> A(N - 1);
    map<int, long long> XY;

    for (auto &a : A)
    {
        cin >> a;
    }

    for (int i = 0; i < M; i++)
    {
        int x;
        long long y;
        cin >> x >> y;

        XY[x - 1] = y;
    }

    long long left = T;
    for (int i = 0; i < N - 1; i++)
    {
        if (XY.count(i))
        {
            left += XY[i];
        }
        left -= A[i];

        if (left <= 0)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
