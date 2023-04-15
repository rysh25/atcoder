#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<long long> A(N);

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    set<long long> seen;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        pq.push(A[i]);
        seen.insert(A[i]);
    }

    long long ans = 0;
    for (int i = 0; i < K; i++)
    {
        ans = pq.top();
        pq.pop();

        for (int j = 0; j < N; j++)
        {
            long long new_price = ans + A[j];
            if (seen.count(new_price) == 0)
            {
                pq.push(new_price);
                seen.insert(new_price);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
