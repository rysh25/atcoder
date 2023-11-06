#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;

    std::vector<long long> A(N);
    long long total = 0;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> A[i];
        total += A[i];
    }

    std::sort(A.begin(), A.end());

    long long low_target = total / N;
    long long high_target = low_target + (total % N != 0);

    long long low_operations = 0;
    for (int i = 0; i < N; ++i)
    {
        low_operations += std::abs(A[i] - low_target);
    }

    long long high_operations = 0;
    for (int i = 0; i < N; ++i)
    {
        high_operations += std::abs(A[i] - high_target);
    }

    long long result = std::min(low_operations, high_operations) / 2;
    std::cout << result << '\n';

    return 0;
}
