// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int N;

    cin >> N;

    long long res = 0;
    for (int i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;
        long long n = B - A + 1;
        res += (A + B) * n / 2;
    }

    cout << res << endl;

    return 0;
}
