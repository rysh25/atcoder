#include <iostream>
#include <vector>
#include <set>
#include <map>
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

    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int prev = A[0];
    for (int i = 1; i < N; i++)
    {
        if (A[i] != prev + 1)
        {
            cout << prev + 1 << endl;
            return 0;
        }
        prev = A[i];
    }

    return 0;
}
