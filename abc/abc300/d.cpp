#include <iostream>
#include <vector>

using namespace std;

vector<bool> sieve_of_eratosthenes(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

vector<int> get_primes_up_to(int n)
{
    vector<bool> is_prime = sieve_of_eratosthenes(n);
    vector<int> primes;

    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }

    return primes;
}

int main()
{
    long long N;
    cin >> N;

    int sqrt_n = static_cast<int>(sqrt(N) / 3);
    // cout << "sqrt_n=" << sqrt_n << endl;
    vector<int> primes = get_primes_up_to(sqrt_n);

    // cout << "primes.size()=" << primes.size() << endl;

    long long count = 0;

    for (int a : primes)
    {
        if (a * a * 2 * 2 > N)
        {
            break;
        }

        for (int b : primes)
        {
            if (b <= a)
            {
                continue;
            }

            if (sqrt(N / static_cast<double>(a * a)) < b)
            {
                break;
            }

            for (int c : primes)
            {
                if (c <= b)
                {
                    continue;
                }

                if (a * a * b * c * c <= N)
                {
                    ++count;
                }
                else
                {
                    break;
                }
            }
        }
    }

    cout << count << endl;
}
