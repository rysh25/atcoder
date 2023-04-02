#include <iostream>
#include <algorithm>

using namespace std;

long long find_minimum_x(long long n, long long m)
{
    long long min_x = n * n + 1;

    for (long long a = 1; a <= n; ++a)
    {
        long long b = (m + a - 1) / a;
        if (1 <= b && b <= n)
        {
            min_x = min(min_x, a * b);
        }
    }

    return min_x <= n * n ? min_x : -1;
}

int main()
{
    long long n, m;
    cin >> n >> m;

    cout << find_minimum_x(n, m) << endl;

    return 0;
}
