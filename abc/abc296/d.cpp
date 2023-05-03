#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long N, M;
    cin >> N >> M;

    const long long INF = 1e18;
    long long ans = INF;

    for (long long a = 1; a * a - a <= M; a++)
    {
        long long b = (M + a - 1) / a; // 切り上げ
        // cout << "a=" << a << ", b=" << b << ", M/a=" << (M + a - 1) / a << endl;
        if (a > N || b > N)
            continue;

        ans = min(ans, a * b);
    }

    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}
