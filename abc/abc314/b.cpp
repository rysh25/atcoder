#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<vector<int>> bet(37);
    vector<int> C(N, 0);

    for (int i = 0; i < N; i++)
    {
        // cout << "i: " << i << endl;
        cin >> C[i];

        for (int j = 0; j < C[i]; j++)
        {
            // cout << "j: " << j << endl;
            int A;
            cin >> A;

            bet[A].emplace_back(i);
        }
    }

    // for (int i = 0; i < 37; i++)
    // {
    //     cout << "bet[" << i << "]: " << bet[i].size() << endl;
    // }

    int X;
    cin >> X;

    if (bet[X].size() == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int min_ = 200;
    int min_count = 0;

    for (int i = 0; i < bet[X].size(); i++)
    {
        // cout << "bet[" << i << "]: " << bet[X][i] << endl;
        // cout << "c[" << i << "]: " << C[bet[X][i]] << endl;

        if (min_ == C[bet[X][i]])
        {
            min_count++;
        }
        else if (min_ > C[bet[X][i]])
        {
            min_ = C[bet[X][i]];
            min_count = 1;
        }
    }

    cout << min_count << endl;

    for (int i = 0; i < bet[X].size(); i++)
    {
        if (C[bet[X][i]] == min_)
        {
            cout << bet[X][i] + 1 << " ";
        }
    }

    cout << endl;

    return 0;
}
