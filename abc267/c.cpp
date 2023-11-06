// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<long long> A(N);

    for (auto &a : A)
    {
        cin >> a;
    }

    long long s = 0, t = 0;
    for (int i = 0; i < M; i++)
    {
        s += A[i] * (i + 1);
    }

    for (int i = 0; i < M; i++)
    {
        t += A[i];
    }

    long long ans = s;

    for (int i = 0; i < N - M; i++)
    {
        long long ns = s - t + A[i + M] * M;
        long long nt = t - A[i] + A[i + M];
        s = ns;
        t = nt;
        ans = max(ans, s);
    }

    return 0;
}
