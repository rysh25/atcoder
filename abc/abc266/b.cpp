// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    long long N;
    cin >> N;

    long long a = 998244353;
    cout << (N % a + a) % a << endl;

    return 0;
}
