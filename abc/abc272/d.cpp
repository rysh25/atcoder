// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int a = i * i + j * j;
            cout << floor(sqrt(a / )) << " ";
        }
        cout << endl;
    }

    return 0;
}
