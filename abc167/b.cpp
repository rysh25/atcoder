// #include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    int a_count = min(K, A);
    int b_count = min(K - a_count, B);
    int c_count = min(K - a_count - b_count, C);

    cout << (a_count * 1) + (c_count * -1) << endl;

    return 0;
}
