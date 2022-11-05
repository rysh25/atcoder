#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    vector<set<int>> G(N);

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        G[A].insert(B);
        G[B].insert(A);
    }

    for (int i = 0; i < N; i++)
    {
        cout << G[i].size() << " ";
        for (auto itr = G[i].begin(); itr != G[i].end(); itr++)
        {
            cout << *itr + 1 << " ";
        }

        cout << endl;
    }

    return 0;
}
