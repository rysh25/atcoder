#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<long long> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(21, 0));
}
