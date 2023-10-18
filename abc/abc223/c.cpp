#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;

int main()
{
    int N;
    cin >> N;

    vector<long double> A(N), B(N), T(N, 0);

    long double total_time = 0;

    rep(i, N)
    {
        cin >> A[i] >> B[i];
        T[i] = A[i] / B[i];
        total_time += T[i];
    }

    // cout << "total_time: " << total_time << endl;

    long double length = 0;
    long double prev_time = 0;
    long double half_time = total_time / 2;
    rep(i, N)
    {
        // cout << "half_time: " << half_time << ", length: " << length << ",  T[i]: " << T[i] << endl;
        half_time -= T[i];
        length += A[i];
        if (half_time <= 0)
        {
            // cout << "prev_time: " << prev_time << ", half_time: " << half_time << endl;
            length += B[i] * half_time;
            cout << fixed << setprecision(10) << length << endl;
            return 0;
        }
        // cout << length << endl;
        prev_time = half_time;
    }

    return 0;
}
