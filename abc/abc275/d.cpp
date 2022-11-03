// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> memo;

long long f(long long k)
{
    if (k == 0)
        return 1;

    if (memo.count(k) > 0)
        return memo[k];

    // cout << "k=" << k << endl;

    memo[k] = f(k / 2) + f(k / 3);
    return memo[k];
}

int main()
{
    long long N;

    cin >> N;

    cout << f(N) << endl;

    return 0;
}
