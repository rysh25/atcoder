#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> cards(N, 0);

    // for (int i = 0; i < N; i++)
    //     cout << cards[i] << ", ";

    cout << endl;

    for (int i = 0; i < Q; i++)
    {
        int e, x;
        cin >> e >> x;
        // cout << "e=" << e << ", x=" << x << endl;
        x--;
        if (e == 1)
        {
            cards[x] += 1;
        }
        else if (e == 2)
        {
            cards[x] += 2;
        }
        else
        {
            if (cards[x] >= 2)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
