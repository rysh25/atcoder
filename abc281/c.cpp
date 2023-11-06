#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    long long T;

    cin >> N >> T;

    long long sum = 0;

    // vector<int> A(N);
    vector<long long> time(N + 1);

    for (int i = 1; i < N + 1; i++)
    {
        int A;
        cin >> A;

        sum += A;

        time[i] = sum;

        // cout << "time[" << i << "]=" << time[i] << endl;
    }

    long long sec = T % sum;

    // cout << "sec=" << sec << endl;

    auto it = upper_bound(time.begin(), time.end(), sec);

    cout << it - time.begin() << " " << sec - time[it - time.begin() - 1] << endl;

    return 0;
}
