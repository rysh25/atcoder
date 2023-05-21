#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve_of_eratosthenes(int n)
{
    vector<bool> is_prime(n + 10, true);
    vector<int> primes;
    is_prime[0] = false;
    is_prime[1] = false;

    for (long long i = 2; i <= n; ++i)
    {
        if (!is_prime[i])
            continue;

        primes.emplace_back(i);

        for (long long j = i * i; j <= n; j += i)
        {
            is_prime[j] = false;
        }
    }

    return primes;
}

int main()
{
    long long N;
    cin >> N;

    vector<int> primes = sieve_of_eratosthenes(1e6);

    long long count = 0;

    int m = primes.size();
    for (int ai = 0; ai < m; ai++)
    {
        long long a = primes[ai];
        if (a * a * a * a * a > N)
            break;

        for (int bi = ai + 1; bi < m; bi++)
        {
            long long b = primes[bi];
            if (a * a * b * b * b > N)
                break;

            for (int ci = bi + 1; ci < m; ci++)
            {
                long long c = primes[ci];
                if (a * a * b * c * c > N)
                    break;

                count++;
            }
        }
    }

    cout << count << endl;
}
