// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N);

    for (auto &a : A)
    {
        cin >> a;
    }
    sort(A.begin(), A.end());

    int maxOdd = -1;
    int maxOdd2 = -1;
    int maxEven = -1;
    int maxEven2 = -1;

    for (int i = N - 1; i >= 0; i--)
    {
        if (A[i] % 2 == 0)
        {
            if (maxEven == -1)
            {
                maxEven = A[i];
            }
            else if (maxEven2 == -1)
            {
                maxEven2 = A[i];
            }
        }
        else
        {
            if (maxOdd == -1)
            {
                maxOdd = A[i];
            }
            else if (maxOdd2 == -1)
            {
                maxOdd2 = A[i];
            }
        }
    }

    int res = -1;

    if (maxEven != -1 &&
        maxEven2 != -1)
    {
        res = maxEven + maxEven2;
    }

    if (maxOdd != -1 &&
        maxOdd2 != -1)
    {
        res = max(res, maxOdd + maxOdd2);
    }

    cout << res << endl;

    return 0;
}
