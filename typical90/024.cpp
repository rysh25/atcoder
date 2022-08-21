// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main()
{
    int N, K;

    cin >> N >> K;

    int A[N];
    int B[N];

    int diff = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }

    for (int i = 0; i < N; i++)
    {
        diff += abs(A[i] - B[i]);
    }

    if (diff <= K && (K - diff) % 2 == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
