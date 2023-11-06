#include <iostream>
#include <vector>

using namespace std;

long long pow(int x, long long n, int m)
{
    long long ret = 1;
    while (n > 0)
    {
        if (n & 1)
            ret *= x % m;
        x *= x % m;
        n >>= 1;
    }
    return ret;
}

int main()
{
    int A, M;
    long long X;
    cin >> A >> X >> M;

    long long res = (((pow(A, X, M) - 1) % M) / (A - 1));

    cout << "pow=" << pow(A, X, M) << endl;
    cout << "pow=" << (pow(A, X, M) - 1) % M << endl;
    cout << "A-1=" << A - 1 << endl;
    cout << res << endl;
    cout << (res % M + M) % M << endl;

    return 0;
}
