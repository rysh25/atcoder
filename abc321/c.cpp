#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int K;
    cin >> K;

    queue<long long> q;
    for (int i = 1; i <= 9; i++)
    {
        q.push(i);
    }

    for (int i = 1; i < K; i++)
    {
        long long x = q.front();
        q.pop();

        int last_digit = x % 10;

        for (int j = 0; j < last_digit; j++)
        {
            q.push(10 * x + j);
        }
    }

    cout << q.front() << endl;

    return 0;
}
