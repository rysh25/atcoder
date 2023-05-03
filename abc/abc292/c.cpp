#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long f(int x)
{
    long long res = 0;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i != 0)
            continue;
        int j = x / i;
        if (i == j)
            res++;
        else
            res += 2;
    }

    return res;
}

int main()
{
    int N;

    cin >> N;

    long long ans = 0;
    for (int x = 0; x < N; x++)
    {
        ans += f(x) * f(N - x);
    }

    cout << ans << endl;

    return 0;
}
