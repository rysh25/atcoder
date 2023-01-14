#include <iostream>

using namespace std;

template <typename T>
bool is_prime(T N)
{
    if (N == 1)
        return false;
    for (T i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}
int main()
{
    long long N;
    cin >> N;
    if (is_prime(N))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
