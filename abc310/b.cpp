#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;
    vector<int> P(N), C(N);
    vector<set<int>> F(N);

    for (int i = 0; i < N; i++)
    {
        cin >> P[i] >> C[i];
        for (int j = 0; j < C[i]; j++)
        {
            int f;
            cin >> f;
            F[i].insert(f);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j)
            {
                continue;
            }

            // cout << "i = " << i << ", j = " << j << endl; // debug

            if (P[i] < P[j])
            {
                continue;
            }

            bool ok = true;
            for (auto f : F[i])
            {
                // cout << "f = " << f << endl; // debug
                if (F[j].count(f) <= 0)
                {
                    ok = false;
                    break;
                }
            }

            if (ok && (P[i] > P[j] || F[i].size() < F[j].size()))
            {
                // cout << "i=" << i << ", j=" << j << endl; // debug
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
