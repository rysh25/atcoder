#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    set<long long> s;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        s.insert(A[i]);
    }

    long long ans = 0;
    for (int i = 0; i < K; i++)
    {
        ans = *s.begin();
        s.erase(s.begin());

        for (int j = 0; j < N; j++)
        {
            long long new_price = ans + A[j];
            s.insert(new_price);
        }
    }

    cout << ans << endl;
    return 0;
}
