// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <sort>

using namespace std;

int main()
{
    int N, M;

    vector<int> A(N);

    for (auto &a : A)
    {
        cin >> a;
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++)
    {
        A[i] += ((i + 1) * M);

    }


    return 0;
}
