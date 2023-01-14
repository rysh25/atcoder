#include <iostream>

using namespace std;

template <typename T>
T gcd(T x, T y) { return (x % y) ? gcd(y, x % y) : y; }

int main()
{
    long long A, B;
    cin >> A >> B;

    cout << gcd(A, B);
}
