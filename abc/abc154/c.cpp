// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int N;
    cin >> N;

    set<int> exist;

    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;

        exist.insert(A);
    }

    if (exist.size() == N)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
