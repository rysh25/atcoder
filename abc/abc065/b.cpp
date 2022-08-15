// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int a[N];

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    int j = 1;
    int i = 0;
    for (;; i++)
    {
        if (a[j - 1] == 2)
        {
            break;
        }
        j = a[j - 1];
        if (i >= N)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << i + 1 << endl;
    return 0;
}
