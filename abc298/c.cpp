#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<multiset<int>> box(N + 1);
    vector<set<int>> num(2 * 1e5 + 1);

    for (int k = 0; k < Q; k++)
    {
        int q, i, j;
        cin >> q;

        if (q == 1)
        {
            cin >> i >> j;
            // cout << "q=" << q << endl;
            box[j].insert(i);
            num[i].insert(j);
        }
        else if (q == 2)
        {
            cin >> i;
            // cout << "q=" << q << endl;
            for (auto b : box[i])
            {
                cout << b << " ";
            }
            cout << endl;
        }
        else
        {
            cin >> i;
            // cout << "q=" << q << endl;
            for (auto b : num[i])
            {
                cout << b << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
