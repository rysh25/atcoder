#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N), B(N);

    int sum_a = 0, sum_b = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
        sum_a += A[i];
        sum_b += B[i];
    }

    // int avg_a = sum_a / N;
    // int avg_b = sum_b / N;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int med_a = 0;
    int med_b = 0;
    if (N % 2 == 0)
    {
        med_a = (A[N / 2 - 1] + A[N / 2]) / 2;
        med_b = (B[N / 2 - 1] + B[N / 2]) / 2;
    }
    else
    {
        med_a = A[N / 2];
        med_b = B[N / 2];
    }

    // cout << "Start: " << med_a << ", End: " << med_b << endl;

    long long res = 0;
    for (int i = 0; i < N; i++)
    {
        res += abs(med_a - A[i]);
        res += abs(A[i] - B[i]);
        res += abs(B[i] - med_b);
    }

    cout << res << endl;

    return 0;
}
